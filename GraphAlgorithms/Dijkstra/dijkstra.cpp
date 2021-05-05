//
// Created by Hodosi on 3/27/2021.
//

#include "dijkstra.h"

#include <queue>
#include <iostream>

using namespace std;


void initialization(vector<Node*> &nodes_list, Node* source_node){
    for(auto node : nodes_list){
        node -> distance = INT16_MAX;
        node -> parent = -1;
        node -> visited = false;
    }
    source_node -> distance = 0;
}

bool relax(Node* predecessor, Node* successor, int weight){
    if(successor -> distance > predecessor -> distance + weight){
        successor -> distance = predecessor -> distance + weight;
        successor -> parent = predecessor -> id;
        return true;
    }
    return false;
}

struct costumeCmp{
    bool operator()(const Node* predecessor, const Node* successor){
        return  (predecessor -> distance > successor -> distance);
    }
};

void dijkstra(vector<Node*> &nodes_list, vector<vector<pair<Node*,int>>> &adjacency_list, Node *source_node){

    initialization(nodes_list, source_node);

    priority_queue<Node*, vector<Node*>, costumeCmp > p_queue;

    p_queue.push(source_node);

    while (!p_queue.empty()){
        auto predecessor = p_queue.top();
        p_queue.pop();
        if(predecessor->visited){
            continue;
        }
        for(auto successor : adjacency_list[predecessor -> id]){
            if(relax(predecessor, successor.first, successor.second)){
                p_queue.push(successor.first);
            }
        }
        predecessor->visited = true;
    }
}

void printMinimumPath(vector<Node*> &nodes_list, Node *source_node, ofstream &fout){
    for(auto node : nodes_list){
        if(node -> distance == INT16_MAX){
            fout << "INF" << " ";
        }
        else{
            fout << node -> distance << " ";
        }
    }
}