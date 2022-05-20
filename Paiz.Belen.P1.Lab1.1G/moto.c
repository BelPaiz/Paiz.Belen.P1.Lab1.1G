#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "moto.h"




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
    printf("10. Informes\n");
    printf("11. Informes de trabajos\n");
    printf("12. Alta forzada/ Harcodear Motos\n");
    printf("13. Alta forzada/ Harcodear Trabajos\n");
    printf("14. salir\n");
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
        }
        todoOk = 1;
    }
    return todoOk;
}

int cargarMarcaMoto(eMoto vec[], int tam, int id, char desc[])
{
    int todoOk = 0;

    if(vec != NULL && desc != NULL && tam > 0)
    {
      for(int i = 0; i < tam; i++)
      {
          if(vec[i].id == id)
          {
              strcpy(desc, vec[i].marca);
              todoOk = 1;
              break;
          }
      }
    }
    return todoOk;
}
int altaMoto(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC, int* pNextId, int* pFlag)
{
    int todoOk = 0;
    int indice;
    eMoto nuevaMoto;
    int bufferTipo;
    int bufferColor;
    int bufferCilindrada;
    int bufferPuntaje;

    if(vec != NULL && pNextId != NULL && tip != NULL && pFlag != NULL && tam > 0 && tamT > 0)
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
            *pFlag = 0;
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
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarMoto(eMoto vec[], int tam, int id)
{
    int esValido = 0;
    int indice;

    if(buscarMoto(vec, tam, id, &indice) == 1)
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }
    return esValido;
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
int ordenarMotosTipoId(eMoto vec[], int tam)
{
   int todoOk = 0;
   eMoto auxVec;

    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam-1; i++)
        {
            for(int j = i +1; j < tam ; j++)
            {
                if(((vec[i].idTipo == vec[j].idTipo) && (vec[i].id > vec[j].id))
                   ||((vec[i].idTipo != vec[j].idTipo) && (vec[i].idTipo > vec[j].idTipo)))
                   {
                       auxVec = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxVec;
                   }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int listarMotos(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC, int flagM)
{
    int todoOk = 0;

    if(vec != NULL && tip != NULL && col != NULL && tam > 0 && tamT > 0 && tamC > 0 && flagM != 1)
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
            }
        }
        todoOk = 1;
    }
    else
    {
        printf("Primero debe cargar motos en el sistema\n");
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

int bajaMoto(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC, int flag)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;

    if(vec != NULL && tip != NULL && col != NULL && tam > 0 && tamT > 0 && tamC > 0 && flag != 1)
    {
        listarMotos(vec, tam, tip, tamT, col, tamC, flag);
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
    else
    {
        printf("Primero debe cargar motos en el sistema\n");
    }
    return todoOk;
}

int harcodearMotos(eMoto vec[], int tam, int* pNextId, int* pFlag)
{
    int todoOk = 0;
    int cant;

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
    printf("Que cantidad de motos desea dar de alta? 'MAXIMO 10': ");
    scanf("%d", &cant);
    while(cant < 0 || cant > 10)
    {
        printf("Que cantidad de motos desea dar de alta? 'MAXIMO 10': ");
        scanf("%d", &cant);
    }
    if(vec != NULL && pNextId != NULL && tam >= 0 && cant >= 0 && cant < 11)
    {
        for(int i = 0; i < cant; i++)
        {
            vec[i] = motos[i];
            vec[i].id = *pNextId;
            (*pNextId)++;
        }
        *pFlag = 0;
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

int modificarMoto(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC, int flag)
{
    int todoOk = 0;
    int indice;
    int id;
    int idColor;
    int puntaje;

    if(vec && tip && col && tam > 0 && tamT > 0 && tamC > 0 && flag != 1)
    {
        listarMotos(vec, tam, tip, tamT, col, tamC, flag);
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
    else
    {
        printf("Primero debe cargar motos en el sistema\n");
    }
    return todoOk;
}

int mostrarMotosPorColor(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC)
{
    int todoOk = 0;
    int idColor;
    char desc[20];

    if(vec != NULL && tip != NULL && col != NULL && tam > 0 && tamT > 0 && tamC > 0)
    {
        listarColores(col, tamC);

        printf("Ingrese Id Color: ");
        scanf("%d", &idColor);

        while(validarColor(col, tamC, idColor) == 0)
        {
            listarColores(col, tamC);
            printf("Ingrese Id Color Valido: ");
            scanf("%d", &idColor);
        }
        cargarDescripcionColor(col, tamC, idColor, desc);
        strupr(desc);
        printf("********************************** MOTOS DE COLOR %s********************************\n\n", desc);
        printf(" ID           MARCA            TIPO            COLOR     CILINDRADA          PUNTAJE \n");
        printf("-------------------------------------------------------------------------------------\n\n");
        for(int i=0; i < tam; i++)
        {
            if(!vec[i].isEmpty && vec[i].idColor == idColor)
            {
                mostrarMotoFila(vec[i], tam, tip, tamT, col, tamC);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int menuInformes()
{
    int opcion;

    printf("\n   *** INFORMES ***\n\n");
    printf("1. Mostrar motos de un color seleccionado\n");
    printf("2. Promedio del puntaje de un tipo seleccionado\n");
    printf("3. Mostrar motos de mayor cilindrada\n");
    printf("4. Listar motos separadas por tipo\n");
    printf("5. Contar motos de un color y tipo seleccionado\n");
    printf("6. Mostrar color/es mas elegidos\n");
    printf("Ingrese Opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int Informes(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC, int flagM)
{
    int todoOk = 0;

    if(vec && tip && col && tam > 0 && tamT > 0 && tamC > 0 && flagM != 1)
    {
        switch(menuInformes())
        {
        case 1:
            mostrarMotosPorColor(vec, tam, tip, tamT, col, tamC);
            break;
        case 2:
            promedioPuntajePorIdTipo(vec, tam, tip, tamT);
            break;
        case 3:
            mostrarMotosPorMayorCilindrada(vec, tam, tip, tamT, col, tamC);
            break;
        case 4:
            listarMotosXTipo(vec, tam, tip, tamT, col, tamC);
            break;
        case 5:
            contarMotosPorColorTipo(vec, tam, tip, tamT, col, tamC);
            break;
        case 6:
            colorMasElegido(vec, tam, tip, tamT, col, tamC);
            break;

        }
    }
    else
    {
        printf("Para acceder a los informes debe cargar motos en el sistema\n");
    }
    todoOk = 1;
    return todoOk;
}

int promedioPuntajePorIdTipo(eMoto vec[], int tam, eTipo tip[], int tamT)
{
    int todoOk = 0;
    int idTipo;
    char desc[20];
    int contadorTipo = 0;
    int acumuladorPuntaje = 0;
    float promedio = 0;

    if(vec != NULL && tip != NULL && tam > 0 && tamT > 0)
    {
        listarTipos(tip, tamT);

        printf("Ingrese Id Tipo: ");
        scanf("%d", &idTipo);

        while(validarTipo(tip, tamT, idTipo) == 0)
        {
            listarTipos(tip, tamT);
            printf("Ingrese Id Tipo: ");
            scanf("%d", &idTipo);
        }
        cargarDescripcionTipo(tip, tamT, idTipo, desc);
        strupr(desc);

        for(int i=0; i < tam; i++)
        {
            if(!vec[i].isEmpty && vec[i].idTipo == idTipo)
            {
                contadorTipo++;
                acumuladorPuntaje += vec[i].puntaje;
            }
        }
        promedio = (float) acumuladorPuntaje / contadorTipo;
        printf("El promedio de puntaje del tipo %s es: %.2f\n\n", desc, promedio);
        todoOk = 1;
    }
    return todoOk;
}

int mostrarMotosPorMayorCilindrada(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC)
{
    int todoOk = 0;

    if(vec != NULL && tip != NULL && col != NULL && tam > 0 && tamT > 0 && tamC > 0)
    {
        printf("****************************** MOTOS DE MAYOR CILINDRADA*****************************\n\n");
        printf(" ID           MARCA            TIPO            COLOR     CILINDRADA          PUNTAJE \n");
        printf("-------------------------------------------------------------------------------------\n\n");
        for(int i=0; i < tam; i++)
        {
            if(!vec[i].isEmpty && vec[i].cilindrada == 750)
            {
                mostrarMotoFila(vec[i], tam, tip, tamT, col, tamC);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int listarMotosXTipo(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC)
{
    int todoOk = 0;
    char desc[20];

    if(vec != NULL && tip != NULL && col != NULL && tam > 0 && tamT > 0 && tamC > 0)
    {

        printf(" ID           MARCA            TIPO            COLOR     CILINDRADA          PUNTAJE \n");
        printf("-------------------------------------------------------------------------------------\n\n");
        for(int j=0; j < tamT; j++)
        {
            cargarDescripcionTipo(tip, tamT, tip[j].id, desc);
            strupr(desc);
            printf("\n********************************** MOTOS DE TIPO %s********************************\n", desc);
            printf("-------------------------------------------------------------------------------------\n\n");
            for(int i=0; i < tam; i++)
            {
                if(!vec[i].isEmpty && vec[i].idTipo == tip[j].id)
                {
                    mostrarMotoFila(vec[i], tam, tip, tamT, col, tamC);
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int contarMotosPorColorTipo(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC)
{
    int todoOk = 0;
    int idTipo;
    int idColor;
    char desC[20];
    char desT[20];
    int contadorColorTipo = 0;

    if(vec != NULL && tip != NULL && col != NULL && tam > 0 && tamT > 0 && tamC > 0)
    {
        listarTipos(tip, tamT);

        printf("Seleccione Id Tipo: ");
        scanf("%d", &idTipo);

        while(validarTipo(tip, tamT, idTipo) == 0)
        {
            listarTipos(tip, tamT);
            printf("ERROR! Seleccione Id Tipo: ");
            scanf("%d", &idTipo);
        }
        listarColores(col, tamC);

        printf("Seleccione Id Color: ");
        scanf("%d", &idColor);

        while(validarColor(col, tamC, idColor) == 0)
        {
            listarColores(col, tamC);
            printf("ERROR! Seleccione Id Color: ");
            scanf("%d", &idColor);
        }
        cargarDescripcionColor(col, tamC, idColor, desC);
        cargarDescripcionTipo(tip, tamT, idTipo, desT);

        for(int i=0; i < tam; i++)
        {
            if(!vec[i].isEmpty && vec[i].idTipo == idTipo && vec[i].idColor == idColor)
            {
                contadorColorTipo++;
            }
        }
        if(contadorColorTipo != 0)
        {
            printf("La cantidad de motos de color %s y de tipo %s es: %d\n", desC, desT, contadorColorTipo);
        }
        else
        {
            printf("No hay motos de color %s y de tipo %s cargadas en el sistema\n", desC, desT);
        }
        todoOk = 1;
    }
    return todoOk;
}

int contadorMotosXColor(eMoto vec[], int tam,  eColor col[], int tamC, int idColor, int* pCont)
{
    int todoOk = 0;
    int contadorColor = 0;

    if(vec != NULL && col != NULL && tam > 0 && tamC > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(!vec[i].isEmpty && vec[i].idColor == idColor)
            {
                contadorColor++;
            }
        }
        *pCont = contadorColor;
        todoOk = 1;
    }
    return todoOk;
}

int colorMasElegido(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC)
{
    int todoOk = 0;
    int contadorMotosColor[tamC];
    int flag = 1;
    int colorMasPedido = 0;


    if(vec != NULL && tip != NULL && col != NULL && tam > 0 && tamT > 0 && tamC > 0)
    {

        for(int i=0; i < tamC; i++)
        {
            contadorMotosColor[i] = 0;
        }
        for(int i=0; i < tamC; i++)
        {
            contadorMotosXColor(vec, tam, col, tamC, col[i].id, &contadorMotosColor[i]);
        }
        for(int i=0; i < tamC; i++)
        {
            if(flag || contadorMotosColor[i] > colorMasPedido)
            {
                colorMasPedido = contadorMotosColor[i];
                flag = 0;
            }
        }
            printf("El Color/es mas elegido es/son: \n");
            for(int i=0; i < tamC; i++)
            {
                if(contadorMotosColor[i] == colorMasPedido)
                {
                    printf("%s\n", col[i].nombreColor);
                }
            }

        todoOk = 1;
    }
    return todoOk;
}
