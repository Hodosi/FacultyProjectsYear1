//
// Created by Hodosi on 5/6/2021.
//

#include "fromFileToAdjacencyPriorityQueue.h"


void fromFileToAdjacencyPriorityQueue(vector<priority_queue<pair<int, Node*>>> &adjacency_p_queue, vector<Node*> &nodes_list, int nodes, ifstream &fin){
    int predecessor_id, successor_id, weight;
    while (fin >> predecessor_id >> successor_id >> weight){
        Node *successor;
        successor = nodes_list[successor_id];
        adjacency_p_queue[predecessor_id].push(make_pair(weight, successor));
    }
}

void printAdjacencyPriorityQueue(vector<priority_queue<pair<int, Node*>>> adjacency_p_queue, int nodes){
    int predecessor;
    for(predecessor = 0; predecessor < nodes; predecessor++){
        cout << predecessor << " : ";
        while (!adjacency_p_queue[predecessor].empty()){
            auto weight_successor = adjacency_p_queue[predecessor].top();
            adjacency_p_queue[predecessor].pop();
            cout << weight_successor.second->id << " " << weight_successor.first << " ; ";
        }
        cout << "\n";
    }
    cout << "\n";
}