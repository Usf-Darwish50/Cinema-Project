#include "Movie.hpp"

string MovieC::GetGenreStr()
{
    string genreStr = "";
    for(const auto& genre : m_genre) {
        genreStr += (m_genreStr.at(genre) + ", ");
    }
    if(!(genreStr.empty())) {
        genreStr.pop_back();
        genreStr.pop_back();
    }
    return genreStr;
}