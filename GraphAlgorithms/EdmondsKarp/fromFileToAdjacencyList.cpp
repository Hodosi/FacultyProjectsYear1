#include "fromFileToAdjacencyList.h"

void fromFileToAdjacencyList(vector<vector<pair<Node*, int>>> &adjacency_list, vector<Node*> &nodes_list, ifstream &fin){

    int predecessor_id, successor_id, weight;
    while (fin >> predecessor_id >> successor_id >> weight){
        Node *successor;
        successor = nodes_list[successor_id];
        adjacency_list[predecessor_id].push_back(make_pair(successor, weight));

        // residual graph
        Node *predecessor;
        predecessor = nodes_list[predecessor_id];
        adjacency_list[successor_id].push_back(make_pair(predecessor, 0));
    }
}

void printAdjacencyList(vector<vector<pair<Node*, int>>> &adjacency_list, int nodes){

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
