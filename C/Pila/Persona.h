#ifndef _PERSONA_H_
#define _PERSONA_H_

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
char *mostrarPersona(const void *p);

#endif