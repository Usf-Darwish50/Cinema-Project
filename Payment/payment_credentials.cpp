#include "payment_credentials.h"

SecurityCodeCredentials::SecurityCodeCredentials(const std::string& security_code)
    : security_code_{security_code} {}


std::string SecurityCodeCredentials::GetSecurityCode() const 
{
    return security_code_;
}

EmailCredentials::EmailCredentials(const std::string& email)
    : email_{email} {}

std::string EmailCredentials::GetEmail() const 
{
    return email_;
}
