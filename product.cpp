// product.cpp
#include "product.h"
#include "store.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <iomanip>



void Product::addProduct() {
    do {
        std::cout << std::endl;
        std::cout << "How many products do you want to add to the store assortment? ";
        int quantity_products;
        std::cin >> quantity_products;
        if (quantity_products <= 0) {
            std::cout << std::endl;
            std::cout << "Invalid value, enter a quantity greater than zero." << std::endl;
            std::cout << std::endl;
        }
        for (int i = 0; i < quantity_products; ++i) { // For loop that allows the user to set the amount of product entries
            std::shared_ptr<Product> newProduct = std::make_shared<Product>();
            std::cout << std::endl;
            std::cout << "Enter the data of the product you want to add." << std::endl;
            std::cout << "Product name: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, newProduct->product_name);
            std::transform(newProduct->product_name.begin(), newProduct->product_name.end(),
                           newProduct->product_name.begin(),
                           ::tolower);
            newProduct->product_name[0] = std::toupper(newProduct->product_name[0]);
            std::cout << "Quantity of the product: ";
            std::cin >> newProduct->product_quantity;
            std::cout << "Selling price per unit: ";
            std::cin >> newProduct->selling_price;
            std::cout << "Purchase cost per unit: ";
            std::cin >> newProduct->purchase_cost;
            if (std::cin.fail()) {
                Store::cleanbuffer();
                return;
            } else {
                std::cout << "Added product(s) to the list successfully" << std::endl;
                product_list.push_back(newProduct); // Adding the product to the vector
            }
        }
        std::cout << std::endl;
        std::cout << "Do you want to go back to the main menu? (y/n) ";
        char backToMenuChoice;
        std::cin >> backToMenuChoice;

        if (backToMenuChoice == 'y' || backToMenuChoice == 'Y') {
            std::cout << std::endl;
            return;
        } else if (backToMenuChoice == 'n' || backToMenuChoice == 'N') {

        } else {
            std::cout << std::endl;
            std::cout << "Invalid choice. Please enter 'y' or 'n'." << std::endl;
            std::cout << std::endl;
        }
    } while (true);
}

