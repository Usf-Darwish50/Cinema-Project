#ifndef PAYMENT_HPP
#define PAYMENT_HPP

#include <string>
#include "payment_credentials.h"

class Payment {
public:
    virtual ~Payment() = default;
    virtual void Pay(const PaymentCredentials& credentials) = 0;
};

class CreditPayment : public Payment {
public:
    void Pay(const PaymentCredentials& credentials) override;
};

class DebitPayment : public Payment {
public:
    void Pay(const PaymentCredentials& credentials) override;
};

class PayPalPayment : public Payment {
public:
    void Pay(const PaymentCredentials& credentials) override;
};

#endif // PAYMENT_HPP
