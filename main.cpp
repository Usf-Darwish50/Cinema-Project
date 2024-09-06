#include <iostream>
#include <string>
#include <vector>

#include "Customer/CustomerCProxy.hpp"
#include "Cinema/Cinema.hpp"
#include "Movie/Movie.hpp"
#include "Payment/Payment.hpp"
#include "Payment/payment_credentials.h"
#include "Slots/Slot.h"

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

    // Create a few movies
    MovieCBuilder movieBuilder;
    auto movie1 = movieBuilder.SetTitle("The Dark Knight")
                            .SetRating(9.0)
                            .AddGenre(MovieGenreE::ACTION)
                            .AddGenre(MovieGenreE::THRILLER)
                            .AddShowTime(ShowTimeS{DayE::SATURDAY, TimeE::NINE_AM})
                            .Build();

    auto movie2 = movieBuilder.SetTitle("The Shawshank Redemption")
                            .SetRating(9.3)
                            .AddGenre(MovieGenreE::DRAMA)
                            .AddShowTime(ShowTimeS{DayE::SUNDAY, TimeE::TWELVE_PM})
                            .Build();

    auto movie3 = movieBuilder.SetTitle("The Godfather")    
                            .SetRating(9.2)
                            .AddGenre(MovieGenreE::DRAMA)
                            .AddShowTime(ShowTimeS{DayE::MONDAY, TimeE::THREE_PM})
                            .Build();

    Seat seat1(SeatE::Premium)
    , seat2(SeatE::Regular)
    , seat3(SeatE::Standard);

    Hall hall1(HallE::HALL_1)
    , hall2(HallE::HALL_2)
    , hall3(HallE::HALL_3);

    for(int i=0; i<10; i++){
        hall1.seats.emplace_back(seat1);
        hall1.seats.emplace_back(seat2);
        hall1.seats.emplace_back(seat3);
    }

    for(int i=0; i<20; i++){
        hall2.seats.emplace_back(seat1);
        hall2.seats.emplace_back(seat2);
        hall2.seats.emplace_back(seat3);
    }

    for(int i=0; i<30; i++){
        hall3.seats.emplace_back(seat1);
        hall3.seats.emplace_back(seat2);
        hall3.seats.emplace_back(seat3);
    }

    Slot slot1(DayE::FRIDAY, TimeE::NINE_PM)
    , slot2(DayE::FRIDAY, TimeE::NINE_PM)
    , slot3(DayE::SATURDAY, TimeE::TWELVE_PM)
    , slot4(DayE::SUNDAY, TimeE::SIX_PM)
    , slot5(DayE::SUNDAY, TimeE::THREE_PM)
    , slot7(DayE::WEDNESDAY, TimeE::TWELEVE_AM)
    , slot6(DayE::THURSDAY, TimeE::TWELEVE_AM);

    slot1.halls.emplace_back(hall1);
    slot1.halls.emplace_back(hall2);
    slot2.halls.emplace_back(hall1);
    slot3.halls.emplace_back(hall1);
    slot3.halls.emplace_back(hall2);
    slot4.halls.emplace_back(hall3);
    slot5.halls.emplace_back(hall3);
    slot6.halls.emplace_back(hall2);
    slot6.halls.emplace_back(hall3);
    slot7.halls.emplace_back(hall2);
    slot7.halls.emplace_back(hall3);

    movie1.AddSlot(slot1);
    movie1.AddSlot(slot2);
    movie1.AddSlot(slot3);
    movie2.AddSlot(slot4);
    movie2.AddSlot(slot5);
    movie3.AddSlot(slot6);
    movie3.AddSlot(slot7);

    cinema.AddMovie(movie1);
    cinema.AddMovie(movie2);
    cinema.AddMovie(movie3);

    // Print all movies
    auto movie = cinema.ShowMovies();

    cout << "Selected movie is: " << movie.GetTitle() << endl;

    // after picking a movie, go through the slots in order to find the 
    // slots that contain the movie.
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