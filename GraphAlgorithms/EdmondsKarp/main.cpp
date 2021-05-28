#include "domain.h"
#include "fromFileToAdjacencyList.h"
#include "edmondsKarp.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using std::cout;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::pair;

int main() {
    //ifstream  fin(argv[1]);
    //ofstream fout(argv[2]);

    ifstream  fin("D:\\FacultyProjects\\GraphAlgorithms\\EdmondsKarp\\graf_in.txt");
    ofstream fout("D:\\FacultyProjects\\GraphAlgorithms\\EdmondsKarp\\graf_out.txt");

    int nr_nodes, nr_sources, nr_edges;

    fin >> nr_nodes >> nr_sources >>nr_edges;

    vector<Node*> nodes_list(nr_nodes + 1, NULL);
    for(int id = 0; id < nr_nodes + 1; id++){
        Node *new_node = new Node();
        new_node -> id = id;
        nodes_list[id] = new_node;
    }

    vector<vector<pair<Node*, int>>> adjacency_list(nr_nodes + 1);
    fromFileToAdjacencyList(adjacency_list, nodes_list, fin);
    printAdjacencyList(adjacency_list, nr_nodes);

    unsigned int start = clock();
    int flow = edmondsKarp(nodes_list, adjacency_list, nr_sources);
    cout << "Time: " << clock() - start;
    printMaximumFlow(adjacency_list, nr_nodes, flow, fout);

    for(auto node : nodes_list){
        delete node;
    }

    fin.close();
    fout.close();

    return 0;
}