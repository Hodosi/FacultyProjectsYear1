//
// Created by Hodosi on 5/7/2021.
//

#include "flowRelabel.h"
#include <queue>

void initialization(vector<Node*> &nodes_list, vector<vector<pair<int, Node*>>> &adjacency_list){

    int nodes = nodes_list.size();
    Node* source_node = nodes_list[0];

    for(auto node : nodes_list){
        node -> excess_flow = 0;
        node -> height = 0;
    }

    source_node->height = nodes;

    for(auto& weight_node : adjacency_list[source_node->id]){

        Node* successor = weight_node.second;
        int increase_flow = weight_node.first;

        successor->excess_flow = increase_flow;
        weight_node.first = 0;    // weight_node.first -= increase_flow;

        for(auto& weight_node_residual : adjacency_list[successor->id]){
            if(weight_node_residual.second == source_node){
                weight_node_residual.first += increase_flow;
                break;
            }
        }
    }
}

bool uplift(vector<Node*> &nodes_list, Node* current_node){

    Node* source_node = nodes_list[0];

    if(current_node->excess_flow > 0 && current_node->height <= source_node->height){
        current_node->height += 1;
        return true;
    }

    return false;
}

bool pumping(vector<vector<pair<int, Node*>>> &adjacency_list, Node* predecessor){

    bool pumped = false;

    if(predecessor->excess_flow <= 0){
        return pumped;
    }

    for(auto& weight_node : adjacency_list[predecessor->id]){

        Node* successor = weight_node.second;

        if(weight_node.first > 0 && predecessor->height == successor->height + 1){

            pumped = true;
            int increase_flow = min(weight_node.first, predecessor->excess_flow);

            weight_node.first -= increase_flow;
            predecessor->excess_flow -= increase_flow;
            successor->excess_flow += increase_flow;

            for(auto& weight_node_residual : adjacency_list[successor->id]){
                if(weight_node_residual.second == predecessor){
                    weight_node_residual.first += increase_flow;
                    break;
                }
            }
        }
    }

    return pumped;
}

int preflowPush(vector<Node*> &nodes_list, vector<vector<pair<int, Node*>>> &adjacency_list){

    Node* destination_node = nodes_list[nodes_list.size() - 1];

    initialization(nodes_list, adjacency_list);

    while (true) {

        bool pumped = false;
        for(int i = 1; i < nodes_list.size() - 1; i++){
            Node* predecessor = nodes_list[i];
            if(pumping(adjacency_list, predecessor)){
                pumped = true;
                break;
            }
        }
        if(pumped){
            continue;
        }

        bool uplifted = false;
        for(int i = 1; i < nodes_list.size() - 1; i++){
            Node* predecessor = nodes_list[i];
            if(uplift(nodes_list, predecessor)){
                uplifted = true;
                break;
            }
        }
        if(uplifted){
            continue;
        }

        break;
    }

    return destination_node->excess_flow;
}

bool unload(vector<Node*> &nodes_list, vector<vector<pair<int, Node*>>> &adjacency_list, Node* predecessor){

    Node* source_node = nodes_list[0];

    if(predecessor->excess_flow <= 0){
        return false;
    }

    while (predecessor->excess_flow > 0){
        if(pumping(adjacency_list, predecessor)){
           continue;
        }
        if(!uplift(nodes_list, predecessor)){
            predecessor->excess_flow = 0;
        }
    }

    return true;
}

int relabelToFront(vector<Node*> &nodes_list, vector<vector<pair<int, Node*>>> &adjacency_list){

    Node* destination_node = nodes_list[nodes_list.size() - 1];

    initialization(nodes_list, adjacency_list);

    while (true){

        bool unloaded = false;
        for(int i = 1; i < nodes_list.size() - 1; i++){
            Node* predecessor = nodes_list[i];
            if(unload(nodes_list,adjacency_list, predecessor)){
                unloaded = true;
                break;
            }
        }

        if(unloaded){
            continue;
        }

        break;
    }

    return destination_node->excess_flow;
}

void printMaximumFlow(int flow, ofstream &fout){
   fout << flow;
}