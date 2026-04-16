#include<iostream>
using namespace std;
class LowerTriangular
{
private:
    int *A;
    int n;
public:
    LowerTriangular()
    {
        n = 2;
        A = new int[n*(n+1)/2];
    }
    LowerTriangular(int n)
    {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    ~LowerTriangular()
    {
        delete[] A;
    }
    void set(int i, int j, int x)
    {
        if(i >= j)
        {
            int index = (i*(i-1))/2 + (j-1);
            A[index] = x;
        }
    }
    int get(int i, int j)
    {
        if(i >= j)
        {
            int index = (i*(i-1))/2 + (j-1);
            return A[index];
        }
        else
            return 0;
    }
    void display()
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(i >= j)
                    cout << get(i, j) << " ";
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
    LowerTriangular d(n);
    cout << "Enter lower triangular elements:\n";
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cin >> x;
            d.set(i, j, x);
        }
    }
    cout << "\nMatrix:\n";
    d.display();
    return 0;
}