#include <stdio.h>
#include <stdlib.h>
#include "validacionesDatos.h"

int validarLetras(char letras[])
{
    int todoOk = 1;
    int esLetra;

    if(letras != NULL)
    {
        for(int i = 0; i < strlen(letras) -1; i++)
        {
            esLetra = isalpha(letras[i]);
            if(esLetra == 0)
            {
              todoOk = 0;
              break;
            }
        }
    }

    return todoOk;
}

int pidoValidoLetras(char cadena[], int tam, char mensaje[])
{
    int todoOk = 0;
    char buffer[100];

    if(cadena != NULL && mensaje != NULL && tam > 0)
    {
        printf("Ingrese %s: ", mensaje);
        fflush(stdin);
        fgets(buffer, tam, stdin);
        while(validarLetras(buffer) == 0)
        {
            printf("Ingreso invalido.\nReingrese %s: ", mensaje);
            fflush(stdin);
            fgets(buffer, tam, stdin);
        }
        strcpy(cadena, buffer);
        todoOk = 1;
    }
    return todoOk;
}
