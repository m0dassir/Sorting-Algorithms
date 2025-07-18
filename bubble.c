#include <stdlib.h> // For using malloc()
#include <stdio.h>

void bubble_sort(int *array, int number_of_elements);

int main()
{
    //int array[] = {64, 34, 25, 12, 22, 11, 90, 5};

    // Get the number of elements
    //int number_of_elements = sizeof(array) / sizeof(array[0]);

    // Prompt user for the number of elements in the array
    int number_of_elements;
    printf("Specify the number of integers for the array: ");
    scanf("%i", &number_of_elements);

    // Dynamically allocate memory for the array
    int *array = malloc(sizeof(int) * number_of_elements);
    if (array == NULL)
    {
        printf("Could not allocate memory for the array.\n");
        return 1;
    }

    // Populate the array by taking input from the user
    for (int i = 0; i < number_of_elements; i++)
    {
        printf("Element %02i: ", i + 1);
        scanf("%i", &array[i]);
    }

    // Function call for bubble sort
    bubble_sort(array, number_of_elements);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < number_of_elements; i++)
    {
        printf("%i, ", array[i]);
    }
    printf("\n");
}

void bubble_sort(int *array, int number_of_elements)
{
    for (int i = 0; i < number_of_elements - 1; i++)
    {
        for (int j = 0; j < number_of_elements - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
