//
// Created by Khaled on 9/6/2024.
//

#include "Seat.h"

Seat::Seat(SeatE type_) {
    type = type_;
    isReserved = false;
}

string Seat::typeToString(SeatE seat) {
    switch (seat) {
        case SeatE::Premium: return "Premium";
        case SeatE::Standard: return "Standard";
        case SeatE::Regular: return "Regular";
        default: return "Unknown type";
    }
}
