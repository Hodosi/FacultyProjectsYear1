//
// Created by Hodosi on 3/27/2021.
//

#ifndef DIJKSTRA_DOMAIN_H
#define DIJKSTRA_DOMAIN_H

typedef struct{
    int id;
    long int distance;
    int parent;
    bool visited;
} Node;

typedef struct {
    int weight;
    Node* predecessor;
    Node* successor;
} Edge;

#endif //DIJKSTRA_DOMAIN_H
