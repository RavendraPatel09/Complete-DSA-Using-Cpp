#include <stdio.h>
#include <stdlib.h>
struct diagonal
{
    int n;
    int *A;
};
void create(struct diagonal *d, int n)
{
    d->n = n;
    d->A = (int *)malloc(n * sizeof(int));
}
void set(struct diagonal *d, int i, int j, int x)
{
    if (i == j)
        d->A[i - 1] = x;
}
int get(struct diagonal *d, int i, int j)
{
    if (i == j)
        return d->A[i - 1];
    else
        return 0;
}
void display(struct diagonal d)
{
    for (int i = 1; i <= d.n; i++)
    {
        for (int j = 1; j <= d.n; j++)
        {
            if (i == j)
                printf("%d ", d.A[i - 1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
int main()
{
    struct diagonal d;
    create(&d, 4);
    set(&d, 1, 1, 5);
    set(&d, 2, 2, 8);
    set(&d, 3, 3, 9);
    set(&d, 4, 4, 6);
    display(d);
    return 0;
}