#include <string>
#include <iostream>
#include "StockInsuficienteException.h"
#ifndef PRODUCT_H
#define PRODUCT_H
class Product {
    private:
        int idProduct;
        std::string name;
        float price;
        int stock;
        
    
    public:
  
        Product(int id, std::string n, float p, int s):
        idProduct(id),  name(n), price(p), stock(s) {}

        virtual ~Product() = default;

        virtual std::string getType() const = 0;

        void sell(int amount){
            if(amount> stock)
            {
                throw StockInsuficienteException("Insufficient stock...");
            }

            stock -= amount;
        }

        float getPrice () const{
            return price;
        }

        int getStock() const{
            return stock;
        };


        void showProduct () const{
            std::cout << "ID: " << idProduct
                  << ", Nombre: " << name
                  << ", Precio: " << price
                  << ", Stock: " << stock << std::endl;
        }

        bool operator==(const Product& other) const{
            return idProduct == other.idProduct;
        };

        int getId() const{
            return idProduct;
        }

};
#endif