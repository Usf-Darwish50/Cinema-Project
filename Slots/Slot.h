//
// Created by Khaled on 9/6/2024.
//

#ifndef SOFTWARE_DESIGN_WORKSHOP_SLOT_H
#define SOFTWARE_DESIGN_WORKSHOP_SLOT_H

using namespace std;
#include "../Cinema/Common.hpp"
#include "../Hall/Hall.h"
#include "../Seat/Seat.h"
#include<vector>
#include <iomanip>
#include <map>
#include <iostream>

class Slot {
public:
    vector<Seat> ShowSeats();
    Slot(DayE day_, TimeE time_, Hall *hall);
    Hall *hall;
    bool isReserved;
    DayE day;
    TimeE time;
};


#endif //SOFTWARE_DESIGN_WORKSHOP_SLOT_H
