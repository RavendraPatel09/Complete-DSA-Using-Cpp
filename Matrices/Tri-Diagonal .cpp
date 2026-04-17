#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *A, n, ch, i, j, x;
    printf("Enter dimension: ");
    scanf("%d", &n);
    A = (int *)malloc((3 * n - 2) * sizeof(int));
    do
    {
        printf("\n1. Create\n2. Get\n3. Set\n4. Display\n5. Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= n; j++)
                {
                    if (i - j == 1)
                        scanf("%d", &A[i - 2]);
                    else if (i - j == 0)
                        scanf("%d", &A[n - 1 + i - 1]);
                    else if (i - j == -1)
                        scanf("%d", &A[2 * n - 1 + i - 1]);
                }
            }
            break;
        case 2:
            scanf("%d %d", &i, &j);
            if (i - j == 1)
                printf("%d\n", A[i - 2]);
            else if (i - j == 0)
                printf("%d\n", A[n - 1 + i - 1]);
            else if (i - j == -1)
                printf("%d\n", A[2 * n - 1 + i - 1]);
            else
                printf("0\n");
            break;
        case 3:
            scanf("%d %d %d", &i, &j, &x);
            if (i - j == 1)
                A[i - 2] = x;
            else if (i - j == 0)
                A[n - 1 + i - 1] = x;
            else if (i - j == -1)
                A[2 * n - 1 + i - 1] = x;
            break;
        case 4:
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= n; j++)
                {
                    if (i - j == 1)
                        printf("%d ", A[i - 2]);
                    else if (i - j == 0)
                        printf("%d ", A[n - 1 + i - 1]);
                    else if (i - j == -1)
                        printf("%d ", A[2 * n - 1 + i - 1]);
                    else
                        printf("0 ");
                }
                printf("\n");
            }
            break;
        }
    } while (ch != 5);
    free(A);
    return 0;
}

