//
// Created by Hodosi on 4/12/2021.
//

#ifndef KRUSKAL_DOMAIN_H
#define KRUSKAL_DOMAIN_H

typedef struct{
    int id;
    int distance;
    int parent;
    int subset;
} Node;

typedef struct {
    int weight;
    Node* predecessor;
    Node* successor;
} Edge;

#endif //KRUSKAL_DOMAIN_H
