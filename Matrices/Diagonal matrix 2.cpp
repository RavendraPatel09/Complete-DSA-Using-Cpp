#include<iostream>
using namespace std;
class diagonal
{
private:
    int n;
    int *A;
public:
    diagonal(int n)
    {
        this->n = n;
        A = new int[n];
    }
    void set(int i, int j, int x)
    {
        if (i == j)
            A[i - 1] = x;
    }
    int get(int i, int j)
    {
        if (i == j)
            return A[i - 1];
        else
            return 0;
    }
    void display()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    cout << A[i - 1] << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};
int main()
{
    diagonal d(4);
    d.set(1, 1, 3);
    d.set(2, 2, 5);
    d.set(3, 3, 10);
    d.set(4, 4, 19);
    d.display();
    return 0;
}