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

unsigned int FibonacciByLoop(unsigned int n) {
    if (n < 2) return 1;
    
    unsigned int a = 0;
    unsigned int b = 1;
    unsigned int result = 0;
    int idx = 2;
    
    while (idx <= n) {
        result = a + b;
        a = b;
        b = result;
        idx++;
    }
    
    return result;
}

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
    unsigned int input = 20;
    unsigned int result = FibonacciIterative(input);
    unsigned int result2 = FibonacciByLoop(input);
    
    cout << "FibonacciIterative result for input, " << input << ", " << "is " << result << endl;
    cout << "FibonacciByLoop result for input, " << input << ", " << "is " << result2 << endl;

    return 0;
}
