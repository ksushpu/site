#include "expensestatistics.h"
#include <algorithm>

ExpenseStatistics::ExpenseStatistics(const PurchaseHistory& history)
    : history(history) {}

double ExpenseStatistics::getTotalExpenses() const {
    double total = 0.0;
    for (const auto& record : history.getRecords()) {
        total += record.getProduct().getPrice();
    }
    return total;
}

double ExpenseStatistics::getPeriodExpenses(const QDate& start, const QDate& end) const {
    double total = 0.0;
    for (const auto& record : filterByDateRange(start, end)) {
        total += record.getProduct().getPrice();
    }
    return total;
}

QMap<QString, double> ExpenseStatistics::getCategoryExpenses(const QDate& start, const QDate& end) const {
    QMap<QString, double> categories;
    for (const auto& record : filterByDateRange(start, end)) {
        QString category = record.getProduct().getCategory();
        categories[category] += record.getProduct().getPrice();
    }
    return categories;
}

QMap<QString, double> ExpenseStatistics::comparePeriods(
    const QDate& period1Start, const QDate& period1End,
    const QDate& period2Start, const QDate& period2End) const
{
    QMap<QString, double> comparison;

    double period1Total = getPeriodExpenses(period1Start, period1End);
    double period2Total = getPeriodExpenses(period2Start, period2End);

    comparison["Период 1 (Всего)"] = period1Total;
    comparison["Период 2 (Всего)"] = period2Total;
    comparison["Разница"] = period2Total - period1Total;
    comparison["Изменение (%)"] = (period1Total > 0)
                                      ? ((period2Total - period1Total) / period1Total * 100)
                                      : 0.0;

    return comparison;
}

QList<PurchaseRecord> ExpenseStatistics::filterByDateRange(const QDate& start, const QDate& end) const {
    QList<PurchaseRecord> result;
    for (const auto& record : history.getRecords()) {
        QDate recordDate = record.getDateTime().date();
        if (recordDate >= start && recordDate <= end) {
            result.append(record);
        }
    }
    return result;
}
