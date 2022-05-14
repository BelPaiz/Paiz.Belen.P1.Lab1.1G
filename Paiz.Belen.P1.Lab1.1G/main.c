#include <stdio.h>
#include <stdlib.h>
#include "moto.h"

#define TAM 15
#define TAMT 4
#define TAMC 5
#define TAMS 4

int main()
{
    char salir ='n';
    int proxIdMoto = 500;
    eMoto motos[TAM];
    eTipo tipos[TAMT] =
    {
        {1000, "Enduro"},
        {1001, "Chopera"},
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
    harcodearMotos(motos, TAM, 10, &proxIdMoto);

    do
    {
        switch(menuMoto())
        {
        case 1:
            altaMoto(motos, TAM, tipos, TAMT, colores, TAMC, &proxIdMoto);
            break;
        case 2:
            modificarMoto(motos, TAM, tipos, TAMT, colores, TAMC);
            break;
        case 3:
            bajaMoto(motos, TAM, tipos, TAMT, colores, TAMC);
            break;
        case 4:
            listarMotos(motos, TAM, tipos, TAMT, colores, TAMC);
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
            printf("Alta trabajo\n");
            break;
        case 9:
            printf("Listar trabajos\n");
            break;
        case 10:
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
