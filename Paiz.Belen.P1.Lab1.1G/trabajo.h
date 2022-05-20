#include "fecha.h"
#include "moto.h"
#include "servicio.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    int idMoto;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED

/** \brief carga en 1 los campos isEmpty de las estructuras del array de trabajos
 *
 * \param vec[] eTrabajo array de structuras de trabajos
 * \param tam int tamaño del array de trabajos
 * \return int retorna 1 si pudo inicializar todas las estructuras
 *
 */
int inicializarTrabajo(eTrabajo vec[], int tam);

/** \brief busca la estructura vacia mas proxima
 *
 * \param vec[] eTrabajo array de structuras de trabajos
 * \param tam int tamaño del array de trabajos
 * \param pIndex int* carga aqui el indice de la estructura encontrada
 * \return int devuelve 1 si pudo encontrar la estructura
 *
 */
int buscarLibreTrabajo(eTrabajo vec[], int tam, int* pIndex);

/** \brief permite cargar los datos de un alta de un nuevo trabajo
 *
 * \param trab[] eTrabajo array de structuras de trabajos
 * \param tamT int tamaño del array de trabajos
 * \param vec[] eMoto array de motos
 * \param tam int tamaño array de motos
 * \param serv[] eServicio array de estructuras de servicios
 * \param tamS int tamaño del vector de servicios
 * \param tip[] eTipo array de tipos
 * \param tamTi int tamaño del array de tipos
 * \param col[] eColor array de colores
 * \param tamC int tamaño del array de colores
 * \param pNextId int* proximo numero de id
 * \return int devuelve 1 si pudo dar de lata el nuevo trabajo
 *
 */
int altaTrabajo(eTrabajo trab[], int tamT, eMoto vec[], int tam, eServicio serv[], int tamS,eTipo tip[], int tamTi, eColor col[], int tamC, int* pNextId, int* pFlagT, int flagM);

/** \brief muestra en forma de tabla los trabajos guardados
 *
 * \param trab[] eTrabajo  array de structuras de trabajos
 * \param tamTr int tamaño del array de trabajos
 * \param serv[] eServicio array de estructuras de servicios
 * \param tamS int tamaño del vector de servicios
 * \return int retorna 1 si pudo mostrar
 *
 */
int listarTrabajos(eTrabajo trab[], int tamTr, eServicio serv[], int tamS, int flagT);

/** \brief muestra los datos guardados en una estructura de trabajos
 *
 * \param trab eTrabajo estructuras de trabajos
 * \param serv[] eServicio array de estructuras de servicios
 * \param tamS int tamaño del vector de servicios
 * \return void
 *
 */
void mostrarTrabajoFila(eTrabajo trab, eServicio serv[], int tamS);

/** \brief muestra los datos guardados en una estructura de trabajos
 *
 * \param trab eTrabajo estructuras de trabajos
 * \param serv[] eServicio array de estructuras de servicios
 * \param tamS int tamaño del vector de servicios
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo trab, eServicio serv[], int tamS);

/** \brief alta forzada para estructuras de trabajos
 *
 * \param vec[] eTrabajo array de estructuras de trabajos
 * \param tam int int tamaño del array de trabajos
 * \param cant int cantidad de estructuras a dar de alta
 * \param pNextId int* direccion de memoria del siguiente id
 * \return int devuelve 1 si pudo dar de alta las estructuras solicitadas
 *
 */
int harcodearTrabajos(eTrabajo vec[], int tam, int* pNextId, int* pFlagT, int flagM);


/** \brief imprime en pantalla las opciones de informes de trabajos y permite al usuario ingresadr una opcion
 *
 * \return int retorna la opcion ingresada
 *
 */
int menuInformesTrabajos();

