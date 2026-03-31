#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int *A;
    int size;
    int length;
};
int main()
{
    struct Array arr={{2,3,4,5,6},10,5};
    printf("Enter the Size of an Array: ");\
    scanf("%d",&arr.size);
    arr.A = (int *)malloc(arr.size*sizeof(int));
    arr.length=0;
}