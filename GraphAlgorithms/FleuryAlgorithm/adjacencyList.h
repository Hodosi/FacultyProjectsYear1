//
// Created by Hodosi on 4/22/2021.
//

#ifndef FLEURYALGORITHM_ADJACENCYLIST_H
#define FLEURYALGORITHM_ADJACENCYLIST_H

#include "domain.h"

#include <vector>
#include <string>

using namespace std;

void fromFileToAdjacencyList(vector<vector<Node*>> &, vector<Node*> &, int, ifstream &);
void printAdjacencyList(vector<vector<Node*>>, int);

#endif //FLEURYALGORITHM_ADJACENCYLIST_H
