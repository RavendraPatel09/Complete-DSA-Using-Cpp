#include<iostream>
using namespace std;
int main()
{
    int arr[]={1,2,3,4,5,10,-1,15};
    int min = arr[0];
    int max = arr[0];
    for(int i=1;i<8;i++)
    {
        if(arr[i]>max)
            max=arr[i];
        else if(arr[i]<min)
            min=arr[i];
    } 
    cout<<"Max is "<<max<<endl;
    cout<<"Min is "<<min<<endl;
    return 0;
}
// Best case is when it in in decresing order 
//worst case is when it is in increasing order