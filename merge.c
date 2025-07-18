// Merge sort using recursion
// Time complexity O(nlogn)
// Space complexity O(n)

#include <stdio.h>
#include <stdlib.h> // For using malloc()

int merge_sort(double *array, int start, int end);
int merge(double *array, int start, int mid, int end);

int main()
{
    double unsorted[] = {3, 7, 6, -10, 15, 18, 25};
    int size = sizeof(unsorted) / sizeof(unsorted[0]);
    if (merge_sort(unsorted, 0, size - 1) != 0)
    {
        printf("Merge sort failed due to memory allocation error.\n");
        return 1;
    }

    printf("Sorted: ");
    for (int i = 0; i < size; i++)
    {
        printf("%.01f ", unsorted[i]);
    }
    printf("\n");
    return 0;
}

int merge_sort(double *array, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        if (merge_sort(array, start, mid) != 0)
        {
            return 1;
        }
        if (merge_sort(array, mid + 1, end) != 0)
        {
            return 1;
        }
        if (merge(array, start, mid, end) != 0)
        {
            return 1;
        }
    }
    return 0;
}

int merge(double *array, int start, int mid, int end)
{
    // Left subarray
    int n1 = mid - start + 1;
    // Right subarray
    int n2 = end - mid;

    // Statically allocate left[] and right[]
    //double left[n1], right[n2];

    // Dynamically allocate memory for left[] and right[]
    double *left = malloc(sizeof(double) * n1);
    if (left == NULL)
    {
        return 1;
    }
    double *right = malloc(sizeof(double) * n2);
    if (right == NULL)
    {
        free(left);
        return 1;
    }

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
    {
        left[i] = array[start + i];
    }
    for (int j = 0; j < n2; j++)
    {
        right[j] = array[mid + 1 + j];
    }

    // Index for left[]
    int i = 0;
    // Index for right[]
    int j = 0;
    // Index for merged array[]
    int k = start;

    // Merge left[] and right[] into array[]
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i += 1;
        }
        else
        {
            array[k] = right[j];
            j += 1;
        }

        k += 1;
    }

    // Copy remaining elements of left[]
    while (i < n1)
    {
        array[k] = left[i];
        i += 1;
        k += 1;
    }

    // Copy remaining elements of right[]
    while (j < n2)
    {
        array[k] = right[j];
        j += 1;
        k += 1;
    }

    free(left);
    free(right);
    return 0;
}
