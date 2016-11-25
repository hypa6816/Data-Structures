#ifndef ELEVATOR_H
#define ELEVATOR_H


class Elevator
{
    public:
        Elevator(int, int, int);
        ~Elevator();
        int getTopFloor();
        bool goDownOneFloor ();
        int getCurrentFloor();
        bool goUpOneFloor();


    protected:
    private:
        int currentFloor;
        int topFloor;
        int bottomFloor;

};

#endif // ELEVATOR_H
