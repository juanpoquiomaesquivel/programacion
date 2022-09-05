#ifndef _LECTURA_H_
#define _LECTURA_H_

#ifndef LEN_STR_INPUT
#define LEN_STR_INPUT 100
#endif

void leerInteger(int **var);
void leerDouble(double **var);
void leerFloat(float **var);
void leerString(char **var);
void leerChar(char **var);
void lectura(void *ptr, const char *formato);

#endif