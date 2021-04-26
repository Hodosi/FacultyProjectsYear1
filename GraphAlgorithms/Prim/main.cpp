#include "domain.h"
#include "adjacencyList.h"
#include "prim.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;


//ifstream  fin("D:\\FacultyProjects\\GraphAlgorithms\\Dijkstra\\graf.txt");
//ofstream fout("D:\\FacultyProjects\\GraphAlgorithms\\Dijkstra\\out.txt");

int main() {
    //ifstream  fin(argv[1]);
    //ofstream fout(argv[2]);

    ifstream  fin("D:\\FacultyProjects\\GraphAlgorithms\\Prim\\graf.txt");
    ofstream fout("D:\\FacultyProjects\\GraphAlgorithms\\Prim\\out.txt");
    int nodes, edges;

    fin >> nodes >> edges;

    vector<Node*> nodes_list(nodes, NULL);
    for(int id = 0; id < nodes; id++){
        Node *new_node = new Node();
        new_node -> id = id;
        nodes_list[id] = new_node;
    }

    vector<vector<pair<Node*,int>>> adjacency_list(nodes);
    fromFileToAdjacencyList(adjacency_list, nodes_list, nodes, fin);
    printAdjacencyList(adjacency_list, nodes);

    prim(nodes_list, adjacency_list, nodes_list[0]);
    printSpanningTree(nodes_list, nodes_list[0],fout);


    for(auto node : nodes_list){
        delete node;
    }

    fin.close();
    fout.close();

    return 0;
}
