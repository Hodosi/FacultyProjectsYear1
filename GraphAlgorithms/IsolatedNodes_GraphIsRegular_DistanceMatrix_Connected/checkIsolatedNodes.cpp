//
// Created by Hodosi on 3/12/2021.
//

#include "checkIsolatedNodes.h"
#include <iostream>

void isolatedNodes(vector<int> &isolated_nodes, vector<vector<int>> adjacency_matrix, int nodes){
    int predecessor, successor;
    bool isolated;
    for(predecessor = 1; predecessor <= nodes; predecessor++){
        isolated = true;
        for(successor = 1; successor <= nodes; successor++){
            if(adjacency_matrix[predecessor][successor] > 0){
                if(adjacency_matrix[predecessor][successor] < INT_MAX){
                    isolated = false;
                    break;
                }
            }
        }
        if(isolated){
            isolated_nodes.push_back(predecessor);
        }
    }
}

void printIsolatedNodes(vector<int> isolated_nodes){
    cout << "Isolated nodes: ";
    for(auto node : isolated_nodes){
        cout << node << " ";
    }
    cout << "\n\n";
}