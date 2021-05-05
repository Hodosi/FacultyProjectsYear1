#include "prim.h"

#include <queue>
#include <set>
#include <iostream>

using namespace std;


void initialization(vector<Node*> &nodes_list, Node* source_node){
    for(auto node : nodes_list){
        node -> distance = INT16_MAX;
        node -> parent = -1;
        node -> visited = false;
    }
    source_node -> distance = 0;
}


struct costumeCmp{
    bool operator()(const Node* predecessor, const Node* successor){
        return  (predecessor -> distance >= successor -> distance);
    }
};

void prim(vector<Node*> &nodes_list, vector<vector<pair<Node*,int>>> &adjacency_list, Node *source_node){

    initialization(nodes_list, source_node);

    priority_queue<Node*, vector<Node*>, costumeCmp > p_queue;

    p_queue.push(source_node);

    set<int> extracted_from_queue;

    while (!p_queue.empty()){

        auto predecessor = p_queue.top();
        p_queue.pop();

        if(predecessor->visited){
           continue;
        }

        for(auto successor : adjacency_list[predecessor -> id]){
            if(successor.second < successor.first->distance){
                if(extracted_from_queue.find(successor.first -> id) == extracted_from_queue.end()) {
                    successor.first->parent = predecessor->id;
                    successor.first->distance = successor.second;
                }
                p_queue.push(successor.first);
            }
        }

        extracted_from_queue.insert(predecessor->id);
        predecessor->visited = true;

    }
}

void printSpanningTree(vector<Node*> &nodes_list, Node *source_node, ofstream &fout){

    int min_weight = 0;
    //priority_queue<pair<int, int>> tree_edges;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > tree_edges;

    for(auto node : nodes_list){
        int predecessor = node -> id;
        int successor = node->parent;
        if(predecessor < successor){
            tree_edges.push(make_pair(predecessor, successor));
        }
        else{
            tree_edges.push(make_pair(successor, predecessor));
        }
        min_weight += node->distance;
    }

    fout << min_weight << "\n";
    fout << nodes_list.size() - 1 << "\n";

    tree_edges.pop(); // popping the first element with key -1
    while(!tree_edges.empty()){
        auto edge = tree_edges.top();
        tree_edges.pop();
        fout << edge.first << " ";
        fout << edge.second << "\n";
    }
}