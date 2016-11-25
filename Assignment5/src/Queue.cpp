#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue(int qs)
{
    //ctor
    queueSize = qs;
    arrayQueue = new string[queueSize];
    queueHead = 0;
    queueTail = 0;
    queueCount = 0;

}

Queue::~Queue()
{
    delete []arrrayQueue;
}

bool Queue::queueIsFull(){
    bool isFull = false;
    if(queueCount== queueSize-1){
        isFull = true;
    }
    return isFull;
}

bool Queue::queueIsEmpty(){
    bool isEmpty = false;
    if(queueCount==0){
        isEmpty = true;
    }
    return isEmpty;
}
void Queue::enqueue(string input){
    if(queueIsFull()!=true){

        if(queueTail==queueSize-1){
            queueTail = 0;
        }
        arrayQueue[queueTail] = input;
        queueCount++;
        if(queueTail!=queueSize-1){
            queueTail++;
        }

        cout<<"E: "<<input<<endl;
        cout<<"H: "<<queueHead<<endl;
        cout<<"T: "<<queueTail<<endl;

    }
    else{
        cout<<"Queue full"<<endl;
    }


}

std::string Queue::dequeue(){
    if(!queueIsEmpty()){
        string word = arrayQueue[queueHead];
        queueCount --;
        if(queueHead == queueSize-1){
            queueHead = 0;
        }
        else{
            queueHead ++;
        }
        cout<<"H:	"<<queueHead<<endl;
        cout<<"T:	"<<queueTail<<endl;
        cout<<"word:	"<<word<<endl;
        return word;

    }
    else{
        cout<<"Queue is empty"<<endl;
    }


}

void Queue::printQueue(){
    int current = queueHead;
    while(current!=queueTail){
        if(current == queueSize-1){
        current = 0;
        }
        cout << current<<":	"<<arrayQueue[current]<<endl;
        current++;

    }
    if(queueIsEmpty()){
        cout << "Empty"<<endl;
    }

}
//build destructor




