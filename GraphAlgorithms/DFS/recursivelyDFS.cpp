//
// Created by Hodosi on 3/13/2021.
//

#include "recursivelyDFS.h"

#include <iostream>

using namespace std;

int dfsVisit(vector<vector<Node*>> adjacency_list, Node *current_node, int time){
    time++;
    current_node -> time_start = time;
    current_node -> color = "grey";

    for(auto successor : adjacency_list[current_node -> id]){
        if(successor -> color == "white"){
            successor -> parent = current_node -> id;
            time = dfsVisit(adjacency_list, successor, time);
        }
    }

    current_node -> color = "black";
    time++;
    current_node  -> time_end = time;

    cout << current_node -> id << " ";
    cout << current_node -> time_start << " " << current_node -> time_end << "\n";

    return time;
}

void recursivelyDfs(vector<vector<Node*>> adjacency_list, vector<Node*> &node_list, int nodes){
    int time;

    for(int i = 1; i <= nodes; i++) {
        auto node = node_list[i];
        node -> color = "white";
        node -> time_start = -1;
        node -> time_end = -1;
        node -> parent = -1;
    }

    time = 0;

    for(int i = 1; i <= nodes; i++) {
        auto node = node_list[i];
        if (node -> color == "white") {
            time = dfsVisit(adjacency_list, node, time);
        }
    }
    cout << "\n";
}
