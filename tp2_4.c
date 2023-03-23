#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct compu
{
     int velocidad;  // entre 1 y 3 GHz
     int anio;       // entre 2015 y 2023
     int cantidad;   // entre 1 y 8
     char *tipo_cpu; // valores del arreglo tipos
}PC;

char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

void cargarListaComputadoras(PC listaComputadoras[]);
void mostrarCompu(PC compu);
void mostrarComputadoras(PC listaComputadoras[]);
void pcMasVieja(PC listaComputadoras[]);
void pcMayorVelocidad(PC listaComputadoras[]);

int main(){
     srand(time(NULL));
     PC listaComputadoras[5];

     cargarListaComputadoras(listaComputadoras);
     mostrarComputadoras(listaComputadoras);
     pcMasVieja(listaComputadoras);
     pcMayorVelocidad(listaComputadoras);

     return 0;
}

void cargarListaComputadoras(PC listaComputadoras[]){
     for (int i = 0; i < 5; i++){
          listaComputadoras[i].velocidad = rand() % 3 + 1;
          listaComputadoras[i].anio = rand() % 8 + 2015;
          listaComputadoras[i].cantidad = rand() % 8 + 1;
          listaComputadoras[i].tipo_cpu = *(tipos + i);
     }
}

void mostrarCompu(PC compu){
     printf("Velocidad de procesamiento: %d GHz\n", compu.velocidad);
     printf("Anio de fabricacion: %d\n", compu.anio);
     printf("Tipo de procesador: %s\n", compu.tipo_cpu);
     printf("Cantidad de nucleos: %d\n", compu.cantidad);
}

void mostrarComputadoras(PC listaComputadoras[]){
     for (int i = 0; i < 5; i++){
          printf("\nComputadora %d:\n", i+1);
          mostrarCompu(listaComputadoras[i]);
     }
}

void pcMasVieja(PC listaComputadoras[]){
     PC compuMasVieja;
     int indice = 0;
     compuMasVieja = listaComputadoras[0];
     for (int i = 0; i < 5; i++){
          if (listaComputadoras[i].anio < compuMasVieja.anio){
               compuMasVieja = listaComputadoras[i];
               indice = i;
          }
     }
     printf("\nLa compu mas vieja es la %d:\n", indice+1);
     mostrarCompu(compuMasVieja);
}

void pcMayorVelocidad(PC listaComputadoras[]){
     PC compuMayorVelocidad;
     int indice = 0;
     compuMayorVelocidad = listaComputadoras[0];
     for (int i = 0; i < 5; i++){
          if (listaComputadoras[i].velocidad > compuMayorVelocidad.velocidad)
          {
               compuMayorVelocidad = listaComputadoras[i];
               indice = i;
          }
     }
     printf("\nLa compu con mayor velocidad es la %d:\n", indice+1);
     mostrarCompu(compuMayorVelocidad);
}