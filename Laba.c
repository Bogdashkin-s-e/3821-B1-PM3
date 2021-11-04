#include <stdio.h>
#include <stdlib.h>

int main()
{
	long int N, i, ostINT;
	double min, max, ost, sum;
	double* massZn;
	int* massOst;
	min = 0.0; max = 0.0; N = 0; sum = 0;

	printf("N = \t");
	scanf("%ld", &N);
	
	if ((N == 10) || (N == 100) || (N == 1000) || (N == 10000) || (N == 100000) || (N == 1000000))
  {}
  else
  {
		printf("Error: invalid input N\n");
		return 0;
	}

	printf("min = \t");
	scanf("%lf", &min);
	printf("max = \t");
	scanf("%lf", &max);

	if ((min <= 0.0) || (max <= 0.0) || (max <= min))
	{
		printf("Error: invalid input");
		return 0;
	}

	massZn = (double*)malloc(N * sizeof(double));
	massOst = (int*)malloc(N * sizeof(int));

	for (i = 0; i < N; i++)
		massOst[i] = 0;

	for (i = 0; i < N; i++)
	{
		massZn[i] = (((double)rand()) / RAND_MAX * (max - min) + min);
		ost = (massZn[i] - (int)massZn[i])*N; 
		ostINT=(int)ost;
		/*printf("%lf \t % lf \t %ld \n", massZn[i], ost, ostINT);*/ // для теста
		massOst[ostINT]++ ;
	}

	for (i = 0; i < N; i++)
		if (massOst[i] > 0)
		{
			sum = sum - massZn[i];
		}
		else 
		{
			sum = sum + massZn[i];
		}
	printf("sum =  %lf \n", sum);
	free(massZn);
	free(massOst);
	return 0;
}