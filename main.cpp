#include <iostream>
#include <memory>
#include "product.h"
#include "store.h"
#include <string>
#include <vector>


int main() {
    std::shared_ptr<Product> ptr_product = std::make_shared<Product>();
    std::shared_ptr<Store> ptr_store = std::make_shared<Store>("ShopeX", 100, "PLN");
    while (true) {
        std::cout << "Store Management 1.0" << std::endl;
        std::cout << "1. Display information about the currently managed store" << std::endl;
        std::cout << "2. Add products to the store's assortment" << std::endl;
        std::cout << "3. Show the list of products in the store" << std::endl;
        std::cout << "4. Manage the list of products in the store" << std::endl;
        std::cout << "5. Calculate the trade margin and potential profit" << std::endl;
        std::cout << "6. Change the data of the managed store" << std::endl;
        std::cout << "7. File management" << std::endl;
        std::cout << "8. Exit the program" << std::endl;
        std::cout << "Choose from 1 to 8: ";

        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid value" << std::endl;
        } else {
            switch (choice) {
                case 1:
                    ptr_store->storeInfo();
                    break;
                case 2:
                    ptr_product->addProduct();
                    break;
                case 3:
                    ptr_product->showProduct();
                    break;
                case 4:
                    ptr_product->removeProduct();
                    break;
                case 5:
                    ptr_product->productMargin();
                    break;
                case 6:
                    ptr_store->changeStore();
                    break;
                case 7:
                    ptr_product->fileManagement();
                    break;
                case 8:{
                    exit(0);
                }
                default:
                    std::cout << "Invalid choice" << std::endl;
            }
        }
    }

    return 0;
}
