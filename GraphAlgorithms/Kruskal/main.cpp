
#include "domain.h"
#include "edgeList.h"
#include "kruskal.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int main() {

    ifstream  fin("D:\\FacultyProjects\\GraphAlgorithms\\Kruskal\\graf.txt");
    ofstream fout("D:\\FacultyProjects\\GraphAlgorithms\\Kruskal\\out.txt");

    //ifstream  fin(argv[1]);
    //ofstream fout(argv[2]);

    int nodes, edges;

    fin >> nodes >> edges;

    vector<Node*> nodes_list(nodes, NULL);
    for(int id = 0; id < nodes; id++){
        Node *new_node = new Node();
        new_node -> id = id;
        nodes_list[id] = new_node;
    }

    vector<Edge*> edge_list;
    fromFileToEdgeList(edge_list, nodes_list, fin);
    printEdgeList(edge_list);

    vector<Edge*> span_tree = kruskal(nodes_list, edge_list);
    printSpanningTree(span_tree, fout);

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