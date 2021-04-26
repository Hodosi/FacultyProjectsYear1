//
// Created by Hodosi on 3/13/2021.
//

#ifndef DFS_ADJACENCYLIST_H
#define DFS_ADJACENCYLIST_H

#include "domain.h"

#include <vector>
#include <string>

using namespace std;

void fromFileToAdjacencyList(vector<vector<Node*>> &, vector<Node*> &, int, ifstream &);
void printAdjacencyList(vector<vector<Node*>>, int);

#endif //DFS_ADJACENCYLIST_H
