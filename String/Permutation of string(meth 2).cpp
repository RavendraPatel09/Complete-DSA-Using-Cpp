#include<iostream>
using namespace std;
void permute(char s[], int l, int h)
{
int i;
if (l == h)
{
cout << s << endl;
}
else
{
    for (i = l; i <= h; i++)
    {    swap(s[l], s[i]);
        permute(s, l + 1, h);
        swap(s[l], s[i]); // backtracking
        }
    }
}
int main()
{
    char s[] = "ABC";
    permute(s, 0, 2);
    return 0;
}