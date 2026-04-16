#include<stdio.h>
#include<stdlib.h>
struct matrix
{
    int *A;
    int n;
};
void set(struct matrix *m, int i, int j, int x)
{
    if(i >= j)
        m->A[i*(i-1)/2 + j-1] = x;
}
int get(struct matrix *m, int i, int j)
{
    if(i >= j)
        return m->A[i*(i-1)/2 + j-1];
    else
        return 0;
}
void display(struct matrix m)
{
    int i, j;
    for(i = 1; i <= m.n; i++)
    {
        for(j = 1; j <= m.n; j++)
        {
            printf("%d ", get(&m, i, j));
        }
        printf("\n");
    }
}
int main()
{
    struct matrix m;
    int i, j, x;
    printf("Enter dimension: ");
    scanf("%d", &m.n);
    m.A = (int *)malloc(m.n*(m.n+1)/2 * sizeof(int));
    for(i = 0; i < m.n*(m.n+1)/2; i++)
        m.A[i] = 0;
    printf("Enter full matrix:\n");
    for(i = 1; i <= m.n; i++)
    {
        for(j = 1; j <= m.n; j++)
        {
            scanf("%d", &x);
            if(i >= j)
                set(&m, i, j, x);
        }
    }
    printf("\nStored Matrix:\n");
    display(m);
    free(m.A);
    return 0;
}