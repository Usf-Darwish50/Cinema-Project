//
// Created by Khaled on 9/6/2024.
//

#include "Hall.h"

Hall::Hall(HallE type_){
    type = type_;
}

vector<vector<Seat>>& Hall::GetSeats()
{
    return seats;
}