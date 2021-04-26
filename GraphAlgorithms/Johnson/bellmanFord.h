//
// Created by Hodosi on 3/29/2021.
//

#ifndef JOHNSON_BELLMANFORD_H
#define JOHNSON_BELLMANFORD_H


#include "domain.h"
#include <vector>
#include <fstream>

using namespace std;

bool bellmanFord(vector<Node*> &nodes_list, vector<Edge*> &edge_list, Node *source_node);
void printMinimumPathF(vector<Node*> &nodes_list, Node *source_node, ofstream &fout);


#endif //JOHNSON_BELLMANFORD_H
