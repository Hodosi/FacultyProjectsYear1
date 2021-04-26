/*
1. Let be a file containing an undirected graph represented as:
the first line contains the number of nodes and the following rows
        the edges of the graph. Write a program in C / C ++ that reads the file
and represent / store a graph using the
adjacent, adjacent list and incident matrix.
To convert a graph from one form of representation to another.

File-> adjacency matrix-> adjacency list-> incidence matrix-> adjacency list-> adjacency matrix-> list.
*/

#include "adjacencyMatrix.h"
#include "adjacencyList.h"
#include "incidenceMatrix.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("D:\\FacultyProjects\\GraphAlgorithms\\RepresentationOfGraphs\\in.txt");

    int nodes, edges;
    fin >> nodes;

    //from file to adjacency matrix
    vector<vector<int>> adjacency_matrix(nodes + 1, vector<int>(nodes + 1, 0));
    edges = fromFileToAdjacencyMatrix(adjacency_matrix, fin);
    printAdjacencyMatrix(adjacency_matrix, nodes);

    //from adjacency matrix to adjacency list
    vector<vector<int>> adjacency_list(nodes + 1);
    fromAdjacencyMatrixToAdjacencyList(adjacency_list, adjacency_matrix, nodes);
    printAdjacencyList(adjacency_list, nodes);

    //from adjacency list to incidence matrix
    vector<vector<int>> incidence_matrix(nodes + 1, vector<int>(edges + 1, 0));
    fromAdjacencyListToIncidenceMatrix(incidence_matrix, adjacency_list, nodes);
    printIncidenceMatrix(incidence_matrix, nodes, edges);

    //from incidence matrix to adjacency list
    vector<vector<int>> new_adjacency_list(nodes + 1);
    fromIncidenceMatrixToAdjacencyList(new_adjacency_list, incidence_matrix, nodes, edges);
    printAdjacencyList(new_adjacency_list, nodes);

    //from adjacency list to adjacency matrix
    vector<vector<int>> new_adjacency_matrix(nodes + 1, vector<int>(nodes + 1, 0));
    fromAdjacencyListAdjacencyMatrix(new_adjacency_matrix, adjacency_list, nodes);
    printAdjacencyMatrix(new_adjacency_matrix, nodes);

    return 0;
}
