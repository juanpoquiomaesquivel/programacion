#ifndef _PERSONA_H_
#define _PERSONA_H_

#include <stdbool.h>

typedef struct persona
{
    char *nombres;
    char *apellidoPaterno;
    char *apellidoMaterno;
    int *edad;
    char *dni;
} Persona;

Persona *crearPersona();
void borrarPersona(void *p);
int compararPersona(const void *p, const void *q);
char *mostrarPersona(const void *p);

#endif