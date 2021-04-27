//
// Created by Hodosi on 3/12/2021.
//

#include "BFS.h"
#include <iostream>
#include <queue>

void bfs(vector<vector<Node*>> adjacency_list, Node *source_node, vector<Node*> &node_list, int nodes){

    for(int i = 1; i <= nodes; i++) {
        auto node = node_list[i];
        node -> color = "white";
        node -> distance = INT16_MAX;
        node -> parent = -1;
    }

    source_node -> color = "grey";
    source_node -> distance = 0;
    source_node -> parent = -1;

    queue<Node*> Queue;

    Queue.push(source_node);

    while (!Queue.empty()){
        auto current_node = Queue.front();
        Queue.pop();
        for(auto successor : adjacency_list[current_node -> id]){
            if(successor -> color == "white"){
                successor -> color = "grey";
                successor -> distance = current_node -> distance + 1;
                successor -> parent = current_node -> id;
                Queue.push(successor);
            }
        }
        current_node -> color = "black";
        cout << current_node -> id << " " << current_node -> distance << "\n";
    }
}