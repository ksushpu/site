#ifndef PURCHASEHISTORY_H
#define PURCHASEHISTORY_H

#include "product.h"
#include <QDateTime>
#include <QList>
#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

class PurchaseRecord
{
public:
    PurchaseRecord();
    PurchaseRecord(const Product& product, const QDateTime& dateTime);
    PurchaseRecord(const QJsonObject& json);

    Product getProduct() const;
    QDateTime getDateTime() const;
    QString toString() const;
    ///////////////////////JSON////////////

    QJsonObject toJson() const;

private:
    Product product;
    QDateTime dateTime;
};

class PurchaseHistory
{
public:

    void addRecord(const Product& product);
    void clear();

    QList<PurchaseRecord> getRecords() const;
    QList<PurchaseRecord> filterByDate(const QDate& date) const;
    QList<PurchaseRecord> filterByCategory(const QString& category) const;
    QList<PurchaseRecord> filterByDateAndCategory(const QDate& date, const QString& category) const;

    ///////////////////////JSON///////////
    bool loadFromFile(const QString& filename);
    bool saveToFile(const QString& filename) const;

private:
    QList<PurchaseRecord> records;
};

#endif // PURCHASEHISTORY_H
