//
// Created by Khaled on 9/6/2024.
//

#include "Slot.h"
Slot::Slot(DayE day_, TimeE time_, Hall hall){
    day = day_;
    time = time_;
    isReserved = false;
    this->hall = hall;
}

Seat Slot::ShowSeats()
{
    auto seats = hall.GetSeats();
    int i = 0, j = 0, n = seats[0].size();
    for (auto&& row : seats)
    {
        for (auto && seat : row)
        {
            if (seat.isReserved)
                std::cout << "X" << " ";
            else
            {
                std::cout << i * n + j + 1 << " ";
            }
            ++j;
        }
        cout << "\n";
        ++i;
    }

    cout << "Please select a seat";
}
