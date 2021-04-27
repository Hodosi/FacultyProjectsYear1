#include <iostream>
#include <fstream>
#include <vector>

#include "readMaze.h"
#include "lee.h"

using namespace std;

ifstream fin("D:\\FacultyProjects\\GraphAlgorithms\\Lee\\maze1.txt");

int main() {
    int rows, columns;
    pair<int, int> start_point, end_point;
    vector<vector<int>> maze;

    readMaze(maze, start_point, end_point, rows, columns, fin);
    //printMaze(maze);
    cout << start_point.first << " " << start_point.second << "\n";
    cout << end_point.first << " " << end_point.second << "\n";
    cout << rows << " " << columns << "\n\n";

    lee(maze, start_point, end_point, rows, columns);
    //printMaze(maze);

    return 0;
}
