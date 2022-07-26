#include "Persona.h"
#include "Entrada.h"
#include "Libreria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Persona *crearPersona()
{
    Persona *persona = (Persona *)malloc(sizeof(Persona));
    errorDeMemoria(persona);
    persona->nombres = (char *)leerEntrada("%s", "Ingrese un nombre");
    persona->apellidoPaterno = (char *)leerEntrada("%s", "Ingrese un apellido paterno");
    persona->apellidoMaterno = (char *)leerEntrada("%s", "Ingrese un apellido materno");
    persona->edad = (int *)leerEntrada("%d", "Ingrese una edad");
    persona->dni = (char *)leerEntrada("%s", "Ingrese un dni");

    return persona;
}

void borrarPersona(void *p)
{
    if (p == NULL)
        return;

    Persona *persona = (Persona *)p;
    free(persona->nombres);
    free(persona->apellidoPaterno);
    free(persona->apellidoMaterno);
    free(persona->edad);
    free(persona->dni);
    free(persona);
}

int compararPersona(const void *p, const void *q)
{
    const Persona *p1 = (const Persona *)p;
    const Persona *p2 = (const Persona *)q;

    if (!strcmp(p1->nombres, p2->nombres) && !strcmp(p1->apellidoPaterno, p2->apellidoPaterno) && !strcmp(p1->apellidoMaterno, p2->apellidoMaterno) && *(p1->edad) == *(p2->edad) && !strcmp(p1->dni, p2->dni))
        return 0;
    else
        return *(p1->edad) - *(p2->edad);
}

char *mostrarPersona(const void *p)
{
    char buffer[LONGITUD_DE_ENTRADA_STRING];
    const Persona *persona = (const Persona *)p;
    sprintf(buffer, "Persona(%s %s %s, %d, %s)\n", persona->nombres, persona->apellidoPaterno, persona->apellidoMaterno, *(persona->edad), persona->dni);
    buffer[strcspn(buffer, "\n")] = '\0';
    char *toString = strdup(buffer);
    errorDeMemoria(toString);

    return toString;
}
