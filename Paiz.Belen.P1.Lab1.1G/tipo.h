#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

#endif // TIPO_H_INCLUDED

int cargarDescripcionTipo(eTipo tip[], int tam, int id, char desc[]);
int listarTipos(eTipo tip[], int tam);
int buscarTipo(eTipo tip[], int tam, int id, int* pIndex);
int validarTipo(eTipo tip[], int tam, int id);
