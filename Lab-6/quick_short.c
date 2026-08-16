#include <stdio.h>
#include <time.h>

int pivot(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main()
{
    clock_t st, en;
    int n = 100000;
    FILE *fp = fopen("best_100k.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        if (fscanf(fp, "%d", &arr[i]) != 1)
            break;
    }

    fclose(fp);

    st = clock();
    quickSort(arr, 0, n - 1);
    en = clock();

    double time_taken = ((double)(en - st)) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", time_taken);

    return 0;
}

int pivot(int arr[], int i, int j){
    int k = i+1;
    int l = j;
    int p = arr[i];
    int temp = 0;
    while (k<l)
    {
        while (arr[k] <= p && k < j)
        {
            k++;
        }
        while (arr[l] > p && l > i)
        {
            l--;
        }
        if (k < l)
        {
            temp = arr[k];
            arr[k] = arr[l];
            arr[l] = temp;
        }
    }
    temp = arr[i];
    arr[i] = arr[l];
    arr[l] = temp;
    return l;
}
 void quickSort(int arr[], int low, int high){
    if (low < high)
    {
        int p = pivot(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
 }