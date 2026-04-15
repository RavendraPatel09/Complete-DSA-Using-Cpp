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
}
void set(struct matrix *m, int i, int j, int x)
{
int get(struct matrix m, int i, int j)
void display();
diagonal(int n);
};
void diagonal::set(struct matrix *m, int i, int j, int x)
{
    if (i == j)
        m->A[i - 1] = x;
}
int diagonal::get(struct matrix m, int i, int j)
{
    if (i == j)
        return m.A[i - 1];
    else
        return 0;
}
void diagonal::display(struct matrix m)
{
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            if (i == j)
                cout << m.A[i - 1] << " ";
            else                cout << "0 ";
        }
        cout << endl;   
    }
}
int main()
{
    struct matrix m;
    m.n = 4;
    set(&m, 1, 1, 5);
    set(&m, 2, 2, 8);
    set(&m, 3, 3, 9);
    set(&m, 4, 4, 6);
    display(m);
    return 0;
}
