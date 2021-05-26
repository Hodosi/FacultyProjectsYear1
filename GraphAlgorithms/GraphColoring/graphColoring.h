//
// Created by Hodosi on 5/15/2021.
//

#ifndef GRAPHCOLORING_GRAPHCOLORING_H
#define GRAPHCOLORING_GRAPHCOLORING_H

#include "domain.h"

#include <fstream>
#include <vector>
#include <string>
#include <queue>

using std::ofstream;
using std::vector;
using std::string;
using std::queue;
using std::max;

int greedyColoring(const vector<vector<Node*>>& adjacency_list, vector<Node*> &node_list);
void printColoredGraph(vector<Node*> &node_list, int min_color, ofstream &fout);

#endif //GRAPHCOLORING_GRAPHCOLORING_H
