//
// Created by Hodosi on 3/29/2021.
//

#ifndef JOHNSON_JOHNSON_H
#define JOHNSON_JOHNSON_H

#include "domain.h"
#include "dijkstra.h"
#include "bellmanFord.h"
#include "adjacencyList.h"
#include <vector>
#include "fstream"

using namespace std;

bool johnson(vector<vector<int>> &distance_matrix, vector<Node*> nodes_list, vector<Edge*> edge_list, vector<vector<pair<Node*,int>>> adjacency_list);
void printMinPathMatrix(vector<Edge*> edge_list, vector<vector<int>> &distance_matrix, ofstream &fout);

#endif //JOHNSON_JOHNSON_H
