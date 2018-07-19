//
//  main.cpp
//  ZIGZAG
//
//  Created by LEE CHIEN-MING on 19/07/2018.
//  Copyright © 2018 LEE CHIEN-MING. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

//using namespace std;

std::string convert(std::string str, int B)
{    
    if (1 == B || 0 == B) {
        return str;
    }
    
    std::vector<std::string> container{};
    for (int i = 0; i < B; ++i) {
        container.push_back(std::string{});
    }
    
    int count = 0;
    int browser = 0;
    int increment = 1;
    while (count < str.length()) {
        container[browser] += str[count];
        if (browser + increment >= container.size() || browser + increment < 0)
        {
            increment *= -1;
        }
        browser += increment;
        count++;
    }
    
    for (int i = 1; i < container.size(); ++i) {
        container[0] += container[i];
    }
    
    return container[0];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::string str{"PAYPALISHIRING"};
    std::cout << "Final ZIGZAG: " << convert(str, 3) << std::endl;
    
    // Expect: PAHNAPLSIIGYIR
    // Result: PAHNAPLSIIGYIR
    
    return 0;
}
