#ifndef USER_HPP
#define USER_HPP

#include <string>

class CustomerC {
public:
    CustomerC(const std::string& mail, const std::string& phoneNum)
        : m_mail(mail), m_phoneNum(phoneNum) {}

    const std::string& GetEmail() const { return m_mail; }
    const std::string& GetPhoneNum() const { return m_phoneNum; }

    void SetMail(const std::string& mail) { m_mail = mail; }
    void SetPhoneNum(const std::string& phoneNum) { m_phoneNum = phoneNum; }

private:
    std::string m_mail;
    std::string m_phoneNum;
};

#endif // USER_HPP
