#include<iostream>
using namespace std;
int main()
{
    char A[] = "Hellooooo";
    char B[9];
    int i , j;
    for(j=0; A[j] != '\0'; j++);
    i = j - 1;
    for(i = 0; i<j; i++, j--)
    {
        char t = A[i];
        A[i] = A[j-1];
        A[j-1] = t;
    }
    cout << A;
    return 0;
}