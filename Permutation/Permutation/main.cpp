//
//  main.cpp
//  Permutation
//
//  Created by LEE CHIEN-MING on 02/12/2017.
//  Copyright © 2017 derekli66. All rights reserved.
//

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void printIntArray(const vector<int> &arr)
{
    for (const int &val : arr) {
        cout << val << " ";
    }
    
    cout << endl;
}

void permutations(int startIndex, vector<int> &input, vector<vector<int>> &container)
{
    if (startIndex == input.size() - 1) {
        container.push_back(input);
        return;
    }
    
    for (int i = startIndex; i < input.size(); ++i) {
        swap(input[startIndex], input[i]);
        vector<int> swapped = input;
        permutations(startIndex + 1, swapped, container);
        swap(input[startIndex], input[i]);
    }
}

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> container;
    vector<int> input{1, 2, 3, 4, 5};
    
    permutations(0, input, container);
    
    int counter = 0;
    for (auto&& arr : container) {
        counter++;
        printIntArray(arr);
    }
    
    std::cout << "Total process times: " << counter << std::endl;
    
    return 0;
}
