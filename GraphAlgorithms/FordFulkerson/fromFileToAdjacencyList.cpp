//
// Created by Hodosi on 5/7/2021.
//

#include "fromFileToAdjacencyList.h"

#include <iostream>
#include <fstream>

using namespace std;

void fromFileToAdjacencyList(vector<vector<pair<int, Node*>>> &adjacency_list, vector<Node*> &nodes_list, ifstream &fin){
    int predecessor_id, successor_id, weight;
    while (fin >> predecessor_id >> successor_id >> weight){
        Node *successor;
        successor = nodes_list[successor_id];
        adjacency_list[predecessor_id].push_back(make_pair(weight, successor));

        //residual graph
        Node *predecessor;
        predecessor = nodes_list[predecessor_id];
        adjacency_list[successor_id].push_back(make_pair(0, predecessor));
    }
}

void printAdjacencyList(vector<vector<pair<int, Node*>>> adjacency_list, int nodes){
    int predecessor;
    for(predecessor = 0; predecessor < nodes; predecessor++){
        cout << predecessor << " : ";
        for(auto successor : adjacency_list[predecessor]){
            cout << successor.second -> id << " " << successor.first << " ; ";
        }
        cout << "\n";
    }
    cout << "\n";
}