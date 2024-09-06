#include "CustomerCProxy.hpp"
#include <iostream>
#include <regex>

CustomerProxy::CustomerProxy(const string& email, const string& phoneNum, CinemaC& cinema)
    : m_customer(email, phoneNum), m_cinema(cinema) {  // Initialize m_customer with email and phoneNum
    if (SetEmail(email) && SetPhoneNum(phoneNum)) {
        m_cinema.AddUser(m_customer);
        cout << "User added: " << m_customer.GetEmail() << endl;
    }
}

bool CustomerProxy::SetEmail(const string& email) {
    if (IsValidEmail(email)) {
        m_customer.SetMail(email);
        return true;
    } else {
        cout << "Invalid email format." << endl;
        return false;
    }
}

bool CustomerProxy::SetPhoneNum(const string& phoneNum) {
    if (IsValidPhoneNum(phoneNum)) {
        m_customer.SetPhoneNum(phoneNum);
        return true;
    } else {
        cout << "Invalid phone number format." << endl;
        return false;
    }
}

bool CustomerProxy::IsValidEmail(const string& email) const {
    const regex pattern(R"((\w+)(\.{1}[\w+]){0,1}@(\w+)(\.\w+)+)");
    return regex_match(email, pattern);
}

bool CustomerProxy::IsValidPhoneNum(const string& phoneNum) const {
    if (phoneNum.length() != 11 || phoneNum.substr(0, 2) != "01") {
        return false;
    }
    for (char c : phoneNum) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

string CustomerProxy::GetEmail() const {
    return m_customer.GetEmail();
}

string CustomerProxy::GetPhoneNum() const {
    return m_customer.GetPhoneNum();
}
