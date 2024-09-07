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


    Seat seat1(SeatE::Premium)
    , seat2(SeatE::Regular)
    , seat3(SeatE::Standard);

    Hall hall1(HallE::HALL_1)
    , hall2(HallE::HALL_2)
    , hall3(HallE::HALL_3);


    // Placeholder code, there should be better instantiation code (i.e: Builder) for these functions
    hall1.seats.emplace_back();
    hall1.seats.emplace_back();
    hall1.seats.emplace_back();

    for(int i=0; i<10; i++){
        hall1.seats[0].emplace_back(seat1);
        hall1.seats[1].emplace_back(seat2);
        hall1.seats[2].emplace_back(seat3);
    }

    hall2.seats.emplace_back();
    hall2.seats.emplace_back();
    hall2.seats.emplace_back();

    for(int i=0; i<20; i++){
        hall2.seats[0].emplace_back(seat1);
        hall2.seats[1].emplace_back(seat2);
        hall2.seats[2].emplace_back(seat3);
    }

    hall3.seats.emplace_back();
    hall3.seats.emplace_back();
    hall3.seats.emplace_back();

    for(int i=0; i<30; i++){
        hall3.seats[0].emplace_back(seat1);
        hall3.seats[1].emplace_back(seat2);
        hall3.seats[2].emplace_back(seat3);
    }

    Slot slot1(DayE::FRIDAY, TimeE::NINE_PM, &hall1)
    , slot2(DayE::FRIDAY, TimeE::NINE_PM, &hall2)
    , slot3(DayE::SATURDAY, TimeE::TWELVE_PM, &hall3)
    , slot4(DayE::SUNDAY, TimeE::SIX_PM, &hall1)
    , slot5(DayE::SUNDAY, TimeE::THREE_PM, &hall2)
    , slot6(DayE::THURSDAY, TimeE::TWELVE_AM, &hall3)
    , slot7(DayE::WEDNESDAY, TimeE::TWELVE_AM, &hall1);

    // Create a few movies
    MovieCBuilder movieBuilder;
    auto movie1 = movieBuilder.SetTitle("The Dark Knight")
                            .SetRating(9.0)
                            .AddGenre(MovieGenreE::ACTION)
                            .AddGenre(MovieGenreE::THRILLER)
                            .AddSlot(&slot1)
                            .AddSlot(&slot2)
                            .AddSlot(&slot3)
                            .Build();

    auto movie2 = movieBuilder.SetTitle("The Shawshank Redemption")
                            .SetRating(9.2)
                            .AddGenre(MovieGenreE::DRAMA)
                            .AddSlot(&slot4)
                            .AddSlot(&slot5)
                            .Build();

    auto movie3 = movieBuilder.SetTitle("The Godfather")    
                            .SetRating(9.2)
                            .AddGenre(MovieGenreE::DRAMA)
                            .AddSlot(&slot6)
                            .AddSlot(&slot7)
                            .Build();

    cinema.AddMovie(movie1);
    cinema.AddMovie(movie2);
    cinema.AddMovie(movie3);

    bool exit = false;
    while(!exit){
        const MovieC& movie = cinema.ShowMovies();
        cout << "Selected movie is: " << movie.GetTitle() << endl;

        auto slot = cinema.ShowMovieSlots(movie);
        vector<Seat> selectedSeat = cinema.ShowSlotSeats(slot);
        cout<<"Selected seats types:-"<<endl;
        for(auto & seat : selectedSeat){
            cout<<seat.typeToString(seat.type)<<endl;
        }

        string option;
        while(true){
            cout<<"Do you want to reserve other tickets (yes/no)?"<<endl;
            cin>>option;
            if(option == "no"){
                exit = true;
                break;
            }
            else if(option != "yes"){
                cout<<"invalid option"<<endl;
            }
        }
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