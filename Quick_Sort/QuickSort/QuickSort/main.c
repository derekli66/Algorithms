//
//  main.c
//  QuickSort
//
//  Created by LEE CHIEN-MING on 10/4/16.
//  Copyright © 2016 Pointers. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void quicksort(int array[], int array_size)
{
    if (1 == array_size || 0 == array_size) {
        return;
    }
    
    int pivot_idx = array_size / 2;
    int left_size = 0;
    int right_size = 0;
    
    int pivot_value = array[pivot_idx];
    int *front_array = (int *)malloc(sizeof(int) * array_size);
    int *back_array = (int *)malloc(sizeof(int) * array_size);
    
    for (int i = 0; i < array_size; ++i) {
        if (i == pivot_idx) continue;
        
        if (array[i] <= pivot_value) {
            front_array[left_size++] = array[i];
        }
        else {
            back_array[right_size++] = array[i];
        }
    }
    
    quicksort(front_array, left_size);
    quicksort(back_array, right_size);
    
    int arr_idx = 0;
    for (int k = 0; k < left_size; ++k) {
        array[arr_idx++] = front_array[k];
    }
    array[arr_idx++] = pivot_value;
    for (int j = 0; j < right_size; ++j) {
        array[arr_idx++] = back_array[j];
    }
    
    free(front_array);
    free(back_array);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    const int arr_size = 8;
    int arr[arr_size] = {9, 4, 7, 8, 6, 3, 2, 5};
    
    quicksort(arr, arr_size);
    
    for (int i = 0; i < arr_size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
