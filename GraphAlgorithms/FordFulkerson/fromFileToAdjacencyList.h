//
// Created by Hodosi on 5/7/2021.
//

#ifndef FORDFULKERSON_FROMFILETOADJACENCYLIST_H
#define FORDFULKERSON_FROMFILETOADJACENCYLIST_H

#include "domain.h"

#include <vector>
#include <string>

using namespace std;

void fromFileToAdjacencyList(vector<vector<pair<int, Node*>>> &, vector<Node*> &, ifstream &);
void printAdjacencyList(vector<vector<pair<int, Node*>>>, int);

#endif //FORDFULKERSON_FROMFILETOADJACENCYLIST_H
