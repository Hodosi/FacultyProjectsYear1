#include "domain.h"
//#include "fromFileToAdjacencyPriorityQueue.h"
#include "fromFileToAdjacencyMap.h"
#include "fordFulkerson.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    //ifstream  fin(argv[1]);
    //ofstream fout(argv[2]);

    ifstream  fin("D:\\FacultyProjects\\GraphAlgorithms\\FordFulkerson\\graf.txt");
    ofstream fout("D:\\FacultyProjects\\GraphAlgorithms\\FordFulkerson\\out.txt");

    int nodes, edges;

    fin >> nodes >> edges;

    vector<Node*> nodes_list(nodes, NULL);
    for(int id = 0; id < nodes; id++){
        Node *new_node = new Node();
        new_node -> id = id;
        nodes_list[id] = new_node;
    }

    vector<Edge*> edge_list;

    /*
    vector<priority_queue<pair<int, Node*>>> adjacency_p_queue(nodes);
    fromFileToAdjacencyPriorityQueue(adjacency_p_queue, nodes_list, nodes, fin);
    printAdjacencyPriorityQueue(adjacency_p_queue, nodes);
     */

    vector<map<Edge*, int, costumeCmp>> adjacency_map(nodes);
    fromFileToAdjacencyMap(adjacency_map, nodes_list, edge_list, nodes, fin);
    printAdjacencyMap(adjacency_map, nodes);

    int flow = fordFulkerson(nodes_list, adjacency_map);
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