#include "Elevator.h"

Elevator::Elevator(int tf, int bf, int cf)
{
    //ctor
    int topFLoor = tf;
    int bottomFLoor = bf;
    int currentFloor = cf;

}

Elevator::~Elevator()
{
    //dtor
}

int Elevator::getTopFloor(){
    return topFloor;
}
bool Elevator::goDownOneFloor(){
//decrement currentFloor until currentFloor = bottomFloor
    bool success = false;
    if(currentFloor > bottomFloor){
        currentFloor--;
        success = true;
    }
    return success;
}
int Elevator::getCurrentFloor(){
    return currentFloor;

}
bool Elevator::goUpOneFloor(){
    bool success = false;
    if(currentFloor < topFloor){
        currentFloor++;
        success = true;
    }
    return success;
}
