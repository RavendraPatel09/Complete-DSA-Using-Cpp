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
float Avg(struct Array arr)
{
    return (float)Sum(arr)/arr.length;
}
void Merge(struct Array *arr1, struct Array *arr2, struct Array *arr3)
{
    int i=0, j=0, k=0;

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }

    for(; i<arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for(; j<arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
}
void setmembership(struct Array arr,int key)
{
    int i;
    for(i=0;i<arr.length;i++)
    {
        if(key==arr.A[i])
        {
            printf("Element %d is present in the set.\n",key);
            return;
        }
    }
    printf("Element %d is not present in the set.\n",key);
}
void Intersection(struct Array *arr1, struct Array *arr2, struct Array *arr3)
{
    int i=0, j=0, k=0;

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            i++;
        else if(arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            arr3->A[k++] = arr1->A[i];
            i++;
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;
}
void Union(struct Array *arr1, struct Array *arr2, struct Array *arr3)
{
    int i=0, j=0, k=0;

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if(arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = arr1->A[i];
            i++;
            j++;
        }
    }

    for(; i<arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for(; j<arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    arr3->size = 10;
}
void Merge(struct Array *arr1, struct Array *arr2, struct Array *arr3)
{
    int i=0, j=0, k=0;

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }

    for(; i<arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for(; j<arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
}
int main()
{struct Array arr={{2,3,4,5,6},10,5};
return 0;
}
