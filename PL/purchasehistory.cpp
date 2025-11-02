#include "purchasehistory.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include <QMessageBox>

PurchaseRecord::PurchaseRecord()
    : product(), dateTime(QDateTime::currentDateTime()) {}

PurchaseRecord::PurchaseRecord(const Product& product, const QDateTime& dateTime)
    : product(product), dateTime(dateTime) {}

PurchaseRecord::PurchaseRecord(const QJsonObject& json)
    : product(
          json.value("name").toString(),
          json.value("category").toString(),
          json.value("price").toDouble()
          ),
    dateTime(QDateTime::fromString(json.value("date").toString(), Qt::ISODate))
{
    if (!dateTime.isValid()) {
        dateTime = QDateTime::currentDateTime();
    }
}

Product PurchaseRecord::getProduct() const { return product; }
QDateTime PurchaseRecord::getDateTime() const { return dateTime; }

QString PurchaseRecord::toString() const {
    return QString("%1 (%2) - %3 руб. (%4)")
        .arg(product.getName())
        .arg(product.getCategory())
        .arg(product.getPrice(), 0, 'f', 2)
        .arg(dateTime.toString("dd.MM.yyyy hh:mm"));
}

void PurchaseHistory::addRecord(const Product& product) {
    records.append(PurchaseRecord(product, QDateTime::currentDateTime()));
}

void PurchaseHistory::clear() {
    records.clear();
}

QList<PurchaseRecord> PurchaseHistory::getRecords() const {
    return records;
}

QList<PurchaseRecord> PurchaseHistory::filterByDate(const QDate& date) const {
    QList<PurchaseRecord> result;
    for (const auto& record : records) {
        if (record.getDateTime().date() == date) {
            result.append(record);
        }
    }
    return result;
}

QList<PurchaseRecord> PurchaseHistory::filterByCategory(const QString& category) const {
    QList<PurchaseRecord> result;
    for (const auto& record : records) {
        if (record.getProduct().getCategory().compare(category, Qt::CaseInsensitive) == 0) {
            result.append(record);
        }
    }
    return result;
}

QList<PurchaseRecord> PurchaseHistory::filterByDateAndCategory(const QDate& date, const QString& category) const {
    QList<PurchaseRecord> result;
    for (const auto& record : records) {
        if (record.getDateTime().date() == date &&
            record.getProduct().getCategory().compare(category, Qt::CaseInsensitive) == 0) {
            result.append(record);
        }
    }
    return result;
}

////////////////////JSON////////////////


QJsonObject PurchaseRecord::toJson() const {
    QJsonObject json;
    json["name"] = product.getName();
    json["category"] = product.getCategory();
    json["price"] = product.getPrice();
    json["date"] = dateTime.toString(Qt::ISODate);
    return json;
}

bool PurchaseHistory::loadFromFile(const QString& filename) {
    // Проверяем существование файла
    if (!QFile::exists(filename)) {
        qDebug() << "Файл истории не существует, будет создан новый при сохранении";
        return true; // Это не ошибка - файл создастся при первом сохранении
    }

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Не удалось открыть файл для чтения:" << file.errorString();
        return false;
    }

    // Читаем весь файл
    QByteArray jsonData = file.readAll();
    file.close();

    // Проверяем, не пуст ли файл
    if (jsonData.isEmpty()) {
        qDebug() << "Файл истории пуст";
        return true;
    }

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);

    // Проверяем ошибки парсинга
    if (parseError.error != QJsonParseError::NoError) {
        qWarning() << "Ошибка парсинга JSON:" << parseError.errorString();
        return false;
    }

    // Проверяем, что документ является массивом
    if (!doc.isArray()) {
        qWarning() << "Файл истории не содержит JSON-массив";
        return false;
    }

    QJsonArray jsonArray = doc.array();
    QList<PurchaseRecord> loadedRecords;

    // Читаем записи из массива
    for (const QJsonValue& value : jsonArray) {
        if (!value.isObject()) {
            qWarning() << "Найдена запись, не являющаяся объектом - пропускаем";
            continue;
        }

        QJsonObject obj = value.toObject();
        PurchaseRecord record(obj);

        // Проверяем, что запись загрузилась корректно
        if (!record.getProduct().getName().isEmpty()) {
            loadedRecords.append(record);
        }
    }

    // Если дошли сюда - заменяем текущие записи загруженными
    records = loadedRecords;
    qDebug() << "Успешно загружено" << records.size() << "записей из файла";
    return true;
}

bool PurchaseHistory::saveToFile(const QString& filename) const {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Не удалось открыть файл для записи:" << file.errorString();
        return false;
    }

    QJsonArray jsonArray;
    for (const PurchaseRecord& record : records) {
        jsonArray.append(record.toJson());
    }

    QJsonDocument doc(jsonArray);
    qint64 bytesWritten = file.write(doc.toJson(QJsonDocument::Indented));
    file.close();

    if (bytesWritten == -1) {
        qWarning() << "Ошибка записи в файл:" << file.errorString();
        return false;
    }

    qDebug() << "Успешно сохранено" << records.size() << "записей в файл";
    return true;
}
