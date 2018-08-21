//
//  main.cpp
//  MoveZeroBackward
//
//  Created by LEE CHIEN-MING on 21/06/2018.
//  Copyright © 2018 LEE CHIEN-MING. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> moveZeroBackward(vector<int> array)
{
    int backIdx = 0;
    for (int i = 0; i < array.size(); ++i) {
        if (array[i] != 0) {
            swap(array[i], array[backIdx]);
            backIdx++;
        }
    }
    
    return array;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> numbers{2, 3, 1, 0, 4, 0, 0, 9, 0, 10, 11};
    auto result = moveZeroBackward(numbers);
    
    cout << "{ ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << "}";
    cout << endl;
    
    return 0;
}
