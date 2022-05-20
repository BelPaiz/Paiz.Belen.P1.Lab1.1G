#include "tipo.h"
#include "color.h"
#include "validacionesDatos.h"
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

/** \brief coloca todos los campos isEmpty del vector de motos en 1
 *
 * \param vec[] eMoto vector de estructuras de motos
 * \param tam int tamaño del vector de motos
 * \return int retorna 1 si pudo inicializar todas las estructuras
 *
 */
int inicializarMotos(eMoto vec[], int tam);

/** \brief permite al usuario confirmar la salida del programa
 *
 * \param x char* direccion de memoria de char para confirmar salida
 * \return void
 *
 */
void confirmarSalida(char* x);


/** \brief informa al usuario q no ingreso un numero
 *
 * \return void
 *
 */
void informarNoEsNumero();

/** \brief imprime en pantalla el menu con las opciones y permite al usuario el ingreso de una opcion
 *
 * \return int retorna la opcion ingresada
 *
 */
int menuMoto();

/** \brief busca la primer estructura del array de motos q este vacia
 *
 * \param vec[] eMoto vector de estructuras de motos
 * \param tam int tamaño del vector de motos
 * \param pIndex int* direccion de memoria donde guardar el indice de la estructura vacia
 * \return int retorna 1 si pudo encontrar una estructura vacia, -1 si no hay espacio vacia en el sitema
 *
 */
int buscarLibre(eMoto vec[], int tam, int* pIndex);

/** \brief permite el ingreso de datos para dar de alta una moto en el sistema
 *
 * \param vec[] eMoto vector de estructuras de motos
 * \param tam int tamaño del vector de motos
 * \param tip[] eTipo vector de estructuras de tipos
 * \param tamT int tamaño del vector de tipos
 * \param col[] eColor vector de estructuras de colores
 * \param tamC int tamaño del vector de colores
 * \param pNextId int* direccion de memoria q permite incrementar el valor de la siguiente id
 * \return int retorna 1 si pudo guardar los datos en una estructura de motos vacia
 *
 */
int altaMoto(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC, int* pNextId, int* pFlag);

/** \brief muestra en forma de lista las cilindradas que se pueden seleccionar
 *
 * \return void
 *
 */
void listarCilindradas();

/** \brief recibe un id y busca en q posicion del vector de motos se encuentra
 *
 * \param vec[] eMoto vector de estructuras de motos
 * \param tam int tamaño del vector de motos
 * \param id int id ingresado por el usuario
 * \param pIndex int* direccion de memoria donde volcara el valor del indicce donde se encuentra
 * \return int devuelve 1 si encontro el id
 *
 */
int buscarMoto(eMoto vec[], int tam, int id, int* pIndex);

/** \brief recibe un id y valida si es un id presente en el vector de motos
 *
 * \param vec[] eMoto vector de estructuras de motos
 * \param tam int tamaño del vector de motos
 * \param id int id ingresado por el usuario
 * \return int devuelve 1 si es valido, -1 si es invalido
 *
 */
int validarMoto(eMoto vec[], int tam, int id);

/** \brief muestra la esctructura del indice pedido del vector de motos
 *
 * \param vec[] eMoto vector de estructuras de motos
 * \param tam int tamaño del vector de motos
 * \param tip[] eTipo vector de estructuras de tipos
 * \param tamT int tamaño del vector de tipos
 * \param col[] eColor vector de estructuras de colores
 * \param tamC int tamaño del vector de colores
 * \return void
 *
 */
void mostrarMotoFila(eMoto vec, int tam, eTipo tip[], int tamT, eColor col[], int tamC);



/** \brief muestra la esctructura del indice pedido del vector de motos
 * \param vec[] eMoto vector de estructuras de motos
 * \param tam int tamaño del vector de motos
 * \param tip[] eTipo vector de estructuras de tipos
 * \param tamT int tamaño del vector de tipos
 * \param col[] eColor vector de estructuras de colores
 * \param tamC int tamaño del vector de colores
 * \return void
 *
 */
void mostrarMoto (eMoto vec, int tam, eTipo tip[], int tamT, eColor col[], int tamC);


/** \brief muestra en forma de tabla las estructuras q no estan vacias del vector de motos
 *
 * \param vec[] eMoto vector de estructuras de motos
 * \param tam int tamaño del vector de motos
 * \param tip[] eTipo vector de estructuras de tipos
 * \param tamT int tamaño del vector de tipos
 * \param col[] eColor vector de estructuras de colores
 * \param tamC int tamaño del vector de colores
 * \return int devuelve 1 si pudo listarlas con exito
 *
 */
int listarMotos(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC, int flagM);

/** \brief permite ingresar un id y dar de baja a ese id
 *
 * \param vec[] eMoto vector de estructuras de motos
 * \param tam int tamaño del vector de motos
 * \param tip[] eTipo vector de estructuras de tipos
 * \param tamT int tamaño del vector de tipos
 * \param col[] eColor vector de estructuras de colores
 * \param tamC int tamaño del vector de colores
 * \return int retorna 1 si pudo realizar la baja
 *
 */
int bajaMoto(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC, int flag);

/** \brief muestra las opciones del menu modificar y permite el ingreso de la opcion deseada
 *
 * \return int devuelve la opcion ingresada por el usuario
 *
 */
int menuModificarMoto();

/** \brief perimte realizar un alta forzada de datos en el array de motos
 *
 * \param vec[] eMoto vector de estructuras de motos
 * \param tam int tamaño del vector de motos
 * \param cant int cantidad de motos q se desean dar de alta
 * \param pNextId int* direccion de memoria del siguiente id a usar
 * \return int devuelve 1 si pudo realizar las altas solicitadas
 *
 */
