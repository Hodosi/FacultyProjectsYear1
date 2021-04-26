//
// Created by Hodosi on 3/12/2021.
//

#include "adjacencyList.h"

#include <iostream>
#include <vector>

using  namespace std;

void fromAdjacencyMatrixToAdjacencyList(vector<vector<int>> &adjacency_list, vector<vector<int>> adjacency_matrix, int nodes){
    int predecessor, successor;
    for(predecessor = 1; predecessor <= nodes; predecessor++){
        for(successor = 1; successor <= nodes; successor++){
            if(adjacency_matrix[predecessor][successor] == 1){
                adjacency_list[predecessor].push_back(successor);
            }
        }
    }
}

void fromIncidenceMatrixToAdjacencyList(vector<vector<int>> &adjacency_list, vector<vector<int>> incidence_matrix, int nodes, int edges){
    int predecessor, successor, edge;
    for(predecessor = 1; predecessor <= nodes; predecessor++){
        for(edge = 1; edge <= edges; edge++){
            if(incidence_matrix[predecessor][edge] == 1){
                //top
                for(successor = predecessor - 1; successor >= 1; successor--){
                    if(incidence_matrix[successor][edge] == 1){
                        adjacency_list[predecessor].push_back(successor);
                    }
                }
                //down
                for(successor = predecessor + 1; successor <= nodes; successor++){
                    if(incidence_matrix[successor][edge] == 1){
                        adjacency_list[predecessor].push_back(successor);
                    }
                }
            }
        }
    }
}

void printAdjacencyList(vector<vector<int>> adjacency_list, int nodes){
    int predecessor;
    for(predecessor = 1; predecessor <= nodes; predecessor++) {
        cout << predecessor << " : ";
        for (auto successor : adjacency_list[predecessor]) {
            cout << successor << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}