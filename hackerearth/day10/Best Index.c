#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    long long a[n + 1];  
    long long val = -9999999999;  
    a[0] = 0;

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        a[i] += a[i - 1];  // Cumulative sum
    }
    for (int i = 1; i <= n; i++) {
        long long sum = 0;
        int k = i;
        int l = 1;


        while (k + l < n) {
            l++;
            k += l;
        }
        sum = a[k] - a[i - 1];

        if (sum > val) {
            val = sum;
        }
    }

    printf("%lld\n", val);
    return 0;
}