int harcodearMotos(eMoto vec[], int tam, int* pNextId, int* pFlag);

/** \brief realiza las opciones de modificacion deseadas
 *
 * \param vec[] eMoto vector de estructuras de motos
 * \param tam int tamaño del vector de motos
 * \param tip[] eTipo vector de estructuras de tipos
 * \param tamT int tamaño del vector de tipos
 * \param col[] eColor vector de estructuras de colores
 * \param tamC int tamaño del vector de colores
 * \return int devuelve 1 si pudo realizar las modificaciones
 *
 */
int modificarMoto(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC, int flag);

/** \brief ordena el array de motos de manera ascendente por tipo y id
 *
 * \param vec[] eMoto vector de estructuras de motos
 * \param tam int tamaño del vector de motos
 * \return int devuelve 1 si pudo ordenar el array
 *
 */
int ordenarMotosTipoId(eMoto vec[], int tam);


/** \brief permite al usuario ingresar un id de color y muestra todas las motos cargadas en el sistema de ese color
 *
 * \param vec[] eMoto array de estructura de motos
 * \param tam int tamaño del vector de motos
 * \param tip[] eTipo array de estructura de tipos
 * \param tamT int tamaño del array de tipos
 * \param col[] eColor array de estructura de colores
 * \param tamC int tamaño del array de colores
 * \return int retorna 1 si pudo mostrar
 *
 */
int mostrarMotosPorColor(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC);

/** \brief imprime en pantalla el menu de opciones de informes y permite al usuario ingresar una opcion
 *
 * \return int retorna la opcion ingresada
 *
 */
int menuInformes();

/** \brief esdta funcion realiza el llamado a las demas funciones cuando son solicitadas segun la opcion ingresada por el usuario en el menu
 *
 * \param vec[] eMoto array de estructuras de moto
 * \param tam int tamaño del array de motos
 * \param tip[] eTipo array de estructuras de tipos
 * \param tamT int tamaño del array de estructuras de tipos
 * \param col[] eColor array de estructura de colores
 * \param tamC int tamaño del array de colores
 * \return int devuelve 1 al terminar de ejecutarse correctamente
 *
 */
int Informes(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC, int flagM);

/** \brief calcula el promedio de los puntajes de las motos cargadas en el sistema
 *
 * \param vec[] eMoto array de estructura de motos
 * \param tam int tamaño del array de motos
 * \param tip[] eTipo array de estructuras de tipo
 * \param tamT int tamaño del array de tipo
 * \return int retorna 1 si pudo calcular el promedio
 *
 */
int promedioPuntajePorIdTipo(eMoto vec[], int tam, eTipo tip[], int tamT);


/** \brief muestra en forma de lista mas motos de mayor cilindrada
 *
 * \param vec[] eMoto array de estructuras de motos
 * \param tam int tamaño del array de motos
 * \param tip[] eTipo array de estructuras de tipo
 * \param tamT int tamaño del array de tipo
 * \param col[] eColor array de estructuras de colores
 * \param tamC int tamaño del array de colores
 * \return int retorna 1 si pudo mostrar
 *
 */
int mostrarMotosPorMayorCilindrada(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC);

/** \brief arma un listado de las motos separadas por tipos
 *
 * \param vec[] eMoto array de estructura de motos
 * \param tam int tamaño del array de motos
 * \param tip[] eTipo array de estructuras de tipo
 * \param tamT int tamaño del array de tipo
 * \param col[] eColor array de estructura de color
 * \param tamC int tamaño del array de color
 * \return int devuelve 1 si pudo mostrar
 *
 */
int listarMotosXTipo(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC);


/** \brief realiza el conteo de la cantidad de motos por un tipo y color ingresado por el usuario
 *
 * \param vec[] eMoto array de estructuras de motos
 * \param tam int tamaño del array de motos
 * \param tip[] eTipo array de estructuras de tipo
 * \param tamT int tamaño del array de tipo
 * \param col[] eColor array es estructura de color
 * \param tamC int tamaño del array de color
 * \return int devuelve 1 si pudo realizar el conteo correctamente
 *
 */
int contarMotosPorColorTipo(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC);


/** \brief recorre el array de motos y cuenta segun un color cuantas motos hay en el array de ese color
 *
 * \param vec[] eMoto array de estructura de motos
 * \param tam int tamaño del array de motos
 * \param col[] eColor array de estructura de color
 * \param tamC int tamaño del array de color
 * \param idColor int id del color a contar
 * \param pCont int* direccion de memoria donde escribira el contador
 * \return int retorna 1 si pudo realizar el conteo
 *
 */
int contadorMotosXColor(eMoto vec[], int tam,  eColor col[], int tamC, int idColor, int* pCont);


/** \brief permite comparar las cantidades de motos de cada color e informar cual es el o los colores mas elegidos
 *
 * \param vec[] eMoto array de esructura de motos
 * \param tam int tamaño del array de motos
 * \param tip[] eTipo array de estructuras de tipo
 * \param tamT int tamaño del array de tipo
 * \param col[] eColor array de estructura de color
 * \param tamC int tamaño del array de color
 * \return int retorna 1 si pudo informar el color mas elegido
 *
 */
int colorMasElegido(eMoto vec[], int tam, eTipo tip[], int tamT, eColor col[], int tamC);


/** \brief recibe un id de una moto y carga en una cadena de caracteres el nombre de la marca de esa moto
 *
 * \param vec[] eMoto array de estructura de motos
 * \param tam int tamaño del array de motos
 * \param id int id de la moto
 * \param desc[] char cadena de caracteres donde compiara la marca
 * \return int
 *
 */
int cargarMarcaMoto(eMoto vec[], int tam, int id, char desc[]);
