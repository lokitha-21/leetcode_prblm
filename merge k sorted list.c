#include <stdio.h>
#include <stdlib.h>

struct HeapNode {
    struct ListNode* node;
};

void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct HeapNode heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].node->val < heap[smallest].node->val)
        smallest = left;

    if (right < size && heap[right].node->val < heap[smallest].node->val)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0 || lists == NULL) return NULL;
    struct HeapNode* heap = (struct HeapNode*)malloc(sizeof(struct HeapNode) * listsSize);
    int heapSize = 0;
    for (int i = 0; i < listsSize; i++) {
        if (lists[i] != NULL) {
            heap[heapSize].node = lists[i];
            heapSize++;
        }
    }
    for (int i = (heapSize / 2) - 1; i >= 0; i--) {
        minHeapify(heap, heapSize, i);
    }

    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* tail = &dummy;

    while (heapSize > 0) {
        struct ListNode* smallestNode = heap[0].node;
        
        tail->next = smallestNode;
        tail = tail->next;

        if (smallestNode->next != NULL) {
            heap[0].node = smallestNode->next;
        } else {
            heap[0] = heap[heapSize - 1];
            heapSize--;
        }
        if (heapSize > 0) {
            minHeapify(heap, heapSize, 0);
        }
    }
    free(heap);

    return dummy.next;
}
