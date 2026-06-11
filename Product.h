#include <string>
#ifndef PRODUCT_H
#define PRODUCT_H
class Product {
    private:
        int idProduct;
        std::string name;
        float price;
        int stock;
        std::string category;
    
    public:
  
        Product(int id, std::string n, float p, int s, std::string c):
        idProduct(id),  name(n), price(p), stock(s), category(c) {}

        void showProduct(){}

        void updateStock(int stock){}

        float getPrice(){}

        int getId (){}


};
#endif