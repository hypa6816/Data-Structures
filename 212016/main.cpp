#include <iostream>
#include "Elevator.h""

using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    Elevator el1(10,0,0);
    cout<<el1.getTopFloor()<<endl;
    cout<<"Current: "<<el1.getCurrentFloor()<<endl;
    if(el1.goDownOneFloor()){
        cout<<"elevator down one floor"<<endl;
    }
    else{
        cout<<"elevator is at the bottom"<<endl;
    }
    if(el1.goUpOneFloor()){
        cout<<"elevator on floor:"<<el1.getCurrentFloor()<<endl;

    }
    else{
        cout<<"elevator at the top"<<endl;
    }
    while(el1.goUpOneFloor()){
        cout<<"now on:" <<el1.getCurrentFloor()<<endl;
    }
    Elevator el2(20, 0, 10);
    cout<<"el2 value:"<<el2.getCurrentFloor()<<endl;
    cout<<"el1 value:"<<el1.getCurrentFloor()<<endl;


    return 0;

}
