//
// Created by Hodosi on 3/29/2021.
//

#ifndef JOHNSON_DOMAIN_H
#define JOHNSON_DOMAIN_H

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

#endif //JOHNSON_DOMAIN_H
