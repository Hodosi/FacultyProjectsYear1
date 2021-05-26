#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream  fin("D:\\FacultyProjects\\AlgoFlex\\FordFulkerson\\in.txt");
ofstream fout("D:\\FacultyProjects\\AlgoFlex\\FordFulkerson\\out.txt");

typedef struct{

    int id;
    int flow;
    int parent;
    bool visited;
} Node;

int nr_nodes, nr_edges;
vector<Node*> node_list;
vector<vector<pair<int, Node*>>> adjacency_list;

void fromFileToAdjacencyList(){

    int predecessor_id, successor_id, weight;
    while (fin >> predecessor_id >> successor_id >> weight){
        Node *successor;
        successor = node_list[successor_id];
        adjacency_list[predecessor_id].push_back(make_pair(weight, successor));

        //residual graph
        Node *predecessor;
        predecessor = node_list[predecessor_id];
        adjacency_list[successor_id].push_back(make_pair(0, predecessor));
    }
}

void printAdjacencyList() {

    int predecessor;
    for(predecessor = 0; predecessor < nr_nodes; predecessor++){
        cout << predecessor << " : ";
        for(auto successor : adjacency_list[predecessor]){
            cout << successor.second -> id << " " << successor.first << " ; ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool bfs() {

    int nodes = node_list.size();
    Node* source_node = node_list[0];
    Node* destination_node = node_list[nodes - 1];

    for(int i = 0; i < nodes; i++){
        auto node = node_list[i];
        node -> visited = false;
        node -> parent = -1;
        node -> flow = INT32_MAX;
    }

    queue<Node*> queue_bfs;
    queue_bfs.push(source_node);
    source_node->visited = true;

    while (!queue_bfs.empty()){
        auto current_node = queue_bfs.front();
        queue_bfs.pop();
        for(auto weight_node : adjacency_list[current_node -> id]){
            if(weight_node.first == 0){
                continue;
            }

            Node* successor = weight_node.second;
            if(!successor -> visited){
                successor -> visited = true;
                successor -> parent = current_node -> id;
                successor -> flow = min(current_node -> flow, weight_node.first);
                if(successor == destination_node){
                    return true;
                }
                queue_bfs.push(successor);
            }
        }
    }

    return false;
}

void reweightGraph(){

    int nodes = node_list.size();
    Node* source_node = node_list[0];
    Node* destination_node = node_list[nodes - 1];
    int increase_flow = destination_node->flow;

    Node* current_node = destination_node;
    while (current_node != source_node){
        Node* successor = current_node;
        Node* predecessor = node_list[current_node->parent];

        for(auto& weight_node : adjacency_list[predecessor->id]){
            if(weight_node.second == successor){
                weight_node.first -= increase_flow;
                break;
            }
        }

        for(auto& weight_node : adjacency_list[successor->id]){
            if(weight_node.second == predecessor){
                weight_node.first += increase_flow;
                break;
            }
        }

        current_node = predecessor;
    }
}

int fordFulkerson(){

    int nodes = node_list.size();;
    Node* destination_node = node_list[nodes - 1];

    int maximum_flow = 0;
    while (bfs()){
        int increase_flow = destination_node->flow;
        maximum_flow += increase_flow;
        reweightGraph();
    }

    return maximum_flow;
}

void printMaximumFlow(int flow){
    fout << flow;
}

int main() {

    fin >> nr_nodes >> nr_edges;

    node_list.resize(nr_nodes, NULL);
    for(int id = 0; id < nr_nodes; id++){
        Node *new_node = new Node();
        new_node -> id = id;
        node_list[id] = new_node;
    }


    adjacency_list.resize(nr_nodes);
    fromFileToAdjacencyList();
    //printAdjacencyList();

    int flow = fordFulkerson();

    printMaximumFlow(flow);

    for(auto node : node_list){
        delete node;
    }

    fin.close();
    fout.close();

    return 0;
}
