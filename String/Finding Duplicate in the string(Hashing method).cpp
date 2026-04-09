#include<iostream>
using namespace std;
int main()
{
    char A[] = "Finding";
    int H[26] = {0}, i;
    for(i = 0; A[i] != '\0'; i++)
    {
        H[A[i] - 97]++;
    }
    for(i = 0; i < 26; i++)
    {
        if(H[i] > 1)
        {
            cout << (char)(i + 97) << " is " << H[i] << " times in the string." << endl;
        }
    }
    return 0;
}