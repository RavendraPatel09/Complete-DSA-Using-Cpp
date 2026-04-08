#include <stdio.h>
#include <stdlib.h>
int main()
{
    int A[3][4]={{1,2,3,4},{2,4,6,8},{3,6,9,12}};
    int *B[3];
    int **C;
    int i,j;
    for (i=0;i<3;i++)
    {
        for (j=0;j<4;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    B[0]=(int *)malloc(4*sizeof(int));//created in heap memory
    B[1]=(int *)malloc(4*sizeof(int));
    B[2]=(int *)malloc(4*sizeof(int));
    for (i=0;i<3;i++)
    {
        for (j=0;j<4;j++)
        {
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }
    C=(int **)malloc(3*sizeof(int *));
    C[0]=(int *)malloc(4*sizeof(int));//created in heap memory
    C[1]=(int *)malloc(4*sizeof(int));
    C[2]=(int *)malloc(4*sizeof(int));
    return 0;
}

