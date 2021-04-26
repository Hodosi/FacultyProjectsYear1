//
// Created by Hodosi on 3/12/2021.
//

#include "incidenceMatrix.h"

#include <iostream>
#include <vector>

using  namespace std;

void fromAdjacencyListToIncidenceMatrix(vector<vector<int>> &incidence_matrix, vector<vector<int>> adjacency_list, int nodes){
    int predecessor;
    int edge  = 1;
    for(predecessor = 1; predecessor <= nodes; predecessor++){
        for(auto successor : adjacency_list[predecessor]){
            if(predecessor < successor){
                incidence_matrix[predecessor][edge] = 1;
                incidence_matrix[successor][edge] = 1;
                edge++;
            }
        }
    }
}

void printIncidenceMatrix(vector<vector<int>> incidence_matrix, int nodes, int edges){
    int i, j;
    for(i = 1; i <= nodes; i++){
        for(j = 1; j <= edges; j++){
            cout << incidence_matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
