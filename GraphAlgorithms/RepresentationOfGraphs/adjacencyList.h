//
// Created by Hodosi on 3/12/2021.
//

#ifndef REPRESENTATIONOFGRAPHS_ADJACENCYLIST_H
#define REPRESENTATIONOFGRAPHS_ADJACENCYLIST_H

#include <vector>
using  namespace  std;

void fromAdjacencyMatrixToAdjacencyList(vector<vector<int>> &, vector<vector<int>>, int);
void fromIncidenceMatrixToAdjacencyList(vector<vector<int>> &, vector<vector<int>>, int, int);
void printAdjacencyList(vector<vector<int>>, int);

#endif //REPRESENTATIONOFGRAPHS_ADJACENCYLIST_H
