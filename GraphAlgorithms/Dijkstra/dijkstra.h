//
// Created by Hodosi on 3/27/2021.
//

#ifndef DIJKSTRA_DIJKSTRA_H
#define DIJKSTRA_DIJKSTRA_H

#include "domain.h"
#include <vector>
#include <fstream>

using namespace std;

void dijkstra(vector<Node*> &nodes_list, vector<vector<pair<Node*, int>>> &adjacency_list, Node *source_node);
void printMinimumPath(vector<Node*> &nodes_list, Node *source_node, ofstream &fout);


#endif //DIJKSTRA_DIJKSTRA_H
