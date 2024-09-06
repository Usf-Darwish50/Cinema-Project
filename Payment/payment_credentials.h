#ifndef PAYMENT_CREDENTIALS_H
#define PAYMENT_CREDENTIALS_H

#include <string>

class PaymentCredentials {
public:
    virtual ~PaymentCredentials() = default;
};

class SecurityCodeCredentials : public PaymentCredentials {
public:
    explicit SecurityCodeCredentials(const std::string& security_code);
    std::string GetSecurityCode() const;
private:
    std::string security_code_;
};

class EmailCredentials : public PaymentCredentials {
public:
    explicit EmailCredentials(const std::string& email);
    std::string GetEmail() const;
private:
    std::string email_;
};

#endif // PAYMENT_CREDENTIALS_H
