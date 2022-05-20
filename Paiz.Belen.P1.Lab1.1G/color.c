#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

int cargarDescripcionColor(eColor col[], int tam, int id, char desc[])
{
    int todoOk = 0;

    if(col != NULL && desc != NULL && tam > 0)
    {
      for(int i = 0; i < tam; i++)
      {
          if(col[i].id == id)
          {
              strcpy(desc, col[i].nombreColor);
              todoOk = 1;
              break;
          }
      }
    }
    return todoOk;
}

int listarColores(eColor col[], int tam)
{
    int todoOk = 0;

    if(col != NULL && tam > 0)
    {
        printf("    *** COLORES ***    \n");
        printf("    ID           DESCRIPCION\n");
        printf("-----------------------------\n");
      for(int i = 0; i < tam; i++)
      {
            printf("    %4d         %10s\n", col[i].id, col[i].nombreColor);
      }
      todoOk = 1;
    }
    return todoOk;
}

int buscarColor(eColor col[], int tam, int id, int* pIndex)
{
    int todoOk = 0;


    if(col && pIndex && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(col[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarColor(eColor col[], int tam, int id)
{
    int esValido = 0;
    int indice;

    if(buscarColor(col, tam, id, &indice) == 1)
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }
    return esValido;
}

