//
// Created by Hodosi on 4/10/2021.
//

#ifndef PRIM_ADJACENCYLIST_H
#define PRIM_ADJACENCYLIST_H

#include "domain.h"

#include <vector>
#include <string>

using namespace std;

void fromFileToAdjacencyList(vector<vector<pair<Node*,int>>> &, vector<Node*> &, int, ifstream &);
void printAdjacencyList(vector<vector<pair<Node*,int>>>, int);

#endif //PRIM_ADJACENCYLIST_H
