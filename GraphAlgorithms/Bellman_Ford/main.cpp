#include "domain.h"
#include "edgeList.h"
#include "bellmanFord.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//ifstream  fin("D:\\FacultyProjects\\GraphAlgorithms\\Bellman_Ford\\graf.txt");
//ofstream fout("D:\\FacultyProjects\\GraphAlgorithms\\Bellman_Ford\\out.txt");


int main() {

    ifstream  fin("D:\\FacultyProjects\\GraphAlgorithms\\Bellman_Ford\\graf.txt");
    ofstream fout("D:\\FacultyProjects\\GraphAlgorithms\\Bellman_Ford\\out.txt");

    //ifstream  fin(argv[1]);
    //ofstream fout(argv[2]);

    int nodes, edges, source;

    fin >> nodes >> edges >> source;

    vector<Node*> nodes_list(nodes, NULL);
    for(int id = 0; id < nodes; id++){
        Node *new_node = new Node();
        new_node -> id = id;
        nodes_list[id] = new_node;
    }

    vector<Edge*> edge_list;
    fromFileToEdgeList(edge_list, nodes_list, fin);
    printEdgeList(edge_list);

    bool valid = bellmanFord(nodes_list, edge_list, nodes_list[source]);
    printMinimumPath(nodes_list, nodes_list[source], fout);

    for(auto edge : edge_list){
        delete edge;
    }

    for(auto node : nodes_list){
        delete node;
    }

    fin.close();
    fout.close();
    return 0;
}
