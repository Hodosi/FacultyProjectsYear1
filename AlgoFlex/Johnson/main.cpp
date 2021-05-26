#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

ifstream  fin("D:\\FacultyProjects\\AlgoFlex\\Johnson\\in.txt");
ofstream fout("D:\\FacultyProjects\\AlgoFlex\\Johnson\\out.txt");

typedef struct{

    int id;
    int distance;
    int parent;
    bool visited;
} Node;

typedef struct {

    int weight;
    Node* predecessor;
    Node* successor;
} Edge;

int nr_nodes, nr_edges;
vector<Node*> node_list;
vector<Edge*> edge_list;
vector<vector<pair<Node*, int>>> adjacency_list;
vector<vector<int>> distance_matrix;

void fromFileToEdgeList(){

    int predecessor_id, successor_id, weight;
    while (fin >> predecessor_id >> successor_id >> weight){
        Edge *edge = new Edge();

        Node *predecessor, *successor;
        predecessor = node_list[predecessor_id + 1];
        successor = node_list[successor_id + 1];

        edge -> predecessor = predecessor;
        edge -> successor = successor;
        edge -> weight = weight;

        edge_list.push_back(edge);
    }
}

void printEdgeList(){

    for(auto edge : edge_list){
        cout << edge -> predecessor -> id << " " << edge -> successor -> id << " " << edge -> weight << "\n";
    }
}

void fromEdgeListToAdjacencyList(){

    for(auto edge : edge_list){
        Node *successor = edge->successor;
        Node *predecessor = edge -> predecessor;
        adjacency_list[predecessor -> id].push_back(make_pair(successor, edge->weight));
    }
}

void printAdjacencyList(){

    cout << "\n";
    int predecessor;
    for(predecessor = 0; predecessor <= nr_nodes; predecessor++){
        cout << predecessor << " : ";
        for(auto successor : adjacency_list[predecessor]){
            cout << successor.first -> id << " , " << successor.second << " ; ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void initialization(Node* source_node){

    for(auto node : node_list){
        node -> distance = INT16_MAX;
        node -> parent = -1;
        node->visited = false;
    }
    source_node -> distance = 0;
}

bool relax(Node* predecessor, Node* successor, int weight){
    if(successor -> distance > predecessor -> distance + weight){
        successor -> distance = predecessor -> distance + weight;
        successor -> parent = predecessor -> id;
        return true;
    }
    return false;
}

bool bellmanFord(Node *source_node){

    initialization(source_node);
    for(int i = 1; i < node_list.size(); i++){
        for(auto edge : edge_list){
            relax(edge -> predecessor, edge -> successor, edge -> weight);
        }
    }

    for(auto edge : edge_list){
        if(relax(edge -> predecessor, edge -> successor, edge -> weight)){
            return false;
        }
    }
    return true;
}

struct costumeCmp{

    bool operator()(const Node* predecessor, const Node* successor){
        return  (predecessor -> distance > successor -> distance);
    }
};

void dijkstra(Node *source_node){

    initialization(source_node);

    priority_queue<Node*, vector<Node*>, costumeCmp > p_queue;
    p_queue.push(source_node);

    while (!p_queue.empty()){
        auto predecessor = p_queue.top();
        p_queue.pop();
        if(predecessor->visited){
            continue;
        }
        for(auto successor : adjacency_list[predecessor -> id]){
            if(relax(predecessor, successor.first, successor.second)){
                p_queue.push(successor.first);
            }
        }
        predecessor->visited = true;
    }
}

bool johnson(){

    // add edges from new node (node 0) to all other nodes and mark its weight with 0
    for(int i = 1; i < node_list.size(); i++){
        Edge *edge = new Edge();

        Node *predecessor, *successor;
        predecessor = node_list[0];
        successor = node_list[i];

        edge -> predecessor = predecessor;
        edge -> successor = successor;
        edge -> weight = 0;

        edge_list.push_back(edge);
    }


    if (!bellmanFord(node_list[0])){
        return false;
    }

    // distance list from new node to others
    vector<int> distance_from_new_node(nr_nodes);
    for(auto node : node_list){
        distance_from_new_node[node->id] = node->distance;
    }

    // reweighting
    for(auto edge : edge_list){
        int predecessor_id = edge->predecessor->id;
        int successor_id = edge->successor->id;
        edge->weight = edge->weight + distance_from_new_node[predecessor_id] - distance_from_new_node[successor_id];
    }

    fromEdgeListToAdjacencyList();
    printAdjacencyList();

    // create distance matrix
    for(auto source_node : node_list){
        dijkstra(source_node);
        for(auto destination_node : node_list){
            int source_id = source_node->id;
            int destination_id = destination_node->id;
            int min_distance_from_source = destination_node -> distance;
            if(min_distance_from_source != INT16_MAX){
                distance_matrix[source_id][destination_id] = min_distance_from_source - distance_from_new_node[source_id] + distance_from_new_node[destination_id];
            }
            else{
                distance_matrix[source_id][destination_id] = min_distance_from_source;
            }
        }
    }

    return true;
}

void printMinPathMatrix(){

    for(auto edge : edge_list){
        if(edge->predecessor->id != 0){
            fout << edge -> predecessor -> id - 1 << " ";
            fout << edge -> successor -> id - 1 << " ";
            fout << edge -> weight << "\n";
        }
    }

    for(int i = 1; i < distance_matrix.size(); i++){
        for(int j = 1; j < distance_matrix[0].size(); j++){
            if(distance_matrix[i][j] == INT16_MAX){
                fout << "INF" << " ";
            }
            else{
                fout << distance_matrix[i][j] << " ";
            }
        }
        fout << "\n";
    }
}

int main() {
    fin >> nr_nodes >> nr_edges;

    node_list.resize(nr_nodes + 1, NULL);
    for(int id = 0; id <= nr_nodes; id++){
        Node *new_node = new Node();
        new_node -> id = id;
        node_list[id] = new_node;
    }

    fromFileToEdgeList();
    printEdgeList();

    adjacency_list.resize(nr_nodes + 1);

    distance_matrix.resize(nr_nodes + 1, vector<int>(nr_nodes + 1));
    bool valid = johnson();
    if(valid){
        printMinPathMatrix();
    }
    else{
        fout << -1;
    }

    for(auto node : node_list){
        delete node;
    }

    fin.close();
    fout.close();

    return 0;
}
