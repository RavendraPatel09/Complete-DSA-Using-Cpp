#include<iostream>
using namespace std;
int main()
{
    int arr[] = {1,2,2,4,5,6,6,7,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max = arr[0];
    for(int i=1; i<n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }
   int *H = new int[max+1](); 
    for(int i=0; i<n; i++)
    {
        H[arr[i]]++;
    }
    for(int i=0; i<=max; i++)
    {
        if(H[i] > 1)
        {
            cout << i << " is repeated " << H[i] << " times" << endl;
        }
    }
    return 0;
}