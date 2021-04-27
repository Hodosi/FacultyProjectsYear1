//
// Created by Hodosi on 3/15/2021.
//

#ifndef MOOREALGORITHM_ADJACENCYLIST_H
#define MOOREALGORITHM_ADJACENCYLIST_H

#include "domain.h"

#include <vector>
#include <string>

using namespace std;

void fromFileToAdjacencyList(vector<vector<Node*>> &, vector<Node*> &, int, ifstream &);
void printAdjacencyList(vector<vector<Node*>>, int);

#endif //MOOREALGORITHM_ADJACENCYLIST_H
