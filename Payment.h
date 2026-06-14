#ifndef PAYMENT_H
#define PAYMENT_H
class Payment {
protected:
    float amount;

public:
    Payment(float amount): amount(amount){}

    virtual void processPayment() = 0;

    virtual ~Payment(){};
};
#endif