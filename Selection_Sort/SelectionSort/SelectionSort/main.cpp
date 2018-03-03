//
//  main.cpp
//  SelectionSort
//
//  Created by LEE CHIEN-MING on 16/12/2016.
//  Copyright © 2016 CPP. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

void SelectionSort(std::vector<int> &array) {
    size_t length = array.size();
    int idx = 0;
    
    while (idx < length) {
        int smallestIndex = idx;
        
        for (int j = idx + 1; j < length; ++j) {
            if (array[smallestIndex] > array[j]) {
                smallestIndex = j;
            }
        }
        
        std::swap(array[idx], array[smallestIndex]);
        
        idx++;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> array = {2, 4, 3, 5, 8, 1, 6};
    SelectionSort(array);
    
    for (int i = 0; i <array.size(); ++i) {
        std::cout << array[i] << std::endl;
    }
    
    return 0;
}
