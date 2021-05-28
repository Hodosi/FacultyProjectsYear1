#include "chromaticNumber.h"

void dfsVisit(const vector<set<int>> &adjacency_set, vector<Node*> &node_list, Node* source, vector<bool> &visited_node){

    for(auto node : node_list){
        node->parent = -1;
        node->visited = false;
    }

    stack<int> dfs_stack;

    source->visited = true;
    visited_node[source->id] = true;
    dfs_stack.push(source->id);

    while (!dfs_stack.empty()){
        auto current_node_id = dfs_stack.top();
        dfs_stack.pop();

        for(auto successor_id : adjacency_set[current_node_id]){
            Node* successor = node_list[successor_id];
            if(!successor->visited){
                successor->visited = true;
                visited_node[successor_id] = true;
                dfs_stack.push(successor_id);
            }
        }
    }
}

pair<int, int> dfsNodesEdges(const vector<set<int>> &adjacency_set, vector<Node*> &node_list, Node* source){

    for(auto node : node_list){
        node->parent = -1;
        node->visited = false;
    }

    int nr_nodes = 0;
    int nr_edges = 0;

    stack<int> dfs_stack;

    source->visited = true;
    dfs_stack.push(source->id);

    while (!dfs_stack.empty()){
        auto current_node_id = dfs_stack.top();
        dfs_stack.pop();

        nr_nodes += 1;
        nr_edges += adjacency_set[current_node_id].size();

        for(auto successor_id : adjacency_set[current_node_id]){
            Node* successor = node_list[successor_id];
            if(!successor->visited){
                successor->visited = true;
                dfs_stack.push(successor_id);
            }
        }
    }

    return make_pair(nr_nodes, nr_edges);
}

bool isTree(const vector<set<int>>& adjacency_set, vector<Node*> node_list, Node* source){

    for(auto node : node_list){
        node->parent = -1;
        node->visited = false;
    }

    bool is_tree = true;
    queue<int> bfs_queue;

    source->visited = true;
    bfs_queue.push(source->id);

    while (!bfs_queue.empty()){
        auto current_node_id = bfs_queue.front();
        bfs_queue.pop();

        Node* predecessor = node_list[current_node_id];
        for(auto successor_id : adjacency_set[current_node_id]){
            if(predecessor->parent == successor_id){
                continue;
            }
            Node* successor = node_list[successor_id];
            if(successor->visited){
                is_tree = false;
                return is_tree;
            }
            successor->visited = true;
            successor->parent = current_node_id;
            bfs_queue.push(successor_id);
        }
    }

    return is_tree;
}


int isSpecial(const vector<set<int>> &adjacency_set, vector<Node*> node_list, Node* source){

    auto nodes_edges = dfsNodesEdges(adjacency_set, node_list, source);
    int nr_nodes = nodes_edges.first;
    int nr_edges = nodes_edges.second;

    if(nr_edges == 0) { // graph null
        return 1;
    }

    if(nr_edges == nr_nodes*(nr_nodes - 1)) { // graph complete
        return nr_nodes;
    }

    if(isTree(adjacency_set, node_list, source)){ //tree
        return 2;
    }

    return 0;
}

void subtract_adjacency_set(const vector<set<int>> &adjacency_set, vector<set<int>> &subtracted_adjacency_set, Node* x, Node* y){

}

void divide_adjacency_set(const vector<set<int>> &adjacency_set, vector<set<int>> &divided_adjacency_set, Node* x, Node* y){

}

int minimColors(const vector<set<int>> &adjacency_set, vector<Node*> node_list, Node* source){

    int minim_colors = isSpecial(adjacency_set, node_list, source);
    if(minim_colors > 0){
        return minim_colors;
    }

    int nr_nodes = node_list.size();
    int subtracted_minim_colors = INT32_MIN;
    int divided_minim_colors = INT32_MIN;
    vector<bool> visited_node(nr_nodes, false);

    vector<set<int>> subtracted_adjacency_set(nr_nodes);
    vector<set<int>> divided_adjacency_set(nr_nodes);

    Node* x = source;
    Node* y = node_list[*adjacency_set[source->id].begin()];
    subtract_adjacency_set(adjacency_set, subtracted_adjacency_set, x, y);
    divide_adjacency_set(adjacency_set, divided_adjacency_set, x, y);

    for(auto node : node_list){
        if(!visited_node[node->id]){
            dfsVisit(subtracted_adjacency_set, node_list, node, visited_node);
            subtracted_minim_colors = max(subtracted_minim_colors, minimColors(adjacency_set, node_list, node));
        }
    }

    divided_minim_colors = minimColors(divided_adjacency_set, node_list, source);

    return subtracted_minim_colors - divided_minim_colors;
}

int chromaticNumber(const vector<set<int>>& adjacency_set, vector<Node*> node_list) { // for a graph

    int minim_colors = INT32_MIN;
    int nr_nodes = node_list.size();
    vector<bool> visited_node(nr_nodes, false);
    for(auto node : node_list){
        if(!visited_node[node->id]){
            dfsVisit(adjacency_set, node_list, node, visited_node);
            minim_colors = max(minim_colors, minimColors(adjacency_set, node_list, node));
        }
    }

    return minim_colors;
}

void printChromaticNumber(int chromatic_number, ofstream &fout){
    fout << chromatic_number << "\n";
}