#include <string>
#ifndef STORE_H
#define STORE_H
#include "Customer.h"
#include <vector>
#include "Order.h"
#include "Inventory.h"

class Store {
private:
    std::string name;

    Inventory inventory;

    std::vector<Customer> customers;

    std::vector<Order> orders;

public:
    Store(std::string nombre);

    void registerClient(const Customer& customer){
        customers.push_back(customer);
    }

    void createOrder(){
      std::cout<< "Order created"<< std::endl;  
    }

    void showInventory(){
        inventory.showProducts();
    }
};

#endif