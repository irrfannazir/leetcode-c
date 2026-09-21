#include <stdio.h>
#include <stdlib.h>

#define INT_SIZE 31
#define HASH_TABLE_SIZE 100000

int hash(int key) {
    return key % INT_SIZE;
}

int firstMissingPositive(int* nums, int numsSize) {
    int Hash[HASH_TABLE_SIZE] = {0};
    for(int i = 0; i < numsSize; i++){
        if(nums[i] <= 0) continue;
        if(nums[i] > INT_SIZE * HASH_TABLE_SIZE && numsSize < INT_SIZE*HASH_TABLE_SIZE) continue;
        int int_index = hash(nums[i]);
        int table_index = (nums[i] / INT_SIZE) % HASH_TABLE_SIZE;
        if(table_index >= HASH_TABLE_SIZE) return 0;
        Hash[table_index] |= (1 << int_index);
    }

    int i;
    for(i = 1; i < INT_SIZE*HASH_TABLE_SIZE; i++){
        int a = Hash[(i / INT_SIZE) % HASH_TABLE_SIZE];
        int b = (1 << (i % INT_SIZE));
        if((a & b) == 0) return i;
    }
    return 0;
}

int main() {
    // Test Case 1: Standard unsorted array with a negative number
    int test1[] = {3, 4, -1, 1};
    int size1 = sizeof(test1) / sizeof(test1[0]);
    printf("Test 1 Result: %d (Expected: 2)\n", firstMissingPositive(test1, size1));

    // Test Case 2: Array already fully sequential
    int test2[] = {1, 2, 3, 4};
    int size2 = sizeof(test2) / sizeof(test2[0]);
    printf("Test 2 Result: %d (Expected: 5)\n", firstMissingPositive(test2, size2));

    // Test Case 3: Array with duplicate numbers and non-consecutive elements
    int test3[] = {7, 8, 9, 11, 12};
    int size3 = sizeof(test3) / sizeof(test3[0]);
    printf("Test 3 Result: %d (Expected: 1)\n", firstMissingPositive(test3, size3));

    // Test Case 4: Array containing duplicates and zero
    int test4[] = {1, 1, 0, -1, 2};
    int size4 = sizeof(test4) / sizeof(test4[0]);
    printf("Test 4 Result: %d (Expected: 3)\n", firstMissingPositive(test4, size4));

    return 0;
}