#include "MovieTree.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;

MovieTree::MovieTree()
{
    void printMovieInventory(MovieNode *node);
    MovieNode *search(std::string title);
    root=NULL;

}

MovieTree::~MovieTree()
{
    //dtor
}

void MovieTree::printMovieInventory(){
    printMovieInventory(root);
}

void MovieTree::printMovieInventory(MovieNode *node){
    if(node->leftChild!=NULL){
        printMovieInventory(node->leftChild);
    }
    cout<<"Movie: "<<node->title<<" "<<node->quantity<<endl;
    if(node->rightChild!=NULL){
        printMovieInventory(node->rightChild);
    }


}

MovieNode* MovieTree::search(std::string title){
    cout<<"searching"<<endl;
    MovieNode *tmp = root;
    while(tmp !=NULL){
            cout<<tmp->title<<endl;

        if(title.compare(tmp->title)<0){
            tmp = tmp->leftChild;
        }
        else if (title.compare(tmp->title)>0){
            tmp = tmp->rightChild;
        }
        else if (title.compare(tmp->title)==0){
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
    }
    else{
        cout << "Movie not found." << endl;
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
    cout<<"place:"<<title<<endl;

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
        cout<<"root: "<<title<<endl;
    }
    else if (title.compare(Parent->title) <0){
        Parent->leftChild = node;
        node->parent = Parent;
        cout<<"parent>node: "<<title<<endl;
    }
    else {
        Parent->rightChild = node;
        node->parent = Parent;
        cout<<"parent<node: "<<title<<endl;
    }
}

