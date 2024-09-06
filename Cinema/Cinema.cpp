#include "Cinema.hpp"

unique_ptr<CinemaC> CinemaC::m_cinemaInst = nullptr;

unique_ptr<CinemaC>& CinemaC::GetCinemaInst() 
{
    if(!m_cinemaInst) {
        m_cinemaInst = make_unique<CinemaC>();
    }
    return m_cinemaInst;
}

