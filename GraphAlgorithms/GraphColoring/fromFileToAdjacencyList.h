//
// Created by Hodosi on 5/22/2021.
//

#ifndef GRAPHCOLORING_FROMFILETOADJACENCYLIST_H
#define GRAPHCOLORING_FROMFILETOADJACENCYLIST_H

#include "domain.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::ifstream;
using std::cout;
using std::vector;
using std::string;

void fromFileToAdjacencyList(vector<vector<Node*>>& adjacency_set, vector<Node*> &nodes_list,  ifstream &fin);
void printAdjacencyList(vector<vector<Node*>>& adjacency_set, int nr_nodes);


#endif //GRAPHCOLORING_FROMFILETOADJACENCYLIST_H
