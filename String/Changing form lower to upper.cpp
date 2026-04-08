#include<iostream>
using namespace std;
int main()
{
    char S[]="welcome";
    char A[100];
    int i;
    for(i=0;S[i]!='\0';i++)
    {
    A[i]=S[i]-32;

    }
    cout<<"String in upper case is "<<A<<endl;
    return 0;
}
// Time complexity is O(n) where n is the length of the string