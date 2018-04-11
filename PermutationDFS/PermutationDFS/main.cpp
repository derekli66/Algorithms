//
//  main.cpp
//  PermutationDFS
//
//  Created by LEE CHIEN-MING on 12/04/2018.
//  Copyright © 2018 LEE CHIEN-MING. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> permutationDFS(vector<int> &input) {
    vector<vector<int>> container;
    vector<vector<int>> sources;
    vector<int> leadingIndexes;
    
    size_t length = input.size();
    leadingIndexes.push_back(0);
    sources.push_back(input);
    
    while (sources.size()) {
        vector<int> targetArray = sources.front();
        sources.erase(sources.begin());
        
        int index = leadingIndexes.front();
        leadingIndexes.erase(leadingIndexes.begin());
        
        if (index >= length) {
            container.push_back(targetArray);
        }
        else {
            // Do Swaping
            vector<vector<int>> permu;
            vector<int> newIndexes;
            for (int i = index; i < length; ++i) {
                swap(targetArray[index], targetArray[i]);
                permu.push_back(targetArray);
                newIndexes.push_back(index + 1);
                swap(targetArray[index], targetArray[i]);
            }
            sources.insert(sources.begin(), permu.begin(), permu.end());
            leadingIndexes.insert(leadingIndexes.begin(), newIndexes.begin(), newIndexes.end());
        }
    }
    
    return container;
}

void printIntArray(const vector<int> &arr)
{
    for (const int &val : arr) {
        cout << val << " ";
    }
    
    cout << endl;
}

int main(int argc, const char * argv[]) {
    vector<int> input{1, 2, 3, 4, 5};
    vector<vector<int>> container = permutationDFS(input);
    for (auto&& arr : container) {
        printIntArray(arr);
    }
    std::cout << "Permutations count: " << container.size() << std::endl;
    std::cout << "End of Program" << std::endl;
    
    return 0;
}
