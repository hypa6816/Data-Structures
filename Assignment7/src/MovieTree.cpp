#include "MovieTree.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;

MovieTree::MovieTree()
{

    root=NULL;

}

MovieTree::~MovieTree()
{
    DeleteAll(root);
}

void MovieTree::printMovieInventory(){
    printMovieInventory(root);
}

void MovieTree::printMovieInventory(MovieNode *node){
    if(node->leftChild!=NULL){
        printMovieInventory(node->leftChild);
        cout<<"Left:"<<node->leftChild->title;
    }
    cout<<"Movie: "<<node->title<<" "<<node->quantity<<endl;
    if(node->rightChild!=NULL){
        printMovieInventory(node->rightChild);
        cout<<"Right:"<<node->rightChild->title;
    }




}

MovieNode* MovieTree::search(std::string title){

    MovieNode *tmp = root;
    //cout<<"Movie:"<<title<<endl;
    while(tmp !=NULL){

        if(title.compare(tmp->title)<0){
            tmp = tmp->leftChild;


        }
        else if (title.compare(tmp->title)>0){
            tmp = tmp->rightChild;

        }
        else if (title.compare(tmp->title)==0){
            if(tmp->parent!=NULL){
                cout<<"Parent:"<<tmp->parent->title<<endl;
            }
            if(tmp->leftChild!=NULL&&tmp->rightChild ==NULL){
                cout<<"Left:"<<tmp->leftChild->title<<endl;
                cout<<"Right: NULL"<<endl;
            }
            if(tmp->rightChild!=NULL&&tmp->leftChild==NULL){
                cout<<"Right:"<<tmp->rightChild->title<<endl;
                cout<<"Left: NULL"<<endl;
            }
            if(tmp->rightChild!=NULL && tmp->leftChild!=NULL){
                cout<<"Left:"<<tmp->leftChild->title<<endl;
                cout<<"Right:"<<tmp->rightChild->title<<endl;
            }
            if(tmp->rightChild==NULL&&tmp->leftChild==NULL){
                cout<<"Children NULL"<<endl;
            }

            return tmp;
        }
    }

    return NULL;
}

void MovieTree::findMovie(string title){

    MovieNode *foundMovie = search(title);
    if(foundMovie!=NULL){

        cout << "Movie Info:" << endl;
        cout << "===========" << endl;
        cout << "Ranking:" << foundMovie->ranking << endl;
        cout << "Title:" << foundMovie->title << endl;
        cout << "Year:" << foundMovie->year << endl;
        cout << "Quantity:" << foundMovie->quantity << endl;
    }
    else{
        cout << "Movie not found." << endl;
    }
}

void MovieTree::rentMovie(string title){
    MovieNode *toRentMovie = search(title);
    if(toRentMovie!=NULL){
        toRentMovie->quantity = toRentMovie->quantity - 1;

        cout << "Movie has been rented." << endl;
        cout << "Movie Info:" << endl;
        cout << "===========" << endl;
        cout << "Ranking:" << toRentMovie->ranking << endl;
        cout << "Title:" << toRentMovie->title << endl;
        cout << "Year:" << toRentMovie->year << endl;
        cout << "Quantity:" << toRentMovie->quantity << endl;
        if(toRentMovie->quantity==0){
            deleteMovieNode(title);
        }
    }
    else{
        cout << "Movie out of stock." << endl;
    }
}


void MovieTree::addMovieNode(int ranking, std::string title, int releaseYear, int quantity){
    MovieNode *node = new MovieNode();
    MovieNode *Parent = NULL;
    node->ranking = ranking;
    node->title = title;
    node->year = releaseYear;
    node->quantity = quantity;
    node->parent=NULL;
    node->leftChild=NULL;
    node->rightChild=NULL;
    MovieNode *tmp = root;

    while(tmp !=NULL){

        Parent = tmp;
        if(title.compare(tmp->title)<0){
                tmp = tmp->leftChild;
        }
        else {
            tmp=tmp->rightChild;
        }
    }
    if (Parent == NULL){
        root = node;
    }
    else if (title.compare(Parent->title) <0){
        Parent->leftChild = node;
        node->parent = Parent;
    }
    else {
        Parent->rightChild = node;
        node->parent = Parent;

    }
}

// ASSIGNMENT 7 ADDITIONS ///////////////

MovieNode* MovieTree::treeMinimum(MovieNode * node){
    while(node->leftChild!=NULL){
        node = node->leftChild;
    }
    return node;
}

void MovieTree::deleteMovieNode(std::string title){
    MovieNode *toDelete= search(title);
    if(toDelete != NULL){
        if(toDelete->leftChild==NULL && toDelete->rightChild==NULL){
            toDelete->parent->leftChild=NULL;
            toDelete->parent->rightChild=NULL;
            delete toDelete;
        }
        else if(toDelete->leftChild!=NULL && toDelete->rightChild==NULL){
            toDelete->parent->leftChild = toDelete->leftChild;
            toDelete->parent->leftChild->parent = toDelete->parent;

            delete toDelete;
        }
        else if(toDelete->leftChild==NULL && toDelete->rightChild!=NULL){
            toDelete->parent->rightChild = toDelete->rightChild;
            toDelete->parent->rightChild->parent = toDelete->parent;
            delete toDelete;
        }
        else if(toDelete->leftChild!=NULL && toDelete->rightChild!=NULL){
            MovieNode *buddy = treeMinimum(toDelete->rightChild);
            buddy->parent->leftChild=NULL;
            buddy->rightChild=toDelete->rightChild;
            buddy->leftChild = toDelete->leftChild;
            //have to check the case in which buddy is directly a right child of toDelete

            if(toDelete->parent!=NULL){
                buddy->parent = toDelete->parent;
            }
            else{
                buddy->parent=NULL;
                root=buddy;
            }
            delete toDelete;
        }
    }
    else{
        //If movie not found in tree
        cout << "Movie not found." << endl;
    }
}

int MovieTree::countMovieNodes(){
    MovieNode *node = root;
    int c = 0;
    countMovieNodes(node, &c);
    cout << "Count is : " << c << endl;
    return c;
}

void MovieTree::countMovieNodes(MovieNode *node, int *count){
    if(node->leftChild!=NULL){
        countMovieNodes(node->leftChild,count);

    }
    cout << "Count in countMovie is : " << *count << endl;
    (*count)++;
    if(node->rightChild!=NULL){
        countMovieNodes(node->rightChild,count);

    }
}

void MovieTree::DeleteAll(MovieNode * node){
        if(node->leftChild != NULL){
            DeleteAll(node->leftChild);
        }
        cout<<"Deleting: "<<node->title<<endl;
        if(node->rightChild != NULL){
           DeleteAll(node->rightChild);
        }
        delete node;
}


