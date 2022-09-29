#ifndef _LIBRERIA_H_
#define _LIBRERIA_H_

#ifndef MS_INSUFICIENTE_MEMORIA
#define MS_INSUFICIENTE_MEMORIA "[SISTEMA] :- <No hay memoria suficiente> "
#endif

#ifndef MS_OPCION_CONTINUAR
#define MS_OPCION_CONTINUAR "[SISTEMA] :- <Presione ENTER para continuar>"
#endif

#ifndef MS_OPCION_INCORRECTA
#define MS_OPCION_INCORRECTA "[SISTEMA] :- <Opcion incorrecta>"
#endif

#ifndef MS_PROGRAMA_FINALIZADO
#define MS_PROGRAMA_FINALIZADO "[SISTEMA] :- <Programa finalizado con exito>"
#endif

#ifndef ERROR_DE_MEMORIA
#define ERROR_DE_MEMORIA
void errorDeMemoria(void *ptr);
#endif

#ifndef LIMPIAR_BUFFER
#define LIMPIAR_BUFFER
void limpiarBuffer();
#endif

#endif