//
// Created by Hodosi on 3/29/2021.
//

#include "adjacencyList.h"

#include <iostream>
#include <fstream>

using namespace std;

void fromEdgeListToAdjacencyList(vector<vector<pair<Node*,int>>> &adjacency_list, vector<Node*> &nodes_list, int nodes, vector<Edge*> edge_list){
    int predecessor_id, successor_id, weight;

    for(auto edge : edge_list){
        Node *predecessor, *successor;
        predecessor = nodes_list[edge -> predecessor -> id];
        successor = nodes_list[edge -> successor -> id];

        adjacency_list[edge -> predecessor -> id].push_back(make_pair(successor, edge->weight));
        //adjacency_list[successor_id].push_back(predecessor);
    }
}

void printAdjacencyList(vector<vector<pair<Node*,int>>> adjacency_list, int nodes){
    cout << "\n";
    int predecessor;
    for(predecessor = 0; predecessor <= nodes; predecessor++){
        cout << predecessor << " : ";
        for(auto successor : adjacency_list[predecessor]){
            cout << successor.first -> id << " , " << successor.second << " ; ";
        }
        cout << "\n";
    }
    cout << "\n";
}