/** \brief realiza los llamados a las funciones segun la opcion ingresada por el usuario
 *
 * \param vec[] eMoto array de estructura de motos
 * \param tam int tamaño del array de motos
 * \param tip[] eTipo array de estructura de tipo
 * \param tamT int tamaño del array de tipo
 * \param col[] eColor array de estructura de color
 * \param tamC int tamaño del array de color
 * \param trab[] eTrabajo array de estructura de trabajos
 * \param tamTr int tamaño del array de trabajos
 * \param serv[] eServicio array de estructura de servicios
 * \param tamS int tamaño del array de servicios
 * \param flagM int bandera que permite saber si hay datos de motos guardados en el sitema
 * \param flagT int bandera que permite saber si hay trabajos guardados en el sitema
 * \return int retorna 1 si pudo realizar los llamados
 *
 */
int InformesTrabajos(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC, eTrabajo trab[], int tamTr, eServicio serv[], int tamS, int flagM, int flagT);

/** \brief permite al usuario ingresar el id de una moto y se muestran todos los trabajos realizados en esa moto
 *
 * \param trab[] eTrabajo array de estructuras de trabajo
 * \param tamT int tamaño del array de trabajo
 * \param vec[] eMoto array de estructura de motos
 * \param tam int tamaño del array de motos
 * \param serv[] eServicio array de estructura de servicios
 * \param tamS int tamaño del array de servicios
 * \param tip[] eTipo array de estructuras de tipo
 * \param tamTi int tamaño del array de tipo
 * \param col[] eColor array de estructuras de color
 * \param tamC int tamaño del array de color
 * \param flagM int bandera q permite saber si hay motos cargadas en el sistema
 * \return int retorna 1 si pudo mostrar los trabajos realizados en el id de moto ingresada
 *
 */
int trabajosPorIdMoto(eTrabajo trab[], int tamT, eMoto vec[], int tam, eServicio serv[], int tamS,eTipo tip[], int tamTi, eColor col[], int tamC, int flagM);


/** \brief muestra el importe total de la suma de los importes de cada servicio realizado en un id de moto
 *
 * \param trab[] eTrabajo array de estructuras de trabajos
 * \param tamT int tamaño del array de trabajos
 * \param vec[] eMoto array de estructuras de motos
 * \param tam int tamaño del array de motos
 * \param serv[] eServicio array de estructuras de servicios
 * \param tamS int tamaño del array de servicios
 * \param tip[] eTipo array de estructuras de tipos
 * \param tamTi int tamaño del array de tipos
 * \param col[] eColor array de estructuras de color
 * \param tamC int tamaño del array de colores
 * \param flagM int bandera que permite saber si hay motos cargadas en el sistema
 * \return int devuelve 1 si pudo calcular e informar el total
 *
 */
int TotalImportesServiciosId(eTrabajo trab[], int tamT, eMoto vec[], int tam, eServicio serv[], int tamS,eTipo tip[], int tamTi, eColor col[], int tamC, int flagM);

/** \brief permite al usuario ingresar un id de servicios y muestra todas las motos q se realizaron dicho servicio
 *
 * \param trab[] eTrabajo array de estructura de trabajos
 * \param tamTr int tamaño del array de trabajos
 * \param vec[] eMoto array de estructuras de motos
 * \param tam int tamaño del array de motos
 * \param serv[] eServicio array de estructuras de servicios
 * \param tamS int tamaño del array de servicios
 * \return int devuelve 1 si pudo mostrar las motos que se realizaron el servicio
 *
 */
int serviciosMotosId(eTrabajo trab[], int tamTr, eMoto vec[], int tam, eServicio serv[], int tamS);


/** \brief perimte al usuario ingresar una fecha y muestra todos los servicios que se hicieron en esa fecha
 *
 * \param trab[] eTrabajo array de estructura de trabajos
 * \param tamTr int tamaño del array de trabajos
 * \param serv[] eServicio array de estructura de servicios
 * \param tamS int tamaño del array de servicios
 * \param flagT int bandera que permite saber si hay trabajos cargados en el sistema
 * \return int retorna 1 si pudo mostrar los servicios por fecha
 *
 */
int fechaServicios(eTrabajo trab[], int tamTr, eServicio serv[], int tamS, int flagT);


