#include "adjacencyList.h"
#include "moore.h"

#include <iostream>
#include <fstream>

ifstream fin("D:\\FacultyProjects\\GraphAlgorithms\\MooreAlgorithm\\graf.txt");

int main() {
    int nodes;

    fin >> nodes;

    vector<Node*> nodes_list(nodes + 1, NULL);
    for(int id = 1; id <= nodes; id++){
        Node *new_node = new Node();
        new_node -> id = id;
        nodes_list[id] = new_node;
    }

    vector<vector<Node*>> adjacency_list(nodes + 1);

    fromFileToAdjacencyList(adjacency_list, nodes_list, nodes, fin);
    printAdjacencyList(adjacency_list, nodes);
    Node *source_node = nodes_list[1];
    Node *destination_node = nodes_list[4];
    moore(adjacency_list, source_node, destination_node, nodes_list, nodes);

    for(auto node : nodes_list){
        delete node;
    }


    return 0;
}
