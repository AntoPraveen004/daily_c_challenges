#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int min(int a, int b) {
    return a > b ? b : a;
}

long long Solve(long long k, int* arr, int n) {
    long long out = 0;
    int i, j;
    for (i = j = 0; i < n; i++) {
        if (arr[i] <= 0)
            continue;

        while (i - j > k)
            ++j;

        while (arr[i] != 0 && (i + k) >= min(n - 1, j)) {
            if (arr[j] > 0) {
                j++;
                continue;
            }
            int x = min(arr[i], abs(arr[j]));
            arr[i] -= x;
            arr[j] += x;

            if (arr[j] >= 0)
                j++;
        }
    }

    for (i = 0; i < n; i++)
        out += abs(arr[i]);

    return out;
}

int main() {
    long long k;
    int n, i_arr;

    // Input the size of array n and the value k
    scanf("%d %lld", &n, &k);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));

    // Input the array values
    for (i_arr = 0; i_arr < n; i_arr++) {
        scanf("%d", &arr[i_arr]);
    }

    // Call the Solve function and print the result
    printf("%lld", Solve(k, arr, n));

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
