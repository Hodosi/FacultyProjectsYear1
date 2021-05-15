//
// Created by Hodosi on 5/15/2021.
//

#include "fromFileToAdjacencySet.h"

void fromFileToAdjacencySet(vector<set<int>>& adjacency_set, ifstream &fin) {
    int predecessor_id, successor_id;
    while (fin >> predecessor_id >> successor_id){

        adjacency_set[predecessor_id].insert(successor_id);
        adjacency_set[successor_id].insert(predecessor_id);
    }
}

void printAdjacencySet(vector<set<int>>& adjacency_set){
    int predecessor_id = 0;
    for(const auto& neighborhood : adjacency_set ){
        cout << predecessor_id << " : ";

        for(const auto& successor_id : neighborhood) {
            cout << successor_id << " ";
        }

        cout << "\n";

        predecessor_id += 1;
    }
    cout << "\n";
}