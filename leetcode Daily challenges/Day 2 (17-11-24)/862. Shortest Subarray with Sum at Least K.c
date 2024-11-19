#include <limits.h>
#include <stdlib.h>

// Structure for Deque
typedef struct {
    int index;
    long long prefixSum;
} Element;

typedef struct {
    Element *data;
    int front, rear, size, capacity;
} Deque;

Deque *createDeque(int capacity) {
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    deque->data = (Element *)malloc(capacity * sizeof(Element));
    deque->front = 0;
    deque->rear = -1;
    deque->size = 0;
    deque->capacity = capacity;
    return deque;
}

int isEmpty(Deque *deque) {
    return deque->size == 0;
}

void pushBack(Deque *deque, Element elem) {
    deque->rear = (deque->rear + 1) % deque->capacity;
    deque->data[deque->rear] = elem;
    deque->size++;
}

Element popFront(Deque *deque) {
    Element elem = deque->data[deque->front];
    deque->front = (deque->front + 1) % deque->capacity;
    deque->size--;
    return elem;
}

Element back(Deque *deque) {
    return deque->data[deque->rear];
}

Element front(Deque *deque) {
    return deque->data[deque->front];
}

void popBack(Deque *deque) {
    deque->rear = (deque->rear - 1 + deque->capacity) % deque->capacity;
    deque->size--;
}

void freeDeque(Deque *deque) {
    free(deque->data);
    free(deque);
}

// Function to find the shortest subarray with sum at least k
int shortestSubarray(int *nums, int numsSize, int k) {
    long long *prefixSum = (long long *)malloc((numsSize + 1) * sizeof(long long));
    prefixSum[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    Deque *deque = createDeque(numsSize + 1);
    int minLength = INT_MAX;

    for (int i = 0; i <= numsSize; i++) {
        // Check if we can form a subarray of sum at least k
        while (!isEmpty(deque) && prefixSum[i] - front(deque).prefixSum >= k) {
            minLength = (i - front(deque).index) < minLength ? (i - front(deque).index) : minLength;
            popFront(deque);
        }

        // Maintain deque in increasing order of prefix sums
        while (!isEmpty(deque) && prefixSum[i] <= back(deque).prefixSum) {
            popBack(deque);
        }

        Element elem = {i, prefixSum[i]};
        pushBack(deque, elem);
    }

    free(prefixSum);
    freeDeque(deque);

    return minLength == INT_MAX ? -1 : minLength;
}