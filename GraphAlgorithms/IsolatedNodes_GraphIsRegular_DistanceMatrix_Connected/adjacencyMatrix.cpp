//
// Created by Hodosi on 3/12/2021.
//

#include "adjacencyMatrix.h"

#include <iostream>
#include <vector>

using  namespace std;

int fromFileToAdjacencyMatrix(vector<vector<int>> &adjacency_matrix, int nodes, ifstream &fin){
    int predecessor, successor, cost, edges = 0;
    for(predecessor = 1; predecessor <= nodes; predecessor++){
        for(successor = 1; successor <= nodes; successor++){
            if(predecessor != successor){
                adjacency_matrix[predecessor][successor] = INT16_MAX;
            }
        }
    }

    while(fin >> predecessor >> successor >> cost){
        edges++;
        adjacency_matrix[predecessor][successor] = cost;
        adjacency_matrix[successor][predecessor] = cost;
    }

    return edges;
}


void printAdjacencyMatrix(vector<vector<int>> adjacency_matrix, int nodes){
    int i, j;
    for(i = 1; i <= nodes; i++){
        for(j = 1; j <= nodes; j++){
            cout << adjacency_matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}