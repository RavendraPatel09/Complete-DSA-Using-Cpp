#include <stdio.h>
#include <stdlib.h>
int getIndex(int i, int j)
{
    if (i >= j)
        return (i * (i - 1)) / 2 + (j - 1);
    else
        return (j * (j - 1)) / 2 + (i - 1);
}
int main()
{
    int *A, n, ch, i, j, x;
    printf("Enter dimension: ");
    scanf("%d", &n);
    A = (int *)malloc(n * (n + 1) / 2 * sizeof(int));
    do
    {
        switch (ch)
        {
        case 1: 
            printf("Enter elements (only lower triangle):\n");
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= i; j++)
                {
                    scanf("%d", &A[getIndex(i, j)]);
                }
            }
            break;
        case 2:
            printf("Enter i and j: ");
            scanf("%d %d", &i, &j);
            printf("Element = %d\n", A[getIndex(i, j)]);
            break;
        case 3:
            printf("Enter i, j and value: ");
            scanf("%d %d %d", &i, &j, &x);
            A[getIndex(i, j)] = x;
            break;
        case 4:
            printf("Matrix:\n");
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= n; j++)
                {
                    printf("%d ", A[getIndex(i, j)]);
                }
                printf("\n");
            }
            break;
        }
    } while (ch != 5);
    return 0;
}