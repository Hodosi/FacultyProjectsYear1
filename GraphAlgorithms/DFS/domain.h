//
// Created by Hodosi on 3/13/2021.
//

#ifndef DFS_DOMAIN_H
#define DFS_DOMAIN_H

#include <string>

using namespace std;

typedef struct{
    int id;
    string color;
    int time_start;
    int time_end;
    int parent;
} Node;

#endif //DFS_DOMAIN_H
