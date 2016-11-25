/* Sara Park
Assignment 1
1/21/16
CSCI 2270

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;

string trim(string & str)
{
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last-first+1));
}


struct itemArray
{
string type;
string saleorwanted;
int price;
};




int main(int argc, char *argv[]) {

ifstream inFile;
string data;
inFile.open("messageBoard.txt");
int index = 0;
int i = 0;
itemArray itemArray[100];
string match = "not found";
int soldItems =0;
int loopiterations = 0;

if (inFile.good()){
    cout<< "The message board has opened successfully."<< endl;

    while (getline(inFile,data)){

        loopiterations++;
        stringstream ss(data);

        string type;
        getline(ss,type,',');
        trim(type);


        string saleorwanted;
        getline(ss,saleorwanted,',');
        trim(saleorwanted);


        string price1;
        getline(ss,price1,',');
        int price = atoi(price1.c_str());


       for (int i=0; i < index; i++){
            loopiterations++;
            match = "not found";
            if (type == itemArray[i].type){
            if (saleorwanted == " for sale" && itemArray[i].saleorwanted == " wanted"){
                if (price <= itemArray[i].price){
                    //delete indexes
                        match = "found";
                        cout<<itemArray[i].type<<" "<<price<<endl;
                        for(int a = i; a<index; a++){
                        itemArray[a] = itemArray[a+1];
                        loopiterations++;

                        }

                        soldItems++;
                        index--;
                        break;

                }
            }


            else if (saleorwanted == " wanted" && itemArray[i].saleorwanted == " for sale"){
                if (price >= itemArray[i].price){
                    //delete indexes
                        match = "found";
                        cout<<itemArray[i].type<<" "<<itemArray[i].price<<endl;
                        for(int a = i; a<index; a++){
                        itemArray[a] = itemArray[a+1];
                        loopiterations++;

                        }
                        soldItems++;
                        index--;
                        break;

                    }
                }
            }
        }
        if(match == "not found"){

            itemArray[index].type = type;
            itemArray[index].saleorwanted = saleorwanted;
            itemArray[index].price = price;
            index = index +1;

        }


    }
}
else {
    cout<< "The message board has not opened successfully."<< endl;
}
inFile.close();
for (int a=0; a<index; a++){
       // loopiterations
    if (itemArray[a].saleorwanted == " for sale"){
        cout<<itemArray[a].type<<","<<"for sale"<<", "<<itemArray[a].price<<endl;
    }
    else
        {cout<<itemArray[a].type<<","<<"wanted"<<", "<<itemArray[a].price<<endl;
    }
}
cout << "Loop iterations: " << loopiterations << endl;
cout << "Items Sold: " <<soldItems<< endl;



/*
for (int i=0; i < sizeof(itemArray); i++){
    for (int j=0; j < sizeof(itemArray); i++){
        if (itemArray[i].type == itemArray[j].type){
            if (itemArray[i].saleorwanted == " for sale" && itemArray[j].saleorwanted== " wanted"){
                if (itemArray[i].price <= itemArray[j].price){
                    //delete indexes
                    if (i>j){
                        itemArray[i] = itemArray[i+1];
                        itemArray[j] = itemArray[j+1];
                        cout<<itemArray[i].type<<" "<<itemArray[i].price<<endl;
                        return 1;
                    }
                }
            }

            else (itemArray[i].saleorwanted == " wanted" && itemArray[j].saleorwanted== " for sale");{
                if (itemArray[i].price >= itemArray[j].price){
                    //delete indexes
                    if (j>i){
                        itemArray[j] = itemArray[j+1];
                        itemArray[i] = itemArray[i+1];
                        cout<<itemArray[j].type<<" "<<itemArray[j].price<<endl;
                        return 1;

                    }
                }
            }

        }
    }
}
for (int a=0; a<sizeof(itemArray); a++){
    if (itemArray[a].saleorwanted == " for sale"){
        cout<<itemArray[a].type<<","<<"for sale"<<", "<<itemArray[a].price<<endl;
    }
    else{cout<<itemArray[a].type<<","<<"wanted"<<", "<<itemArray[a].price<<endl;
    }
}
*/

}
