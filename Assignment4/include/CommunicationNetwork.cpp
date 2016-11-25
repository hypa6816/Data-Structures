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

// Create an array of the original 10 cities
string input[10] = {"Los Angeles", "Phoenix", "Denver","Dallas", "St. Louis", "Chicago","Atlanta","Washington, D.C","New York", "Boston"};
    // Place first city into head
    head->name = input[0]; // name of city
    head->next = NULL;
    head->previous = NULL;
    City *current = head; // pointer current is head
    int i = 1;
    // add in the rest of the cities
    while(i < 10){
        City *tmp = new City; // create a tmp of node
        tmp->name = input[i]; // input name of city
        tmp->next = NULL; // nothing is next to the city
        tmp->previous = current; // the previous to the city is the current
        current->next = tmp; // point from current to tmp
        current = current->next; // move on to tmp
        i++;
    }
    tail = current; // make the tail the current
    current = head; // bring back current to head
    // Print the current path
    cout<< "===CURRENT PATH==="<<endl;
    cout<<"NULL <-";
    while(current != tail){
        cout<<current->name<<" <-> ";
        current = current->next;
    }
    current = tail;
    cout<<current->name<<" -> ";
    cout<<"NULL"<<endl;
    cout<<"=================="<<endl;



}

void CommunicationNetwork::printNetwork(){
    // Print the current path
    City *current = head;
    cout<< "===CURRENT PATH==="<<endl;
    cout<<"NULL	<-";
        while(current != tail){
        cout<<current->name<<" <-> ";
        current = current->next;
    }
    current = tail;
    cout<<current->name<<" -> ";
    cout<<"NULL"<<endl;
    cout<<"=================="<<endl;

}

void CommunicationNetwork::addCity(string cityNew, string cityPrevious){

    //with previous:
    //newnode->next=insertprev->next // if you're at head cannot do this
    //newnode->prev=insertprev
    //insertprev->next = newNode
    //insertprev->next->prev=newnode // if you're at tail cannot do this

    //if insert previous is at head
    //null

    // if cityPrevious is the first city
    City *current = head; //current is equal to head
    City *add = new City; //make new city called add
    add->name = cityNew; // place cityNew into add
    if(cityPrevious==head->name){ //if the new city is the same as the head,
            add->next = head; //after add is next
            head = add;// make head add
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
                while(current != NULL){
                    cout<<current->name<<" received "<<inputWord<<endl;
                    current = current->next;
//send message back a while loop using previous

                    }

                }
            }
        }
}


void CommunicationNetwork::deleteCity(string cityNameDelete){
    //delete the city that is the same as cityNameDelete

    //if in middle
    //deleted->previous->next = deleted->next; (if deleted->previous!=NULL)
    //deleted->next->previous = deleted->previous: (if deleted->next!=NULL)

    City *current = head;
    City *cityDelete = new City;
    cityDelete->name = cityNameDelete;
    if(cityNameDelete == head->name){
        head = head -> next;

        delete current;
    }


}

void CommunicationNetwork::clearNetwork(){
    //while(delete->next!=NULL)
    //deleteCity(delete->previous)
    //delete delete


}
