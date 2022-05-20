#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;
}eServicio;

#endif // SERVICIO_H_INCLUDED

/** \brief imprime en pantalla en forma de tabla las estructuras de servicios
 *
 * \param serv[] eServicio array de estructuras de servicios
 * \param tam int taamaño del array de servicios
 * \return int devuelve 1 si pudo listar los servicios
 *
 */
int listarServicios(eServicio serv[], int tam);

/** \brief recibe un id y carga la descripcion de ese id en una cadena de caracteres
 *
 * \param serv[] eServicio array de estructuras de servicios
 * \param tam int taamaño del array de servicios
 * \param id int id a buscar
 * \param desc[] char array donde cargara la descripcion
 * \return int devueve 1 si pudo guardar la descripcion
 *
 */
int cargarDescripcionServicio(eServicio serv[], int tam, int id, char desc[]);

/** \brief recibe un id y busca el indice donde este esta guardado en el array de servicios
 *
 * \param serv[] eServicio array de estructuras de servicios
 * \param tam int taamaño del array de servicios
 * \param id int id ingresado
 * \param pIndex int* direccion donde copiar el indice encontrado
 * \return int  devuelve 1 si pudo encontrar el id y copiar el indice
 *
 */
int buscarServicio(eServicio serv[], int tam, int id, int* pIndex);

/** \brief valida si el id ingresado corresponde a una estructura valida
 *
 * \param serv[] eServicio array de estructuras de servicios
 * \param tam int taamaño del array de servicios
 * \param id int id ingresado
 * \return int devuelve 1 si el id es valido, -1 si el id no existe
 *
 */
int validarServicio(eServicio serv[], int tam, int id);
