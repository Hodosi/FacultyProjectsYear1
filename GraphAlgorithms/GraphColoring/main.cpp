#include "domain.h"
#include "fromFileToAdjacencyList.h"
#include "graphColoring.h"

#include <fstream>
#include <vector>

using std::ifstream;
using std::ofstream;
using std::vector;

int main() {

    ifstream fin("D:\\FacultyProjects\\GraphAlgorithms\\GraphColoring\\graph_in.txt");
    ofstream fout("D:\\FacultyProjects\\GraphAlgorithms\\GraphColoring\\graph_out.txt");

    int nr_nodes, nr_edges;
    vector<Node*> node_list;

    fin >> nr_nodes >> nr_edges;

    for(int i = 0; i < nr_nodes; i++){

        Node* new_node = new Node();
        new_node->id = i;
        new_node->parent = -1;
        new_node->visited = false;
        node_list.push_back(new_node);
    }

    vector<vector<Node*>> adjacency_list(nr_nodes);
    fromFileToAdjacencyList(adjacency_list, node_list, fin);
    printAdjacencyList(adjacency_list, nr_nodes);

    int min_color = greedyColoring(adjacency_list, node_list);
    printColoredGraph(node_list, min_color, fout);

    for(int i = 0; i < nr_nodes; i++){
        delete node_list[i];
    }

    return 0;
}
