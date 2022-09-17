#ifndef _LECTURA_H_
#define _LECTURA_H_

#include "Libreria.h"

#ifndef LONGITUD_DE_ENTRADA_STRING
#define LONGITUD_DE_ENTRADA_STRING 1000
#endif

#ifndef MS_INGRESE_INT
#define MS_INGRESE_INT "[SISTEMA] :- <Ingrese valor 'int'>"
#endif

#ifndef MS_INGRESE_SHORT_INT
#define MS_INGRESE_SHORT_INT "[SISTEMA] :- <Ingrese valor 'short int'>"
#endif

#ifndef MS_INGRESE_LONG_INT
#define MS_INGRESE_LONG_INT "[SISTEMA] :- <Ingrese valor 'long int'>"
#endif

#ifndef MS_INGRESE_FLOAT
#define MS_INGRESE_FLOAT "[SISTEMA] :- <Ingrese valor 'float'>"
#endif

#ifndef MS_INGRESE_DOUBLE
#define MS_INGRESE_DOUBLE "[SISTEMA] :- <Ingrese valor 'double'>"
#endif

#ifndef MS_INGRESE_LONG_DOUBLE
#define MS_INGRESE_LONG_DOUBLE "[SISTEMA] :- <Ingrese valor 'long double'>"
#endif

#ifndef LEER_ENTRADA
#define LEER_ENTRADA
void *leerEntrada(const char *formato, const char *mensaje);
#endif

#endif