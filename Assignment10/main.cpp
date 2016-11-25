#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

int main()
{
    Graph g;

    //Making Graph
    ifstream inFile;
    string data;
    int i = 1;
    int j =-1;
    int k =1;
    int l = 0;

    struct listofcities{
        string cityName;
    };
    listofcities cities[16];

    inFile.open("zombieCities.txt");
    if (inFile.good()){
        cout<<"The file has opened successfully"<<endl;
        while(getline(inFile,data)){
            k=1;
            stringstream ss(data);
            if(i==1){
                string city;

                while(getline(ss,city,',')){

                    if(j !=-1){

                        g.addVertex(city);
                        cities[j].cityName = city;
                    }
                    j++;

                }

            }
            else if (i!= 1){
                string input;
                string edgeCity;
                while(getline(ss,input,',')){

                    if(k ==1){
                         edgeCity = input;
                         l = 0;
                    }
                    else if (k != 1 && l<15){
                        int edgeWeight = atoi(input.c_str());
                        if(edgeWeight>0){
                            g.addEdge(cities[l].cityName,edgeCity,edgeWeight);
                            cout<<cities[l].cityName<<" "<<edgeCity<< edgeWeight<<endl;
                        }
                            l++;

                    }
                    k++;
                }

            }
            i++;

            }
        }
    //Making Menu
    int option = 0;
    do{
        cout << "======Main Menu======" << endl;
        cout << "1. Print vertices" << endl;
        cout << "2. Find districts" << endl;
        cout << "3. Find shortest path" << endl;
        cout << "4. Quit" << endl;
        cin >> option;
        cin.ignore();
    switch(option){

case 1:
    {
        //Print vertices
        g.displayEdges();
        break;
    }

case 2:
    {
        //Find districts
        g.assignDistricts();
        break;
    }

case 3:
    {
        //Find shortest path
        cout<<"Enter a starting city:"<<endl;
        string startingCity;
        getline(cin, startingCity);
        cout<<"Enter an ending city:"<<endl;
        string endingCity;
        getline(cin, endingCity);
        g.shortestPath(startingCity, endingCity);
        break;
    }

case 4:
    {
        //Quit
        cout << "Goodbye!" << endl;
        break;
    }
     }
    }
    while(option!=4);
}





