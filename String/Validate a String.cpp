#include<iostream>
using namespace std;
int valid (char *name)
{
    int i;
    for(i=0;name[i]!='\0';i++)
    {
        if((name[i]>=65 && name[i]<=90) || (name[i]>=97 && name[i]<=122) || (name[i]>=48 && name[i]<=57))
            continue;
        else

            return 0;
    }
    return 1;
}
int main()
{
    char*name = "Ravener123";
    int i;
    for(i=0;name[i]!='\0';i++)
    if(valid(name))
        cout<<"String is valid"<<endl;
    else
        cout<<"String is not valid"<<endl;
    return 0;
}