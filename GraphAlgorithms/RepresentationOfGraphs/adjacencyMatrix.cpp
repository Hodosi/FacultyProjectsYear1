//
// Created by Hodosi on 3/12/2021.
//

#include "adjacencyMatrix.h"

#include <iostream>
#include <vector>

using  namespace std;

int fromFileToAdjacencyMatrix(vector<vector<int>> &adjacency_matrix, ifstream &fin){
    int predecessor, successor, edges = 0;

    while(fin >> predecessor >> successor){
        edges++;
        adjacency_matrix[predecessor][successor] = 1;
        adjacency_matrix[successor][predecessor] = 1;
    }

    return edges;
}

void fromAdjacencyListAdjacencyMatrix(vector<vector<int>> &adjacency_matrix, vector<vector<int>> adjacency_list, int nodes){
    int predecessor;
    for(predecessor = 1; predecessor <= nodes; predecessor++){
        for(auto successor : adjacency_list[predecessor]){
            adjacency_matrix[predecessor][successor] = 1;
        }
    }

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
