#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <string>
#include <vector>
#include <unordered_map>

#include"../Cinema/Common.hpp"
#include "../Slots/Slot.h"

using namespace std;

enum class MovieGenreE {
    ACTION,
    COMEDY,
    DRAMA,
    THRILLER,
    HORROR,
    SCIENCE_FICTION,
    ROMANCE
};

class MovieC {
public:
    MovieC(const string &title, const vector<MovieGenreE> &genre, float rating,  vector<Slot*> slots) :
            m_title(title), m_genre(genre), m_rating(rating), m_slots(slots) {}

    void SetTitle(const string &title) { m_title = title; }

    const string &GetTitle() const { return m_title; }

    void SetGenre(const vector<MovieGenreE> &genre) { m_genre = genre; }

    const vector<Slot*>& GetSlots() const { return m_slots; }

    void AddGenre(MovieGenreE genre) { m_genre.emplace_back(genre); }

    const vector<MovieGenreE> &GetGenreVec() const { return m_genre; }

    void SetRating(float rating) { m_rating = rating; }

    const float &GetRating() const { return m_rating; }

    string GetGenreStr();

private:
    vector<Slot*> m_slots;
    string m_title;
    vector<MovieGenreE> m_genre;
    float m_rating;
    const unordered_map<MovieGenreE, string> m_genreStr = {
            {MovieGenreE::ACTION,          "Action"},
            {MovieGenreE::COMEDY,          "Comedy"},
            {MovieGenreE::DRAMA,           "Drama"},
            {MovieGenreE::THRILLER,        "Thriller"},
            {MovieGenreE::HORROR,          "Horror"},
            {MovieGenreE::SCIENCE_FICTION, "Science fiction"},
            {MovieGenreE::ROMANCE,         "Romance"}
    };
};

class MovieCBuilder {
public:
    MovieCBuilder &SetTitle(const string &title);

    MovieCBuilder &SetRating(const float &rating);

    MovieCBuilder &AddGenre(MovieGenreE genre);

    MovieCBuilder &AddSlot(Slot *slot);
    
    MovieC Build();

private:
    string m_title;
    vector<MovieGenreE> m_genre;
    float m_rating = -1.0f;
    vector<Slot*> m_slots;
};

#endif