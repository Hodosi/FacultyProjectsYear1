#include "domain.h"
#include "huffman.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    //ifstream  fin(argv[1]);
    //ofstream fout(argv[2]);

    ifstream  fin_code("D:\\FacultyProjects\\GraphAlgorithms\\Huffman\\graf_code.txt");
    ofstream fout_code("D:\\FacultyProjects\\GraphAlgorithms\\Huffman\\out_code.txt");

    vector<Node*> nodes_list;
    vector<pair<char, int>> coded_tree;

    string cod = huffmanCode(nodes_list, coded_tree, fin_code);
    printHuffmanCode(coded_tree, cod, fout_code);

    for(auto node : nodes_list){
        delete node;
    }

    fin_code.close();
    fout_code.close();

    ifstream  fin_decode("D:\\FacultyProjects\\GraphAlgorithms\\Huffman\\graf_decode.txt");
    ofstream fout_decode("D:\\FacultyProjects\\GraphAlgorithms\\Huffman\\out_decode.txt");

    nodes_list.clear();
    vector<pair<char, int>> decoded_tree;

    string decoded_text = huffmanDecode(nodes_list, decoded_tree, fin_decode);
    printHuffmanDecode(decoded_text, fout_decode);

    for(auto node : nodes_list){
        delete node;
    }

    fin_decode.close();
    fout_decode.close();

    return 0;
}