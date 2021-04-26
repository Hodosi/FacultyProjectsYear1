//
// Created by Hodosi on 3/12/2021.
//

#ifndef REPRESENTATIONOFGRAPHS_ADJACENCYMATRIX_H
#define REPRESENTATIONOFGRAPHS_ADJACENCYMATRIX_H

#include <vector>
#include <fstream>
using  namespace  std;

int fromFileToAdjacencyMatrix(vector<vector<int>> &, ifstream &);
void fromAdjacencyListAdjacencyMatrix(vector<vector<int>> &, vector<vector<int>>, int);
void printAdjacencyMatrix(vector<vector<int>>, int);

#endif //REPRESENTATIONOFGRAPHS_ADJACENCYMATRIX_H
