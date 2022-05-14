#include "tipo.h"
#include "color.h"
#include "servicio.h"


#ifndef MOTO_H_INCLUDED
#define MOTO_H_INCLUDED

typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    int cilindrada;
    int puntaje;
    int isEmpty;
}eMoto;

#endif // MOTO_H_INCLUDED

int inicializarMotos(eMoto vec[], int tam);
void confirmarSalida(char* x);
void informarNoEsNumero();
int menuMoto();
int buscarLibre(eMoto vec[], int tam, int* pIndex);
int altaMoto(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC, int* pNextId);
void listarCilindradas();
int buscarMoto(eMoto vec[], int tam, int id, int* pIndex);
void mostrarMotoFila(eMoto vec, int tam, eTipo tip[], int tamT, eColor col[], int tamC);
void mostrarMoto (eMoto vec, int tam, eTipo tip[], int tamT, eColor col[], int tamC);
int listarMotos(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC);
void mostrarMotoFila(eMoto vec, int tam, eTipo tip[], int tamT, eColor col[], int tamC);
int bajaMoto(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC);
int menuModificarMoto();
int harcodearMotos(eMoto vec[], int tam, int cant, int* pNextId);
int modificarMoto(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC);
