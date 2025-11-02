#include "productrecommender.h"
#include <QMap>
#include <algorithm>

ProductRecommender::ProductRecommender(const PurchaseHistory& history)
    : history(history) {}

QList<QString> ProductRecommender::getRecommendedCategories() const {
    QMap<QString, int> categoryCounts;
    auto records = history.getRecords();

    for (const auto& record : records) {
        QString category = record.getProduct().getCategory();
        categoryCounts[category]++;
    }

    QList<QPair<int, QString>> sortedCategories;
    for (auto it = categoryCounts.begin(); it != categoryCounts.end(); ++it) {
        sortedCategories.append(qMakePair(it.value(), it.key()));
    }

    std::sort(sortedCategories.begin(), sortedCategories.end(), std::greater<QPair<int, QString>>());

    QList<QString> result;
    for (const auto& pair : sortedCategories) {
        result.append(pair.second);
    }

    return result;
}

QList<QString> ProductRecommender::getRecommendedProducts(const QString& category) const {
    QMap<QString, int> productCounts;
    auto records = history.getRecords();

    for (const auto& record : records) {
        if (record.getProduct().getCategory().compare(category, Qt::CaseInsensitive) == 0) {
            QString name = record.getProduct().getName();
            productCounts[name]++;
        }
    }

    QList<QPair<int, QString>> sortedProducts;
    for (auto it = productCounts.begin(); it != productCounts.end(); ++it) {
        sortedProducts.append(qMakePair(it.value(), it.key()));
    }

    std::sort(sortedProducts.begin(), sortedProducts.end(), std::greater<QPair<int, QString>>());

    QList<QString> result;
    for (const auto& pair : sortedProducts) {
        result.append(pair.second);
    }

    return result;
}
