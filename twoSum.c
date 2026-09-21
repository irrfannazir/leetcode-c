#include <stdio.h>
#include <stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    int key;
    int index;
    int used;
} Hash;

#define TABLE_MAX 10030

unsigned int hash(int key){
    if(key < 0) key = -key;
    return key % TABLE_MAX;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Hash table[TABLE_MAX] = {0};
    *returnSize = 2;
    int *res = malloc(*returnSize * sizeof(int));
    int pos;
    res[0] = 0;
    res[1] = 0;
    for(int i = 0; i < numsSize; i++){
        int con = target - nums[i];
        pos = hash(con);
        if(table[pos].used && table[pos].key == con){
            res[0] = table[pos].index;
            res[1] = i;
            return res;
        }

        pos = hash(nums[i]);
        table[pos].key = nums[i];
        table[pos].index = i;
        table[pos].used = 1;
    }
    return res;
}

int main(void)
{
    int nums[] = {2, 7, 11, 15};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 9;

    int returnSize;

    printf("Input:  ");
    for(int i = 0;i < numsSize; i++){
        printf("%d ", nums[i]);
    }
    puts("");
    
    printf("Target: %d\n", target);
    
    int *result = twoSum(
        nums,
        numsSize,
        target,
        &returnSize
    );
    
    printf("Output: ");
    for(int i = 0;i < returnSize; i++){
        printf("%d ", result[i]);
    }
    puts("");

    free(result);

    return 0;
}