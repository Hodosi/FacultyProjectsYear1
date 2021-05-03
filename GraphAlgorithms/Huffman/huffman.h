//
// Created by Hodosi on 5/3/2021.
//

#ifndef HUFFMAN_HUFFMAN_H
#define HUFFMAN_HUFFMAN_H

#include "domain.h"
#include <vector>
#include <fstream>
#include <string>

using namespace std;

string huffmanCode(vector<Node*> &node_list, vector<pair<char, int>> &coded_tree, ifstream &fin_code);
void printHuffmanCode(vector<pair<char, int>> &coded_tree, string cod, ofstream &fout_code);
string huffmanDecode(vector<Node*> &node_list, vector<pair<char,int>> &decoded_tree, ifstream &fin_decode);
void printHuffmanDecode(string decoded_text, ofstream &fout_decode);

#endif //HUFFMAN_HUFFMAN_H
