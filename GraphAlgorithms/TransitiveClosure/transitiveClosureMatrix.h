//
// Created by Hodosi on 3/16/2021.
//

#ifndef TRANSITIVECLOSURE_TRANSITIVECLOSUREMATRIX_H
#define TRANSITIVECLOSURE_TRANSITIVECLOSUREMATRIX_H

#include <vector>
#include <fstream>
using  namespace  std;

int fromFileToTransitiveClosureMatrix(vector<vector<int>> &, ifstream &, int);
void printTransitiveClosureMatrix(vector<vector<int>>, int);

#endif //TRANSITIVECLOSURE_TRANSITIVECLOSUREMATRIX_H
