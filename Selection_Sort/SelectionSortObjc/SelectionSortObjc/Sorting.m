//
//  Sorting.m
//  SelectionSortObjc
//
//  Created by LEE CHIEN-MING on 16/12/2016.
//  Copyright © 2016 derekli66. All rights reserved.
//

#import "Sorting.h"

@implementation Sorting

+ (void)swapWithIndex1:(NSUInteger)index1 index2:(NSUInteger)index2 array:(NSMutableArray *)array
{
    id obj = array[index1];
    array[index1] = array[index2];
    array[index2] = obj;
}

+ (NSArray *)selectionSort:(NSArray *)array
{
    NSMutableArray *mutableArray = [NSMutableArray arrayWithArray:array];
    NSUInteger length = [mutableArray count];
    NSUInteger idx = 0;
    
    while (idx < length) {
        NSUInteger smallestIdx = idx;
        
        for (NSUInteger i = idx + 1; i < length; ++i) {
            if ([mutableArray[smallestIdx] integerValue] > [mutableArray[i] integerValue]) {
                smallestIdx = i;
            }
        }
        
        [self swapWithIndex1:idx index2:smallestIdx array:mutableArray];
        
        idx++;
    }
    
    return [NSArray arrayWithArray:mutableArray];
}

@end
