#include "Cinema.hpp"

unique_ptr<CinemaC> CinemaC::m_cinemaInst = nullptr;

unique_ptr<CinemaC>& CinemaC::GetCinemaInst() 
{
    if(!m_cinemaInst) {
        m_cinemaInst = make_unique<CinemaC>();
    }
    return m_cinemaInst;
}

MovieC CinemaC::ShowMovies()
{
    auto movies = GetMovies();

    unordered_map<string, MovieC*> movieMap {};

    for (auto movie : movies)
    {
        movieMap[movie.GetTitle()] = &movie;
        std::string MovieStr = "Title: " + movie.GetTitle() + "\n" + "Movie: " + movie.GetGenreStr() + "\n";

        if (movie.GetRating() != 0.0) 
            MovieStr += "Rating: " + std::to_string(movie.GetRating()) + "\n";

        MovieStr += "-----------------------------\n";

        cout << MovieStr;
    }

    std::cout << "\nSelect a movie by entering the movie title: ";
    std::string movieTitle;
    std::getline(std::cin, movieTitle);

    if (movieMap.find(movieTitle) != movieMap.end())
        return *(movieMap[movieTitle]);
    else
        throw ("Invalid Movie");
}

std::string dayToString(DayE day) {
    switch (day) {
        case DayE::SATURDAY: return "Saturday";
        case DayE::SUNDAY: return "Sunday";
        case DayE::MONDAY: return "Monday";
        case DayE::TUESDAY: return "Tuesday";
        case DayE::WEDNESDAY: return "Wednesday";
        case DayE::THURSDAY: return "Thursday";
        case DayE::FRIDAY: return "Friday";
        default: return "Unknown Day";
    }
}

std::string timeToString(TimeE time) {
    switch (time) {
        case TimeE::NINE_AM: return "9 AM";
        case TimeE::TWELVE_PM: return "12 PM";
        case TimeE::THREE_PM: return "3 PM";
        case TimeE::SIX_PM: return "6 PM";
        case TimeE::NINE_PM: return "9 PM";
        case TimeE::TWELVE_AM: return "12 AM";
        default: return "Unknown Time";
    }
}

std::string hallToString(HallE hall) {
    switch (hall) {
        case HallE::HALL_1: return "Hall 1";
        case HallE::HALL_2: return "Hall 2";
        case HallE::HALL_3: return "Hall 3";
        default: return "??";
    }
}

Slot CinemaC::ShowMovieSlots(const MovieC& movie)
{
    auto slots = movie.GetSlots();

    int slotIdx = 1;
    for (auto& slot : slots)
    {
        // TODO: StringViewer function (adapter class)
        std::string slotStr = to_string(slotIdx++) + ") " + "Day: " + dayToString(slot->day) + "\n" + "Time: " + timeToString(slot->time) + "\n" + "Hall: " + hallToString(slot->hall->type) + "\n";

        slotStr += "-----------------------------\n";

        cout << slotStr << endl;
    }

    cout << "\nSelect a slot by entering it's number\n";
    int selection;
    cin >> selection;
    return selection - 1 < slots.size() ? *slots[selection - 1] : throw ("invalid slot selection");
}

vector<Seat> CinemaC::ShowSlotSeats(Slot slot)
{
    auto seat = slot.ShowSeats();
}