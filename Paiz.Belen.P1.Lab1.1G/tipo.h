#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

#endif // TIPO_H_INCLUDED

/** \brief recibe un id y copia su descripcion
 *
 * \param tip[] eTipo array de structuras de tipo
 * \param tam int tamaño del array de tipos
 * \param id int id de donde se debe copiar la descripcion
 * \param desc[] char direccion donde copiar la descripcion encontrada
 * \return int devuelve 1 si pudo copiar lña descripcion
 *
 */
int cargarDescripcionTipo(eTipo tip[], int tam, int id, char desc[]);

/** \brief muestra en forma de tabla las estructuras de tipo
 *
 * \param tip[] eTipo array de structuras de tipo
 * \param tam int tamaño del array de tipos
 * \return int devuelve 1 si pudo listar con exito
 *
 */
int listarTipos(eTipo tip[], int tam);

/** \brief recibe un id y busca el indice donde este esta guardado en el array de tipos
 *
 * \param tip[] eTipo array de structuras de tipo
 * \param tam int tamaño del array de tipos
 * \param id int
 * \param pIndex int*
 * \return int int  devuelve 1 si pudo encontrar el id y copiar el indice
 *
 */
int buscarTipo(eTipo tip[], int tam, int id, int* pIndex);

/** \brief valida si el id ingresado corresponde a una estructura valida
 *
 * \param tip[] eTipo array de structuras de tipo
 * \param tam int tamaño del array de tipos
 * \param id int
 * \return intint devuelve 1 si el id es valido, -1 si el id no existe
 *
 */
int validarTipo(eTipo tip[], int tam, int id);
