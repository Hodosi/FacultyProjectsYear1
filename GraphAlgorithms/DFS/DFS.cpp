//
// Created by Hodosi on 3/13/2021.
//

#include "DFS.h"

#include <iostream>
#include <stack>

void dfs(vector<vector<Node*>> adjacency_list, vector<Node*> &node_list, int nodes){
    int time;

    for(int i = 1; i <= nodes; i++) {
        auto node = node_list[i];
        node -> color = "white";
        node -> time_start = -1;
        node -> time_end = -1;
        node -> parent = -1;
    }

    stack<Node*> Stack;
    time = 0;

    for(int i = 1; i <= nodes; i++) {
        auto node = node_list[i];
        if (node -> color == "white") {
            node -> color = "grey";
            Stack.push(node);

            while (!Stack.empty()){
                auto current_node = Stack.top();
                Stack.pop();
                time++;
                current_node -> time_start = time;

                for(auto successor : adjacency_list[current_node -> id]){
                    if(successor -> color == "white"){
                        successor -> color = "grey";
                        successor -> parent = current_node -> id;
                        Stack.push(successor);
                    }
                }

                current_node -> color = "black";
                time++;
                current_node  -> time_end = time;

                cout << current_node -> id << " ";
                cout << current_node -> time_start << " " << current_node -> time_end << "\n";
            }
        }
    }
    cout << "\n";
}