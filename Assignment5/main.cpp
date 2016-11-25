#include <iostream>
#include "Queue.h"
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

int main()
{
    Queue que(10);
    int option = 0;
    do{
    cout	<<	"======Main	Menu======"	<<	endl;
    cout	<<	"1.	Enqueue"	<<	endl;
    cout	<<	"2.	Dequeue"	<<	endl;
    cout	<<	"3.	Print queue"	<<	endl;
    cout	<<	"4.	Enqueue sequence"	<<	endl;
    cout    <<  "5. Quit" << endl;
    cin     >>    option;
    cout    << endl;

    switch(option){

    case 1 :
        {
            //enqueue word
            string input;
            cout<<"word:"<<endl;
            cin.ignore();
            getline(cin,input);

            que.enqueue(input);
            break;
        }
        /////////////////////////////////////

    case 2 :
        {
            //dequeue word
            string word = que.dequeue();

            break;
        }
        /////////////////////////////////////
    case 3 :
        {
            //print queueArray
            que.printQueue();

            break;
        }
                //////////////////////////////
    case 4 :
        {
            //enqueue sentence
            string sentence;
            cout<<"sentence: "<<endl;
            cin.ignore();
            getline(cin,sentence);
            stringstream ss(sentence);
            string word;
            while(ss>>word){
                que.enqueue(word);
            }
            break;
        }
                /////////////////////////////
    case 5 :
        {
            cout<<"Goodbye!"<<endl;
            break;
        }

    }
    }while(option!=5);
}
