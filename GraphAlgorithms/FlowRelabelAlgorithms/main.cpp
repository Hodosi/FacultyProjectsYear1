#include "domain.h"
#include "fromFileToAdjacencyList.h"
#include "flowRelabel.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <ctime>

using namespace std;


int main() {
    //ifstream  fin(argv[1]);
    //ofstream fout(argv[2]);

    ifstream  fin("D:\\FacultyProjects\\GraphAlgorithms\\FlowRelabelAlgorithms\\graf.txt");
    ofstream fout("D:\\FacultyProjects\\GraphAlgorithms\\FlowRelabelAlgorithms\\out.txt");

    int nodes, edges;

    fin >> nodes >> edges;

    vector<Node*> nodes_list(nodes, NULL);
    for(int id = 0; id < nodes; id++){
        Node *new_node = new Node();
        new_node -> id = id;
        nodes_list[id] = new_node;
    }

    vector<Edge*> edge_list;


    vector<vector<pair<int, Node*>>> adjacency_list(nodes);
    fromFileToAdjacencyList(adjacency_list, nodes_list, fin);
    printAdjacencyList(adjacency_list, nodes);

    unsigned int start = clock();
    //int flow = preflowPush(nodes_list, adjacency_list);
    int flow = relabelToFront(nodes_list, adjacency_list);
    cout << "Time: " << clock() - start;
    printMaximumFlow(flow, fout);

    for(auto node : nodes_list){
        delete node;
    }

    for(auto edge : edge_list){
        delete edge;
    }

    fin.close();
    fout.close();

    return 0;
}