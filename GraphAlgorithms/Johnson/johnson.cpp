//
// Created by Hodosi on 3/29/2021.
//

#include "johnson.h"

bool johnson(vector<vector<int>> &distance_matrix, vector<Node*> nodes_list, vector<Edge*> edge_list, vector<vector<pair<Node*,int>>> adjacency_list){

    // add edges from new node (node 0) to all other nodes and mark its weight with 0
    for(int i = 1; i < nodes_list.size(); i++){
        Edge *edge = new Edge();

        Node *predecessor, *successor;
        predecessor = nodes_list[0];
        successor = nodes_list[i];

        edge -> predecessor = predecessor;
        edge -> successor = successor;
        edge -> weight = 0;

        edge_list.push_back(edge);
    }


    if (bellmanFord(nodes_list, edge_list, nodes_list[0]) == false){
        return false;
    }

    // distance list from new node to others
    vector<int> distance_from_new_node(nodes_list.size());
    for(auto node : nodes_list){
        distance_from_new_node[node->id] = node->distance;
    }

    // reweighting
    for(auto edge : edge_list){
        int predecessor_id = edge->predecessor->id;
        int successor_id = edge->successor->id;
        edge->weight = edge->weight + distance_from_new_node[predecessor_id] - distance_from_new_node[successor_id];
    }

    fromEdgeListToAdjacencyList(adjacency_list, nodes_list, nodes_list.size() - 1, edge_list);
    printAdjacencyList(adjacency_list, nodes_list.size() - 1);

    // create distance matrix
    for(auto source_node : nodes_list){
        dijkstra(nodes_list, adjacency_list, source_node);
        for(auto destination_node : nodes_list){
            int source_id = source_node->id;
            int destination_id = destination_node->id;
            int min_distance_from_source = destination_node -> distance;
            if(min_distance_from_source != INT16_MAX){
                distance_matrix[source_id][destination_id] = min_distance_from_source - distance_from_new_node[source_id] + distance_from_new_node[destination_id];
            }
            else{
                distance_matrix[source_id][destination_id] = min_distance_from_source;
            }
        }
    }

    return true;
}

void printMinPathMatrix(vector<Edge*> edge_list, vector<vector<int>> &distance_matrix, ofstream &fout){
    for(auto edge : edge_list){
        if(edge->predecessor->id != 0){
            fout << edge -> predecessor -> id - 1 << " ";
            fout << edge -> successor -> id - 1 << " ";
            fout << edge -> weight << "\n";
        }
    }
    for(int i = 1; i < distance_matrix.size(); i++){
        for(int j = 1; j < distance_matrix[0].size(); j++){
            if(distance_matrix[i][j] == INT16_MAX){
                fout << "INF" << " ";
            }
            else{
                fout << distance_matrix[i][j] << " ";
            }
        }
        fout << "\n";
    }
}
