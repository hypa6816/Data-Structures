#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "CommunicationNetwork.h"


using namespace std;


int main(){



CommunicationNetwork comm;

int option = 0;
do{
        cout	<<	"======Main	Menu======"	<<	endl;
        cout	<<	"1.	Build	Network"	<<	endl;
        cout	<<	"2.	Print	Network	Path"	<<	endl;
        cout	<<	"3.	Transmit	Message	Coast-To-Coast"	<<	endl;
        cout	<<	"4.	Add	City"	<<	endl;
        cout    <<  "5. Delete City" << endl;
        cout    <<  "6. Clear Network" << endl;
        cout	<<  "7. Quit"	<<	endl;
        cout    <<  "Choose an option: " << endl;
        cin     >>    option;
        cout    << endl;

switch(option){

    case 1 :
        {
            comm.buildNetwork();
            break;
        }
        /////////////////////////////////////

    case 2 :
        {
            comm.printNetwork();
            break;
        }
        /////////////////////////////////////
    case 3 :
        {
            comm.transmitMsg("messageIn.txt");
            break;
        }
    /////////////////////////////////////////////////////
    case 4 :
        {
            string cityNew;
            string cityPrevious;
            cout	<<	"Enter	a	city	name:	"	<<	endl;
            cin.ignore();
            getline(cin, cityNew);
            cout	<<	"Enter	a	previous	city	name:	"	<<	endl;
            getline(cin, cityPrevious);

            comm.addCity(cityNew,cityPrevious);
            break;

        }
    /////////////////////////////////////////////////////
    case 5:
        {
            string cityNameDelete;
            cout << "Enter a city name: "<<endl;
            cin.ignore();
            getline(cin, cityNameDelete);
            comm.deleteCity(cityNameDelete);
            break;
        }
    case 6:
        {
            comm.clearNetwork();
        }



}
}while(option != 7);

}
