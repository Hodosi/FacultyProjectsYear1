//
// Created by Hodosi on 3/12/2021.
//

#ifndef ISOLATEDNODES_GRAPHISREGULAR_DISTANCEMATRIX_CONNECTED_ADJACENCYMATRIX_H
#define ISOLATEDNODES_GRAPHISREGULAR_DISTANCEMATRIX_CONNECTED_ADJACENCYMATRIX_H

#include <vector>
#include <fstream>
using  namespace  std;

int fromFileToAdjacencyMatrix(vector<vector<int>> &, int, ifstream &);
void printAdjacencyMatrix(vector<vector<int>>, int);

#endif //ISOLATEDNODES_GRAPHISREGULAR_DISTANCEMATRIX_CONNECTED_ADJACENCYMATRIX_H