void Product::showProduct() {
    do {
        if (product_list.empty()) {
            std::cout << std::endl;
            std::cout << "Product list is empty!" << std::endl;
            std::cout << std::endl;
        }
        for (int i = 0; i < product_list.size(); ++i) {
            std::cout << std::endl;
            std::cout << i + 1 << ". " << product_list[i]->product_name << std::endl;
            std::cout << " " << std::setprecision(4) << "Price per unit: " << product_list[i]->selling_price << " " << currency
                      << ", "
                      << "Product quantity in stock: " << product_list[i]->product_quantity << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Do you want to go back to the main menu? (y/n) ";
        char backToMenuChoice;
        std::cin >> backToMenuChoice;

        if (backToMenuChoice == 'y' || backToMenuChoice == 'Y') {
            std::cout << std::endl;
            return;
        } else if (backToMenuChoice == 'n' || backToMenuChoice == 'N') {

        } else {
            std::cout << "Invalid choice. Please enter 'y' or 'n'." << std::endl;
        }

    } while (true);
}

void Product::removeProduct() {
    do {
        if (product_list.empty()) {
            std::cout << std::endl;
            std::cout << "Product list is empty!" << std::endl;
            std::cout << std::endl;
            return;
        }
        std::cout << std::endl;
        std::cout << "1. Delete the entire product entry from stock" << std::endl;
        std::cout << "2. Change the quantity of a specific product in the stock" << std::endl;
        std::cout << "3. Delete all entries from the stock" << std::endl;
        std::cout << "4. Go back to the main menu" << std::endl;
        std::cout << "Choice: ";
        int remove_option;
        std::cin >> remove_option;
        if (std::cin.fail()) {
            Store::cleanbuffer();
            return;
        }
        switch (remove_option) {
            case 1: {
                std::cout << "Which product do you want to remove?" << std::endl;
                for (int i = 0; i < product_list.size(); ++i) {
                    std::cout << i + 1 << ". " << product_list[i]->product_name << std::endl;
                    std::cout << " " << std::setprecision(4) << "Price per unit: " << product_list[i]->selling_price
                              << " "
                              << currency << ", "
                              << "Product quantity in stock: " << product_list[i]->product_quantity << std::endl;
                }
                std::cout << "Choose from the range: " << product_list.size() << std::endl;
                int product_remove_choice;
                std::cin >> product_remove_choice;
                if (product_remove_choice >= 1 && product_remove_choice <= product_list.size()) {
                    product_list.erase(product_list.begin() + product_remove_choice - 1);
                } else {
                    std::cout << "Invalid value" << std::endl;
                }
                break;
            }
            case 2: {
                std::cout << "Which product's quantity would you want to change?" << std::endl;
                for (int i = 0; i < product_list.size(); ++i) {
                    std::cout << i + 1 << ". " << product_list[i]->product_name << std::endl;
                    std::cout << " " << std::setprecision(4) << "Price per unit: " << product_list[i]->selling_price
                              << " " << currency << ", "
                              << "Product quantity in stock: " << product_list[i]->product_quantity << std::endl;
                }
                std::cout << "Choose from the range: " << product_list.size() << std::endl;
                int product_remove_choice;
                std::cin >> product_remove_choice;
                if (product_remove_choice >= 1 && product_remove_choice <= product_list.size()) {
                    int new_quantity;
                    std::cout << "Enter a new value for the product quantity: ";
                    std::cin >> new_quantity;
                    product_list[product_remove_choice - 1]->product_quantity = new_quantity;
                } else {
                    std::cout << "Invalid value" << std::endl;
                }
                break;
            }
            case 3: {
                std::cout << "Deleted all item entries from the stock" << std::endl;
                product_list.clear();
                break;
            }
            case 4: {
                return;
            }
            default: {
                std::cout << "Invalid choice. Please enter a valid option (1, 2, or 3)." << std::endl;
                break;
            }
        }
        std::cout << std::endl;
        std::cout << "Do you want to go back to the main menu? (y/n) ";
        char backToMenuChoice;
        std::cin >> backToMenuChoice;
        if (backToMenuChoice == 'y' || backToMenuChoice == 'Y') {
            std::cout << std::endl;
            return;
        } else if (backToMenuChoice == 'n' || backToMenuChoice == 'N') {

        } else {
            std::cout << "Invalid choice. Please enter 'y' or 'n'." << std::endl;
        }
    } while (true);
}

void Product::productMargin() {
    do {
        if (product_list.empty()) {
            std::cout << std::endl;
            std::cout << "Product list is empty!" << std::endl;
            std::cout << std::endl;
            return;
        } else {
            std::cout << std::endl;
            for (int i = 0; i < product_list.size(); ++i) {
                std::cout << i + 1 << ". " << product_list[i]->product_name << std::endl;
                std::cout << " " << std::setprecision(4) << "Price per unit: " << product_list[i]->selling_price << " "
                          << currency << ", "
                          << "Product quantity in stock: " << product_list[i]->product_quantity << std::endl;
            }
        }
        std::cout << "For which product do you want to calculate the trade margin?" << std::endl;
        std::cout << "Choose from the range: " << product_list.size() << std::endl;
        int product_choice;
        std::cin >> product_choice;
        if (product_choice >= 1 && product_choice <= product_list.size()) {
            int margin_index = product_choice - 1;
            margin = ((product_list[margin_index]->selling_price - product_list[margin_index]->purchase_cost)
                      / product_list[margin_index]->selling_price * 100);
            std::cout << "Purchase cost: " << product_list[margin_index]->purchase_cost << " " << currency << std::endl;
            std::cout << "Calculating the trade margin for the product: " << product_list[margin_index]->product_name
                      << std::endl;
            std::cout << "The margin is: " << margin << " " << "%" << std::endl;
            std::cout << "Price with trade margin: " << product_list[margin_index]->selling_price << " " << currency << std::endl;
            std::cout << "Potential profit for quantity: " << product_list[margin_index]->product_quantity << " Units"
                      << " - "
                      << (product_list[margin_index]->product_quantity * product_list[margin_index]->selling_price)
                      << currency << std::endl;
        } else {
            std::cout << "Invalid value" << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Do you want to go back to the main menu? (y/n) ";
        char backToMenuChoice;
        std::cin >> backToMenuChoice;
        if (backToMenuChoice == 'y' || backToMenuChoice == 'Y') {
            std::cout << std::endl;
            return;
        } else if (backToMenuChoice == 'n' || backToMenuChoice == 'N') {

        } else {
            std::cout << "Invalid choice. Please enter 'y' or 'n'." << std::endl;
        }
    } while (true);
}

void Product::changeCurrency(std::string newCurrency) {
    currency = newCurrency;
    std::cout << "Currency in products changed successfully." << std::endl;
    std::cout << std::endl;
}

void Product::fileManagement() {
    do {
        std::cout << std::endl;
        std::cout << "What would you like to do with the file?" << std::endl;
        std::cout << "1. Save products to file" << std::endl;
        std::cout << "2. Clear the file" << std::endl;
        std::cout << "3. Read products from the file" << std::endl;
        std::cout << "4. Go back to the main menu" << std::endl;
        int file_management;
        std::cin >> file_management;
        if (std::cin.fail()) {
            Store::cleanbuffer();
            return;
        }
        switch (file_management) {
            case 1: {
                if (product_list.empty()) {
                    std::cout << std::endl;
                    std::cout << "Product list is empty!" << std::endl;
                    return;
                }
                std::ofstream outputFile("products.txt", std::ofstream::app);
                if (!outputFile.is_open()) {
                    std::cout << "Failed to open the file for writing." << std::endl;
                    return;
                }

                for (const auto &product : product_list) {
                    outputFile << "Product name: " << product->product_name << std::endl;
                    outputFile << "Quantity: " << product->product_quantity << std::endl;
                    outputFile << "Selling price: " << product->selling_price << std::endl;
                    outputFile << "Purchase cost: " << product->purchase_cost << std::endl;
                    outputFile << std::endl;
                }

                outputFile.close();
                std::cout << "Products saved to the file." << std::endl;
                break;
            }
            case 2: {
                std::ofstream outputFile("products.txt", std::ofstream::trunc);
                if (!outputFile.is_open()) {
                    std::cout << "Failed to open the file for writing." << std::endl;
                    return;
                }
                std::cout << "Cleared the file." << std::endl;
                break;
            }
            case 3: {
                std::ifstream inputFile("products.txt");
                if (!inputFile.is_open()) {
                    std::cout << "Failed to open the file for reading." << std::endl;
                    break;
                }

                std::string line;
                std::string name;
                float quantity = 0.0;
                float sell_price = 0.0;
                float purchase = 0.0;
                while (std::getline(inputFile, line)) {
                    if (line.find("Product name: ") != std::string::npos) {
                        name = line.substr(14);
                    } else if (line.find("Quantity: ") != std::string::npos) {
                        quantity = std::stof(line.substr(10));
                    } else if (line.find("Selling price: ") != std::string::npos) {
                        sell_price = std::stof(line.substr(15));
                    } else if (line.find("Purchase cost: ") != std::string::npos) {
                        purchase = std::stof(line.substr(15));
                        std::shared_ptr<Product> newProduct = std::make_shared<Product>();
                        newProduct->product_name = name;
                        newProduct->product_quantity = quantity;
                        newProduct->selling_price = sell_price;
                        newProduct->purchase_cost = purchase;
                        product_list.push_back(newProduct);
                        name.clear();
                        quantity = 0.0;
                        sell_price = 0.0;
                        purchase = 0.0;
                    }
                }

                inputFile.close();
                std::cout << "Products loaded from the file." << std::endl;
                break;
            }
        }
        std::cout << std::endl;
        std::cout << "Do you want to go back to the main menu? (y/n) ";
        char backToMenuChoice;
        std::cin >> backToMenuChoice;

        if (backToMenuChoice == 'y' || backToMenuChoice == 'Y') {
            std::cout << std::endl;
            return;
        } else if (backToMenuChoice == 'n' || backToMenuChoice == 'N') {

        } else {
            std::cout << std::endl;
            std::cout << "Invalid choice. Please enter 'y' or 'n'." << std::endl;
            std::cout << std::endl;
        }
    } while (true);
}

Product::~Product() {
    std::cout << "Released memory of Product object" << std::endl;
}
