#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "HashTable.h"

using namespace std;

HashTable::HashTable()
{
    //ctor
}

HashTable::~HashTable()
{
    //dtor
}

int HashTable::hashSum(std::string x, int s){
    int sum = 0;
    for(int i=0; i<x.length(); i++){
        sum = sum +(int)x[i];
    }
    sum = sum % s;
    cout<<sum<<endl;
    return sum;

}

void HashTable::insertMovie(string name, int year){
    cout << "error" << endl;
    int key = hashSum(name, 10);

    HashElem *node = new HashElem;
    node->title = name;
    node->year = year;
    node->next=NULL;
    node->previous=NULL;
    //cout << "error" <<endl;
    if(hashTable[key]==NULL){
        hashTable[key] = node;
    }
    else{
        HashElem *tmp = hashTable[key];
        //cout << "error";
        while(tmp->next!=NULL){
            tmp = tmp->next;
        }
        tmp->next =node;
        node->previous = tmp;
    }
}



void HashTable::printTableContents(){

}
