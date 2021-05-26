#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

ifstream fin("D:\\FacultyProjects\\AlgoFlex\\TopologicalSorting\\in.txt");

typedef struct{

    int id;
    string color;
    int time_start;
    int time_end;
    int parent;
} Node;

vector<vector<Node*>> adjacency_list;
vector<Node*> node_list;
stack<Node*> sorted_nodes;
int nr_nodes, nr_edges;

void fromFileToAdjacencyList(){

    int predecessor_id, successor_id;
    while (fin >> predecessor_id >> successor_id){
        Node *successor;
        successor = node_list[successor_id];
        adjacency_list[predecessor_id].push_back(successor);
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

    sorted_nodes.push(current_node);

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

void topSort() {

    recursivelyDfs();

    cout << "\nSorted order:\n";
    while (!sorted_nodes.empty()){
        cout << sorted_nodes.top() -> id << " ";
        sorted_nodes.pop();
    }
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

    topSort();

    for(auto node : node_list){
        delete node;
    }

    return 0;
}
