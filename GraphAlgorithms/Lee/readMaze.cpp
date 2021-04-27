//
// Created by Hodosi on 3/16/2021.
//

#include <iostream>
#include <fstream>
#include "readMaze.h"

void readMaze(vector<vector<int>> &maze, pair<int, int> &start_point, pair<int, int> &end_point, int &rows, int &columns, ifstream &fin){
    string line;
    int line_index = 0, column_index = 0;
    while (getline(fin, line)){
        int line_size = line.size();
        vector<int> line_vector(line_size);
        maze.push_back(line_vector);
        column_index = 1;
        for(auto element : line){
            if(element == 'S'){
                start_point = make_pair(line_index, column_index);
                maze[line_index][column_index] = 0;
            }
            else if(element == 'F'){
                end_point = make_pair(line_index, column_index);
                maze[line_index][column_index] = 0;
            }
            else if (element == '1'){
                maze[line_index][column_index] = -1;
            } else{
                maze[line_index][column_index] = 0;
            }
            column_index++;
        }
        line_index++;
    }
    rows = line_index;
    columns = column_index;
}

void printMaze(vector<vector<int>> maze){
    for(auto line : maze){
        for(auto element : line){
            cout << element << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}