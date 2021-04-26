//
// Created by Hodosi on 3/12/2021.
//

#include "warshallAlgoritm.h"

void warshall(vector<vector<int>> &distance_matrix, vector<vector<int>> adjacency_matrix, int nodes){
    for(int i = 1; i <= nodes; i++){
        for(int j = 1; j <= nodes; j++){
            distance_matrix[i][j] = adjacency_matrix[i][j];
        }
    }

    for(int k = 1; k <= nodes; k++){
        for(int i = 1; i <= nodes; i++){
            for(int j = 1; j <= nodes; j++){
                distance_matrix[i][j] = min(distance_matrix[i][j], distance_matrix[i][k] + distance_matrix[k][j]);
            }
        }
    }

}