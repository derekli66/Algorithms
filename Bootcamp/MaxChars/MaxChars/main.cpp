//
//  main.cpp
//  MaxChars
//
//  Created by LEE CHIEN-MING on 23/02/2018.
//  Copyright © 2018 LEE CHIEN-MING. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string chars("Hello World");
    map<char, int> charsMap;
    
    for (const char &ch : chars) {
        auto it = charsMap.find(ch);
        charsMap[ch] = (it == charsMap.end()) ? 1 : (charsMap[ch] + 1);
    }
    
    char winner{};
    int max{0};
    for (auto pair : charsMap) {
        if (pair.second > max) {
            max = pair.second;
            winner = pair.first;
        }
        cout << pair.first << ":" << pair.second << endl;
    }
    
    cout << "The winner is " << winner << endl;
    cout << "End of program" << endl;
    
    return 0;
}
