#include<iostream>
using namespace std;
int main()
{
    int arr[] = {1,3,5,6,7,9,14,23,25};
    int n = sizeof(arr)/sizeof(arr[0]);

    int diff = arr[0] - 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] - i != diff)
        {
            while(diff < arr[i] - i)
            {
                cout << "Missing element is: " << i + diff << endl;
                diff++;
            }
        }
    }
    return 0;
}