#include "Payment.hpp"
#include <iostream>

// Assuming PaymentCredentials have appropriate methods

void CreditPayment::Pay(const PaymentCredentials& credentials) {
    const SecurityCodeCredentials* sc_credentials = 
                        dynamic_cast<const SecurityCodeCredentials*>(&credentials);
    if (sc_credentials) 
    {
        const auto& security_code = sc_credentials->GetSecurityCode();
        std::cout << "Processing credit payment type ----";
        std::cout << "Verifying security code: {" << security_code << "}" << std::endl;
    } 
    else 
    {
        std::cout << "Error: Invalid credentials for Credit Payment" << std::endl;
    }
}

void DebitPayment::Pay(const PaymentCredentials& credentials) {
    const SecurityCodeCredentials* sc_credentials = 
                        dynamic_cast<const SecurityCodeCredentials*>(&credentials);
    if (sc_credentials) 
    {
        const auto& security_code = sc_credentials->GetSecurityCode();
        std::cout << "Processing Debit payment type ----";
        std::cout << "Verifying security code: {" << security_code << "}" << std::endl;
    } 
    else 
    {
        std::cout << "Error: Invalid credentials for Debit Payment" << std::endl;
    }
}

void PayPalPayment::Pay(const PaymentCredentials& credentials) {
    const EmailCredentials* email_credentials = 
                        dynamic_cast<const EmailCredentials*>(&credentials);
    if (email_credentials) 
    {
        const auto& email = email_credentials->GetEmail();
        std::cout << "Processing PayPal payment type ----";
        std::cout << "Verifying PayPal account with email: {" << email << "}" << std::endl;
    } 
    else 
    {
        std::cout << "Error: Invalid credentials for PayPal Payment" << std::endl;
    }
}
