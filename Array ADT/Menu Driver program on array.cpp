#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void display(struct Array arr)
{
    if(arr.length == 0)
    {
        printf("Array is empty\n");
        return;
    }

    printf("Elements are:\n");
    for(int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array *arr, int key)
{
    for(int i = 0; i < arr->length; i++)
    {
        if(key == arr->A[i])
        {
            if(i > 0)
                swap(&arr->A[i], &arr->A[i-1]); // Transposition
            return i;
        }
    }
    return -1;
}

int Get(struct Array arr, int index)
{
    if(index >= 0 && index < arr.length)
        return arr.A[index];

    printf("Invalid index\n");
    return -1;
}

void Set(struct Array *arr, int index, int x)
{
    if(index >= 0 && index < arr->length)
        arr->A[index] = x;
    else
        printf("Invalid index\n");
}

int Max(struct Array arr)
{
    if(arr.length == 0)
    {
        printf("Array is empty\n");
        return -1;
    }

    int max = arr.A[0];
    for(int i = 1; i < arr.length; i++)
        if(arr.A[i] > max)
            max = arr.A[i];

    return max;
}

int Min(struct Array arr)
{
    if(arr.length == 0)
    {
        printf("Array is empty\n");
        return -1;
    }

    int min = arr.A[0];
    for(int i = 1; i < arr.length; i++)
        if(arr.A[i] < min)
            min = arr.A[i];

    return min;
}

int Sum(struct Array arr)
{
    int sum = 0;
    for(int i = 0; i < arr.length; i++)
        sum += arr.A[i];

    return sum;
}

float Avg(struct Array arr)
{
    if(arr.length == 0)
        return 0;

    return (float)Sum(arr) / arr.length;
}

int main()
{
    struct Array arr1;
    int choice;

    printf("Enter size of array: ");
    scanf("%d", &arr1.size);

    arr1.A = (int *)malloc(arr1.size * sizeof(int));
    arr1.length = 0;

    if(arr1.A == NULL)
    {
        printf("Memory allocation failed\n");
        return 0;
    }

    do
    {
        printf("\nMenu\n");
        printf("1. Create\n2. Display\n3. Linear Search\n4. Get\n5. Set\n");
        printf("6. Max\n7. Min\n8. Sum\n9. Average\n10. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter number of elements (<= %d): ", arr1.size);
                scanf("%d", &arr1.length);

                if(arr1.length > arr1.size)
                {
                    printf("Overflow! Max size is %d\n", arr1.size);
                    arr1.length = 0;
                    break;
                }

                printf("Enter elements:\n");
                for(int i = 0; i < arr1.length; i++)
                    scanf("%d", &arr1.A[i]);
                break;

            case 2:
                display(arr1);
                break;

            case 3:
            {
                int key;
                printf("Enter key: ");
                scanf("%d", &key);

                int index = LinearSearch(&arr1, key);

                if(index != -1)
                    printf("Element found at index %d\n", index);
                else
                    printf("Element not found\n");
            }
            break;

            case 4:
            {
                int index;
                printf("Enter index: ");
                scanf("%d", &index);

                int val = Get(arr1, index);
                if(val != -1)
                    printf("Value = %d\n", val);
            }
            break;

            case 5:
            {
                int index, x;
                printf("Enter index and value: ");
                scanf("%d %d", &index, &x);

                Set(&arr1, index, x);
            }
            break;

            case 6:
                printf("Max = %d\n", Max(arr1));
                break;

            case 7:
                printf("Min = %d\n", Min(arr1));
                break;

            case 8:
                printf("Sum = %d\n", Sum(arr1));
                break;

            case 9:
                printf("Average = %.2f\n", Avg(arr1));
                break;

            case 10:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 10);

    free(arr1.A); // important memory cleanup
    return 0;
}