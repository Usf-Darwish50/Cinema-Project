#ifndef CUSTOMERCPROXY_HPP
#define CUSTOMERCPROXY_HPP

#include <string>
#include "../Cinema/Cinema.hpp"
#include "User.hpp"

class CustomerProxy {
public:
    CustomerProxy(const std::string& email, const std::string& phoneNum, CinemaC& cinema);

    bool SetEmail(const std::string& email);
    bool SetPhoneNum(const std::string& phoneNum);

    std::string GetEmail() const;
    std::string GetPhoneNum() const;

private:
    bool IsValidEmail(const std::string& email) const;
    bool IsValidPhoneNum(const std::string& phoneNum) const;

    CustomerC m_customer;
    CinemaC& m_cinema;
};

#endif // CUSTOMERCPROXY_HPP
