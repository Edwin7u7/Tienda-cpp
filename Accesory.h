#include "Product.h"
#include <string>
#ifndef ACCESORY_H
#define ACCSESOY_H

class Accesory : public Product 
{
    private:

        std::string material;
    public:
        Accesory(
        int id,
        std::string nombre,
        float precio,
        int stock,
        std::string material):Product(
            id,
            nombre,
            precio,
            stock
        ), material(material){}

    std::string getType() const override{
        return "Accesory";
    };
};

#endif 