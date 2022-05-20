#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
   int id;
   char nombreColor[20];
}eColor;

#endif // COLOR_H_INCLUDED
/** \brief recibe el id de un color y devuelve la descripcion
 *
 * \param eColor vector de la estructura color
 * \param int tamaño del vector color
 * \param int id de la descripcion a copiar
 * \param char cadena de caracteres donde se copiara la descripcion
 * \return retorna 1 si pudo copiar la descripcion
 *
 */
int cargarDescripcionColor(eColor col[], int tam, int id, char desc[]);

/** \brief muestra en forma de tabla todas las esctructuras de color guardadas en el vector de colores
 *
 * \param eColor vector de la estructura color
 * \param int tamaño del vector color
 * \return retorna 1 si pudo mostrar con exito
 *
 */
int listarColores(eColor col[], int tam);

/** \brief recibe un id de tipo color y busca ese id en el vector de colores
 *
 * \param eColor vector de la estructura color
 * \param int tamaño del vector color
 * \param int id a buscar
 * \param  int* donde cargara el indice del id encontrado
 * \return retorna 1 si pudo encontar el id
 *
 */
int buscarColor(eColor col[], int tam, int id, int* pIndex);


/** \brief recibe un id y valida si ese id existe en el vector de colores
 *
 * \param col[] eColor vector de la estructura color
 * \param tam int tamaño del vector color
 * \param id int id a validar
 * \return int retorna 1 si el id es valido, 0 en caso de que no lo fuera
 *
 */
int validarColor(eColor col[], int tam, int id);
