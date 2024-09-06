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

MovieCBuilder& MovieCBuilder::SetTitle(const string& title)
{
    m_title = title;
    return *this;
}

MovieCBuilder& MovieCBuilder::SetRating(const float& rating)
{
    m_rating = rating;
    return *this;
}

MovieCBuilder& MovieCBuilder::AddGenre(MovieGenreE genre)
{
    m_genre.emplace_back(genre);
    return *this;
}

MovieCBuilder& MovieCBuilder::AddSlot(Slot* slot)
{
    if (!slot->isReserved)
        m_slots.push_back(slot);
    return *this;
}

MovieC MovieCBuilder::Build() 
{
    MovieC movie = MovieC(m_title, m_genre, m_rating, m_slots);
    this->m_genre.clear();
    this->m_slots.clear();
    return movie;
}