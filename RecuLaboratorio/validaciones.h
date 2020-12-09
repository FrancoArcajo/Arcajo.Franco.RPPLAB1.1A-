#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED
#include "cliente.h"

int validacionCadena(char cadena[]);
int strLwr(char* str);
int normalizeStr(char* str);
int isInt(char *pAux);
int getInt(int* pAux);
int utn_getEntero(int* pEntero, int reintentos, char* mensaje, char* mensajeError, int minimo, int maximo);
int getCadena(char* pAux, int limit);
int validarCliente(eCliente clientes[], int tam, int idCliente);


#endif // VALIDACIONES_H_INCLUDED
