//
// Created by Hodosi on 5/15/2021.
//

#include "graphColoring.h"

int assignColor(const vector<vector<Node*>>& adjacency_list, Node* source){
    if(source->color >= 0){
        return source->color;
    }

    int nr_nodes = adjacency_list.size();
    vector<bool> available(nr_nodes, true);
    for(auto successor : adjacency_list[source -> id]){
        if(successor->color >= 0){
            available[successor->color] = false;
        }
    }

    for(int color = 0; color < nr_nodes; color++){
        if(available[color]){
            return color;
        }
    }
    return nr_nodes;
}

int tryColor(const vector<vector<Node*>>& adjacency_list, vector<Node*> &node_list, Node* source){
    int nr_nodes = node_list.size();
    int max_color = 0;

    source->color = 0;
    source->visited = true;

    vector<bool> available(nr_nodes, false);
    queue<Node*> bfs_queue;

    bfs_queue.push(source);

    while (!bfs_queue.empty()){
        auto current_node = bfs_queue.front();
        bfs_queue.pop();
        for(auto successor : adjacency_list[current_node -> id]){
            if(!successor->visited) {
                int color_id = assignColor(adjacency_list, successor);
                if(color_id > max_color){
                    max_color = color_id;
                }
                successor->color = color_id;
                successor->visited = true;
                successor -> parent = current_node -> id;
                bfs_queue.push(successor);
            }
        }
    }

    return max_color;
}

int greedyColoring(const vector<vector<Node*>>& adjacency_list, vector<Node*> &node_list){
    int max_color = 0;
    for(auto node : node_list){
        node->parent = -1;
        node->color = -1;
        node->visited = false;
    }
    for(auto node : node_list){
        /*
        int crt_max_color = assignColor(adjacency_list,node);
        node->color = crt_max_color;
        max_color = max(max_color, crt_max_color);
        */
        if(!node->visited){
            int crt_max_color = tryColor(adjacency_list, node_list, node);
            max_color = max(max_color, crt_max_color);
        }
    }
    return max_color + 1;
}

void printColoredGraph(vector<Node*> &node_list, int min_color, ofstream &fout){
    fout << min_color << "\n";
    for(auto node : node_list){
        fout << node->color << " ";
    }
}
