#include <stdlib.h>
#include <stdbool.h>
#define HASH_SIZE 20011 
typedef struct {
    int key;
    int value;
    bool occupied;
} HashNode;
int hashFunction(int key) {
    int h = key % HASH_SIZE;
    if (h < 0) h += HASH_SIZE;
    return h;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashNode* hashTable = (HashNode*)calloc(HASH_SIZE, sizeof(HashNode));
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
 
        int h = hashFunction(complement);
        while (hashTable[h].occupied) {
            if (hashTable[h].key == complement) {
                result[0] = hashTable[h].value;
                result[1] = i;
                free(hashTable);
                return result;
            }
            h = (h + 1) % HASH_SIZE; 
        }
        h = hashFunction(nums[i]);
        while (hashTable[h].occupied) {
            h = (h + 1) % HASH_SIZE;
        }
        hashTable[h].key = nums[i];
        hashTable[h].value = i;
        hashTable[h].occupied = true;
    }
    
    free(hashTable);
    return NULL;
}
