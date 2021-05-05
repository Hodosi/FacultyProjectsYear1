//
// Created by Hodosi on 5/3/2021.
//

#ifndef HUFFMAN_DOMAIN_H
#define HUFFMAN_DOMAIN_H

#include <string>

using std::string;

typedef struct {
    int id;
    int parent;
    int left_child;
    int right_child;
    char ch;
    int freq;
    string cod;
} Node;


#endif //HUFFMAN_DOMAIN_H
