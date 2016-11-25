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
    for (int i =0; i<10; i++){
        hashTable[i] = NULL;
    }
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
    //cout<<sum<<endl;
    return sum;

}

void HashTable::insertMovie(string name, int year){

    int key = hashSum(name, tableSize);
    HashElem *node = new HashElem(name,year);
    node->next=NULL;
    node->previous=NULL;

    if(hashTable[key]==NULL){
        hashTable[key] = node;
        //cout<<"working"<<"key:"<<key<<endl;
    }
    else{
        HashElem *tmp = hashTable[key];
        while(tmp->next!=NULL){
            tmp = tmp->next;
        }
        tmp->next =node;
        node->previous = tmp;
    }
}


void HashTable::printTableContents(){
    for (int i =0; i<tableSize; i++){
        if(hashTable[i]!=NULL){
            //ut<<"in if"<<endl;
            HashElem *tmp = hashTable[i];
            cout<< tmp->title<<" : "<<tmp->year<<endl;
            while(tmp->next !=NULL){
                //ut<<"in while"<<endl;
                tmp =tmp ->next;
                cout<< tmp->title<<" : "<<tmp->year<<endl;

            }
        }
        else{
            cout<< "empty"<<endl;
        }
    }
}

void HashTable::findMovie(string name){
    //use hash sum
    HashElem * found=NULL;
    for (int i =0; i<10; i++){
        if(hashTable[i]!=NULL){
            HashElem *tmp = hashTable[i];
            if(tmp->title == name){
                found = tmp;
                cout<<i<<":" <<tmp->title<<":"<<tmp->year<<endl;
                break;
            }
            else{
                while(tmp->next !=NULL){
                    if(tmp->title == name){
                        found = tmp;
                        cout<<i<<":" <<tmp->title<<":"<<tmp->year<<endl;
                        break;
                }
                else{
                tmp =tmp ->next;
                }
                }
            }
        }
    }
    if(found ==NULL){
        cout<< "Movie is not found"<<endl;
    }

}

void HashTable::deleteMovie(string name){
    HashElem * found=NULL;
    int index =NULL;
    for (int i =0; i<10; i++){
        if(hashTable[i]!=NULL){
            HashElem *tmp = hashTable[i];
            if(tmp->title == name){
                found = tmp;
                index = i;
                break;
            }
            else{
                while(tmp->next !=NULL){
                    if(tmp->title == name){
                            found = tmp;
                            index = i;
                            break;
                    }
                    else{
                    tmp =tmp ->next;
                    }
                }
            }
        }
    }
    if(found ==NULL){
        cout<< "Movie is not found"<<endl;
    }
    else{
        if(found->next!=NULL && found->previous != NULL){
            //found is in the middle
            found->previous->next = found->next;
            found->next->previous = found->previous;
        }
        else if(found->next!=NULL && found->previous ==NULL){
            //found is in the front
            hashTable[index] = found->next;
            found->next->previous = NULL;
        }
        else if(found->next == NULL && found->previous !=NULL){
            //found is at the end
            found->previous->next = NULL;
        }
        else if(found->next ==NULL && found->previous ==NULL){
            //found is at the front without any following
            hashTable[index]=NULL;
        }
        delete found;
    }

}
