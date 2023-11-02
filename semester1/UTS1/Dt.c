#include <stdio.h>

int main() 
{
    int N;
    scanf("%d", &N);

    double puputTotal = 0.0;
    double pipitTotal = 0.0;
    double puput[N], pipit[N];

    for (int i = 0; i < N; i++) 
	{
        scanf("%lf %lf", &puput[i], &pipit[i]);
    }
    //		5
    //		3 	4 	6 	7 	8 	9 	2 	4 	7 	5
    //	   p1	p2	p1	p2	p1	p2	p1	p2	p1	p2
    //		0	0	1	1	2	2	3	3	4	4
    if(N % 2 == 0)
    {
        for(int i = 0; i < N; i += 2)
        {
        	puput[i] /= (3.0/4.0);
		}
	}
	else if(N % 2 == 1)
	{
		for(int i = 1; i < N; i+=2)
		{
			puput[i] /= (4.0/5.0);
		}
	}
	
		
	
	for(int i = 0; i < N; i++)
	{
    	puputTotal += puput[i];
    	pipitTotal += pipit[i];
	}
    
    if (puputTotal < pipitTotal) 
	{
    	printf("Pipit\n");
	} 
	else if (puputTotal == pipitTotal) 
	{
    	printf("Pipit\n");
	} 
	else 
	{
    	printf("Puput\n");
	}
    return 0;
}
