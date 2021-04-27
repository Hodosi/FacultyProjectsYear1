//
// Created by Hodosi on 3/27/2021.
//

#include "edgeList.h"
#include <iostream>

void fromFileToEdgeList(vector<Edge*> &edge_list , vector<Node*> &nodes_list, ifstream& fin){
    int predecessor_id, successor_id, weight;
    while (fin >> predecessor_id >> successor_id >> weight){
        Edge *edge = new Edge();

        Node *predecessor, *successor;
        predecessor = nodes_list[predecessor_id];
        successor = nodes_list[successor_id];

        edge -> predecessor = predecessor;
        edge -> successor = successor;
        edge -> weight = weight;

        edge_list.push_back(edge);
    }
}

void printEdgeList(vector<Edge*> &edge_list){
    for(auto edge : edge_list){
        cout << edge -> predecessor -> id << " " << edge -> successor -> id << " " << edge -> weight << "\n";
    }
}
