#include "adjacencyList.h"

#include <iostream>
#include <fstream>

using namespace std;

void fromFileToAdjacencyList(vector<vector<pair<Node*,int>>> &adjacency_list, vector<Node*> &nodes_list, int nodes, ifstream &fin){
    int predecessor_id, successor_id, weight;
    while (fin >> predecessor_id >> successor_id >> weight){
        Node *predecessor, *successor;
        predecessor = nodes_list[predecessor_id];
        successor = nodes_list[successor_id];

        adjacency_list[predecessor_id].push_back(make_pair(successor, weight));
        adjacency_list[successor_id].push_back(make_pair(predecessor, weight));
    }
}

void printAdjacencyList(vector<vector<pair<Node*,int>>> adjacency_list, int nodes){
    int predecessor;
    for(predecessor = 0; predecessor < nodes; predecessor++){
        cout << predecessor << " : ";
        for(auto successor : adjacency_list[predecessor]){
            cout << successor.first -> id << " " << successor.second << " ; ";
        }
        cout << "\n";
    }
    cout << "\n";
}