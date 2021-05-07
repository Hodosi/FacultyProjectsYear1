#include "domain.h"
#include "edgeList.h"
#include "adjacencyList.h"
#include "dijkstra.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;


int main() {
    //ifstream  fin(argv[1]);
    //ofstream fout(argv[2]);

    ifstream  fin("D:\\FacultyProjects\\GraphAlgorithms\\Dijkstra\\graf.txt");
    ofstream fout("D:\\FacultyProjects\\GraphAlgorithms\\Dijkstra\\out.txt");
    int nodes, edges, source;

    fin >> nodes >> edges >> source;

    vector<Node*> nodes_list(nodes, NULL);
    for(int id = 0; id < nodes; id++){
        Node *new_node = new Node();
        new_node -> id = id;
        nodes_list[id] = new_node;
    }

    vector<vector<pair<Node*,int>>> adjacency_list(nodes);
    fromFileToAdjacencyList(adjacency_list, nodes_list, nodes, fin);
    printAdjacencyList(adjacency_list, nodes);

    unsigned int start = clock();
    dijkstra(nodes_list, adjacency_list, nodes_list[source]);
    cout << "Time: " << clock() - start;
    printMinimumPath(nodes_list, nodes_list[source],fout);


    for(auto node : nodes_list){
        delete node;
    }

    fin.close();
    fout.close();

    return 0;
}
