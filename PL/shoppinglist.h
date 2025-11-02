#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

#include "product.h"
#include <QList>
#include <QString>

class ShoppingList
{
public:
    void addProduct(const Product& product);
    void removeProduct(int index);
    void clear();

    double calculateTotalCost() const;

    const QList<Product>& getProducts() const;
    int getProductCount() const;

private:
    QList<Product> products;
};

#endif // SHOPPINGLIST_H
