#ifndef _LECTURA_H_
#define _LECTURA_H_

#ifndef LEN_STR_INPUT
#define LEN_STR_INPUT 100
#endif

#ifndef BOOL
#define BOOL
typedef enum
{
    false,
    true
} bool;
#endif

#ifndef NO_MEMORY
#define NO_MEMORY "[SISTEMA] :- <No hay memoria suficiente> "
#endif

#ifndef FLUSH
#define FLUSH
void flush();
#endif

#ifndef ERROR_MEMORY
#define ERROR_MEMORY
void error(void *ptr);
#endif

void leerInteger(int **var);
void leerDouble(double **var);
void leerFloat(float **var);
void leerString(char **var);
void leerChar(char **var);
void lectura(void *ptr, const char *formato);

#endif