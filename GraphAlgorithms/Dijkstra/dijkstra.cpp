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
    }
    source_node -> distance = 0;
}

void relax(Node* predecessor, Node* successor, int weight){
    if(successor -> distance > predecessor -> distance + weight){
        successor -> distance = predecessor -> distance + weight;
        successor -> parent = predecessor -> id;
    }
}

struct costumeCmp{
    bool operator()(const Node* predecessor, const Node* successor){
        return  (predecessor -> distance > successor -> distance);
    }
};

void dijkstra(vector<Node*> &nodes_list, vector<vector<pair<Node*,int>>> &adjacency_list, Node *source_node){
    initialization(nodes_list, source_node);
    source_node -> distance = 0;

    priority_queue<Node*, vector<Node*>, costumeCmp > p_queue;
    for(auto node : nodes_list){
        p_queue.push(node);
    }

    while (!p_queue.empty()){
        auto predecessor = p_queue.top();
        p_queue.pop();
        for(auto successor : adjacency_list[predecessor -> id]){
            relax(predecessor, successor.first, successor.second);
        }

        priority_queue<Node*, vector<Node*>, costumeCmp > cpy_p_queue;
        while (!p_queue.empty()){
            cpy_p_queue.push(p_queue.top());
            p_queue.pop();
        }
        swap(p_queue, cpy_p_queue);
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