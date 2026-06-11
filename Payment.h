#ifndef PAYMENT_H
#define PAYMENT_H
class Payment {
protected:
    float amount;

public:
    Payment(float amount): amount(amount){}

    virtual void procesarPago() = 0;

    virtual ~Payment() = default;
};
#endif