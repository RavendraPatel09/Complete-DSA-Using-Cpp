#include<iostream>
using namespace std;
int main()
{
    char S[]="WeLcOmE";
    char A[100];
    int i;
    for(i=0;S[i]!='\0';i++)
    {
    if (S[i]>=65 && S[i]<=90)
        A[i]=S[i]+32;
    else if (S[i]>=97 && S[i]<=122)
        A[i]=S[i]-32;
    else
        A[i]=S[i];

    }
    cout<<"String after changing case is "<<A<<endl;
    return 0;
}
// Time complexity is O(n) where n is the length of the string