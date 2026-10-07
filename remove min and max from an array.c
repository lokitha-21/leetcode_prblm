#include <stdio.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minimumDeletions(int* nums, int numsSize) {
    if (numsSize <= 2) {
        return numsSize;
    }

    int minIdx = 0;
    int maxIdx = 0;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < nums[minIdx]) {
            minIdx = i;
        }
        if (nums[i] > nums[maxIdx]) {
            maxIdx = i;
        }
    }

    int i = minIdx < maxIdx ? minIdx : maxIdx;
    int j = minIdx > maxIdx ? minIdx : maxIdx;

    int opt1 = j + 1;                        
    int opt2 = numsSize - i;                
    int opt3 = (i + 1) + (numsSize - j); 

    return MIN(opt1, MIN(opt2, opt3));
}
