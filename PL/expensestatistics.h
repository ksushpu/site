#ifndef EXPENSESTATISTICS_H
#define EXPENSESTATISTICS_H

#include "purchasehistory.h"
#include <QDate>
#include <QMap>

class ExpenseStatistics
{
public:
    ExpenseStatistics(const PurchaseHistory& history);

    // Основные методы статистики
    double getTotalExpenses() const;
    double getPeriodExpenses(const QDate& start, const QDate& end) const;
    QMap<QString, double> getCategoryExpenses(const QDate& start, const QDate& end) const;

    // Методы для сравнения периодов
    QMap<QString, double> comparePeriods(
        const QDate& period1Start, const QDate& period1End,
        const QDate& period2Start, const QDate& period2End) const;

private:
    const PurchaseHistory& history;
    QList<PurchaseRecord> filterByDateRange(const QDate& start, const QDate& end) const;
};

#endif // EXPENSESTATISTICS_H
