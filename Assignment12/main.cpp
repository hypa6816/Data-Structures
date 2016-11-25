#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "HashTable.h"


using namespace std;

int main()
{
    HashTable ht;
       //Making Menu
    int option = 0;
    do{
        cout << "======Main Menu======" << endl;
        cout << "1. Insert movie" << endl;
        cout << "2. Delete movie" << endl;
        cout << "3. Find movie" << endl;
        cout << "4. Print Table Contents" << endl;
        cout << "5. Quit" << endl;
        cin >> option;
        cin.ignore();
    switch(option){

case 1:
    {
        //Insert
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

            ht.insertMovie(tmpTitle, tmpYear);
        }
    }
        break;
    }

case 2:
    {
        //Delete
        break;
    }

case 3:
    {
        //Find
        break;
    }
case 4:
    {
        //Print
        ht.printTableContents();
        break;
    }
case 5:
    {
        //Quit
        cout << "Goodbye!" << endl;
        break;
    }
     }
    }
    while(option!=5);
}

