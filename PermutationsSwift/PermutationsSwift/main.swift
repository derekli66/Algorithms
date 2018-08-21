//
//  main.swift
//  PermutationsSwift
//
//  Created by LEE CHIEN-MING on 2018/8/21.
//  Copyright © 2018 PositiveGrid. All rights reserved.
//

import Foundation

var result: Array<Array<Int>> = []

func permutations(_ numbers: Array<Int>, begin: Int, result: inout Array<Array<Int>>)
{
    if (begin == numbers.count) {
        result.append(numbers)
        return
    }
    
    var nums = numbers
    for idx in begin..<numbers.count {
        nums.swapAt(begin, idx)
        permutations(nums, begin: begin + 1, result: &result)
        nums.swapAt(idx, begin)
    }
}

let nums = [1, 2, 3, 4, 5]

permutations(nums, begin: 0, result: &result)
debugPrint("//---------Permutations------------------")
debugPrint(result)
debugPrint("//---------Permutations Count------------")
debugPrint(result.count)
