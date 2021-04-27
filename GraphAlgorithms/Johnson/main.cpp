#include "domain.h"
#include "edgeList.h"
#include "adjacencyList.h"
#include "dijkstra.h"
#include "bellmanFord.h"
#include "johnson.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream  fin("D:\\FacultyProjects\\GraphAlgorithms\\Johnson\\graf.txt");
ofstream fout("D:\\FacultyProjects\\GraphAlgorithms\\Johnson\\out.txt");

int main() {
    //ifstream  fin(argv[1]);
    //ofstream fout(argv[2]);
    int nodes, edges;

    fin >> nodes >> edges;

    vector<Node*> nodes_list(nodes + 1, NULL);
    for(int id = 0; id <= nodes; id++){
        Node *new_node = new Node();
        new_node -> id = id;
        nodes_list[id] = new_node;
    }

    vector<Edge*> edge_list;
    fromFileToEdgeList(edge_list, nodes_list, fin);
    printEdgeList(edge_list);

    vector<vector<pair<Node*,int>>> adjacency_list(nodes + 1);
    //fromEdgeListToAdjacencyList(adjacency_list, nodes_list, nodes, edge_list);
    //printAdjacencyList(adjacency_list, nodes);

    vector<vector<int>> distance_matrix(nodes + 1, vector<int>(nodes + 1));
    bool valid = johnson(distance_matrix, nodes_list, edge_list, adjacency_list);
    if(valid){
        printMinPathMatrix(edge_list, distance_matrix, fout);
    }
    else{
        fout << -1;
    }

    //dijkstra(nodes_list, adjacency_list, nodes_list[source]);
    //printMinimumPath(nodes_list, nodes_list[source],fout);

    //bool valid = bellmanFord(nodes_list, edge_list, nodes_list[source]);
    //printMinimumPathF(nodes_list, nodes_list[source], fout);


    for(auto node : nodes_list){
        delete node;
    }

    fin.close();
    fout.close();

    return 0;
}
