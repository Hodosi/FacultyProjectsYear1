//
// Created by Hodosi on 5/6/2021.
//

#ifndef FORDFULKERSON_FROMFILETOADJACENCYMAP_H
#define FORDFULKERSON_FROMFILETOADJACENCYMAP_H

#include "domain.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

void fromFileToAdjacencyMap(vector<map<Edge*, int, costumeCmp>> &adjacency_map, vector<Node*> &nodes_list, vector<Edge*> &edge_list,  int nodes, ifstream &fin);
void printAdjacencyMap(vector<map<Edge*, int, costumeCmp>> &adjacency_map, int nodes);


#endif //FORDFULKERSON_FROMFILETOADJACENCYMAP_H
