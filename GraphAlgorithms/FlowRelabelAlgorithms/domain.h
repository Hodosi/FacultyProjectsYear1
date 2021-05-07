//
// Created by Hodosi on 5/7/2021.
//

#ifndef FLOWRELABELALGORITHMS_DOMAIN_H
#define FLOWRELABELALGORITHMS_DOMAIN_H

using namespace std;

typedef struct{
    int id;
    int excess_flow;
    int height;
    int parent;
    bool visited;
} Node;

typedef struct {
    int weight;
    Node* predecessor;
    Node* successor;
} Edge;

#endif //FLOWRELABELALGORITHMS_DOMAIN_H
