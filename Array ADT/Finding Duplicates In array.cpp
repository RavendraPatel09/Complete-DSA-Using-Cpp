#include<iostream>
using namespace std;

int main()
{
    int arr[] = {1,2,2,4,5,6,6,7,7,8,9};
    int last_duplicate = -1;
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Duplicate elements are: ";

    for(int i = 0; i < n-1; i++)
    {
        if(arr[i] == arr[i+1] && arr[i] != last_duplicate)
        {
            cout << arr[i] << " ";
            last_duplicate = arr[i];
        }
    }

    return 0;
}