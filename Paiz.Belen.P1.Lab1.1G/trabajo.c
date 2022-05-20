#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trabajo.h"
#include "servicio.h"


int inicializarTrabajo(eTrabajo vec[], int tam)
{
    int todoOk = 0;

    if(vec != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibreTrabajo(eTrabajo vec[], int tam, int* pIndex)
{
    int todoOk = 0;


    if(vec && pIndex && tam > 0 )
    {
        *pIndex = -1;
        for(int i = 0; i < tam; i++)
        {
            if(vec[i].isEmpty == 1)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaTrabajo(eTrabajo trab[], int tamT, eMoto vec[], int tam, eServicio serv[], int tamS,eTipo tip[], int tamTi, eColor col[], int tamC, int* pNextId, int* pFlagT, int flagM)
{
    int todoOk = 0;
    int indice;
    eTrabajo nuevoTrabajo;
    int bufferMoto;
    int bufferServicio;
    eFecha bufferFecha;


    if(trab != NULL && vec != NULL && pNextId != NULL && serv != NULL && tip != NULL && col != NULL && tamTi > 0 && tamC > 0 && tam > 0 && tamS > 0 && tamT > 0 && flagM != 1)
    {
        system("cls");
        printf("*** Alta Trabajo ***\n\n");
        buscarLibreTrabajo(trab, tamT, &indice);
        if(indice == -1)
        {
            printf("No hay lugar en el sistema.\n");
        }
        else
        {
            nuevoTrabajo.id = *pNextId;


            listarMotos(vec, tam, tip, tamTi, col, tamC, flagM);
            printf("Ingrese Id de Moto: ");
            scanf("%d",&bufferMoto);
            while(validarMoto(vec, tam, bufferMoto) == 0)
            {
                listarMotos(vec, tam, tip, tamTi, col, tamC, flagM);
                printf("Ingrese Id de Moto: ");
                scanf("%d",&bufferMoto);
                validarMoto(vec, tam, bufferMoto);
            }
            nuevoTrabajo.idMoto = bufferMoto;

            listarServicios(serv, tamS);
            printf("Ingrese Id de Servicio: ");
            scanf("%d",&bufferServicio);
            while(validarServicio(serv, tamS, bufferServicio) == 0)
            {
                listarServicios(serv, tamS);
                printf("Ingrese Id de Servicio: ");
                scanf("%d",&bufferServicio);
                validarServicio(serv, tamS, bufferServicio);
            }
            nuevoTrabajo.idServicio = bufferServicio;


            while(pidoValidoFecha(&bufferFecha)== 0)
            {
                if(pidoValidoFecha(&bufferFecha))
                {
                   break;
                }
            }
            nuevoTrabajo.fecha = bufferFecha;

            nuevoTrabajo.isEmpty = 0;

            trab[indice] = nuevoTrabajo;

            (*pNextId)++;
            *pFlagT = 0;
            todoOk = 1;
        }

    }
    else
    {
        printf("No hay motos cargadas en el sistema\n");
    }
    return todoOk;
}

int listarTrabajos(eTrabajo trab[], int tamTr, eServicio serv[], int tamS, int flagT)
{
    int todoOk = 0;

    if(trab != NULL && serv != NULL && tamTr > 0 && tamS > 0 && flagT != 1)
    {
        // system("cls");
        printf("******************  TRABAJOS  ********************\n\n");
        printf(" ID     ID MOTO       SERVICIO              FECHA \n");
        printf("---------------------------------------------------\n\n");

        for(int i = 0; i < tamTr; i++)
        {
            if( !trab[i].isEmpty)
            {
                mostrarTrabajoFila(trab[i], serv, tamS);
            }
        }
        todoOk = 1;
    }
    else
    {
        printf("No hay trabajos cargados en el sistema\n");
    }
    return todoOk;
}

void mostrarTrabajoFila(eTrabajo trab, eServicio serv[], int tamS)
{
    char descServ[20];

    cargarDescripcionServicio(serv, tamS, trab.idServicio, descServ);

    printf("%4d     %4d       %10s           %2d/%2d/%d\n",
           trab.id,
           trab.idMoto,
           descServ,
           trab.fecha.dia,
           trab.fecha.mes,
           trab.fecha.anio);
}

void mostrarTrabajo(eTrabajo trab, eServicio serv[], int tamS)
{
    char descServ[20];


    printf("\nId: %d\n", trab.id);
    printf("Moto: %d\n", trab.idMoto);
    cargarDescripcionServicio(serv, tamS, trab.idServicio, descServ);
    printf("Tipo: %s\n", descServ);
    printf("Fecha: %d/%d/%d\n", trab.fecha.dia, trab.fecha.mes, trab.fecha.anio);

}

int harcodearTrabajos(eTrabajo vec[], int tam, int* pNextId, int* pFlagT, int flagM)
{
    int todoOk = 0;
    int cant;

    eTrabajo trabajo[10] =
    {
        {0, 500, 20000 ,{29,3,2019},0},
        {0, 508, 20002 ,{2,9,2021},0},
        {0, 505, 20001 ,{9,12,2020},0},
        {0, 507, 20002 ,{14,8,2019},0},
        {0, 506, 20003 ,{12,5,2022},0},
        {0, 505, 20001 ,{5,11,2019},0},
        {0, 502, 20002 ,{23,6,2020},0},
        {0, 501, 20001 ,{16,1,2021},0},
        {0, 503, 20003 ,{31,3,2022},0},
        {0, 504, 20000 ,{2,7,2021},0},

    };
    printf("Que cantidad de trabajos desea dar de alta? 'MAXIMO 10': ");
    scanf("%d", &cant);
    while(cant < 0 || cant > 10)
    {
        printf("Que cantidad de trabajos desea dar de alta? 'MAXIMO 10': ");
        scanf("%d", &cant);
    }

    if(vec != NULL && pNextId != NULL && tam >= 0 && cant >= 0 && cant < 11 && flagM != 1)
    {
        for(int i = 0; i < cant; i++)
        {
            vec[i] = trabajo[i];
            vec[i].id = *pNextId;
            (*pNextId)++;
        }
        *pFlagT = 0;
        todoOk = 1;
    }
    else
    {
        printf("No hay motos cargadas en el sistema\n");
    }
    return todoOk;
}

int menuInformesTrabajos()
{
    int opcion;

    printf("\n*** INFORMES DE TRABAJOS Y SERVICIOS ***\n\n");
    printf("1. Listar trabajos de Motos por Id\n");
    printf("2. Total de Importes a pagar por moto con Id\n");
    printf("3. listar trabajo por id Servicio\n");
    printf("4. listar Servicios en determinada fecha\n");
    printf("Ingrese Opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
int InformesTrabajos(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC, eTrabajo trab[], int tamTr, eServicio serv[], int tamS, int flagM, int flagT)
{
    int todoOk = 0;

    if(vec && tip && col && trab && serv && tam > 0 && tamT > 0 && tamC > 0 && tamTr > 0 && tamS > 0 && flagT != 1)
    {
        switch(menuInformesTrabajos())
        {
        case 1:
            trabajosPorIdMoto(trab, tamTr, vec, tam, serv, tamS, tip, tamT, col, tamC, flagM);
            break;
        case 2:
            TotalImportesServiciosId(trab, tamTr, vec, tam, serv, tamS, tip, tamT, col, tamC, flagM);
            break;
        case 3:
            serviciosMotosId(trab, tamTr, vec, tam, serv, tamS);
            break;
        case 4:
            fechaServicios(trab, tamTr, serv, tamS, flagT);
            break;


        }
    }
    else
    {
        printf("Para acceder a los informes primero debe cargar trabajos en el sistema\n");
    }
    todoOk = 1;
    return todoOk;
}

int trabajosPorIdMoto(eTrabajo trab[], int tamT, eMoto vec[], int tam, eServicio serv[], int tamS,eTipo tip[], int tamTi, eColor col[], int tamC, int flagM)
{
    int todoOk = 0;
    int bufferMoto;

    if(trab != NULL && vec != NULL && serv != NULL && tip != NULL && tamT > 0 && tam > 0 && tamS > 0 && tamTi > 0)
    {
        listarMotos(vec, tam, tip, tamTi, col, tamC, flagM);
        printf("Ingrese Id de Moto: ");
        scanf("%d",&bufferMoto);
        while(validarMoto(vec, tam, bufferMoto) == 0)
        {
            listarMotos(vec, tam, tip, tamTi, col, tamC, flagM);
            printf("Ingrese Id de Moto: ");
            scanf("%d",&bufferMoto);
            validarMoto(vec, tam, bufferMoto);
        }
        printf("************  TRABAJOS PARA ID MOTO %d *************\n\n", bufferMoto);
        printf(" ID     ID MOTO       SERVICIO              FECHA \n");
        printf("---------------------------------------------------\n\n");
        for(int i=0; i < tamT; i++)
        {
            if(!trab[i].isEmpty && trab[i].idMoto == bufferMoto)
            {
                mostrarTrabajoFila(trab[i], serv, tamS);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int TotalImportesServiciosId(eTrabajo trab[], int tamT, eMoto vec[], int tam, eServicio serv[], int tamS,eTipo tip[], int tamTi, eColor col[], int tamC, int flagM)
{
    int todoOk = 0;
    int bufferMoto;
    float acumPrecios = 0;


    if(trab != NULL && vec != NULL && serv != NULL && tip != NULL && tamT > 0 && tam > 0 && tamS > 0 && tamTi > 0)
    {
        listarMotos(vec, tam, tip, tamTi, col, tamC, flagM);
        printf("Ingrese Id de Moto: ");
        scanf("%d",&bufferMoto);
        while(validarMoto(vec, tam, bufferMoto) == 0)
        {
            listarMotos(vec, tam, tip, tamTi, col, tamC, flagM);
            printf("Ingrese Id de Moto: ");
            scanf("%d",&bufferMoto);
            validarMoto(vec, tam, bufferMoto);
        }
        for(int i=0; i < tamT; i++)
        {
            if(!trab[i].isEmpty && trab[i].idMoto == bufferMoto)
            {
                for(int j=0; j < tamS; j++)
                {
                    if(trab[i].idServicio == serv[j].id)
                    {
                        acumPrecios += serv[j].precio;
                    }
                }
            }
        }
        printf("El total a pagar de la moto id nro: %d es: $%.2f\n", bufferMoto, acumPrecios);
        todoOk = 1;
    }
    return todoOk;
}

int serviciosMotosId(eTrabajo trab[], int tamTr, eMoto vec[], int tam, eServicio serv[], int tamS)
{
    int todoOk = 0;
    int bufferServicio;
    char descServ[20];
    char marcaMoto[20];

    if(trab && vec && serv && tamTr > 0 && tam > 0 && tamS > 0)
    {
        listarServicios(serv, tamS);
        printf("Ingrese Id de Servicio: ");
        scanf("%d",&bufferServicio);
        while(validarServicio(serv, tamS, bufferServicio) == 0)
        {
            listarServicios(serv, tamS);
            printf("Ingrese Id de Servicio: ");
            scanf("%d",&bufferServicio);
            validarServicio(serv, tamS, bufferServicio);
        }
        cargarDescripcionServicio(serv, tamS, bufferServicio, descServ);
        strupr(descServ);
        system("cls");
        printf("******** SERVICIO DE %s *********\n\n", descServ);
        printf(" ID MOTO     MARCA       FECHA \n");
        printf("--------------------------------\n\n");

        for(int i = 0; i < tamTr; i++)
        {
            if( !trab[i].isEmpty && trab[i].idServicio == bufferServicio)
            {
                cargarMarcaMoto(vec, tam, trab[i].idMoto, marcaMoto);
                printf(" %4d   %10s     %2d/%2d/%d\n", trab[i].idMoto, marcaMoto, trab[i].fecha.dia, trab[i].fecha.mes, trab[i].fecha.anio);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int fechaServicios(eTrabajo trab[], int tamTr, eServicio serv[], int tamS, int flagT)
{
    int todoOk = 0;
    eFecha bufferFecha;
    char descServ[20];
    int flag = 1;

    if(trab && serv && tamTr > 0 && tamS > 0)
    {
        listarTrabajos(trab, tamTr, serv, tamS, flagT);
        printf("Ingrese fecha: \n");
        while(pidoValidoFecha(&bufferFecha)== 0)
            {
                if(pidoValidoFecha(&bufferFecha))
                {
                    break;
                }
            }
        printf("Servicios realizados en la fecha: %2d/%2d/%d\n\n", bufferFecha.dia, bufferFecha.mes, bufferFecha.anio);
        for(int i=0; i < tamTr; i++)
        {
            if(trab[i].fecha.dia == bufferFecha.dia
               && trab[i].fecha.mes == bufferFecha.mes
               && trab[i].fecha.anio == bufferFecha.anio)
            {
                cargarDescripcionServicio(serv, tamS, trab[i].idServicio, descServ);
                printf("** %10s\n", descServ);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("No se realizaron servicios en esa fecha\n");
        }
        todoOk = 1;
    }
    return todoOk;
}
