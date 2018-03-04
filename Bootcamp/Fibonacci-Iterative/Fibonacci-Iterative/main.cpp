//
//  main.cpp
//  Fibonacci-Iterative
//
//  Created by LEE CHIEN-MING on 04/03/2018.
//  Copyright © 2018 LEE CHIEN-MING. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

unsigned int FibonacciIterative(unsigned int n) {
    vector<unsigned int> results{0, 1};
    
    for (int i = 2; i <= n; ++i) {
        unsigned int first = results[i - 1];
        unsigned int second = results[i - 2];
        results.push_back((first + second));
    }
    
    return results.back();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    unsigned int input = 15;
    unsigned int result = FibonacciIterative(input);
    
    cout << "Fibonacci result for input, " << input << ", " << "is " << result << endl;
    
    return 0;
}
