#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "moto.h"
#include "validacionesDatos.h"


int inicializarMotos(eMoto vec[], int tam)
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

void confirmarSalida(char* x)
{
    printf("Confirma que desea salir?: ");
    fflush(stdin);
    scanf("%c",x);
}

void informarNoEsNumero()
{
    printf("Eso no es un numero.\n");
}

int menuMoto()
{
    int opcion;
    int opcionIngresada;

    system("cls");
    printf("   *** Service de Motos ***\n\n");
    printf("1. Alta Moto\n");
    printf("2. Modificar moto\n");
    printf("3. Baja moto\n");
    printf("4. Listar moto\n");
    printf("5. Listar tipos\n");
    printf("6. Listar colores\n");
    printf("7. Listar servicios\n");
    printf("8. Alta trabajo\n");
    printf("9. Listar trabajo\n");
    printf("10. salir\n");
    printf("Ingrese Opcion: ");
    fflush(stdin);

    opcionIngresada = (scanf("%d", &opcion));

    if(opcionIngresada == 0)
    {
        opcion = 100;
    }
    return opcion;

}

int buscarLibre(eMoto vec[], int tam, int* pIndex)
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
            todoOk = 1;
        }
    }
    return todoOk;
}

int altaMoto(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC, int* pNextId)
{
    int todoOk = 0;
    int indice;
    eMoto nuevaMoto;
    int bufferTipo;
    int bufferColor;
    int bufferCilindrada;
    int bufferPuntaje;

    if(vec != NULL && pNextId != NULL && tip != NULL && tam > 0 && tamT > 0)
    {
        system("cls");
        printf("*** Alta Moto ***\n\n");
        buscarLibre(vec, tam, &indice);
        if(indice == -1)
        {
            printf("No hay lugar en el sistema.\n");
        }
        else
        {
            nuevaMoto.id = *pNextId;
            pidoValidoLetras(nuevaMoto.marca, tam, "Marca");

            fflush(stdin);

            listarTipos(tip, tamT);
            printf("Ingrese Id Tipo: ");
            scanf("%d", &bufferTipo);

            while(validarTipo(tip, tamT, bufferTipo) == 0)
            {
                listarTipos(tip, tamT);
                printf("Ingrese Id Tipo Valido: ");
                scanf("%d", &bufferTipo);
            }
            nuevaMoto.idTipo = bufferTipo;

            listarColores(col, tamC);
            printf("Ingrese Id Color: ");
            scanf("%d", &bufferColor);

            while(validarColor(col, tamC, bufferColor) == 0)
            {
                listarColores(col, tamC);
                printf("Ingrese Id Color Valido: ");
                scanf("%d", &bufferColor);
            }
            nuevaMoto.idColor = bufferColor;

            listarCilindradas();
            printf("Ingrese cilindrada: ");
            scanf("%d", &bufferCilindrada);
            while(bufferCilindrada != 50
                    && bufferCilindrada != 500
                    && bufferCilindrada != 125
                    && bufferCilindrada != 600
                    && bufferCilindrada != 750)
            {
                listarCilindradas();
                printf("Ingrese cilindrada Valida: ");
                scanf("%d", &bufferCilindrada);
            }
            nuevaMoto.cilindrada = bufferCilindrada;

            printf("Ingrese Puntaje: ");
            scanf("%d", &bufferPuntaje);
            while(bufferPuntaje < 1 || bufferPuntaje > 10)
            {
                printf("Ingrese Puntaje: ");
                scanf("%d", &bufferPuntaje);
            }
            nuevaMoto.puntaje = bufferPuntaje;

            nuevaMoto.isEmpty = 0;

            vec[indice] = nuevaMoto;

            (*pNextId)++;
            todoOk = 1;
        }

    }
    return todoOk;
}

void listarCilindradas()
{
    printf("*** CILINDRADAS DISPONIBLES ***\n");
    printf("50cc\n");
    printf("125cc\n");
    printf("500cc\n");
    printf("600cc\n");
    printf("750cc\n");
}

int buscarMoto(eMoto vec[], int tam, int id, int* pIndex)
{
    int todoOk = 0;


    if(vec && pIndex && tam > 0 )
    {
        *pIndex = -1;
        for(int i = 0; i < tam; i++)
        {
            if(!vec[i].isEmpty && vec[i].id == id)
            {
                *pIndex = i;
                break;
            }
            todoOk = 1;
        }
    }
    return todoOk;
}

void mostrarMoto (eMoto vec, int tam, eTipo tip[], int tamT, eColor col[], int tamC)
{
    char descTip[20];
    char descCol[20];

    printf("\nId: %d\n", vec.id);
    printf("Marca: %s\n", vec.marca);
    cargarDescripcionTipo(tip, tamT, vec.idTipo, descTip);
    printf("Tipo: %s\n", descTip);
    cargarDescripcionColor(col, tamC, vec.idColor, descCol);
    printf("Color: %s\n", descCol);
    printf("Cilindrada: %d\n", vec.cilindrada);
    printf("Puntaje: %d\n", vec.puntaje);

}

