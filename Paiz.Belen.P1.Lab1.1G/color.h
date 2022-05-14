#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
   int id;
   char nombreColor[20];
}eColor;

#endif // COLOR_H_INCLUDED

int cargarDescripcionColor(eColor col[], int tam, int id, char desc[]);
int listarColores(eColor col[], int tam);
int buscarColor(eColor col[], int tam, int id, int* pIndex);
int validarColor(eColor col[], int tam, int id);
