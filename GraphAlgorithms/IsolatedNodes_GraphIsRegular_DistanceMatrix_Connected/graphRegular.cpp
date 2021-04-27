//
// Created by Hodosi on 3/12/2021.
//

#include "graphRegular.h"
#include <iostream>

bool isRegular(vector<vector<int >> adiacency_matrix, int nodes){
    int predecessor = 1, successor, k_grade = 0, grade;

    for(successor = 1; successor <= nodes; successor++){
        if(adiacency_matrix[predecessor][successor] > 0){
            if(adiacency_matrix[predecessor][successor] < INT_MAX){
                k_grade++;
            }
        }
    }

    for(predecessor = 2; predecessor <= nodes; predecessor++){
        grade = 0;
        for(successor = 1; successor <= nodes; successor++){
            if(adiacency_matrix[predecessor][successor] > 0){
                if(adiacency_matrix[predecessor][successor] < INT_MAX){
                    grade++;
                }
            }
        }
        if(grade != k_grade){
            return false;
        }
    }

    return true;
}

void printRegular(bool regular){
    if(regular){
        cout << "the graph is regular\n";
    }
    else{
        cout << "the graph is not regular\n";
    }
    cout << "\n";
}