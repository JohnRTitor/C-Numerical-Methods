#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define   size   10

int main()
{
	 float a[size][size], solution[size], ratio;
	 int i,j,k,unknown;
	 /* Inputs */
	 /* 1. Reading number of unknowns */
	 printf("Enter number of unknowns variables: ");
	 scanf("%d", &unknown);
	 /* 2. Reading Augmented Matrix */
	 for(i=1;i<=unknown;i++)
	 {
		  for(j=1;j<=unknown+1;j++)
		  {
			   printf("a[%d][%d] = ",i,j);
			   scanf("%f", &a[i][j]);
		  }
	 }
	/* Applying Gauss Elimination */
	 for(i=1;i<=unknown-1;i++)
	 {
		  if(a[i][i] == 0.0)
		  {
			   printf("Mathematical Error!");
			   exit(0);
		  }
		  for(j=i+1;j<=unknown;j++)
		  {
			   ratio = a[j][i]/a[i][i];

			   for(k=1;k<=unknown+1;k++)
			   {
			  		a[j][k] = a[j][k] - ratio*a[i][k];
			   }
		  }
	 }
	 /* Obtaining Solution by Back Subsitution */
	 solution[unknown] = a[unknown][unknown+1]/a[unknown][unknown];

	 for(i=unknown-1;i>=1;i--)
	 {
		  solution[i] = a[i][unknown+1];
		  for(j=i+1;j<=unknown;j++)
		  {
		  		solution[i] = solution[i] - a[i][j]*solution[j];
		  }
		  solution[i] = solution[i]/a[i][i];
	 }
	 /* Displaying Solution */
	 printf("\nSolution:\n");
	 for(i=1;i<=unknown;i++)
	 {
	  	printf("solution[%d] = %0.3f\n",i, solution[i]);
	 }
	 return(0);
}