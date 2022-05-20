#include <stdio.h>
#include <stdlib.h>
#include "moto.h"
#include "color.h"
#include "tipo.h"
#include "servicio.h"
#include "trabajo.h"

#define TAM 15
#define TAMT 4
#define TAMC 5
#define TAMS 4
#define TAMTR 40

int main()
{
    char salir ='n';
    int proxIdMoto = 500;
    int proxIdTrabajo = 7000;
    int flagMoto = 1;
    int flagTrab = 1;
    eMoto motos[TAM];
    eTrabajo trabajos[TAMTR];
    eTipo tipos[TAMT] =
    {
        {1000, "Chopera"},
        {1001, "Enduro"},
        {1002, "Scooter"},
        {1003, "Vintage"}
    };
    eColor colores[TAMC] =
    {
        {10000, "Gris"},
        {10001, "Negro"},
        {10002, "Azul"},
        {10003, "Blanco"},
        {10004, "Rojo"}
    };
    eServicio servicios[TAMS] =
    {
        {20000, "Limpieza", 450},
        {20001, "Ajuste", 300},
        {20002, "Balanceo", 150},
        {20003, "Cadena", 390}
    };

    inicializarMotos(motos, TAM);
    inicializarTrabajo(trabajos, TAMTR);

    do
    {
        switch(menuMoto())
        {
        case 1:
            if(altaMoto(motos, TAM, tipos, TAMT, colores, TAMC, &proxIdMoto, &flagMoto))
            {
                printf("Datos cargados con exito!!\n");
            }
            else
            {
                printf("No se pudo cargar los datos\n");
            }
            break;
        case 2:
            modificarMoto(motos, TAM, tipos, TAMT, colores, TAMC, flagMoto);
            break;
        case 3:
            bajaMoto(motos, TAM, tipos, TAMT, colores, TAMC, flagMoto);
            break;
        case 4:
            ordenarMotosTipoId(motos, TAM);
            listarMotos(motos, TAM, tipos, TAMT, colores, TAMC, flagMoto);
            break;
        case 5:
            listarTipos(tipos, TAMT);
            break;
        case 6:
            listarColores(colores, TAMC);
            break;
        case 7:
            listarServicios(servicios, TAMS);
            break;
        case 8:
            if(altaTrabajo(trabajos, TAMTR, motos, TAM, servicios, TAMS, tipos, TAMT, colores, TAMC, &proxIdTrabajo, &flagTrab, flagMoto))
            {
                printf("Trabajo cargado con exito!!\n");
            }
            else
            {
                printf("No se pudo cargar trabajo\n");
            }
            break;
        case 9:
            listarTrabajos(trabajos, TAMTR, servicios, TAMS, flagTrab);

            break;
        case 10:
            Informes(motos, TAM, tipos, TAMT, colores, TAMC, flagMoto);
            break;
        case 11:
            InformesTrabajos(motos, TAM, tipos, TAMT, colores, TAMC, trabajos, TAMTR, servicios, TAMS, flagMoto, flagTrab);
            break;
        case 12:
            harcodearMotos(motos, TAM, &proxIdMoto, &flagMoto);
            break;
        case 13:
            harcodearTrabajos(trabajos, TAMTR, &proxIdTrabajo, &flagTrab, flagMoto);
            break;
        case 14:
            confirmarSalida(&salir);
            break;
        case 100:
            informarNoEsNumero();
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
        system("pause");
    }
    while(salir != 's');







    return 0;
}
