#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *A, n, ch, i, j, x;
    printf("Enter dimension: ");
    scanf("%d", &n);
    A = (int *)malloc((2 * n - 1) * sizeof(int));
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
                    if (i <= j)
                        scanf("%d", &A[j - i]);
                    else
                        scanf("%d", &A[n + i - j - 1]);
                }
            }
            break;
        case 2:
            scanf("%d %d", &i, &j);
            if (i <= j)
                printf("%d\n", A[j - i]);
            else
                printf("%d\n", A[n + i - j - 1]);
            break;
        case 3:
            scanf("%d %d %d", &i, &j, &x);
            if (i <= j)
                A[j - i] = x;
            else
                A[n + i - j - 1] = x;
            break;
        case 4:
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= n; j++)
                {
                    if (i <= j)
                        printf("%d ", A[j - i]);
                    else
                        printf("%d ", A[n + i - j - 1]);
                }
                printf("\n");
            }
            break;
        }
    } while (ch != 5);
    free(A);
    return 0;
}