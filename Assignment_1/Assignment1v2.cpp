/* Sara Park
Assignment 1
1/21/16
CSCI 2270

*/

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct itemArray
{
string type;
string saleorwanted;
string price;
};


int main() {

ifstream inFile;
string data;
inFile.open("messageBoard.txt");
int counter = 0;
itemArray itemArray[500];

if (inFile.good()){
    cout<< "The message board has opened successfully."<< endl;

    while (getline(inFile,data,',')){

        stringstream ss(data);
        /*if (ss.peek() == ','|| ss.peek() == ' '){
            ss.ignore();
        }*/

        string type;
        ss>> type;
        itemArray[counter].type = type;
        cout<< type << endl;

        string saleorwanted;
        ss>> saleorwanted;
        itemArray[counter].saleorwanted = saleorwanted;
        cout<< saleorwanted << endl;

        string price;
        ss>> price;
        itemArray[counter].price = price;
        cout<< price << endl;

        counter = counter + 1;
    }
}
else {
    cout<< "The message board has not opened successfully."<< endl;
}
inFile.close();

cout<< "For sale or not: "<< itemArray[1].saleorwanted << endl;

}
