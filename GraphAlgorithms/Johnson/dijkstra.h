//
// Created by Hodosi on 3/29/2021.
//

#ifndef JOHNSON_DIJKSTRA_H
#define JOHNSON_DIJKSTRA_H

#include "domain.h"
#include <vector>
#include <fstream>

using namespace std;

void dijkstra(vector<Node*> &nodes_list, vector<vector<pair<Node*, int>>> &adjacency_list, Node *source_node);
void printMinimumPath(vector<Node*> &nodes_list, Node *source_node, ofstream &fout);


#endif //JOHNSON_DIJKSTRA_H
