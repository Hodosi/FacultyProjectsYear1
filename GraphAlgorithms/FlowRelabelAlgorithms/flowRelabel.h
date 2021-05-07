//
// Created by Hodosi on 5/7/2021.
//

#ifndef FLOWRELABELALGORITHMS_FLOWRELABEL_H
#define FLOWRELABELALGORITHMS_FLOWRELABEL_H

#include "domain.h"

#include <vector>
#include <fstream>

using namespace std;

int preflowPush(vector<Node*> &nodes_list, vector<vector<pair<int, Node*>>> &adjacency_list);
int relabelToFront(vector<Node*> &nodes_list, vector<vector<pair<int, Node*>>> &adjacency_list);
void printMaximumFlow(int flow, ofstream &fout);


#endif //FLOWRELABELALGORITHMS_FLOWRELABEL_H
