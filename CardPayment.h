#include "Payment.h"
#include <string>
#include <iostream>
#ifndef CARDPAYMENT_H
#define CARDPAYMENT_H
class CardPayment : public Payment {
private:
    std::string cardNumber;

public:
    CardPayment(float amount,
                std::string cardN): Payment(amount),cardNumber(cardN){} ;

    void processPayment() override{
        std::cout<< "Procesando pago con tarjeta por $"<< amount<< std::endl;
    };
};
#endif