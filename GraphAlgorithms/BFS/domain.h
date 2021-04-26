//
// Created by Hodosi on 3/12/2021.
//

#ifndef BFS_DOMAIN_H
#define BFS_DOMAIN_H

#include <string>

using namespace std;

typedef struct{
    int id;
    string color;
    int distance;
    int parent;
} Node;

#endif //BFS_DOMAIN_H
