//
// Created by Hodosi on 4/10/2021.
//

#ifndef PRIM_PRIM_H
#define PRIM_PRIM_H

#include "domain.h"
#include <vector>
#include <fstream>

using namespace std;

void prim(vector<Node*> &nodes_list, vector<vector<pair<Node*, int>>> &adjacency_list, Node *source_node);
void printSpanningTree(vector<Node*> &nodes_list, Node *source_node, ofstream &fout);

#endif //PRIM_PRIM_H
