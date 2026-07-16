// Write a program to implement Binary Search (Iterative Method)

#include <stdio.h>
#include <time.h>

int binary_search(int arr[], int n, int target);

int main()
{
    FILE *fp;
    int n = 100000;
    int target;
    int index;
    clock_t st, en;
    double time_taken;

    printf("Enter the target element to search: ");
    scanf("%d", &target);

    // Change the file name as required
    fp = fopen("best_100k.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);

    printf("\nFirst Element : %d\n", arr[0]);
    printf("Last Element  : %d\n", arr[n - 1]);

    if (arr[0] < arr[n - 1])
        printf("Array Order   : Ascending\n");
    else
        printf("Array Order   : Descending\n");

    st = clock();

    index = binary_search(arr, n, target);

    en = clock();

    time_taken = (double)(en - st) / CLOCKS_PER_SEC;

    if (index != -1)
        printf("\nElement %d found at index %d\n", target, index);
    else
        printf("\nElement %d not found\n", target);

    printf("Execution Time = %.9f seconds\n", time_taken);

    return 0;
}

int binary_search(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;

    // Check array order
    int ascending = (arr[0] < arr[n - 1]);

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (ascending)
        {
            // Ascending order
            if (arr[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        else
        {
            // Descending order
            if (arr[mid] > target)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    return -1;
}