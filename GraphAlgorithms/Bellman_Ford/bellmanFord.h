//
// Created by Hodosi on 3/27/2021.
//

#ifndef BELLMAN_FORD_BELLMANFORD_H
#define BELLMAN_FORD_BELLMANFORD_H

#include "domain.h"
#include <vector>
#include <fstream>

using namespace std;

bool bellmanFord(vector<Node*> &nodes_list, vector<Edge*> &edge_list, Node *source_node);
void printMinimumPath(vector<Node*> &nodes_list, Node *source_node, ofstream &fout);

#endif //BELLMAN_FORD_BELLMANFORD_H
