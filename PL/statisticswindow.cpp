#include "statisticswindow.h"
#include "ui_statisticswindow.h"
#include <QTableWidgetItem>
#include <QMessageBox>

StatisticsWindow::StatisticsWindow(const ExpenseStatistics& stats, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StatisticsWindow)
    , stats(stats)
{
    ui->setupUi(this);
    ui->period1Start->setDate(QDate::currentDate().addMonths(-1));
    ui->period1End->setDate(QDate::currentDate());
    ui->period2Start->setDate(QDate::currentDate().addMonths(-2));
    ui->period2End->setDate(QDate::currentDate().addMonths(-1));
}

StatisticsWindow::~StatisticsWindow()
{
    delete ui;
}

void StatisticsWindow::on_calculateButton_clicked()
{
    QDate start = ui->period1Start->date();
    QDate end = ui->period1End->date();

    if (start > end) {
        QMessageBox::warning(this, "Ошибка", "Начальная дата должна быть раньше конечной");
        return;
    }

    QMap<QString, double> expenses = stats.getCategoryExpenses(start, end);
    showExpensesTable(expenses);

    double total = stats.getPeriodExpenses(start, end);
    ui->totalLabel->setText(QString("Итого: %1 руб.").arg(total, 0, 'f', 2));
}

void StatisticsWindow::on_compareButton_clicked()
{
    QDate p1Start = ui->period1Start->date();
    QDate p1End = ui->period1End->date();
    QDate p2Start = ui->period2Start->date();
    QDate p2End = ui->period2End->date();

    if (p1Start > p1End || p2Start > p2End) {
        QMessageBox::warning(this, "Ошибка", "Начальная дата должна быть раньше конечной");
        return;
    }

    QMap<QString, double> comparison = stats.comparePeriods(p1Start, p1End, p2Start, p2End);
    showExpensesTable(comparison);
}

void StatisticsWindow::showExpensesTable(const QMap<QString, double>& expenses)
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(expenses.size());
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels({"Категория", "Сумма"});

    int row = 0;
    for (auto it = expenses.begin(); it != expenses.end(); ++it) {
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(it.key()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(it.value(), 'f', 2)));
        row++;
    }

    ui->tableWidget->resizeColumnsToContents();
}
