// store.h
#ifndef STORE_H
#define STORE_H
#include "product.h"
#include <string>
#include <memory>

class Store {
public:

    Store(std::string t_name, int t_staff, std::string t_currency)
            : name(t_name), staff(t_staff), currency(t_currency) {
    }

    void storeInfo();
    void changeStore();
    ~Store();
    void static cleanbuffer();

private:
    std::string name;
    int staff;
    std::string currency = "PLN";
};

#endif
