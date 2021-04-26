//
// Created by Hodosi on 3/27/2021.
//

#ifndef DIJKSTRA_ADJACENCYLIST_H
#define DIJKSTRA_ADJACENCYLIST_H

#include "domain.h"

#include <vector>
#include <string>

using namespace std;

void fromFileToAdjacencyList(vector<vector<pair<Node*,int>>> &, vector<Node*> &, int, ifstream &);
void printAdjacencyList(vector<vector<pair<Node*,int>>>, int);

#endif //DIJKSTRA_ADJACENCYLIST_H
