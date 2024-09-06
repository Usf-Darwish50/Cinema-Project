//
// Created by Khaled on 9/6/2024.
//

#ifndef SOFTWARE_DESIGN_WORKSHOP_SEAT_H
#define SOFTWARE_DESIGN_WORKSHOP_SEAT_H

#include "../Cinema/Common.hpp"
#include <string>

class Seat {
public:
    Seat(SeatE type_);
    SeatE type;
    bool isReserved;
};


#endif //SOFTWARE_DESIGN_WORKSHOP_SEAT_H
