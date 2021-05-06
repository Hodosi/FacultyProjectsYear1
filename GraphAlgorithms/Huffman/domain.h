//
// Created by Hodosi on 5/3/2021.
//

#ifndef HUFFMAN_DOMAIN_H
#define HUFFMAN_DOMAIN_H

#include <string>

using std::string;

struct Node {
    int id;
    Node* parent;
    Node* left_child;
    Node* right_child;
    char ch;
    int freq;
    string cod;
};


#endif //HUFFMAN_DOMAIN_H
