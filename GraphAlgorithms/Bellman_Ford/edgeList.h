//
// Created by Hodosi on 3/27/2021.
//

#ifndef BELLMAN_FORD_EDGELIST_H
#define BELLMAN_FORD_EDGELIST_H

#include "domain.h"
#include <fstream>
#include <vector>

using namespace std;
void fromFileToEdgeList(vector<Edge*> &edge_list , vector<Node*> &nodes_list, ifstream& fin);
void printEdgeList(vector<Edge*> &edge_list);

#endif //BELLMAN_FORD_EDGELIST_H
