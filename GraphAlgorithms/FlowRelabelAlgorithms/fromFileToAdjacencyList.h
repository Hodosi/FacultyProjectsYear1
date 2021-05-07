//
// Created by Hodosi on 5/7/2021.
//

#ifndef FLOWRELABELALGORITHMS_FROMFILETOADJACENCYLIST_H
#define FLOWRELABELALGORITHMS_FROMFILETOADJACENCYLIST_H

#include "domain.h"

#include <vector>
#include <string>

using namespace std;

void fromFileToAdjacencyList(vector<vector<pair<int, Node*>>> &, vector<Node*> &, ifstream &);
void printAdjacencyList(vector<vector<pair<int, Node*>>>, int);

#endif //FLOWRELABELALGORITHMS_FROMFILETOADJACENCYLIST_H
