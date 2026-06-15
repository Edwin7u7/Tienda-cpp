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
        Customer c): idOrder(id),customer(c){total=0;};

    void addProduct(Product* product){
        products.push_back(product);
    };

    void asignPayment(std::unique_ptr<Payment> payment){
        this->payment =move(payment);
    };

    void processPayment(){
        if(payment)
        {
            payment->processPayment();
        }
    }

    float calculateTotal(){
        total = 0;

        for(auto producto: products)
        {
            total +=producto->getPrice();
        }

        return total;
    }

    void showOrder()const{
        std::cout << "\n Order #" << idOrder;

        std::cout << "\nCustomer: "<< customer.getNombre();

        std::cout << "\nProducts:\n";

        for(auto producto : products)
        {
            producto->showProduct();
        }

        std::cout << "\nTotal: "<< total<< std::endl;
    }

};
#endif