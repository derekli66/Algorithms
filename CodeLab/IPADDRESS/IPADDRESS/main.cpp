//
//  main.cpp
//  IPADDRESS
//
//  Created by LEE CHIEN-MING on 12/04/2018.
//  Copyright © 2018 LEE CHIEN-MING. All rights reserved.
//

/*
 Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255.
 The numbers cannot be 0 prefixed unless they are 0.
 
 Example:
 Given “25525511135”,
 return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order)
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// Recursive call
vector<string> IpAddressParser(string str, int dotCount = 3)
{
    if (dotCount == 0) {
        // Prevent trailing string with '0' or '00' prefix
        if (str.length() > 1  && (str.substr(0,1) == string{"0"} || str.substr(0,2) == string{"00"})) {
            return vector<string>{};
        }
        
        // If length less or equal 3, check if value less or equal to 255
        if (str.length() > 0 && str.length() <= 3 && stoi(str) <= 255)  {
            return vector<string>{str};
        } else {
            return vector<string>{};
        }
    }
    
    vector<string> container{};
    
    for (int i = 0; i < 3; ++i) {
        // if index out of range, then skip
        if (str.length() < (i+1)) break;
        
        string first = str.substr(0, i + 1);
        // We don't want our prefix contains '0' prefix
        if (first.length() > 1 && first.substr(0,1) == string{"0"}) break;

        string second = str.substr(i + 1);
        
        vector<string> result = IpAddressParser(second, dotCount - 1);
        if (result.size() > 0 && stoi(first) <= 255) {
            for (int i = 0; i < result.size(); ++i) {
                ostringstream leadingStr{};
                leadingStr << to_string(stoi(first)); // to eliminate zero prefix
                leadingStr << "." ;
                leadingStr << result[i];
                container.push_back(leadingStr.str());
            }
        }
    }
    
    return container;
}

vector<string> restoreIpAddresses(string A) {
    return IpAddressParser(A);
}

int main(int argc, const char * argv[]) {
    // 0100100-> 0.10.0.100,     0.100.10.0
    // 010010-> 0.10.0.10,     0.100.1.0
    string ipAddress{"0100100"};
    vector<string> ipAddresses = IpAddressParser(ipAddress);

    for (string str : ipAddresses) {
        cout << "IP: " << str << endl;
    }
    
    return 0;
}
