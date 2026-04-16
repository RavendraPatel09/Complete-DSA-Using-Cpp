#include<iostream>
using namespace std;
class Diagonal
{
private:
    int *A;
    int n;
public:
    Diagonal()
    {
        n = 2;
        A = new int[n];
    }
    Diagonal(int n)
    {
        this->n = n;
        A = new int[n];
    }
    ~Diagonal()
    {
        delete[] A;
    }
    void set(int i, int j, int x)
    {
        if(i == j)
            A[i-1] = x;
    }
    int get(int i, int j)
    {
        if(i == j)
            return A[i-1];
        else
            return 0;
    }
    void display()
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(i == j)
                    cout << A[i-1] << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};
int main()
{
    int n, x;
    cout << "Enter dimension: ";
    cin >> n;
    Diagonal d(n);
    cout << "Enter diagonal elements:\n";
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        d.set(i, i, x);
    }
    cout << "\nMatrix:\n";
    d.display();
    return 0;
}