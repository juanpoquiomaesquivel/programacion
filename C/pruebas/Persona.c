#include "Persona.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Persona *crearPersona()
{
    Persona *persona = (Persona *)malloc(sizeof(Persona));
    persona->nombres = NULL;
    persona->apellidoPaterno = NULL;
    persona->apellidoMaterno = NULL;
    persona->edad = NULL;
    persona->dni = NULL;
}

void destruirPersona(Persona **persona)
{
    if (*persona != NULL)
    {
        free((*persona)->nombres);
        free((*persona)->apellidoPaterno);
        free((*persona)->apellidoMaterno);
        free((*persona)->edad);
        free((*persona)->dni);
        free(*persona);
        *persona = NULL;
    }
}