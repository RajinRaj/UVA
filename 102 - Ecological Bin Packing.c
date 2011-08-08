#include <stdio.h>
#include <stdlib.h>

int main()
{
   int max;
   int max_cmp;
   int total_bottle;
   int G1, B1, C1, G2, B2, C2, G3, B3, C3;
   char *order;
   while(scanf("%d %d %d %d %d %d %d %d %d", &B1, &G1, &C1, &B2, &G2, &C2, &B3, &G3, &C3) != EOF)
   {
      total_bottle = G1 + B1 + C1 + G2 + B2 + C2 + G3 + B3 + C3;
   
      order = "GCB";
      max = G1 + C2 + B3;
   
      max_cmp = G1 + B2 + C3;
      if(max_cmp >= max)
      {
         max = max_cmp;
         order = "GBC";
      }
   
      max_cmp = C1 + G2 + B3;
      if(max_cmp >= max)
      {
         max = max_cmp;
         order = "CGB";
      }
   
      max_cmp = C1 + B2 + G3;
      if(max_cmp >= max)
      {
         max = max_cmp;
         order = "CBG";
      }
   
      max_cmp = B1 + G2 + C3;
      if(max_cmp >= max)
      {
         max = max_cmp;
         order = "BGC";
      }
   
      max_cmp = B1 + C2 + G3;
      if(max_cmp >= max)
      {
         max = max_cmp;
         order = "BCG";
      }
   
      printf("%s %d\n", order, total_bottle-max);
      //system("pause");
   }
   return 0;
}
