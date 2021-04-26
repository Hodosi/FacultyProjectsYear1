//
// Created by Hodosi on 3/29/2021.
//

#ifndef JOHNSON_EDGELIST_H
#define JOHNSON_EDGELIST_H

#include "domain.h"
#include <fstream>
#include <vector>

using namespace std;
void fromFileToEdgeList(vector<Edge*> &edge_list , vector<Node*> &nodes_list, ifstream& fin);
void printEdgeList(vector<Edge*> &edge_list);

#endif //JOHNSON_EDGELIST_H
