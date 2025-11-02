#include "historywindow.h"
#include "ui_historywindow.h"
#include <QDate>

HistoryWindow::HistoryWindow(const PurchaseHistory& history, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HistoryWindow)
    , history(history)
{
    ui->setupUi(this);

    QSet<QString> categories;
    for (const auto& record : history.getRecords()) {
        categories.insert(record.getProduct().getCategory());
    }
    for (const QString& category : categories) {
        ui->categoryCombo->addItem(category);
    }

    updateHistoryList(history.getRecords());
}

HistoryWindow::~HistoryWindow()
{
    delete ui;
}

void HistoryWindow::on_filterButton_clicked()
{
    QDate date = ui->dateEdit->date();
    QString category = ui->categoryCombo->currentText();

    QList<PurchaseRecord> filtered;
    if (ui->dateCheckBox->isChecked() && ui->categoryCheckBox->isChecked()) {
        filtered = history.filterByDateAndCategory(date, category);
    } else if (ui->dateCheckBox->isChecked()) {
        filtered = history.filterByDate(date);
    } else if (ui->categoryCheckBox->isChecked()) {
        filtered = history.filterByCategory(category);
    } else {
        filtered = history.getRecords();
    }

    updateHistoryList(filtered);
}

void HistoryWindow::on_clearFilterButton_clicked()
{
    ui->dateCheckBox->setChecked(false);
    ui->categoryCheckBox->setChecked(false);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->categoryCombo->setCurrentIndex(0);
    updateHistoryList(history.getRecords());
}

void HistoryWindow::updateHistoryList(const QList<PurchaseRecord>& records)
{
    ui->historyList->clear();
    for (const auto& record : records) {
        ui->historyList->addItem(record.toString());
    }
    ui->countLabel->setText(QString("Найдено записей: %1").arg(records.size()));
}
