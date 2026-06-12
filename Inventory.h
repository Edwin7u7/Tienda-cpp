#include <string>
#include <vector>
#include <memory>
#ifndef INVENTORY_H
#define INVENTORY_H
#include "Product.h"
class Inventory{
    private:
        std::vector<std::unique_ptr<Product>> products;
    public:
         void agregarProducto(
        std::unique_ptr<Product> producto){};

        Product* searchProduct(
            int id);

        void showProducts() const;
};
#endif 