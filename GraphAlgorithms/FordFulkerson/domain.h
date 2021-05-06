//
// Created by Hodosi on 5/6/2021.
//

#ifndef FORDFULKERSON_DOMAIN_H
#define FORDFULKERSON_DOMAIN_H

#include <map>

using namespace std;

typedef struct{
    int id;
    int flow;
    int parent;
    bool visited;
} Node;

typedef struct {
    int weight;
    Node* predecessor;
    Node* successor;
} Edge;


struct costumeCmp {
    bool operator()(const Edge* edge_1, const Edge* edge_2) const{
        return edge_1->weight >= edge_2->weight;
    }
};


#endif //FORDFULKERSON_DOMAIN_H
