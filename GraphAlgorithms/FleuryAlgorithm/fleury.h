//
// Created by Hodosi on 4/22/2021.
//

#ifndef FLEURYALGORITHM_FLEURY_H
#define FLEURYALGORITHM_FLEURY_H

#include <vector>
#include "domain.h"
#include "fstream"

using namespace std;

void fleury(vector<Node*> &nodes_list, vector<vector<Node*>> adjacency_list, vector<Node*> &euler_circuit);
void printEulerCircuit(vector<Node*> &euler_circuit, ofstream &fout);

#endif //FLEURYALGORITHM_FLEURY_H
