// store.cpp
#include "store.h"
#include "product.h"
#include <iostream>
#include <algorithm>
#include <memory>




void Store::cleanbuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid value!" << std::endl;
    std::cout << std::endl;
}

void Store::storeInfo() {
        do {
            std::cout << std::endl;
            std::cout << "Store name: " << name << std::endl;
            std::cout << "Number of staff: " << staff << std::endl;
            std::cout << "Currency: " << currency << std::endl;
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

void Store::changeStore() {
    std::cout << std::endl;
        std::cout << "Changing managed store data..." << std::endl;
        do {
            std::cout << "Choose the data you want to change: " << std::endl;
            std::cout << "1. Store name " << std::endl;
            std::cout << "2. Number of staff " << std::endl;
            std::cout << "3. Currency " << std::endl;
            std::cout << "4. Go back to main menu" << std::endl;
            int choice_store_change;
            std::cin >> choice_store_change;
            if (std::cin.fail()){
                cleanbuffer();
                return;
            }
            else {
                switch (choice_store_change) {
                    case 1: {
                        std::cout << "Enter a new store name: ";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::string newName;
                        std::getline(std::cin, newName);
                        std::transform(newName.begin(), newName.end(), newName.begin(), ::tolower);
                        newName[0] = std::toupper(newName[0]);
                        if (std::cin.fail()) {
                            cleanbuffer();
                        } else {
                            std::cout << "Name changed successfully" << std::endl;
                            name = newName;
                        }
                        break;
                    }
                    case 2: {
                        std::cout << "Enter a new number of staff: ";
                        std::cin >> staff;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        if (std::cin.fail()) {
                            cleanbuffer();
                        } else {
                            std::cout << "Staff changed successfully" << std::endl;
                        }
                        break;
                    }
                    case 3: {
                        {
                            std::cout << "Please set the new currency for the store" << std::endl;
                            std::cout << "1. PLN, 2. USD, 3. EUR" << std::endl;

                            int currency_choice;
                            std::cin >> currency_choice;

                            if (std::cin.fail()) {
                                cleanbuffer();
                                return;
                            }

                            switch (currency_choice) {
                                case 1: {
                                    currency = "PLN";
                                    break;
                                }
                                case 2: {
                                    currency = "USD";
                                    break;
                                }
                                case 3: {
                                    currency = "EUR";
                                    break;
                                }
                                default: {
                                    std::cout << "Invalid choice!" << std::endl;
                                    return;
                                }
                            }
                            std::shared_ptr<Product> ptr_product = std::make_shared<Product>();
                            ptr_product->changeCurrency(currency);
                            std::cout << "Currency changed successfully" << std::endl;
                        }
                        case 4:{
                            std::cout << std::endl;
                            return;
                        }

                    }
                }
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
            }
        } while (true);
    }


Store::~Store() {
    // Destruktor
}
