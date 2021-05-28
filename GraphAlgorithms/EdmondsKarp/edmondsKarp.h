#ifndef EDMONDSKARP_EDMONDSKARP_H
#define EDMONDSKARP_EDMONDSKARP_H

#include "domain.h"

#include <vector>
#include <fstream>
#include <stack>
#include <queue>
#include <algorithm>

using std::ofstream;
using std::vector;
using std::queue;
using std::pair;
using std::make_pair;
using std::min;

int edmondsKarp(vector<Node*> &nodes_list, vector<vector<pair<Node*, int>>> &adjacency_list, int nr_sources);
void printMaximumFlow(vector<vector<pair<Node*, int>>> &adjacency_list, int source_id, int flow, ofstream &fout);

#endif //EDMONDSKARP_EDMONDSKARP_H
