#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>

class Product
{
public:
    Product();  // Добавляем конструктор по умолчанию
    Product(const QString& name, const QString& category, double price);

    QString getName() const;
    QString getCategory() const;
    double getPrice() const;

    void setName(const QString& name);
    void setCategory(const QString& category);
    void setPrice(double price);

private:
    QString name;
    QString category;
    double price;
};

#endif // PRODUCT_H
