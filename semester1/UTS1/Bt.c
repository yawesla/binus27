#include <stdio.h>

int main() 
{
    int N, min;
    scanf("%d %d", &N, &min);
    
    
    int matrix[N][N];
    for (int i = 0; i < N; i++) 
	{
        for (int j = 0; j < N; j++) 
		{
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int doubleheal = min*min;
    int nevin = 99999999;
    int row;
    int column;
    for (int i = 0; i < N; i++) 
	{
        for (int j = 0; j < N; j++) 
		{
            if (matrix[i][j] < nevin) 
			{
                nevin = matrix[i][j];
                row = i;
                column = j;
            }
        }
    }
    
    for(int i = 0; i < N; i++)
    {
    	for(int j = 0; j < N; j++)
    	{
    		if(row == i && column == j)
    		{
    			matrix[i][j] += doubleheal;
    			if(matrix[i][j] >= 10000)
    			{
    				matrix[i][j] = 10000;
				}
			}
			else if(row == i || column == j)
			{
				matrix[i][j] += min;
				if(matrix[i][j] >= 10000)
				{
					matrix[i][j] = 10000;
				}
			}
		}
	}
    
    
    printf("ans: ");
    for (int i = 0; i < N; i++) 
	{
        for (int j = 0; j < N; j++) 
		{
			printf("%d ", matrix[i][j]);
        }
    }
        printf("\n");

    return 0;
}
