#include <iostream>
#include <string>
#include <vector>

#include "Customer/CustomerCProxy.hpp"
#include "Cinema/Cinema.hpp"
#include "Movie/Movie.hpp"
#include "Payment/Payment.hpp"
#include "Payment/payment_credentials.h"

#define TESTING_CUSTOMERPROXY
#define TESTING_PAYMENT

using namespace std;

/*
class MovieC {
    public:
        string name;
        string genre;
};

class CustomerC{
	public:
		string m_mail;
		int m_phoneNum;
};

class CinemaC {
    public:
        vector<MovieC> movies;
};
*/

int main() 
{
    
#ifdef TESTING_CUSTOMERPROXY
    
        CinemaC cinema;

    CustomerProxy customer1("user1@example.com", "01234567890", cinema);
    CustomerProxy customer2("user2@example.com", "01234567891", cinema);
    CustomerProxy customer3("user3@example.com", "01234567892", cinema);
    CustomerProxy customer4("user3example.com", "01234567892", cinema);
    CustomerProxy customer5("user3@example.com", "012345678XY", cinema);


    

    // Print all users
    for (const auto& user : cinema.GetUsers()) {
        cout << "Email: " << user.GetEmail() << endl;
        cout << "Phone Number: " << user.GetPhoneNum() << endl;
        cout << "-----------------------" << endl;
        //TODO: ERROR after printing user it produces segemntaion fault but output is correct
    }
#endif

#ifdef TESTING_PAYMENT

    SecurityCodeCredentials credit_credentials("1234");  
    SecurityCodeCredentials debit_credentials("5678");
    EmailCredentials paypal_credentials(customer1.GetEmail());  

    CreditPayment credit_payment;
    DebitPayment debit_payment;
    PayPalPayment paypal_payment;

    
    std::cout << "Testing CreditPayment:" << std::endl;
    credit_payment.Pay(credit_credentials);

    std::cout << "\nTesting DebitPayment:" << std::endl;
    debit_payment.Pay(debit_credentials);

    std::cout << "\nTesting PayPalPayment:" << std::endl;
    paypal_payment.Pay(paypal_credentials);

#endif
    return 0;
}