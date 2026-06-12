#include <string>
#include <vector>
#include <memory>
#ifndef ORDER_H
#define ORDER_H
#include "Customer.h"
#include "Product.h"
#include "Payment.h"
class Order{
    private:
        int idOrder;
        Customer customer;
        std::vector<Product*>products;
        std::unique_ptr<Payment> payment;
        float total;

    public:
        Order(
        int id,
        Customer c): customer(c), idOrder(id){};

    void addProduct(
        Product* product);

    void asignPayment(
        std::unique_ptr<Payment> payment);

    void processPayment();

    float calculateTotal();

};
#endif