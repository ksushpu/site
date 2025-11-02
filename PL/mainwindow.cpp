#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "historywindow.h"
#include "productrecommender.h"
#include "expensestatistics.h"
#include "statisticswindow.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QDebug>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ////СТАТИСТИКА/////
    QPushButton *statisticsButton = new QPushButton("Статистика", this);
    statisticsButton->setStyleSheet("background-color: #D4E8F2;");
    ui->horizontalLayout_2->insertWidget(2, statisticsButton);
    connect(statisticsButton, &QPushButton::clicked, this, &MainWindow::on_statisticsButton_clicked);

    //ЗАГРУЗКА ИЗ ФАЙЛА/////
    if (!purchaseHistory.loadFromFile(HISTORY_FILE)) {
        QMessageBox::warning(this, "Ошибка загрузки",
                             "Не удалось загрузить историю покупок. Будет создана новая история.\n"
                             "Проверьте целостность файла " + HISTORY_FILE);
    }

    loadCategories();

    updateProductList();


    // Добавляем кнопки в интерфейс
    QPushButton *historyButton = new QPushButton("История", this);
    historyButton->setStyleSheet("background-color: #D4E8F2;");
    QPushButton *recommendationsButton = new QPushButton("Рекомендации", this);
    recommendationsButton->setStyleSheet("background-color: #D4E8F2;");

    ui->horizontalLayout_2->insertWidget(0, historyButton);
    ui->horizontalLayout_2->insertWidget(1, recommendationsButton);

    connect(historyButton, &QPushButton::clicked, this, &MainWindow::on_historyButton_clicked);
    connect(recommendationsButton, &QPushButton::clicked, this, &MainWindow::on_recommendationsButton_clicked);

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addButton_clicked()
{
    QString name = ui->nameEdit->text();
    QString category = ui->categoryCombo->currentText();
    double price = ui->priceEdit->text().toDouble();

    if (name.isEmpty() || category.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Заполните все поля");
        return;
    }

    // Добавляем категорию, если её нет в списке
    if (ui->categoryCombo->findText(category) == -1) {
        ui->categoryCombo->addItem(category);
        saveCategoriesToFile(); // Сохраняем обновленный список категорий
    }

    Product product(name, category, price);
    shoppingList.addProduct(product);
    purchaseHistory.addRecord(product);
    updateProductList();

    ui->nameEdit->clear();
    ui->priceEdit->clear();
}


void MainWindow::on_removeButton_clicked()
{
    int row = ui->productList->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "Ошибка", "Выберите товар для удаления");
        return;
    }

    shoppingList.removeProduct(row);
    updateProductList();
}

void MainWindow::on_clearButton_clicked()
{
    shoppingList.clear();
    updateProductList();
}

void MainWindow::on_calculateButton_clicked()
{
    double total = shoppingList.calculateTotalCost();
    ui->totalLabel->setText(QString("Итого: %1 руб.").arg(total, 0, 'f', 2));
}

void MainWindow::updateProductList()
{
    ui->productList->clear();
    const QList<Product>& products = shoppingList.getProducts();

    for (const Product& product : products) {
        QString itemText = QString("%1 (%2) - %3 руб.")
                               .arg(product.getName())
                               .arg(product.getCategory())
                               .arg(product.getPrice(), 0, 'f', 2);
        ui->productList->addItem(itemText);
    }

    ui->countLabel->setText(QString("Товаров: %1").arg(shoppingList.getProductCount()));
}

//////////////////////HISTORY_AND_RECOMENDATION_BUTTON//////////////////

void MainWindow::on_historyButton_clicked()
{
    HistoryWindow *historyWindow = new HistoryWindow(purchaseHistory, this);
    historyWindow->exec();
    delete historyWindow;
}

void MainWindow::on_recommendationsButton_clicked()
{
    ProductRecommender recommender(purchaseHistory);
    QStringList categories = recommender.getRecommendedCategories();

    QString message = "Рекомендуемые категории:\n";
    for (const QString& category : categories) {
        message += "- " + category + "\n";

        QStringList products = recommender.getRecommendedProducts(category);
        if (!products.isEmpty()) {
            message += "  Популярные товары:\n";
            for (const QString& product : products) {
                message += "  - " + product + "\n";
            }
        }
    }

    QMessageBox::information(this, "Рекомендации", message);
}
////////////////JSON////////////////
void MainWindow::closeEvent(QCloseEvent *event) {
    if (!purchaseHistory.saveToFile(HISTORY_FILE)) {
        QMessageBox::critical(this, "Ошибка сохранения",
                              "Не удалось сохранить историю покупок!\n"
                              "Ваши данные могут быть потеряны.");
    }

    // Сохраняем категории при закрытии
    saveCategoriesToFile();

    event->accept();
}
void MainWindow::loadHistory()
{
    purchaseHistory.loadFromFile(HISTORY_FILE);
}

void MainWindow::saveHistory()
{
    purchaseHistory.saveToFile(HISTORY_FILE);
}

bool MainWindow::checkHistoryFileIntegrity() {
    QFile file(HISTORY_FILE);
    if (!file.exists()) return true;

    if (!file.open(QIODevice::ReadOnly)) return false;

    QByteArray data = file.readAll();
    file.close();

    QJsonParseError error;
    QJsonDocument::fromJson(data, &error);

    return (error.error == QJsonParseError::NoError);
}
////////////////STATS//////
void MainWindow::on_statisticsButton_clicked() {
    ExpenseStatistics stats(purchaseHistory);
    StatisticsWindow *statsWindow = new StatisticsWindow(stats, this);
    statsWindow->exec();
    delete statsWindow;
}


//////////CATEGORIES/////////
void MainWindow::saveCategoriesToFile() {
    QFile file("categories.json");
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Could not open categories file for writing";
        return;
    }

    QJsonArray categoriesArray;
    for (int i = 0; i < ui->categoryCombo->count(); ++i) {
        categoriesArray.append(ui->categoryCombo->itemText(i));
    }

    QJsonDocument doc(categoriesArray);
    file.write(doc.toJson());
    file.close();
}

void MainWindow::loadCategoriesFromFile() {
    QFile file("categories.json");
    if (!file.exists()) return;

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Could not open categories file for reading";
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(data, &error);
    if (error.error != QJsonParseError::NoError) {
        qWarning() << "Error parsing categories file:" << error.errorString();
        return;
    }

    if (!doc.isArray()) {
        qWarning() << "Categories file is not an array";
        return;
    }

    QJsonArray categoriesArray = doc.array();
    for (const QJsonValue& value : categoriesArray) {
        QString category = value.toString();
        if (!category.isEmpty() && ui->categoryCombo->findText(category) == -1) {
            ui->categoryCombo->addItem(category);
        }
    }
}

void MainWindow::loadCategories()
{
    ui->categoryCombo->clear();

    // Сначала загружаем сохраненные категории
    loadCategoriesFromFile();

    // Затем добавляем категории из истории покупок
    QSet<QString> categories;
    for (const auto& record : purchaseHistory.getRecords()) {
        categories.insert(record.getProduct().getCategory());
    }

    for (const QString& category : categories) {
        if (ui->categoryCombo->findText(category) == -1) {
            ui->categoryCombo->addItem(category);
        }
    }
}
