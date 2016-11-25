#include "CommunicationNetwork.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;



CommunicationNetwork::CommunicationNetwork()
{
    //ctor
}

CommunicationNetwork::~CommunicationNetwork()
{
    //dtor
}

void CommunicationNetwork::buildNetwork(){
string input[10] = {"Los Angeles", "Phoenix", "Denver","Dallas", "St. Louis", "Chicago","Atlanta","Washington, D.C","New York", "Boston"};

    //Had a scoping error here. I made a new head. This will not input anything in my original struct.
    head->name = input[0];
    head->next = NULL;
    City *current = head;
    int i = 1;
    while(i < 10){
        City *tmp = new City;
        tmp->name = input[i]; //(*tmp).value
        tmp->next = NULL;

        current->next = tmp;
        current = current->next;
        i++;
    }
    tail = current;
    current = head;
    cout<< "===CURRENT PATH==="<<endl;
    while(current != NULL){
        cout<<current->name<<" -> ";
        current = current->next;
    }
    cout<<"NULL"<<endl;
    cout<<"=================="<<endl;



}

void CommunicationNetwork::printNetwork(){
    cout<< "===CURRENT PATH==="<<endl;
    City *current = head;
    //current = head;
    while(current != NULL){
        cout<<current->name<<" -> ";
        current = current->next;
    }
    cout<<"NULL"<<endl;
    cout<<"=================="<<endl;

}

void CommunicationNetwork::addCity(string cityNew, string cityPrevious){

    // if cityPrevious is the first city
    City *current = head;
    City *add = new City;
    add->name = cityNew;
    if(cityPrevious==head->name){
            add->next = head;
            head = add;
    }
    else{ // if cityPrevious is not the first city
        //Search for where cityPrevious is located
            City *tmp = head;
            City *returnNode = NULL;
            bool found = false;
            while(found!= true && tmp!=NULL){
                    if (tmp->name == cityPrevious){
                        found=true;
                        returnNode=tmp;
                    }
                    else{
                        tmp=tmp->next;
                    }
            }
            add->next = returnNode->next;
            returnNode->next =add;
    }


}

void CommunicationNetwork::transmitMsg(char *){

    ifstream inFile;
    string data;

    inFile.open("messageIn.txt");
    if (inFile.good()){
        cout<<"The file has opened successfully"<<endl;
        while(getline(inFile,data)){
            stringstream ss(data);
            // divide lines to single words
            string inputWord;
            while(ss>>inputWord){
                City *current = head;
                //cout<<inputWord<<endl;
                while(current != NULL){
                    cout<<current->name<<" received "<<inputWord<<endl;
                    current = current->next;


                    }

                }
            }
        }
}





