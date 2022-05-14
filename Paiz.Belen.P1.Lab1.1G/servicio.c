#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "servicio.h"


int cargarDescripcionServicio(eServicio serv[], int tam, int id, char desc[])
{
    int todoOk = 0;

    if(serv != NULL && desc != NULL && tam > 0)
    {
      for(int i = 0; i < tam; i++)
      {
          if(serv[i].id == id)
          {
              strcpy(desc, serv[i].descripcion);
              todoOk = 1;
              break;
          }
      }
    }
    return todoOk;
}
int listarServicios(eServicio serv[], int tam)
{
    int todoOk = 0;

    if(serv != NULL && tam > 0)
    {
        printf("    *** LISTADO DE SERVICIOS ***    \n");
        printf("    ID            DESCRIPCION         PRECIOS\n");
        printf("---------------------------------------------\n");
      for(int i = 0; i < tam; i++)
      {
            printf("    %4d         %10s          %4.2f\n", serv[i].id, serv[i].descripcion, serv[i].precio);
      }
      todoOk = 1;
    }
    return todoOk;
}

int buscarServicio(eServicio serv[], int tam, int id, int* pIndex)
{
    int todoOk = 0;


    if(serv && pIndex && tam > 0 )
    {
        *pIndex = -1;
        for(int i = 0; i < tam; i++)
        {
            if(serv[i].id == id)
            {
                *pIndex = i;
                break;
            }
            todoOk = 1;
        }
    }
    return todoOk;
}

int validarServicio(eServicio serv[], int tam, int id)
{
    int esValido = 0;
    int indice;

    if(buscarServicio(serv, tam, id, &indice) == 1)
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }
    return esValido;
}
