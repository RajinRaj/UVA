#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 26

int total_intersection = 0;
int count[MAX] = {0};
int intersection[MAX][MAX];
int odd[2] = {0};
int total_length = 0;

void initialize();
void printall();

int main()
{
   char street[MAX];
   int street_len;
   int start, end;
   int i, j, k;
   int tmp;
   
   while(scanf("%s", street) != EOF)
   {
      if(strcmp(street, "deadend") == 0)
      {
         for(i = 0; i < MAX; i++)
         {
            if((count[i]%2 == 1))
            {
               if(odd[0] != 0)odd[1] = i;
               else odd[0] = i;
            }
         }
         
         if((odd[0] != 0) || (odd[1] != 0))
         {
            for(k = 0; k < MAX; k++)
            {
               for(i = 0; i < MAX; i++)
               {
                  for(j = 0; j < MAX; j++)
                  {
                     if( intersection[i][k]*intersection[k][j] != 0 ){
                        tmp = intersection[i][k] + intersection[k][j];
                        if( tmp < intersection[i][j] || intersection[i][j] == 0 )
                           intersection[i][j] = tmp;
                     }
                  }
               }
            }
            total_length += intersection[odd[0]][odd[1]];
         }
         printf("%d\n", total_length);
         initialize();
      }
      else
      {
         street_len = strlen(street);
         start = (street[0]%97);
         end = (street[street_len-1]%97);
         intersection[start][end] = street_len;
         intersection[end][start] = street_len;
         total_length += street_len;
         count[start]++;
         count[end]++;
         total_intersection++;
      }
   }
   return 0;
}

void printall()
{
   int i, j;
   for(i = 0; i < MAX; i++)
   {
      for(j = 0; j < MAX; j++)printf("%2d ", intersection[i][j]);
      printf("\n");
   }
   printf("\n");
} 

void initialize()
{
   int i, j;
   
   for(i = 0; i < MAX; i++)
   {
      count[i] = 0;
      for(j = 0; j < MAX; j++)intersection[i][j];
   }
   total_length = 0;
   total_intersection = 0;
   odd[0] = 0;
   odd[1] = 0;
   return;
}
