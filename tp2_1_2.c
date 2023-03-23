#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int main()
{
     srand(time(NULL));
     int i;
     double *pVt;
     double vt[N];
     pVt = &vt[0];
     for (i = 0; i < N; i++)
     {
          *pVt = 1 + rand() % 100;
          printf("%f\t", *pVt);
          pVt++;
     }

     return 0;
}