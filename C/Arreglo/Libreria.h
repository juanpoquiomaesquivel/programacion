#ifndef _LIBRERIA_H_
#define _LIBRERIA_H_

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

#ifndef FLUSH_BUFFER
#define FLUSH_BUFFER
void flush_buffer();
#endif

#ifndef MEMORY_ERROR
#define MEMORY_ERROR
void memory_error(void *ptr);
#endif

#ifndef EXIT_OPTION
#define EXIT_OPTION "[SISTEMA] :- <Programa finalizado>"
#endif

#ifndef NO_OPTION
#define NO_OPTION "[SISTEMA] :- <Opcion incorrecta>"
#endif

#ifndef CONTINUE_OPTION
#define CONTINUE_OPTION "[SISTEMA] :- <Presione ENTER para continuar>"
#endif

#endif