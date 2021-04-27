//
// Created by Hodosi on 4/12/2021.
//

#ifndef KRUSKAL_KRUSKAL_H
#define KRUSKAL_KRUSKAL_H

#include "domain.h"
#include <vector>
#include <fstream>

using namespace std;

vector<Edge*> kruskal(vector<Node*> &nodes_list, vector<Edge*> &edge_list);
void printSpanningTree(vector<Edge*> &span_tree,ofstream &fout);

#endif //KRUSKAL_KRUSKAL_H
