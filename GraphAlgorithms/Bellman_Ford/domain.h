//
// Created by Hodosi on 3/27/2021.
//

#ifndef BELLMAN_FORD_DOMAIN_H
#define BELLMAN_FORD_DOMAIN_H

typedef struct{
    int id;
    int distance;
    int parent;
} Node;

typedef struct {
    int weight;
    Node* predecessor;
    Node* successor;
} Edge;

#endif //BELLMAN_FORD_DOMAIN_H
