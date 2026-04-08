#include<iostream>
using namespace std;
int main()
{
    int n;
    int arr[]={1,2,3,4,5,10,-1,15}
    min =A[0];
    max =A[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max)
            max=arr[i];
        else if(arr[i]<min)
            min=arr[i];
    }   
}
// Best case is when it in in decresing order 
//worst case is when it is in increasing order