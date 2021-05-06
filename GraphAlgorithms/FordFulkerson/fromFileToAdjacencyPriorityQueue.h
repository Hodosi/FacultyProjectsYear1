//
// Created by Hodosi on 5/6/2021.
//

#ifndef FORDFULKERSON_FROMFILETOADJACENCYPRIORITYQUEUE_H
#define FORDFULKERSON_FROMFILETOADJACENCYPRIORITYQUEUE_H

#include "domain.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

void fromFileToAdjacencyPriorityQueue(vector<priority_queue<pair<int, Node*>>> &adjacency_p_queue, vector<Node*> &nodes_list, int nodes, ifstream &fin);
void printAdjacencyPriorityQueue(vector<priority_queue<pair<int, Node*>>> adjacency_p_queue, int nodes);

#endif //FORDFULKERSON_FROMFILETOADJACENCYPRIORITYQUEUE_H
