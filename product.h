// product.h
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>
#include <memory>
#include "store.h"


class Product {
public:
    Product() = default;


    void addProduct();
    void showProduct();
    void removeProduct();
    void productMargin();
    void showGraph();
    void changeCurrency(std::string newCurrency);
    void fileManagement();
    ~Product();



private:
    std::vector<std::shared_ptr<Product>> product_list;
    std::string product_name;
    std::string currency = "PLN";
    float selling_price;
    float purchase_cost;
    float margin;
    double product_quantity;
};

#endif