int listarMotos(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC)
{
    int todoOk = 0;
    int flag = 1;

    if(vec != NULL && tip != NULL && col != NULL && tam > 0 && tamT > 0 && tamC > 0)
    {
        // system("cls");
        printf("*************************************** MOTOS **************************************\n\n");
        printf(" ID           MARCA            TIPO            COLOR     CILINDRADA          PUNTAJE \n");
        printf("-------------------------------------------------------------------------------------\n\n");

        for(int i = 0; i < tam; i++)
        {
            if( !vec[i].isEmpty)
            {
                mostrarMotoFila(vec[i], tam, tip, tamT, col, tamC);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("No hay motos cargadas en el sistema.\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

void mostrarMotoFila(eMoto vec, int tam, eTipo tip[], int tamT, eColor col[], int tamC)
{
    char descTip[20];
    char descCol[20];

    cargarDescripcionTipo(tip, tamT, vec.idTipo, descTip);
    cargarDescripcionColor(col, tamC, vec.idColor, descCol);

    printf("%4d     %10s       %10s      %10s       %4d               %4d\n",
           vec.id,
           vec.marca,
           descTip,
           descCol,
           vec.cilindrada,
           vec.puntaje);
}

int bajaMoto(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;

    if(vec != NULL && tam > 0 )
    {
        listarMotos(vec, tam, tip, tamT, col, tamC);
        printf("Ingrese Id: ");
        scanf("%d",&id);

        if(buscarMoto(vec, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("No existe un empleado con id %d en el sistema.\n", id);
            }
            else
            {
                mostrarMoto(vec[indice], tam, tip, tamT, col, tamC);
                printf("Presione 's' para confirmar baja: ");
                fflush(stdin);
                scanf("%c",&confirma);

                if(confirma == 's' || confirma == 'S')
                {
                    vec[indice].isEmpty = 1;
                    printf("Baja exitosa!\n");
                }
                else
                {
                    printf("Baja cancelada por el usuario!\n");
                }
            }
            todoOk = 1;
        }
    }
    return todoOk;
}

int harcodearMotos(eMoto vec[], int tam, int cant, int* pNextId)
{
    int todoOk = 0;

    eMoto motos[10] =
    {
        {0, "Honda", 1002, 10000, 50,1,0},
        {0, "Suzuki", 1000, 10001, 500,10,0},
        {0, "Kawasaki", 1003, 10003, 125,9,0},
        {0, "Honda", 1001, 10004, 600,5,0},
        {0, "Yamaha", 1002, 10002, 750,3,0},
        {0, "Suzuki", 1001, 10003, 125,8,0},
        {0, "Honda", 1000, 10000, 50,6,0},
        {0, "Kawasaki", 1001, 10001, 125,4,0},
        {0, "Suzuki", 1003, 10004, 600,2,0},
        {0, "Yamaha", 1002, 10000, 750,7,0},
    };
    if(vec != NULL && pNextId != NULL && tam >= 0 && cant >= 0)
    {
        for(int i = 0; i < cant; i++)
        {
            vec[i] = motos[i];
            vec[i].id = *pNextId;
            (*pNextId)++;
        }
        todoOk = 1;
    }
    return todoOk;
}

int menuModificarMoto()
{
    int opcion;

    printf("\n   *** Campo a modificar ***\n\n");
    printf("1. Color\n");
    printf("2. Puntaje\n");
    printf("Ingrese Opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int modificarMoto(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC)
{
    int todoOk = 0;
    int indice;
    int id;
    int idColor;
    int puntaje;

    if(vec && tip && col && tam > 0 && tamT > 0 && tamC > 0 )
    {
        listarMotos(vec, tam, tip, tamT, col, tamC);
        printf("Ingrese Id: ");
        scanf("%d",&id);

        if(buscarMoto(vec, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("No existe moto con id %d en el sistema.\n", id);
            }
            else
            {
                mostrarMoto(vec[indice], tam, tip, tamT, col, tamC);

                switch(menuModificarMoto())
                {
                case 1:
                    listarColores(col, tamC);

                    printf("Ingrese nuevo Id Color: ");
                    scanf("%d", &idColor);

                    while(validarColor(col, tamC, idColor) == 0)
                    {
                        listarColores(col, tamC);
                        printf("Ingrese Id Color Valido: ");
                        scanf("%d", &idColor);
                    }
                    vec[indice].idColor = idColor;
                    printf("Color modificado!\n");
                    break;

                case 2:
                    printf("Ingrese Puntaje: ");
                    scanf("%d", &puntaje);
                    while(puntaje < 1 || puntaje > 10)
                    {
                        printf("Ingrese Puntaje: ");
                        scanf("%d", &puntaje);
                    }
                    vec[indice].puntaje = puntaje;
                    break;

                    printf("Puntaje modificado!\n");
                    break;
                }
            }
            todoOk = 1;
        }
    }
    return todoOk;
}
