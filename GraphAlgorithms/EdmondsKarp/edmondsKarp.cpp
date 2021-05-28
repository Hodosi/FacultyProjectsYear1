#include "edmondsKarp.h"

bool bfs(vector<Node*> &nodes_list, vector<vector<pair<Node*, int>>> &adjacency_list) {

    int nr_nodes = nodes_list.size();
    Node* source_node = nodes_list[nr_nodes - 1];
    Node* destination_node = nodes_list[nr_nodes - 2];

    for(int i = 0; i < nr_nodes; i++){
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
        for(auto node_weight : adjacency_list[current_node -> id]){
            if(node_weight.second == 0){
                continue;
            }

            Node* successor = node_weight.first;
            if(!successor -> visited){
                successor -> visited = true;
                successor -> parent = current_node -> id;
                successor -> flow = min(current_node -> flow, node_weight.second);
                if(successor == destination_node){
                    return true;
                }
                queue_bfs.push(successor);
            }
        }
    }

    return false;
}


void reweightGraph(vector<Node*> &nodes_list, vector<vector<pair<Node*, int>>> &adjacency_list){

    int nr_nodes = nodes_list.size();
    Node* source_node = nodes_list[nr_nodes - 1];
    Node* destination_node = nodes_list[nr_nodes - 2];
    int increase_flow = destination_node->flow;

    Node* current_node = destination_node;

    while (current_node != source_node){
        Node* successor = current_node;
        Node* predecessor = nodes_list[current_node->parent];

        for(auto& node_weight : adjacency_list[predecessor->id]){
            if(node_weight.first == successor){
                node_weight.second -= increase_flow;
                break;
            }
        }

        for(auto& node_weight : adjacency_list[successor->id]){
            if(node_weight.first == predecessor){
                node_weight.second += increase_flow;
                break;
            }
        }

        current_node = predecessor;
    }
}

void completeEdges(vector<Node*> &nodes_list, vector<vector<pair<Node*, int>>> &adjacency_list, int nr_sources){

    int nr_nodes = nodes_list.size();
    Node* super_source_node = nodes_list[nr_nodes - 1];
    for(int i = 0; i < nr_sources; i++){
        Node* successor = nodes_list[i];
        adjacency_list[nr_nodes - 1].push_back(make_pair(successor, INT32_MAX));

        // residual graph
        adjacency_list[i].push_back(make_pair(super_source_node, 0));
    }
}

int edmondsKarp(vector<Node*> &nodes_list, vector<vector<pair<Node*, int>>> &adjacency_list, int nr_sources){

    completeEdges(nodes_list, adjacency_list, nr_sources);

    int nr_nodes = nodes_list.size();
    Node* destination_node = nodes_list[nr_nodes - 2];

    int maximum_flow = 0;
    while (bfs(nodes_list, adjacency_list)){
        int increase_flow = destination_node->flow;
        maximum_flow += increase_flow;
        reweightGraph(nodes_list, adjacency_list);
    }

    return maximum_flow;
}

void printMaximumFlow(vector<vector<pair<Node*, int>>> &adjacency_list, int source_id, int flow, ofstream &fout){

    fout << flow << "\n";

    for(auto& node_weight : adjacency_list[source_id]){
        fout << INT32_MAX - node_weight.second << " ";
    }
}