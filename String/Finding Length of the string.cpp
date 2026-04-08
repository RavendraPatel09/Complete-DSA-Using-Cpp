#include<iostream>
using namespace std;
int main()
{
    string str;
    char S[]= "welcome";
    int count=0;
    for(int i=0;S[i]!='\0';i++)
    {
        count++;
    }
    cout<<"Length of the string is "<<count<<endl;
    return 0;
}
// Time complexity is O(n) where n is the length of the string