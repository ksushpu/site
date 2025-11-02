#ifndef PRODUCTRECOMMENDER_H
#define PRODUCTRECOMMENDER_H

#include "purchasehistory.h"
#include <QString>
#include <QList>

class ProductRecommender
{
public:
    ProductRecommender(const PurchaseHistory& history);

    QList<QString> getRecommendedCategories() const;
    QList<QString> getRecommendedProducts(const QString& category) const;

private:
    const PurchaseHistory& history;
};

#endif // PRODUCTRECOMMENDER_H
