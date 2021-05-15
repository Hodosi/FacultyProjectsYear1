//
// Created by Hodosi on 5/15/2021.
//

#ifndef GRAPHCOLORING_FROMFILETOADJACENCYSET_H
#define GRAPHCOLORING_FROMFILETOADJACENCYSET_H

#include "domain.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>

using std::ifstream;
using std::cout;
using std::vector;
using std::set;
using std::string;

void fromFileToAdjacencySet(vector<set<int>>& adjacency_set, ifstream &fin);
void printAdjacencySet(vector<set<int>>& adjacency_set);

#endif //GRAPHCOLORING_FROMFILETOADJACENCYSET_H
