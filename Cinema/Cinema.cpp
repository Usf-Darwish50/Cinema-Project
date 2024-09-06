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
        return *movieMap[movieTitle];
    else
        return MovieC("NotFound", {}, 0.0, ShowTimeS{DayE::MONDAY, TimeE::NINE_AM});
}
