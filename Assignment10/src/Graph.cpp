

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "Graph.h"

using namespace std;

Graph::Graph()
{

}

Graph::~Graph()
{
    //dtor
}
void Graph::addEdge(string v1, string v2, int weight){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
/*
                    adjVertex av2;
                    av2.v = &vertices[i];
                    av2.weight = weight;
                    vertices[j].adj.push_back(av2);
                    */
                }
            }
        }
    }
}
void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        v.district = -1;
        v.visited = false;
        vertices.push_back(v);

    }
}

void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
       // vertices[i].district = -1;
        //vertices[i].visited = false;
        cout<<vertices[i].district<<":";
        cout<<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v->name<<"***";
        }
        cout<<endl;
    }

}

void Graph::assignDistricts(){
    int districtID = 0;
    std::queue<vertex*> q;
    vertex *v;
    for(int i = 0; i < vertices.size(); i++){
        if(!vertices[i].visited){
            v = &vertices[i];
            districtID++;
            q.push(v);
            vertices[i].visited = true;
        }
        while(!q.empty()){
            v = q.front();
            q.pop();
            v->ID = districtID;
            for(i = 0; i < v->adj.size(); i++){
                if(!v->adj[i].v->visited){
                    q.push(v->adj[i].v);
                    v->adj[i].v->visited = true;
                    v->adj[i].v->district = districtID;
                }
            }
        }
    }

/*
  for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].district<<":";
        cout<<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v->name<<"***";
        }
        cout<<endl;
    }
    */

}

void Graph::shortestPath(std::string startingCity,std::string endingCity){
    //Find startingCity and endingCity and compare the district from each struct. If the districts are the same
    //BRS traverse from the starting city to the ending city and print out the path that was taken. This automatically
    //results in the shortest path. If the districts are not the same then print out that they're not in the same
    //district and there is no path.
    std::queue<vertex*> q;
    vertex *v;
    vertex *start;
    vertex *ending;
    // use vertex using function find vertex
    for(int i = 0; i < vertices.size(); i++){
        if(!vertices[i].name == startingCity){
            v = &vertices[i];
            q.push(v);
            vertices[i].visited = true;
        }
        while(!q.empty()){
            v = q.front();
            q.pop();
            for(i = 0; i < v->adj.size(); i++){
                if(!v->adj[i].v->visited){
                    q.push(v->adj[i].v);
                    v->adj[i].v->visited = true;
                    if(v->adj[i].v->name == startingCity){
                        start = v->adj[i].v;
                    }
                    if(v->adj[i].v->name == endingCity){
                        ending = v->adj[i].v;
                    }
                    if(start->district == ending->district){
                        //traverse from startingCity to endingCity and print path
                        cout<<","<<v->adj[i].v->name;
                        cout<<endl;
                    }
                    if(start->district == -1 && ending->district == -1){
                        cout<<"Please identify the districts before checking distances"<<endl;
                        break;
                    }
                    if(start->district != ending->district){
                        cout<<"No safe path between cities"<<endl;
                        break;
                    }
                    else{
                        cout<<"One or more cities doesn't exist"<<endl;
                        break;
                    }
                }
            }
        }
    }
}

