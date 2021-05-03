#include "domain.h"
#include "prufer.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    //ifstream  fin(argv[1]);
    //ofstream fout(argv[2]);

    ifstream  fin_code("D:\\FacultyProjects\\GraphAlgorithms\\Prufer\\graf_code.txt");
    ofstream fout_code("D:\\FacultyProjects\\GraphAlgorithms\\Prufer\\out_code.txt");

    int nodes;

    fin_code >> nodes;

    vector<Node*> nodes_list(nodes, NULL);
    for(int id = 0; id < nodes; id++){
        Node *new_node = new Node();
        new_node -> id = id;
        nodes_list[id] = new_node;
    }

    vector<int> coded_tree;

    pruferCode(nodes_list, coded_tree, fin_code);
    printPruferCode(coded_tree, fout_code);

    for(auto node : nodes_list){
        delete node;
    }

    fin_code.close();
    fout_code.close();

    ifstream  fin_decode("D:\\FacultyProjects\\GraphAlgorithms\\Prufer\\graf_decode.txt");
    ofstream fout_decode("D:\\FacultyProjects\\GraphAlgorithms\\Prufer\\out_decode.txt");

    fin_decode >> nodes;

    nodes_list.resize(nodes + 1, NULL);
    for(int id = 0; id < nodes + 1; id++){
        Node *new_node = new Node();
        new_node -> id = id;
        nodes_list[id] = new_node;
    }

    vector<int> decoded_tree;

    pruferDecode(nodes_list, decoded_tree, fin_decode);
    printPruferDecode(decoded_tree, fout_decode);



    for(auto node : nodes_list){
        delete node;
    }

    fin_decode.close();
    fout_decode.close();

    return 0;
}