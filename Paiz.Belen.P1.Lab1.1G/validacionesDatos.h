#ifndef VALIDACIONESDATOS_H_INCLUDED
#define VALIDACIONESDATOS_H_INCLUDED



#endif // VALIDACIONESDATOS_H_INCLUDED

/** \brief valida que los datos ingresdaos por el ususario sean caracteres
 *
 * \param letras[] char cadena de caracteres
 * \return int devuelve 1 si todos los datos en la cadena con caracteres
 *
 */
int validarLetras(char letras[]);

/** \brief permite el ingreso de cadenas de caracteres al usuario
 *
 * \param cadena[] char cadena de caraceteres
 * \param tam int tamaño de la cadena de caracteres
 * \param mensaje[] char mensaje con el nombred el dato q se pedira ingresar al usuario
 * \return int devuelve 1 si pudo pedir y cargar los datos en el sistema
 *
 */
int pidoValidoLetras(char cadena[], int tam, char mensaje[]);
