#include "product.h"

Product::Product()
    : name(""), category(""), price(0.0) {}

Product::Product(const QString& name, const QString& category, double price)
    : name(name), category(category), price(price) {}

QString Product::getName() const { return name; }
QString Product::getCategory() const { return category; }
double Product::getPrice() const { return price; }

void Product::setName(const QString& name) { this->name = name; }
void Product::setCategory(const QString& category) { this->category = category; }
void Product::setPrice(double price) { this->price = price; }
