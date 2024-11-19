void countApplesAndOranges(int s, int t, int a, int b, int apples_count, int* apples, int oranges_count, int* oranges) {
int appleCount = 0;  // To count apples falling on the house
    int orangeCount = 0; // To count oranges falling on the house

    // Count the apples that land on the house
    for (int i = 0; i < apples_count; i++) {
        int landingPosition = a + apples[i];
        if (landingPosition >= s && landingPosition <= t) {
            appleCount++;
        }
    }

    // Count the oranges that land on the house
    for (int i = 0; i < oranges_count; i++) {
        int landingPosition = b + oranges[i];
        if (landingPosition >= s && landingPosition <= t) {
            orangeCount++;
        }
    }

    // Print the results
    printf("%d\n%d\n", appleCount, orangeCount);
}