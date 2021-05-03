//
// Created by Hodosi on 5/3/2021.
//

#include "prufer.h"
#include <iostream>
#include <queue>

struct costumeCmp{
    bool operator()(const Node* node_1, const Node* node_2){
        return (node_1->id >= node_2->id);
    }
};

void pruferCode(vector<Node*> &node_list, vector<int> &coded_tree, ifstream &fin_code) {

    vector<int> child_list(node_list.size(), 0);

    coded_tree.clear();
    for(int i = 0; i < node_list.size(); i++){
        int _parent;
        fin_code >> _parent;
        node_list[i]->parent = _parent;
        cout << _parent << " ";
        if(_parent != -1){
            child_list[_parent]++;
        }
    }
    cout << "\n";

    priority_queue<Node*, vector<Node*>, costumeCmp> leaf_queue;

    for(int i = 0; i < child_list.size(); i++){
        if(child_list[i] == 0){
            leaf_queue.push(node_list[i]);
        }
    }

    while (!leaf_queue.empty()){
        Node* current_leaf = leaf_queue.top();
        leaf_queue.pop();
        coded_tree.push_back(current_leaf->parent);
        child_list[current_leaf->parent]--;
        if(child_list[current_leaf->parent] == 0){
            if(node_list[current_leaf->parent]->parent == -1){ //root
                break;
            }
            leaf_queue.push(node_list[current_leaf->parent]);
        }
    }
}

void printPruferCode(vector<int> &coded_tree, ofstream &fout_code) {
    fout_code << coded_tree.size() << "\n";
    for(auto _parent : coded_tree){
        fout_code << _parent << " ";
    }
}

void pruferDecode(vector<Node*> &node_list, vector<int> &decoded_tree, ifstream &fin_decode) {

    decoded_tree.clear();
    decoded_tree.resize(node_list.size(), -1);
    queue<int> coded_tree;
    vector<int> freq(node_list.size(), 0);

    for(int i = 0; i < node_list.size(); i++){
        int _x;
        fin_decode >> _x;
        cout << _x << " ";
        node_list[i]->parent = -1;
        coded_tree.push(_x);
        freq[_x]++;
    }
    cout << "\n";

    for(int i = 0; i < node_list.size() - 1; i++){
        int _parent = coded_tree.front();
        coded_tree.pop();
        for(int j = 0; j < node_list.size(); j++){
            if(freq[j] == 0){
                node_list[j]->parent = _parent;
                decoded_tree[j] = _parent;
                freq[j]++;
                break;
            }
        }
        freq[_parent]--;
    }
}

void printPruferDecode(vector<int> &decoded_tree, ofstream &fout_decode) {
    fout_decode << decoded_tree.size() << "\n";
    for(auto _parent : decoded_tree){
        fout_decode << _parent << " ";
    }
}
