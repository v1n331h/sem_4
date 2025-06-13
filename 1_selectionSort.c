#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    double start, end;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Random numbers between 0 and 1000
    }
    printf("Unsorted array: \n");
    printArray(arr, n);

    start = clock();
    selectionSort(arr, n);
    end = clock();

    printf("Sorted array: \n");
    printArray(arr, n);

    double time_taken = (end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort the array: %lf seconds\n", time_taken);
    
    return 0;
}