//
//  main.m
//  SelectionSortObjc
//
//  Created by LEE CHIEN-MING on 16/12/2016.
//  Copyright © 2016 derekli66. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Sorting.h"

unsigned int reverseBits(unsigned int num) {
    unsigned int rev = 0;
    unsigned int head = 31;
    
    while (num) {
        if (num & 1) {
            rev = rev | 1 << head;
        }
        
        num >>= 1;
        head--;
    }
    
    return rev;
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        int value = 2 >> 1;
        NSLog(@"value %d", value);
        
        unsigned int num = 1 << 31;
        unsigned int result = reverseBits(num);
        NSLog(@"Result: %d", result);
        
        NSArray *numArray = @[@(1000), @(3), @(9), @(5), @(6), @(7), @(2), @(12)];

        NSArray *sortedArray = [Sorting selectionSort:numArray];
        NSLog(@"Confirm sortedArray result: %@", sortedArray);
        
        NSUInteger parent[100][100];
        
        parent[0][1] = 10;
        parent[0][3] = 20;
        
        NSLog(@"%ld", parent[0][1]);
        NSLog(@"%ld", parent[0][0]);
        
    }
    return 0;
}
