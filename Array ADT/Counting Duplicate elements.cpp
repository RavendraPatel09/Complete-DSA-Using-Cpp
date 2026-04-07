#include<iostream>
using namespace std;

int main()
{
    int arr[] = {1,2,2,4,5,6,6,7,7,8,9};
    for(i=0 ; i<n-1 ; i++)
    {
        if(arr[i] == arr[i+1])
        {
            cout<<arr[i]<<" ";
        }
        j = i+1;
        while(arr[i] == arr[j])
        {            j++;
        }        i = j-1;
    }
    return 0;
}