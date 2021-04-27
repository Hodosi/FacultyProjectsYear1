//
// Created by Hodosi on 4/22/2021.
//

#ifndef FLEURYALGORITHM_DOMAIN_H
#define FLEURYALGORITHM_DOMAIN_H

typedef struct{
    int id;
    long int distance;
    int parent;
} Node;

typedef struct {
    int weight;
    Node* predecessor;
    Node* successor;
} Edge;

#endif //FLEURYALGORITHM_DOMAIN_H
