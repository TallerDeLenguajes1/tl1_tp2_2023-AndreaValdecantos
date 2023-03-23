#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 7

int main(){
     srand(time(NULL));
     int i, j;
     int *pElemento;
     int mt[N][M];
     pElemento = &mt[0][0];

     for (i = 0; i < N; i++)
     {
          for (j = 0; j < M; j++)
          {
               *pElemento = 1 + rand() % 100;
               printf("%d\t", *pElemento);
               pElemento++;
          }
          printf("\n");
     }

     return 0;
}