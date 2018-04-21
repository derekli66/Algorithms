//
//  main.cpp
//  ArrayElementArrange
//
//  Created by LEE CHIEN-MING on 21/04/2018.
//  Copyright © 2018 LEE CHIEN-MING. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void CreateCombination(const vector<int>& arrA, const vector<int>& arrB, int idxA, int idxB, vector<int> &currentArray, vector<vector<int>>& container)
{
    if (arrA.size() == idxA && arrB.size() == idxB) {
        container.push_back(currentArray);
        return;
    }
    
    if (arrA.size() > idxA) {
        vector<int> nextArray {currentArray};
        nextArray.push_back(arrA[idxA]);
        CreateCombination(arrA, arrB, idxA+1, idxB, nextArray, container);
    }
    
    if (arrB.size() > idxB) {
        vector<int> nextArray {currentArray};
        nextArray.push_back(arrB[idxB]);
        CreateCombination(arrA, arrB, idxA, idxB+1, nextArray, container);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> arrA {1, 2};
    vector<int> arrB {3, 4};
    vector<int> currentArray{};
    vector<vector<int>> container{};
    
    CreateCombination(arrA, arrB, 0, 0, currentArray, container);
    
    for (int i = 0; i < container.size(); ++i) {
        vector<int>& array = container[i];
        cout << "[ ";
        for (int j = 0; j < array.size(); ++j) {
            cout << array[j] << " ";
        }
        cout << "]";
        cout << endl;
    }
    
    return 0;
}
