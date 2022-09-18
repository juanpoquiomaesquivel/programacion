#include "Persona.h"
#include "Entrada.h"
#include "Libreria.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Persona *crearPersona()
{
    Persona *persona = (Persona *)malloc(sizeof(Persona));
    persona->nombres = leerEntrada("%s", "Ingrese un nombre");
    persona->apellidoPaterno = leerEntrada("%s", "Ingrese un apellido paterno");
    persona->apellidoMaterno = leerEntrada("%s", "Ingrese un apellido materno");
    persona->edad = leerEntrada("%d", "Ingrese una edad");
    persona->dni = leerEntrada("%s", "Ingrese un dni");

    return persona;
}

void borrarPersona(void *p)
{
    Persona *persona = (Persona *)p;
    free(persona->nombres);
    free(persona->apellidoPaterno);
    free(persona->apellidoMaterno);
    free(persona->edad);
    free(persona->dni);
}

char *mostrarPersona(const void *p)
{
    char buffer[LONGITUD_DE_ENTRADA_STRING];
    Persona *persona = (Persona *)p;
    sprintf(buffer, "Persona(%s %s %s, %d, %s)\n", persona->nombres, persona->apellidoPaterno, persona->apellidoMaterno, *(persona->edad), persona->dni);
    buffer[strcspn(buffer, "\n")] = '\0';

    return strdup(buffer);
}
