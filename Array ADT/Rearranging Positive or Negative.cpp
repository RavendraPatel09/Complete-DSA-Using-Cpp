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
int LinearSearch(struct Array *arr,int key)
{
    int i;
    for(i=0;i<arr->length;i++)
    {
        if(key==arr->A[i])
        {swap(&arr->A[i],&arr->A[i-1]);
        return i;
        }
    }
    return -1;
}
int Get(struct Array arr,int index)
{
    if(index>=0 && index<arr.length)
    return arr.A[index];
    return -1;
}
void Set(struct Array *arr,int index,int x)
{
    if(index>=0 && index<arr->length)
    arr->A[index]=x;
}
int Max(struct Array arr)
{
    int max=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {
        if(arr.A[i]>max)
        max=arr.A[i];
    }
    return max;
}
int Min(struct Array arr)
{
    int min=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {
        if(arr.A[i]<min)
        min=arr.A[i];
    }
    return min;
}
int Sum(struct Array arr)
{
    int sum=0;
    for(int i=0;i<arr.length;i++)
    sum+=arr.A[i];
    return sum;
}
void InsertSort(struct Array *arr,int x)
{
    int i=arr->length-1;
    if(arr->length==arr->size)
    return;
    while(i>=0 && arr->A[i]>x)
    {
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}
int isSorted(struct Array arr)
{
    for(int i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
        return 0;
    }
    return 1;
}
void Rearrange(struct Array *arr)
{
    int i,j;
    int i=0,
    j=arr->length-1;
    while(i<j)
    {
        while(arr->A[i]<0)i++;
        while(arr->A[j]>=0)j--;
        if(i<j)swap(&arr->A[i],&arr->A[j]);
    }
}
int main()
{struct Array arr={{2,4,-2,4,5,7,-9,12,-49},10,9};
// InsertSort(&arr,159);
printf("Sorted: %d\n",isSorted(arr));
display(arr);
Rearrange(&arr);
printf("Rearranged: \n");
display(arr);
return 0;
}
