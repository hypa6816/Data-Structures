#include <iostream>

using namespace std;
struct Node {

int key;

Node *next;
Node *head = NULL;

};
int main{
Node *walker = head;

while(walker != NULL){

        if(walker->key == 50) {

                 cout << walker->key << endl;

                 break;

         }

         walker = walker->next;

}

cout << walker->key << endl;
}
