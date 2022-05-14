#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"
#include "color.h"

int cargarDescripcionTipo(eTipo tip[], int tam, int id, char desc[])
{
    int todoOk = 0;

    if(tip != NULL && desc != NULL && tam > 0)
    {
      for(int i = 0; i < tam; i++)
      {
          if(tip[i].id == id)
          {
              strcpy(desc, tip[i].descripcion);
              todoOk = 1;
              break;
          }
      }
    }
    return todoOk;
}

int listarTipos(eTipo tip[], int tam)
{
    int todoOk = 0;

    if(tip != NULL && tam > 0)
    {
        printf("    *** TIPOS ***    \n");
        printf("    ID     DESCRIPCION\n");
        printf("-----------------------\n");
      for(int i = 0; i < tam; i++)
      {
            printf("    %4d         %10s\n", tip[i].id, tip[i].descripcion);
      }
      todoOk = 1;
    }
    return todoOk;
}

int buscarTipo(eTipo tip[], int tam, int id, int* pIndex)
{
    int todoOk = 0;


    if(tip && pIndex && tam > 0 )
    {
        *pIndex = -1;
        for(int i = 0; i < tam; i++)
        {
            if(tip[i].id == id)
            {
                *pIndex = i;
                break;
            }
            todoOk = 1;
        }
    }
    return todoOk;
}

int validarTipo(eTipo tip[], int tam, int id)
{
    int esValido = 0;
    int indice;

    if(buscarTipo(tip, tam, id, &indice) == 1)
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }
    return esValido;
}

