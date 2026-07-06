// Write a program to sort array elements using heap sort.

// Time Complexity of Heap Sort
// 	           1k	       10k	      100k
// best	    0.001000s   0.116000s	11.031000s
// average	0.002000s	0.325000s	35.031000s
// worst	0.004000s	0.336000s	22.031000s

#include <stdio.h>
#include <time.h>

int heap_sort(int arr[], int n);
void heapify(int arr[], int n, int i);
int main()
{
    FILE *fp;
    clock_t st, en;
    int n = 100000;
    int arr[n];

    fp = fopen("worst_100k.txt", "r");
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);

    st = clock();
    heap_sort(arr, n);
    en = clock();


    printf("\nTime taken: %f seconds\n", ((double)(en - st)) / CLOCKS_PER_SEC);
    return 0;
}

int heap_sort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }

    return 0;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}