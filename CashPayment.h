#include "Payment.h"
#include <iostream>
#ifndef CASHPAYMENT_H
#define CASHPAYMENT_H
class CashPayment : public Payment {
private:
    float recievedCash;

public:
    CashPayment(float amount,
                 float recievedCash): Payment(amount), recievedCash(recievedCash){};

    void processPayment() override{
        std::cout<< "Procesando pago en efectivo por $"<< amount<< std::endl;
    };
};

#endif