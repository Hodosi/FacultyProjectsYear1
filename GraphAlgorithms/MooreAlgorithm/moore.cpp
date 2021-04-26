//
// Created by Hodosi on 3/15/2021.
//

#include "moore.h"
#include <iostream>
#include <queue>

void moore(vector<vector<Node*>> adjacency_list, Node *source_node, Node *destination_node, vector<Node*> &node_list, int nodes){
    vector<int> path_list(nodes + 1, INT16_MAX);
    vector<int> parent_list(nodes + 1, -1);

    path_list[source_node -> id] = 0;

    queue<Node*> Queue;

    Queue.push(source_node);

    while (!Queue.empty()){
        auto current_node = Queue.front();
        Queue.pop();
        for(auto successor : adjacency_list[current_node -> id]){
            if(path_list[successor -> id] == INT16_MAX){
                parent_list[successor -> id] = current_node -> id;
                path_list[successor -> id] = path_list[current_node -> id] + 1;
                Queue.push(successor);
            }
        }
    }

    //shortest path

    int current_path_position = path_list[destination_node -> id];

    vector<int> path(current_path_position + 1, 0);
    path[current_path_position] = destination_node -> id;

    while (current_path_position > 0){
        path[current_path_position - 1] = parent_list[path[current_path_position]];
        current_path_position--;
    }

    cout << "Path List:\n";
    for(int i = 1; i <= nodes; i++){
        cout << path_list[i] << " ";
    }
    cout << "\n";

    cout << "Parent List:\n";
    for(int i = 1; i <= nodes; i++){
        cout << parent_list[i] << " ";
    }
    cout << "\n";

    cout << "Path from node source node to destination node\n";
    for(int i = 1; i <= path.size() - 1; i++){
        cout << path[i] << " ";
    }
    cout << "\n";

}