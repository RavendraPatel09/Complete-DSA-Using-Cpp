#include<iostream>
using namespace std;
int main()
{
    int n = 9;
    int arr[]={1,2,4,5,6,7,8,9,10};
    int k = 6;
    bool found=false;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==k)
            {
                cout<<"Pair found: "<<arr[i]<<" and "<<arr[j]<<endl;
                found=true;
            }
        }
    }
    if(!found)
    {
        cout<<"No pair found with sum "<<k<<endl;
    }
    return 0;
}