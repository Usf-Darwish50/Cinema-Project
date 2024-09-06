#ifndef CINEMA_HPP
#define CINEMA_HPP

#include <string>
#include <vector>
#include <memory>
#include <optional>

#include "../Movie/Movie.hpp"
#include "../Customer/User.hpp"
#include "Common.hpp" 

class CinemaC {
    public:
        static unique_ptr<CinemaC>& GetCinemaInst();
        void AddMovie(const MovieC& movie) { m_movies.emplace_back(movie); }
        const vector<MovieC>& GetMovies() const { return m_movies; }
        void AddUser(const CustomerC& user) { m_users.emplace_back(user); }
        const vector<CustomerC>& GetUsers() const { return m_users; }

    private:
        static unique_ptr<CinemaC> m_cinemaInst;
    private:
        const vector<unsigned int> m_seatPrice = {
            {60, 90, 90, 130, 130, 90, 90, 60}
        };
        vector<MovieC> m_movies;
        vector<CustomerC> m_users;
        const map<HallE, float> c_HallPrice = {
            {HallE::HALL_1, 20},
            {HallE::HALL_2, 40},
            {HallE::HALL_3, 50}
        };

        const map<DayE, float> c_DayPrice = {
            {DayE::THURSDAY, 70},
            {DayE::FRIDAY, 70},
            {DayE::SATURDAY, 64},
            {DayE::SUNDAY, 40},
            {DayE::MONDAY, 20},
            {DayE::TUESDAY, 15},
            {DayE::WEDNESDAY, 30}
        };

        const map<TimeE, float> c_TimePrice = {
            {TimeE::NINE_AM, 5},
            {TimeE::TWELVE_PM, 8},
            {TimeE::THREE_PM, 2},
            {TimeE::SIX_PM, 15},
            {TimeE::NINE_PM, 25},
            {TimeE::TWELEVE_AM, 30}
        };
};
#endif