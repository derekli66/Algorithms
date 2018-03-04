//
//  main.cpp
//  Fibonacci-Recursion
//
//  Created by LEE CHIEN-MING on 04/03/2018.
//  Copyright © 2018 LEE CHIEN-MING. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

int FibMemoization(int n, std::map<int,int> &memo)
{
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }
    
    int result = FibMemoization(n - 1, memo) + FibMemoization(n - 2, memo);
    memo[n] = result;
    return result;
}

int Fibonacci(int n)
{
    if (n < 2) return 1;
    
    map<int,int> cached { {0,0} , {1,1} };
    
    return FibMemoization(n - 1, cached) + FibMemoization(n - 2, cached);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int resultOfMemo = Fibonacci(15);
    
    cout << "Fibonacci with memoization: " << resultOfMemo << endl;
    
    return 0;
}
