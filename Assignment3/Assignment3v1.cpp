#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

struct City{
    string name;
    City *next;
};

int main(){

string input[10] = {"Los Angeles", "Phoenix", "Denver","Dallas", "St. Louis", "Chicago","Atlanta","Washington, D.C","New York", "Boston"};
City *head = new City;
        head->name = input[0];
        head->next = NULL;
        City *current = head;

int option = 0;
do{
        cout	<<	"======Main	Menu======"	<<	endl;
        cout	<<	"1.	Build	Network"	<<	endl;
        cout	<<	"2.	Print	Network	Path"	<<	endl;
        cout	<<	"3.	Transmit	Message	Coast-To-Coast"	<<	endl;
        cout	<<	"4.	Add	City"	<<	endl;
        cout	<<  "5.	Quit"	<<	endl;
        cout    <<  "Choose an option: " << endl;
        cin     >>    option;
        cout    << endl;

switch(option){

    case 1 :
        {
            //cout << "Choice 1 : Build Network" << endl;
            //convert an array into a linked list
            int i = 1;
            while(i < 10){
                City *tmp = new City;
                tmp->name = input[i]; //(*tmp).value
                tmp->next = NULL;

                current->next = tmp;
                current = current->next;
                i++;
            }
            City *tail = current;
            current = head;
            cout<< "===CURRENT PATH==="<<endl;
            while(current != NULL){
                cout<<current->name<<" -> ";
                current = current->next;
            }
            cout<<"NULL"<<endl;
            cout<<"=================="<<endl;
            break;
        }
        /////////////////////////////////////

    case 2 :
        {
            //cout << "Choice 2: Print Network Path" <<endl;
            cout<< "===CURRENT PATH==="<<endl;
            City *tail = current;
            current = head;
            while(current != NULL){
                cout<<current->name<<" -> ";
                current = current->next;
            }
            cout<<"NULL"<<endl;
            cout<<"=================="<<endl;
            break;
        }
        /////////////////////////////////////
    case 3 :
        {
            //cout << "Choice 3: Transmit Message" <<endl;
            ifstream inFile;
            string data;

            inFile.open("messageIn.txt");
            if (inFile.good()){
                //cout<<"The file has opened successfully"<<endl;
                while(getline(inFile,data)){
                    stringstream ss(data);
                    // divide lines to single words
                    string inputWord;
                    while(ss>>inputWord){
                        current = head;
                        //cout<<inputWord<<endl;
                        while(current != NULL){
                            cout<<current->name<<" received "<<inputWord<<endl;
                            current = current->next;
                            //i++;

                        }

                    }
                }
            }
        }
    /////////////////////////////////////////////////////
    case 4 :
        {
            //cout <<"Choice 4: Add City"<<endl;
            string cityNew;
            string cityPrevious;
            cout	<<	"Enter	a	city	name:	"	<<	endl;
            cin.ignore();
            getline(cin, cityNew);
            cout	<<	"Enter	a	previous	city	name:	"	<<	endl;
            getline(cin, cityPrevious);
            // if cityPrevious is the first city
            current = head;
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
                                //left=tmp->next
                            }
                            else{
                                tmp=tmp->next;
                            }
                    }
                    add->next = returnNode->next;
                    returnNode->next =add;
            }
        }



}
}while(option != 5);

}
