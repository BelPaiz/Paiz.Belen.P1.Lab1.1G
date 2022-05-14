#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;
}eServicio;

#endif // SERVICIO_H_INCLUDED

int listarServicios(eServicio serv[], int tam);
int buscarServicio(eServicio serv[], int tam, int id, int* pIndex);
int validarServicio(eServicio serv[], int tam, int id);
