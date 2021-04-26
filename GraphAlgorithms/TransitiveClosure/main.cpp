#include <iostream>

#include "transitiveClosureMatrix.h"

int main() {
    ifstream fin("D:\\FacultyProjects\\GraphAlgorithms\\TransitiveClosure\\in.txt");

    int nodes, edges;
    fin >> nodes;

    //from file to closure matrix
    vector<vector<int>> closure_matrix(nodes + 1, vector<int>(nodes + 1, 0));
    for(int i = 1; i <= nodes; i++){
        closure_matrix[i][i] = 1;
    }
    edges = fromFileToTransitiveClosureMatrix(closure_matrix, fin, nodes);
    printTransitiveClosureMatrix(closure_matrix, nodes);

    return 0;
}
