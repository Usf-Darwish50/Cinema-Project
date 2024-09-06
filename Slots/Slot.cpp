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