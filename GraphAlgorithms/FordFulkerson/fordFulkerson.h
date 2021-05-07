//
// Created by Hodosi on 5/6/2021.
//

#ifndef FORDFULKERSON_FORDFULKERSON_H
#define FORDFULKERSON_FORDFULKERSON_H

#include "domain.h"

#include <vector>
#include <fstream>

using namespace std;

int fordFulkerson(vector<Node*> &nodes_list, vector<vector<pair<int, Node*>>> &adjacency_list);
void printMaximumFlow(int flow, ofstream &fout);


#endif //FORDFULKERSON_FORDFULKERSON_H
