// Write a program to implement binary search algorithm using recursive method. 
#include <stdio.h>
#include <time.h>

int binary_search(int arr[], int n, int target);

int main()
{
    FILE *fp;
    int n = 100000;
    int target = 999;
    int index;
    clock_t st, en;
    double time_taken;

    fp = fopen("best_1k.txt", "r");

    if (fp == NULL){
        printf("Error opening file.\n");
        return 1;
    }

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);

    st = clock();
    index = binary_search(arr, n, target);
    en = clock();

    time_taken = (double)(en - st) / CLOCKS_PER_SEC;

    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found\n");

    printf("Execution Time = %f seconds\n", time_taken);
    return 0;
}

int binary_search(int arr[], int n, int target)
{
    if (n <= 0)
        return -1;

    int mid = n / 2;

    if (arr[mid] == target)
        return mid;

    if (arr[mid] < target)
    {
        int result = binary_search(arr + mid + 1, n - mid - 1, target);
        return (result == -1) ? -1 : result + mid + 1;
    }
    else
    {
        return binary_search(arr, mid, target);
    }
}