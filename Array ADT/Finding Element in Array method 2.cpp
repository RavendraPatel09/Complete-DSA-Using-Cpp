#include<iostream>
using namespace std;
int main()
{
    int arr[] = {3,2,5,6,8,9,1,7,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int l = 1, h = 12;
    int H[100] = {0};
    // Mark elements in hash table
    for(int i = 0; i < n; i++)
    {
        H[arr[i]]++;
    }
    for(int i = l; i <= h; i++)
    {
        if(H[i] == 0)
        {
            cout << "Missing element is: " << i << endl;
        }
    }
    return 0;
}