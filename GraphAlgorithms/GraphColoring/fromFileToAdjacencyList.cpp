#include "fromFileToAdjacencyList.h"

void fromFileToAdjacencyList(vector<vector<Node*>> &adjacency_list, vector<Node*> &nodes_list, ifstream &fin) {

    int predecessor_id, successor_id;
    while (fin >> predecessor_id >> successor_id){
        Node *predecessor, *successor;
        predecessor = nodes_list[predecessor_id];
        successor = nodes_list[successor_id];
        adjacency_list[predecessor_id].push_back(successor);
        adjacency_list[successor_id].push_back(predecessor);
   }
}

void printAdjacencyList(vector<vector<Node*>> &adjacency_list, int nr_nodes){

    int predecessor;
    for(predecessor = 0; predecessor < nr_nodes; predecessor++){
        cout << predecessor << " : ";
        for(auto successor : adjacency_list[predecessor]){
            cout << successor->id << " ";
        }
        cout << "\n";
   }
   cout << "\n";
}