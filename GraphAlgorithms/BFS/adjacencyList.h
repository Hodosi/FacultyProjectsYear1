//
// Created by Hodosi on 3/12/2021.
//

#ifndef BFS_ADJACENCYLIST_H
#define BFS_ADJACENCYLIST_H

#include "domain.h"

#include <vector>
#include <string>

using namespace std;

void fromFileToAdjacencyList(vector<vector<Node*>> &, vector<Node*> &, int, ifstream &);
void printAdjacencyList(vector<vector<Node*>>, int);

#endif //BFS_ADJACENCYLIST_H
