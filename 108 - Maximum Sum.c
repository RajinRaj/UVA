#include <stdio.h>
//#include <stdlib.h>
#define MAX 100

int main()
{
   int array[MAX][MAX];
   int max = 0;
   int sum = 0;
   int i, j, k;
   int dim;
   
   scanf("%d", &dim);
   for(i = 0; i < dim; i++)
   {
      for(j = 0; j < dim; j++)
      {
         scanf("%d", &array[i][j]);
      }
   }
   /*Calculate vertical sum*/
   for(i = 0; i < dim; i++)
   {
      for(j = 1; j < dim; j++)
      {
         array[j][i] += array[j-1][i];
      }//row
   }//column
   
   max = array[0][0];
   for(i = 0; i < dim; i++)
   {
      for(j = i; j < dim; j++)
      {
         sum = 0;
         for(k = 0; k < dim; k++)
         {
            if(i == j || i == 0)sum += array[j][k];
            else sum += (array[j][k] - array[i-1][k]);
            if(sum > max)max = sum;
            else if(sum < 0)sum = 0;
         }
      }//end row
   }//start row
   
   printf("%d\n", max);
   //system("pause");
   return 0;
}
