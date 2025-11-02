#include "shoppinglist.h"

void ShoppingList::addProduct(const Product& product) {
    products.append(product);
}

void ShoppingList::removeProduct(int index) {
    if (index >= 0 && index < products.size()) {
        products.removeAt(index);
    }
}

void ShoppingList::clear() {
    products.clear();
}

double ShoppingList::calculateTotalCost() const {
    double total = 0.0;
    for (const Product& product : products) {
        total += product.getPrice();
    }
    return total;
}

const QList<Product>& ShoppingList::getProducts() const {
    return products;
}

int ShoppingList::getProductCount() const {
    return products.size();
}
