#include "CommunicationNetwork.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;



CommunicationNetwork::CommunicationNetwork()
{
    //City *head = new City;
    //City *tail = new City;
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
    if(cityPrevious=="First"){ //if the new city is the same as the head,
            add->next = head; //after add is next
            head->previous = add;
            add->previous=NULL;
            head = add;// make head add

    }
    else{ // if cityPrevious is not the first city
        //Search for where cityPrevious is located
            City *tmp = head; // make temporary instance of city to move around struct
            City *returnNode = NULL; // once match is found return location using returnNode
            bool found = false; // initialize found
            while(found!= true && tmp!=NULL){ // while the match is not found and tmp is not at the end..
                    if (tmp->name == cityPrevious){//if the tmp is found..
                        found=true;
                        returnNode=tmp;// place returnNode as tmp
                    }
                    else{
                        tmp=tmp->next; // if match is not found iterate to the next location in array
                    }
            }
            add->previous = returnNode;
            add->next = returnNode->next;
            returnNode->next = add;
            returnNode->next->previous = add;
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
                while(current->next != NULL){
                    cout<<current->name<<" received "<<inputWord<<endl;
                    current->message= inputWord;
                    current = current->next;
//send message back a while loop using previous

                    }
                while(current != NULL){
                    cout<<current->name<<" received "<<inputWord<<endl;
                    current->message = inputWord;
                    current = current->previous;
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
    if(cityNameDelete == head->name){
        head = head -> next;
        head->previous = NULL;

        delete current;
    }
    else{
        // if in the middle
        City *tmp = head; // make temporary instance of city to move around struct
        City *returnNode = NULL; // once match is found return location using returnNode
        bool found = false; // initialize found
        while(found!= true && tmp!=NULL){ // while the match is not found and tmp is not at the end..
                if (tmp->name == cityNameDelete){//if the tmp is found..
                    found=true;
                    returnNode=tmp;// place returnNode as tmp
                }
                else{
                    tmp=tmp->next; // if match is not found iterate to the next location in array
                }
        }
        if (returnNode->next!=NULL){
            returnNode->previous->next = returnNode->next;
            returnNode->next->previous= returnNode->previous;
        }
        else if (returnNode->next==NULL){
            tail = tail -> previous;
            tail->next = NULL;
        }

        delete returnNode;



    }



}

void CommunicationNetwork::clearNetwork(){
    City *current = head;



    while(current->next!=NULL){
        City *tmp = NULL;
        head = head -> next;
        head -> previous = NULL;
        tmp = current;

        delete tmp;
        current = head;


    }
    if(current->next ==NULL){
            delete current;
        }


}







