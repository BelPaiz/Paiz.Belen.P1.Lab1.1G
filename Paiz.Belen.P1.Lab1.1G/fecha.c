#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"


//validar Fecha


int validoAnio(int anio)
{
    int todoOk;

    int anioActual = 2022;
    if(anio < 1950 || anio > anioActual)
    {
        todoOk = 0;
        printf("Anio invalido\n");
    }
    else
    {
        todoOk = 1;
    }
    return todoOk;
}
int validoAnioBisiesto(int anio)
{
    int todoOk = 0;
    if(validoAnio(anio))
    {
        if(anio % 4 == 0)
        {
            todoOk = 2;
        }
        else
        {
            todoOk = 1;
        }
    }
    return todoOk;

}
int validoMes(int mes)
{
    int todoOk;
    if(mes < 1 || mes > 12)
    {
        todoOk = 0;
        printf("Mes invalido\n");
    }
    else
    {
        todoOk = 1;
    }
    return todoOk;
}

int validoDia(int dia)
{
    int todoOk;
    if(dia < 1 || dia > 31)
    {
        todoOk = 0;
        printf("Dia invalido\n");
    }
    else
    {
        todoOk = 1;
    }
    return todoOk;
}
int validoDiaMes(int mes, int dia, int anio)
{
    int todoOk = 1;
    if(validoDia(dia) && validoMes(mes) && validoAnio(anio))
    {
        if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
        {
            if(dia > 30)
            {
                printf("Este mes solo tiene 30 dias\n");
                todoOk = 0;
            }

        }
        else
        {
            if(mes == 2)
            {
                if((validoAnioBisiesto(anio)) == 2)
                {
                    if(dia > 29)
                    {
                        printf("Este mes solo tiene 29 dias.\n");
                        todoOk = 0;
                    }

                }
                else
                {
                    if(dia > 28)
                    {
                        printf("Este mes solo tiene 28 dias.\n");
                        todoOk = 0;
                    }
                }
            }
            else
            {
                if(dia > 31)
                {
                    printf("Este mes solo tiene 31 dias.\n");
                    todoOk = 0;
                }
            }
        }

    }
    return todoOk;
}

int pidoValidoFecha(eFecha* fecha)
{
    int todoOk = 1;
    eFecha nuevaFecha;

    printf("Ingrese dia:");
    scanf("%d", &nuevaFecha.dia);
    while(!validoDia(nuevaFecha.dia))
    {
        printf("Ingreso Invalido\n Reingrese dia:");
        scanf("%d", &nuevaFecha.dia);
    }
    printf("Ingrese mes:");
    scanf("%d", &nuevaFecha.mes);
    while(!validoMes(nuevaFecha.mes))
    {
        printf("Ingreso Invalido\n Reingrese mes:");
        scanf("%d", &nuevaFecha.mes);
    }
    printf("Ingrese año:");
    scanf("%d", &nuevaFecha.anio);
    while(!validoAnio(nuevaFecha.anio))
    {
        printf("Ingreso Invalido\n Reingrese año:");
        scanf("%d", &nuevaFecha.anio);
    }
    while(!validoDiaMes(nuevaFecha.mes, nuevaFecha.dia, nuevaFecha.anio))
    {
        printf("Ingreso Invalido. Reintente\n");
        todoOk = 0;
        break;
    }
    *fecha = nuevaFecha;
    return todoOk;
}

