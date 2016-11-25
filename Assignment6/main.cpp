#include "MovieTree.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    MovieTree movietree;
    //read in file
    ifstream inFile;
    string data;
    inFile.open("Assignment6Movies.txt");
    if (inFile.good()){
        while (getline(inFile,data)){

            stringstream ss(data);

            string tmpRanking1;
            getline(ss,tmpRanking1,',');
            int tmpRanking = atoi(tmpRanking1.c_str());

            string tmpTitle;
            getline(ss,tmpTitle, ',');

            string tmpYear1;
            getline(ss,tmpYear1, ',');
            int tmpYear = atoi(tmpYear1.c_str());

            string tmpQuantity1;
            getline(ss,tmpQuantity1,',');
            int tmpQuantity = atoi(tmpQuantity1.c_str());

            movietree.addMovieNode(tmpRanking, tmpTitle, tmpYear, tmpQuantity);
        }
    }
    int option = 0;
    do{
        cout	<<	"======Main	Menu======"	<<	endl;
        cout	<<	"1.	Find a Movie"	<<	endl;
        cout	<<	"2.	Rent a Movie"	<<	endl;
        cout	<<	"3.	Print the inventory"	<<	endl;
        cout	<<	"4.	Quit"	<<	endl;

        cin     >>    option;
        cin.ignore();
        cout    << endl;

        switch(option){

            case 1 :
                {
                    //find a movie
                    string name;
                    getline(cin,name);
                    cout<<name<<endl;
                    movietree.findMovie(name);
                    break;

                }
                /////////////////////////////////////

            case 2 :
                {
                    //rent a movie
                    string rent;
                    getline(cin,rent);
                    movietree.rentMovie(rent);
                    break;

                }
                /////////////////////////////////////
            case 3 :
                {
                    //print the inventory
                    MovieNode *tree;
                    movietree.printMovieInventory();

                    break;
                }
                /////////////////////////////////////
            case 4 :
                {
                    cout<<"Goodbye!"<<endl;
                    break;
                }

        }
    }while(option!=4);
}


