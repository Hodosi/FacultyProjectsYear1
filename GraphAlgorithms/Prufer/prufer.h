//
// Created by Hodosi on 5/3/2021.
//

#ifndef PRUFER_PRUFER_H
#define PRUFER_PRUFER_H

#include "domain.h"
#include <vector>
#include <fstream>

using namespace std;

void pruferCode(vector<Node*> &node_list, vector<int> &coded_tree, ifstream &fin_code);
void printPruferCode(vector<int> &coded_tree, ofstream &fout_code);
void pruferDecode(vector<Node*> &node_list, vector<int> &decoded_tree, ifstream &fin_decode);
void printPruferDecode(vector<int> &decoded_tree, ofstream &fout_decode);

#endif //PRUFER_PRUFER_H
