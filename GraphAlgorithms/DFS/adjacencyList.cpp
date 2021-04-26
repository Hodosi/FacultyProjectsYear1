//
// Created by Hodosi on 3/13/2021.
//

#include "adjacencyList.h"


#include <iostream>
#include <fstream>

using namespace std;

void fromFileToAdjacencyList(vector<vector<Node*>> &adjacency_list, vector<Node*> &nodes_list, int nodes, ifstream &fin){
    int predecessor_id, successor_id, cost;
    while (fin >> predecessor_id >> successor_id >> cost){
        Node *predecessor, *successor;
        predecessor = nodes_list[predecessor_id];
        successor = nodes_list[successor_id];

        adjacency_list[predecessor_id].push_back(successor);
        adjacency_list[successor_id].push_back(predecessor);
    }
}

void printAdjacencyList(vector<vector<Node*>> adjacency_list, int nodes){
    int predecessor;
    for(predecessor = 1; predecessor <= nodes; predecessor++){
        cout << predecessor << " : ";
        for(auto successor : adjacency_list[predecessor]){
            cout << successor -> id << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}