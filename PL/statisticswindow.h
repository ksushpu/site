#ifndef STATISTICSWINDOW_H
#define STATISTICSWINDOW_H

#include <QDialog>
#include "expensestatistics.h"

namespace Ui {
class StatisticsWindow;
}

class StatisticsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StatisticsWindow(const ExpenseStatistics& stats, QWidget *parent = nullptr);
    ~StatisticsWindow();

private slots:
    void on_calculateButton_clicked();
    void on_compareButton_clicked();

private:
    Ui::StatisticsWindow *ui;
    const ExpenseStatistics& stats;
    void showExpensesTable(const QMap<QString, double>& expenses);
};

#endif // STATISTICSWINDOW_H
