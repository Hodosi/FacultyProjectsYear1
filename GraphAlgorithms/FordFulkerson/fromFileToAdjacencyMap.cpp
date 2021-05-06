//
// Created by Hodosi on 5/6/2021.
//

#include "fromFileToAdjacencyMap.h"

void fromFileToAdjacencyMap(vector<map<Edge*, int, costumeCmp>> &adjacency_map, vector<Node*> &nodes_list, vector<Edge*> &edge_list, int nodes, ifstream &fin){
    int predecessor_id, successor_id, weight;
    while (fin >> predecessor_id >> successor_id >> weight){
        Node *predecessor;
        Node *successor;
        Edge *edge = new Edge ();

        predecessor = nodes_list[predecessor_id];
        successor = nodes_list[successor_id];

        edge->predecessor = predecessor;
        edge->successor = successor;
        edge->weight = weight;

        edge_list.push_back(edge);

        adjacency_map[predecessor_id].insert(make_pair(edge, weight));

        Edge *edge_residual = new Edge ();

        edge_residual->predecessor = successor;
        edge_residual->successor = predecessor;
        edge_residual->weight = 0;

        edge_list.push_back(edge_residual);

        adjacency_map[successor_id].insert(make_pair(edge_residual, 0));

    }
}

void printAdjacencyMap(vector<map<Edge*, int, costumeCmp>> &adjacency_map, int nodes){
    int predecessor;
    for(predecessor = 0; predecessor < nodes; predecessor++){
        cout << predecessor << " : ";
        for(auto edge_weight : adjacency_map[predecessor]){
            cout << edge_weight.first->successor->id << " " << edge_weight.second << " ; ";
        }
        cout << "\n";
    }
    cout << "\n";
}
