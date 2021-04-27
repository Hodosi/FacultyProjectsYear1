//
// Created by Hodosi on 3/29/2021.
//

#include "bellmanFord.h"
#include <iostream>
using namespace std;

void initializationF(vector<Node*> &nodes_list, Node* source_node){
    for(auto node : nodes_list){
        node -> distance = INT16_MAX;
        node -> parent = -1;
    }
    source_node -> distance = 0;
}

void relaxF(Node* predecessor, Node* successor, int weight){
    if(successor -> distance > predecessor -> distance + weight){
        successor -> distance = predecessor -> distance + weight;
        successor -> parent = predecessor -> id;
    }
}

bool bellmanFord(vector<Node*> &nodes_list, vector<Edge*> &edge_list, Node *source_node){
    initializationF(nodes_list, source_node);
    for(int i = 1; i < nodes_list.size(); i++){
        for(auto edge : edge_list){
            relaxF(edge -> predecessor, edge -> successor, edge -> weight);
        }
    }
    for(auto edge : edge_list){
        if(edge -> successor -> distance > edge -> predecessor -> distance + edge -> weight){
            return false;
        }
    }
    return true;
}
void printMinimumPathF(vector<Node*> &nodes_list, Node *source_node, ofstream &fout){
    for(auto node : nodes_list){
        if(node -> distance == INT16_MAX){
            fout << "INF" << " ";
        }
        else{
            fout << node -> distance << " ";
        }
    }
}
