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
#include<map>

class Slot {
public:
    Slot(DayE day_, TimeE time_);
    vector<Hall> halls;
    bool isReserved;
    DayE day;
    TimeE time;
};


#endif //SOFTWARE_DESIGN_WORKSHOP_SLOT_H
