#ifndef EDMONDSKARP_FROMFILETOADJACENCYLIST_H
#define EDMONDSKARP_FROMFILETOADJACENCYLIST_H

#include "domain.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cout;
using std::ifstream;
using std::string;
using std::vector;
using std::pair;
using std::make_pair;

void fromFileToAdjacencyList(vector<vector<pair<Node*, int>>> &, vector<Node*> &, ifstream &);
void printAdjacencyList(vector<vector<pair<Node*, int>>> &, int);

#endif //EDMONDSKARP_FROMFILETOADJACENCYLIST_H
