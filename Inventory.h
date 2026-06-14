#include <string>
#include <vector>
#include <memory>
#ifndef INVENTORY_H
#define INVENTORY_H
#include "Product.h"
#include <iostream>
class Inventory{
    private:
        std::vector<std::unique_ptr<Product>> products;
    public:

         void addProduct(std::unique_ptr<Product> product){
            products.push_back(
                move(product)
            );
         };

        Product* searchProduct(int id){
            for(auto& product : products)
            {
                if(product->getId()== id)
                {
                    return product.get();
                }
            }

            return nullptr;
        };

        void showProducts() const{
            for(const auto& product: products)
            {
                product->showProduct();
            }
        };
};
#endif 