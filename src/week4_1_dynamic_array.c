/*
 * week4_1_dynamic_array.c
 * Author: Amanda Laima Bramberga
 * Student ID: 251RDC071
 * Description:
 *   Demonstrates creation and usage of a dynamic array using malloc.
 *   Allocate memory for n integers, read them from the user,
 *   print their sum and average, and then free the memory.
 *
 *   Output must match the format in the Week 4 instructions exactly
 *   (it is checked by the autograder).
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int *arr = NULL;
    int i;
    long long sum = 0;
    double average;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    // TODO: Allocate memory for n integers using malloc
    // Example: arr = malloc(n * sizeof(int));
    arr = malloc(n * sizeof(int));  /// The size is only known at run time, so it must go on the heap.

    // TODO: Check allocation success
    // If arr is NULL: print "Memory allocation failed." and return 1
    if (arr == NULL) {   /// Using a NULL pointer later would crash the program.
        printf("Memory allocation failed.\n");
        return 1;
    }

    // TODO: Print the prompt "Enter %d integers: " (with n), then read
    //       n integers into the array.
    //       If a value cannot be read: print "Invalid input.",
    //       free the array and return 1
    /// Freeing before returning avoids a memory leak.
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            free(arr);
            return 1;
        }
    }

    // TODO: Compute the sum and the average (use floating point for the average)
    /// Long long avoids overflow; casting to double avoids integer division.
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }
    average = (double)sum / n;

    // TODO: Print the results exactly as:
    //       Sum = <sum>
    //       Average = <average with 2 decimals, %.2f>
    printf("Sum: %lld\n", sum);
    printf("Average: %.2f\n", average);

    // TODO: Free allocated memory
    free(arr);  /// Freeing prevents a leak.

    return 0;
}
