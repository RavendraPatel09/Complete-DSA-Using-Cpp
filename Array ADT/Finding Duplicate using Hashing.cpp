#include<iostream>
using namespace std;
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10,2,4,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int H[11] = {0}; // Initialize hash array with zeros
    for (int i=0; i<n; i++)
    {
        H[arr[i]]++;
    }
    for (int i=0; i<=10; i++)
    {
        if (H[i] > 1)
        {
            cout << i << " is repeated " << H[i] << " times" << endl;
        }
    }
}