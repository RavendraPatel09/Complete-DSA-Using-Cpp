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
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int BinarySearch(struct Array *arr,int key)
{
int l,mid,h;
l=0;
h=arr->length-1;
while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr->A[mid])
        return mid;
        else if(key<arr->A[mid])
        h=mid-1;
        else
        l=mid+1;
    }
    return -1;
}
int RBinarySearchHelper(struct Array *arr, int l, int h, int key)
{
    int mid;
    if(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr->A[mid])
            return mid;
        else if(key<arr->A[mid])
            return RBinarySearchHelper(arr,l,mid-1,key);
        else
            return RBinarySearchHelper(arr,mid+1,h,key);
    }
    return -1;
}

int RBinarySearch(struct Array *arr,int key)
{
    return RBinarySearchHelper(arr, 0, arr->length-1, key);
}
int main()
{struct Array arr={{2,3,4,5,6},10,5};
printf("Index of element is %d\n",RBinarySearch(&arr,2));
display(arr);
return 0;
}