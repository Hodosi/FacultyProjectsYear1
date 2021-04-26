//
// Created by Hodosi on 3/29/2021.
//

#ifndef JOHNSON_ADJACENCYLIST_H
#define JOHNSON_ADJACENCYLIST_H

#include "domain.h"

#include <vector>
#include <string>

using namespace std;

void fromEdgeListToAdjacencyList(vector<vector<pair<Node*,int>>> &, vector<Node*> &, int, vector<Edge*>);
void printAdjacencyList(vector<vector<pair<Node*,int>>>, int);

#endif //JOHNSON_ADJACENCYLIST_H
