#ifndef GRAPHCOLORING_DOMAIN_H
#define GRAPHCOLORING_DOMAIN_H

#include <vector>
using std::vector;

typedef struct {

    int id;
    int parent;
    bool visited;
    int color;
} Node;

#endif //GRAPHCOLORING_DOMAIN_H
