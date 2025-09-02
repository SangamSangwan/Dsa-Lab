#include <stdio.h>

int main (){

int row,col;
printf("Enter the number of row and column ");
scanf("%d %d",&row,&col);

int arr[row][col];

printf("Enter the elements of array");
for(int i=0;i<row;i++)
{
    for(int j=0;j<col;j++)
    {
        scanf("%d",&arr[i][j]);
    }
}

printf("The given array is \n");
for(int i=0;i<row;i++)
{
    for(int j=0;j<col;j++)
    {
        printf("%d\t",arr[i][j]);
    }
    printf("\n");
}

    printf("Sum of each row:\n");
    for (int i = 0; i < row; i++) 
    {
        int rowSum = 0;
        for (int j = 0; j < col; j++) 
        {
            rowSum += arr[i][j];
        }
        printf("Row %d sum = %d\n", i + 1, rowSum);
    }

        printf("Sum of each column:\n");
    for (int j = 0; j < col; j++) 
    {
        int colSum = 0;
        for (int i = 0; i < row; i++) 
        {
            colSum += arr[i][j];
        }
        printf("Column %d sum = %d\n", j + 1, colSum);
    }
    return 0;
}