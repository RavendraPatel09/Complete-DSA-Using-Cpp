#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int A[10];
    int size;
    int length;
};
void display(struct Array arr)
{
    int i;
    printf("Elements are: \n");
    for(i=0;i<arr.length;i++)
    printf("%d ",arr.A[i]);
    
}
int BinarySearch(struct Array *arr,int key)
{
    int low=0;
    int high=arr->length-1;
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(key==arr->A[mid])
        {swap(&arr->A[mid],&arr->A[mid-1]);
        return mid;
        }
        else if(key<arr->A[mid])
        high=mid-1;
        else
        low=mid+1;
    }
    {
        if(key==arr->A[i])
        {swap(&arr->A[i],&arr->A[i-1]);
        return i;
        }
    }
    return -1;
}
int main()
{struct Array arr={{2,3,4,5,6},10,5};
printf("Index of element is %d\n",BinarySearch(&arr,3));
display(arr);
return 0;
}