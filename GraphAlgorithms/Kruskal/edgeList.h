//
// Created by Hodosi on 4/12/2021.
//

#ifndef KRUSKAL_EDGELIST_H
#define KRUSKAL_EDGELIST_H

#include "domain.h"
#include <fstream>
#include <vector>

using namespace std;
void fromFileToEdgeList(vector<Edge*> &edge_list , vector<Node*> &nodes_list, ifstream& fin);
void printEdgeList(vector<Edge*> &edge_list);

#endif //KRUSKAL_EDGELIST_H
