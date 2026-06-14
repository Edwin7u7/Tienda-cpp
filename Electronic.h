#include "Product.h"
#include <string>
#ifndef ELECTRONIC_H
#define ELECTRONIC_H
class Electronic : public Product{
    private:
    int monthlyGuarantee;

public:
    Electronic(
        int id,
        std::string name,
        float price,
        int stock,
        int mg): Product(
            id,
            name,
            price,
            stock), monthlyGuarantee(mg){}


    std::string getType() const override{
        return "Electronic device";
    }
};
#endif