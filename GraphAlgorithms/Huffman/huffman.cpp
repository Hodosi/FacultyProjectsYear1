//
// Created by Hodosi on 5/3/2021.
//

#include "huffman.h"
#include <map>
#include <queue>

struct costumeCmp{
    bool operator()(const Node* node_1, const Node* node_2){
        return node_1->freq > node_2->freq;
    }
};

string huffmanCode(vector<Node*> &node_list, vector<pair<char, int>> &coded_tree, ifstream &fin_code){

    string input_text{""};
    string  coded_text{""};
    getline(fin_code, input_text);

    map<char, int> freq_map;
    for(auto ch : input_text){
        auto iterator = freq_map.find(ch);
        if(iterator == freq_map.end()){
            freq_map.insert(make_pair(ch, 1));
        }
        else{
            iterator->second++;
        }
    }

    priority_queue<Node*, vector<Node*>, costumeCmp> p_queue;
    int _id = 0;
    for(auto ch_freq : freq_map){
        Node *new_node = new Node();
        new_node->freq = ch_freq.second;
        new_node->parent = -1;
        new_node->id = _id;
        _id++;
        new_node->ch = ch_freq.first;
        new_node->left_child = -1;
        new_node->right_child = -1;
        p_queue.push(new_node);
        coded_tree.push_back(ch_freq);
        node_list.push_back(new_node);
    }

    for(int i = 1; i < freq_map.size(); i++){
        Node *new_node = new Node();
        auto left_min = p_queue.top();
        p_queue.pop();
        auto right_min = p_queue.top();
        p_queue.pop();
        new_node->freq = left_min->freq + right_min->freq;
        new_node->parent = -1;
        new_node->id = _id;
        _id++;
        new_node->left_child = left_min->id;
        new_node->right_child = right_min->id;
        p_queue.push(new_node);
        node_list.push_back(new_node);
    }

    auto root = p_queue.top();
    p_queue.pop();

    queue<Node*> queue_bfs;
    queue_bfs.push(root);

    root->cod = "";

    while (!queue_bfs.empty()){
        auto current_node = queue_bfs.front();
        queue_bfs.pop();
        string current_cod = current_node->cod;

        if(current_node->left_child != -1){
            Node* left_child = node_list[current_node->left_child];
            left_child->cod = current_cod + "0";
            queue_bfs.push(left_child);
        }
        if(current_node->right_child != -1){
            Node* right_child = node_list[current_node->right_child];
            right_child->cod = current_cod + "1";
            queue_bfs.push(right_child);
        }
    }

    map<char, Node*> ch_cod_map;
    for(int i = 0; i < freq_map.size(); i++){
        ch_cod_map.insert(make_pair(node_list[i]->ch, node_list[i]));
    }

    for(auto ch : input_text){
        coded_text += ch_cod_map[ch]->cod;
    }

    return coded_text;
}

void printHuffmanCode(vector<pair<char, int>> &coded_tree, string cod, ofstream &fout_code){
    fout_code << coded_tree.size() << "\n";
    for(auto ch_freq : coded_tree){
        fout_code << ch_freq.first << " " << ch_freq.second << "\n";
    }
    fout_code << cod;
}

string huffmanDecode(vector<Node*> &node_list, vector<pair<char,int>> &decoded_tree, ifstream &fin_decode){
    return "yes";
}

void printHuffmanDecode(string decoded_text, ofstream &fout_decode) {

}

