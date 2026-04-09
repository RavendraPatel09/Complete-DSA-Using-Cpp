#include<iostream>
using namespace std;
int main()
{
    char A[] = "decimal";
    char B[] = "medical";
    int i, H[26] = {0};
    for(i = 0; A[i] != '\0'; i++)
    {
        H[A[i] - 97]++;
    }
    for(i = 0; B[i] != '\0'; i++)
    {
        H[B[i] - 97]--;
        if(H[B[i] - 97] < 0)
        {
            cout << "Not anagram" << endl;
            return 0;
        }
    }
    cout << "Anagram" << endl;
    return 0;
}