#include <string>
#ifndef SHOPINGCART_H
#define SHOPINGCART_H
#include "Product.h"
#include <vector>
class ShopingCart {
private:
    std::vector<Product*> productos;

public:
    void addProduct(
        Product* product){};

    float calculateTotal() const;
};
#endif