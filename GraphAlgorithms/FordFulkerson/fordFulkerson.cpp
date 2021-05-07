//
// Created by Hodosi on 5/6/2021.
//

#include "fordFulkerson.h"

#include <stack>
#include <queue>
#include <algorithm>

bool bfsGreedy(vector<Node*> &nodes_list, vector<vector<pair<int, Node*>>> &adjacency_list) {

    int nodes = nodes_list.size();
    Node* source_node = nodes_list[0];
    Node* destination_node = nodes_list[nodes - 1];

    for(int i = 0; i < nodes; i++){
        auto node = nodes_list[i];
        node -> visited = false;
        node -> parent = -1;
        node -> flow = INT32_MAX;
    }

    source_node->visited = true;

    queue<Node*> queue_bfs;

    queue_bfs.push(source_node);

    while (!queue_bfs.empty()){
        auto current_node = queue_bfs.front();
        queue_bfs.pop();
        for(auto weight_node : adjacency_list[current_node -> id]){
            if(weight_node.first == 0){
                continue;
            }
            Node* successor = weight_node.second;
            if(!successor -> visited){
                successor -> visited = true;
                successor -> parent = current_node -> id;
                successor -> flow = min(current_node -> flow, weight_node.first);
                if(successor == destination_node){
                    return true;
                }
                queue_bfs.push(successor);
            }
        }
    }

    return false;
}

bool dfsGreedy(vector<Node*> &nodes_list, vector<vector<pair<int, Node*>>> &adjacency_list){

    int nodes = nodes_list.size();
    Node* source_node = nodes_list[0];
    Node* destination_node = nodes_list[nodes - 1];

    for(int i = 0; i < nodes; i++){
        auto node = nodes_list[i];
        node -> visited = false;
        node -> parent = -1;
        node -> flow = INT32_MAX;
    }

    source_node->visited = true;

    stack<Node*> stack_dfs;

    stack_dfs.push(source_node);

    while (!stack_dfs.empty()){
        auto current_node = stack_dfs.top();
        stack_dfs.pop();
        for(auto weight_node : adjacency_list[current_node -> id]){
            if(weight_node.first == 0){
                continue;
            }
            Node* successor = weight_node.second;
            if(!successor -> visited){
                successor -> visited = true;
                successor -> parent = current_node -> id;
                successor -> flow = min(current_node -> flow, weight_node.first);
                if(successor == destination_node){
                    return true;
                }
                stack_dfs.push(successor);
            }
        }
    }

    return false;
}


void reweightGraph(vector<Node*> &nodes_list, vector<vector<pair<int, Node*>>> &adjacency_list){

    int nodes = nodes_list.size();
    Node* source_node = nodes_list[0];
    Node* destination_node = nodes_list[nodes - 1];
    int increase_flow = destination_node->flow;

    Node* current_node = destination_node;

    while (current_node != source_node){
        Node* successor = current_node;
        Node* predecessor = nodes_list[current_node->parent];

        for(auto& weight_node : adjacency_list[predecessor->id]){
            if(weight_node.second == successor){
                weight_node.first -= increase_flow;
                break;
            }
        }

        for(auto& weight_node : adjacency_list[successor->id]){
            if(weight_node.second == predecessor){
                weight_node.first += increase_flow;
                break;
            }
        }

        /*
        for(int i = 0 ; adjacency_list[predecessor->id].size(); i++){
            auto& weight_node = adjacency_list[predecessor->id][i];
            if(weight_node.second == successor){
                weight_node.first -= increase_flow;
                while (i < adjacency_list[predecessor->id].size() - 1){
                     int precedent_weight = adjacency_list[predecessor->id][i].first;
                     int next_weight = adjacency_list[predecessor->id][i + 1].first;
                     if(precedent_weight < next_weight){
                         swap(adjacency_list[predecessor->id][i], adjacency_list[predecessor->id][i + 1]);
                     }
                     else{
                         break;
                     }
                     i++;
                }
                break;
            }
        }

        for(int i = 0; adjacency_list[successor->id].size(); i++){
            auto& weight_node = adjacency_list[successor->id][i];
            if(weight_node.second == predecessor){
                weight_node.first += increase_flow;
                while (i > 0){
                    int precedent_weight = adjacency_list[successor->id][i - 1].first;
                    int next_weight = adjacency_list[successor->id][i].first;
                    if(precedent_weight < next_weight){
                        swap(adjacency_list[successor->id][i - 1], adjacency_list[successor->id][i]);
                    }
                    else{
                        break;
                    }
                    i--;
                }
                break;
            }
        }
        */

        current_node = predecessor;
    }
}

int fordFulkerson(vector<Node*> &nodes_list, vector<vector<pair<int, Node*>>> &adjacency_list){

    /*
    for(auto& successor_list : adjacency_list){
        sort(successor_list.begin(), successor_list.end(), greater<pair<int, Node*>>());
    }
    */

    int nodes = nodes_list.size();
    Node* source_node = nodes_list[0];
    Node* destination_node = nodes_list[nodes - 1];

    int maximum_flow = 0;
    while (bfsGreedy(nodes_list, adjacency_list)){
        int increase_flow = destination_node->flow;
        maximum_flow += increase_flow;
        reweightGraph(nodes_list, adjacency_list);
    }

    return maximum_flow;
}

void printMaximumFlow(int flow, ofstream &fout){
    fout << flow;
}