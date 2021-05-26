#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream fin("D:\\FacultyProjects\\GraphAlgorithms\\DFS\\in.txt");

typedef struct{
    int id;
    string color;
    int time_start;
    int time_end;
    int parent;
} Node;

vector<vector<Node*>> adjacency_list;
vector<Node*> node_list;
int nr_nodes;

void fromFileToAdjacencyList(){
    int predecessor_id, successor_id, cost;
    while (fin >> predecessor_id >> successor_id >> cost){
        Node *predecessor, *successor;
        predecessor = node_list[predecessor_id];
        successor = node_list[successor_id];

        adjacency_list[predecessor_id].push_back(successor);
        adjacency_list[successor_id].push_back(predecessor);
    }
}

void printAdjacencyList(){
    int predecessor;
    for(predecessor = 1; predecessor <= nr_nodes; predecessor++){
        cout << predecessor << " : ";
        for(auto successor : adjacency_list[predecessor]){
            cout << successor -> id << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int dfsVisit(Node *current_node, int time){
    time++;
    current_node -> time_start = time;
    current_node -> color = "grey";

    for(auto successor : adjacency_list[current_node -> id]){
        if(successor -> color == "white"){
            successor -> parent = current_node -> id;
            time = dfsVisit(successor, time);
        }
    }

    current_node -> color = "black";

    time++;
    current_node  -> time_end = time;

    cout << current_node -> id << " ";
    cout << current_node -> time_start << " " << current_node -> time_end << "\n";

    return time;
}

void recursivelyDfs(){
    int time;

    for(int i = 1; i <= nr_nodes; i++) {
        auto node = node_list[i];
        node -> color = "white";
        node -> time_start = -1;
        node -> time_end = -1;
        node -> parent = -1;
    }

    time = 0;

    for(int i = 1; i <= nr_nodes; i++) {
        auto node = node_list[i];
        if (node -> color == "white") {
            time = dfsVisit(node, time);
        }
    }
    cout << "\n";
}

int main() {
    fin >> nr_nodes;

    node_list.resize(nr_nodes + 1, NULL);

    for(int id = 1; id <= nr_nodes; id++){
        Node *new_node = new Node();
        new_node -> id = id;
        node_list[id] = new_node;
    }

    adjacency_list.resize(nr_nodes + 1);

    fromFileToAdjacencyList();
    printAdjacencyList();

    recursivelyDfs();

    for(auto node : node_list){
        delete node;
    }

    return 0;
}
