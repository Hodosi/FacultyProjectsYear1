#include "domain.h"
#include "fromFileToAdjacencySet.h"
#include "chromaticNumber.h"

#include <fstream>
#include <vector>
#include <set>

using std::ifstream;
using std::ofstream;
using std::vector;
using std::set;

int main() {

    ifstream fin("D:\\FacultyProjects\\GraphAlgorithms\\GraphColoring\\graph_in.txt");
    ofstream fout("D:\\FacultyProjects\\GraphAlgorithms\\GraphColoring\\graph_out.txt");

    int nr_nodes, nr_edges;
    vector<Node*> node_list;
    vector<set<int>> adjacency_set;

    fin >> nr_nodes >> nr_edges;

    for(int i = 0; i < nr_nodes; i++){
        Node* new_node = new Node();
        new_node->id = i;
        new_node->parent = -1;
        new_node->visited = false;
        node_list.push_back(new_node);
    }

    adjacency_set.resize(nr_nodes);
    fromFileToAdjacencySet(adjacency_set, fin);
    printAdjacencySet(adjacency_set);

    int chromatic_number = chromaticNumber(adjacency_set, node_list);
    printChromaticNumber(chromatic_number, fout);

    for(int i = 0; i < nr_nodes; i++){
        delete node_list[i];
    }

    return 0;
}
