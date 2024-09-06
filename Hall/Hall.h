//
// Created by Khaled on 9/6/2024.
//

#ifndef SOFTWARE_DESIGN_WORKSHOP_HALL_H
#define SOFTWARE_DESIGN_WORKSHOP_HALL_H

#include "../Seat/Seat.h"
#include <vector>

class Hall {
public:
    Hall(HallE type_);
    HallE type;
    std::vector<Seat> seats;
};


#endif //SOFTWARE_DESIGN_WORKSHOP_HALL_H
