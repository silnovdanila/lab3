#pragma once
class Table 
{
private:
    int tableNumber;
    int seats;
    int isReserved;
public:
    Table(int number, int seatsCount){
        this->tableNumber = number;
        this->seats = seatsCount;
        this->isReserved = 0;
    }
    Table() = default;
    int getTableNumber() const { 
        return tableNumber;
    }
    int getSeats() const {
        return seats;
    }
    int isReserved() const {
        return isReserved;
    }
    void reserve() {
        isReserved = 1;
    }
    void release() {
        isReserved = 0;
    }
};
