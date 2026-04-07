#include<iostream>
using namespace std;
int main()
{
    int arr[] = {1,2,2,4,5,6,6,7,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n-1; i++)
    {
        if(arr[i] == arr[i+1])
        {
            int j = i + 1;
            while(j < n && arr[i] == arr[j])
            {
                j++;
            }
            cout << arr[i] << " is repeated " << j - i << " times" << endl;
            i = j - 1;
        }
    }
    return 0;
}