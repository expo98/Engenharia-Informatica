#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Function to check if there exists a pair of elements in the array that sums up to a given value
void checkForSum(int arr1[], int n, int s) {
    // Iterate through array elements up to the second last element
    for (int i = 0; i < n - 1; i++) {
        // Iterate through array elements from the (i + 1)th element to the last element
        for (int j = i + 1; j < n; j++) {
            // Check if the sum of the current pair of elements equals the given sum
            if (arr1[i] + arr1[j] == s) {
                printf("Pair of elements can make the given sum by the value of index %d and %d\n", i, j);
                return; // Exit the function as pair found
            }
        }
    }
    printf("No pair can make the given sum.");
}

// Main function
int main() {
  clock_t begin = clock();

    // Array and sum initialization
    int arr1[] = {80, 98, 83, 92, 1, 38, 37, 54, 58, 89};
    int s = 181;

    // Display the given array
    int arraySize = sizeof(arr1) / sizeof(arr1[0]);
  

    // Check for a pair of elements that sum up to the given value
    checkForSum(arr1, arraySize, s);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Execution time : %f seconds\n", time_spent);
    return 0;
}
