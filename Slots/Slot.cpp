//
// Created by Khaled on 9/6/2024.
//

#include "Slot.h"
Slot::Slot(DayE day_, TimeE time_, Hall *hall){
    day = day_;
    time = time_;
    isReserved = false;
    this->hall = hall;
}

vector<Seat> Slot::ShowSeats()
{
    auto seats = hall->GetSeats();
    int i = 0, j = 0, n = seats[0].size();

    for (auto&& row : seats)
    {
        for (auto && seat : row)
        {
            if (seat.isReserved)
                std::cout << setw(3) << "X" << " ";
            else
                std::cout << setw(3) << std::to_string(i * n + j + 1) << " ";
            ++j;
        }
        std::cout << "\n";
        ++i;
        j = 0;
    }
    std::cout << "Please select seats number one by one, enter -1 to exit"<<endl;
    string option;
    vector<Seat> selectedSeats;
    while(option != "-1"){
        cin>>option;
        try{
            int opt = stoi(option);
            if(opt > 0 && opt < seats.size() * seats[0].size()){
                int row = (opt-1) / seats[0].size();
                selectedSeats.emplace_back(seats[row][opt%seats[0].size()]);
            }
            else if(opt != -1){
                cout<<"Invalid option"<<endl;
            }
        }
        catch(exception& e){
            cout<<"Invalid option"<<endl;
        }
    }
    return selectedSeats;
}
