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
    int i;
    printf("Elements are: \n");
    for(i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
}
int main()
{
    struct Array arr;
    int i,j;
    printf("Enter the Size of an Array: ");
    scanf("%d",&arr.size);
    arr.A = (int *)malloc(arr.size*sizeof(int));
    arr.length=0;
    printf("Enter the number of elements: ");
    scanf("%d",&arr.length);

    printf("Enter the elements: \n");
    for(i=0;i<arr.length;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr.A[i]);
    }
    return 0;
    display(arr);
}