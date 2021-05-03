//
// Created by Hodosi on 4/12/2021.
//

#include "kruskal.h"
#include <set>
#include <algorithm>
#include <iostream>

struct costumeCmpId{
    bool operator()(const Node* node_1, const Node* node_2){
        return  (node_1 -> id < node_2 -> id);
    }
};

struct costumeCmpWeight{
    bool operator()(const Edge* edge_1, const Edge* edge_2){
        return  (edge_1 -> weight < edge_2 -> weight);
    }
};

int find_subset(vector<Node*> &nodes_list, Node* node){

    Node* current = node;
    while (current->parent != -1){
        current = nodes_list[current->parent];
    }

    return current->subset;
}

Node* find_subset_boss(vector<Node*> &nodes_list, Node* node){

    Node* current = node;
    while (current->parent != -1){
        current = nodes_list[current->parent];
    }

    return current;
}

void union_subsets(vector<Node*> &nodes_list, Node* predecessor, Node* successor){

    Node* x = find_subset_boss(nodes_list, predecessor);
    Node* y = find_subset_boss(nodes_list, successor);

    y->parent = x->id;
}



vector<Edge*> kruskal(vector<Node*> &nodes_list, vector<Edge*> &edge_list){
    vector<Edge*> span_tree;

    for(auto node : nodes_list){
        node->parent = -1;
        node->subset = node->id;
    }

    sort(edge_list.begin(), edge_list.end(), costumeCmpWeight());

    for(auto edge : edge_list){
       int x = find_subset(nodes_list, edge->predecessor);
       int y = find_subset(nodes_list, edge->successor);
       if(x != y){
           span_tree.push_back(edge);
           union_subsets(nodes_list, edge->predecessor, edge->successor);
       }
    }

    return span_tree;
}
void printSpanningTree(vector<Edge*> &span_tree,ofstream &fout){
    int min_weight;

    for(auto edge : span_tree){
        min_weight += edge->weight;
    }

    fout << min_weight << "\n";
    fout << span_tree.size() << "\n";

    for(auto edge : span_tree){
       fout << edge->predecessor->id << " ";
       fout << edge->successor->id << " ";
       fout << edge->weight << "\n";
    }
}
