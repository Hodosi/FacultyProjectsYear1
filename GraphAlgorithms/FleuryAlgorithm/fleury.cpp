//
// Created by Hodosi on 4/22/2021.
//

#include "fleury.h"

vector<bool> visited;

int dfsCount(vector<vector<Node*>>& adjacency_list, int current_node){

    int current_id = current_node;
    visited[current_id] = true;
    int count = 1;
    for(auto successor : adjacency_list[current_id]){
        if(!visited[successor->id]){
            count += dfsCount(adjacency_list, successor->id);
        }
    }

    return count;
}

void removeEdge(vector<vector<Node*>> &adjacency_list, int predecessor, int successor){

    int p_id = predecessor;
    int s_id = successor;

    int nr_neighbors = adjacency_list[p_id].size();
    for(int i = 0; i < nr_neighbors; i++){
        if(adjacency_list[p_id][i]->id == s_id){
            swap(adjacency_list[p_id][i], adjacency_list[p_id][nr_neighbors - 1]);
            adjacency_list[p_id].pop_back();
            break;
        }
    }

    nr_neighbors = adjacency_list[s_id].size();
    for(int i = 0; i < nr_neighbors; i++){
        if(adjacency_list[s_id][i]->id == p_id){
            swap(adjacency_list[s_id][i], adjacency_list[s_id][nr_neighbors - 1]);
            adjacency_list[s_id].pop_back();
            break;
        }
    }
}

bool isNotBridge(vector<vector<Node*>> &adjacency_list, int predecessor, int successor){

    int count_before_removing, count_after_removing;
    int nodes = adjacency_list.size();

    visited = vector<bool>(nodes, false);
    count_before_removing = dfsCount(adjacency_list, successor);

    removeEdge(adjacency_list, predecessor, successor);

    visited = vector<bool>(nodes, false);
    count_after_removing = dfsCount(adjacency_list, successor);

    if(count_before_removing == count_after_removing){
        return true;
    }

    return false;
}

void fleury(vector<Node*> &nodes_list, vector<vector<Node*>> adjacency_list, vector<Node*> &euler_circuit){

    int current_id = 0;
    euler_circuit.push_back(nodes_list[current_id]);

    bool circuit_found = false;
    while (! circuit_found){
        int old_id = current_id;

        if(adjacency_list[current_id].size() == 1){
            auto successor = adjacency_list[current_id][0];
            removeEdge(adjacency_list, nodes_list[current_id]->id, successor->id);

            euler_circuit.push_back(successor);
            current_id = successor->id;
            continue;
        }

        for(auto successor : adjacency_list[current_id]){
            if(isNotBridge(adjacency_list, current_id, successor->id)){
                euler_circuit.push_back(successor);
                current_id = successor->id;
                break;
            }
            else{ //add back removed edges
                adjacency_list[current_id].push_back(successor);
                adjacency_list[successor->id].push_back(nodes_list[current_id]);
            }
        }

        if(current_id == old_id){
            circuit_found = true;
        }
    }
}

void printEulerCircuit(vector<Node*> &euler_circuit, ofstream &fout){
    for(auto node : euler_circuit){
        fout << node->id << " ";
    }
}