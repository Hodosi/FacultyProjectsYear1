/*
2. Let a graph be represented in a certain form (the graph is read from a file). This is solved:
a. to determine the isolated nodes in a graph.
b. to determine if the graph is regular.
c. for a graph represented with the adjacent matrix to determine the distance matrix.
d. for a graph represented by an adjacent matrix to determine if it is connected
 */

#include "adjacencyMatrix.h"
#include "checkIsolatedNodes.h"
#include "graphRegular.h"
#include "warshallAlgoritm.h"

#include <iostream>
#include <vector>

using namespace std;


int main() {
    ifstream fin("D:\\FacultyProjects\\GraphAlgorithms\\IsolatedNodes_GraphIsRegular_DistanceMatrix_Connected\\in.txt");

    int nodes, edges;
    fin >> nodes;

    //from file to adjacency matrix
    vector<vector<int>> adjacency_matrix(nodes + 1, vector<int>(nodes + 1, 0));
    edges = fromFileToAdjacencyMatrix(adjacency_matrix, nodes, fin);
    printAdjacencyMatrix(adjacency_matrix, nodes);

    //isolated nodes
    vector<int> isolated_nodes;
    isolatedNodes(isolated_nodes, adjacency_matrix, nodes);
    printIsolatedNodes(isolated_nodes);

    //is regular graph?
    bool regular = isRegular(adjacency_matrix, nodes);
    printRegular(regular);

    //distance matrix
    vector<vector<int>> distance_matrix(nodes + 1, vector<int>(nodes + 1, 0));
    warshall(distance_matrix, adjacency_matrix, nodes);
    printAdjacencyMatrix(distance_matrix, nodes);

    if(isolated_nodes.empty()){
        cout << "the graph is connected!\n";
    }
    else{
        cout << "the graph is not connected!\n";
    }

    return 0;
}
