//
// Created by Hodosi on 5/15/2021.
//

#ifndef GRAPHCOLORING_CHROMATICNUMBER_H
#define GRAPHCOLORING_CHROMATICNUMBER_H

#include "domain.h"

#include <fstream>
#include <vector>
#include <set>
#include <stack>
#include <queue>

using std::ofstream;
using std::vector;
using std::set;
using std::stack;
using std::queue;
using std::max;
using std::pair;
using std::make_pair;

int chromaticNumber(const vector<set<int>>& adjacency_set, vector<Node*> node_list);
void printChromaticNumber(int chromatic_number, ofstream &fout);

#endif //GRAPHCOLORING_CHROMATICNUMBER_H
