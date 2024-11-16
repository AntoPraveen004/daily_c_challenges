int* resultsArray(int* nums, int numsSize, int k, int* returnSize) {
    // Variable 'm' to track the length of the current consecutive sequence
    int m = 1;
    // Size of the input array
    int n = numsSize;
    int* results = malloc(sizeof(int) * (n - k + 1));

    if (k == 1) {
        results[0] = nums[0];
    }

    for (int i = 1; i < n; i++) {

        if (nums[i] == nums[i - 1] + 1) {
            m = m + 1;   
        }else
            m = 1; 

        if (i >= k - 1) {

            if (m >= k) {
                results[i - k + 1] = nums[i];
            } else {
                results[i - k + 1] = -1;
            }
        }
    }
    *returnSize = n - k + 1;
    return results;
}
