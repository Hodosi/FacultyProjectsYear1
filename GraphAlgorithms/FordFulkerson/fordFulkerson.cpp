//
// Created by Hodosi on 5/6/2021.
//

#include "fordFulkerson.h"

#include <stack>
#include <algorithm>

bool dfsGreedy(vector<Node*> &nodes_list, vector<map<Edge*, int, costumeCmp> > &adjacency_map){

    int nodes = nodes_list.size();
    Node* source_node = nodes_list[0];
    Node* destination_node = nodes_list[nodes - 1];

    for(int i = 0; i < nodes; i++){
        auto node = nodes_list[i];
        node -> visited = false;
        node -> parent = -1;
        node -> flow = INT32_MAX;
    }

    stack<Node*> stack_dfs;

    stack_dfs.push(source_node);

    while (!stack_dfs.empty()){
        auto current_node = stack_dfs.top();
        stack_dfs.pop();
        for(auto edge_weight : adjacency_map[current_node -> id]){
            if(edge_weight.second == 0){
                continue;
            }
            Node* successor = edge_weight.first->successor;
            if(!successor -> visited){
                successor -> parent = current_node -> id;
                successor -> flow = min(current_node -> flow, edge_weight.second);
                if(successor == destination_node){
                    return true;
                }
                stack_dfs.push(successor);
            }
        }
        current_node->visited = true;
    }

    return false;
}


void reweightGraph(vector<Node*> &nodes_list, vector<map<Edge*, int, costumeCmp> > &adjacency_map){
    int nodes = nodes_list.size();
    Node* source_node = nodes_list[0];
    Node* destination_node = nodes_list[nodes - 1];
    int increase_flow = destination_node->flow;

    Node* current_node = destination_node;

    while (current_node != source_node){
        Node* successor = current_node;
        Node* predecessor = nodes_list[current_node->parent];

        for(auto& edge_weight : adjacency_map[predecessor->id]){
            if(edge_weight.first->predecessor == predecessor && edge_weight.first->successor == successor){
                edge_weight.first->weight -= increase_flow;
                edge_weight.second -= increase_flow;
                break;
            }
        }

        for(auto& edge_weight : adjacency_map[successor->id]){
            if(edge_weight.first->predecessor == successor && edge_weight.first->successor == predecessor){
                edge_weight.first->weight += increase_flow;
                edge_weight.second += increase_flow;
                break;
            }
        }


        current_node = predecessor;
    }
}

int fordFulkerson(vector<Node*> &nodes_list, vector<map<Edge*, int, costumeCmp> > &adjacency_map){

    int nodes = nodes_list.size();
    Node* source_node = nodes_list[0];
    Node* destination_node = nodes_list[nodes - 1];

    int maximum_flow = 0;
    while (dfsGreedy(nodes_list, adjacency_map)){
        int increase_flow = destination_node->flow;
        maximum_flow += increase_flow;
        reweightGraph(nodes_list, adjacency_map);
    }

    return maximum_flow;
}

void printMaximumFlow(int flow, ofstream &fout){
    fout << flow;
}