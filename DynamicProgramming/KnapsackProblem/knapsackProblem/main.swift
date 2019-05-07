//
//  main.swift
//  knapsackProblem
//
//  Created by LEE CHIEN-MING on 2019/5/7.
//  Copyright © 2019 derekli66. All rights reserved.
//

import Foundation

func knapsack(_ weights: Array<Int>,_ values: Array<Int>,_ index: Int,_ remainingWeight: Int,_ cache: inout Array<Array<Int>>) -> Int {
    
    if (index < 0) { return 0 }
    
    if (cache[index][remainingWeight] != -1) {
        return cache[index][remainingWeight]
    }
    
    var choosedValue: Int = 0
    if (remainingWeight >= weights[index]) {
        // Choose
        choosedValue = values[index] + knapsack(weights, values, index - 1, remainingWeight - weights[index], &cache)
    }
    
    // Not choose
    let notChoosedValue = knapsack(weights, values, index - 1, remainingWeight, &cache)
    
    cache[index][remainingWeight] = max(choosedValue, notChoosedValue)
    
    return cache[index][remainingWeight]
}

let weights = [2, 5, 3, 1, 1]
let values = [10, 1, 2, 2, 1]
let weightLimit = 5
var squareCache = Array<Array<Int>>()

for _ in 0..<weights.count {
    squareCache.append(Array<Int>(repeating: -1, count: 6))
}

let mostValue = knapsack(weights, values, weights.count - 1, weightLimit, &squareCache)

print("[Knapsack] The most value can be carried is \(mostValue)")
