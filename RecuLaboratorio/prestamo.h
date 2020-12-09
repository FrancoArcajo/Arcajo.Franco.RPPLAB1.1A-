#ifndef PRESTAMO_H_INCLUDED
#define PRESTAMO_H_INCLUDED
#include "cliente.h"

typedef struct {
  int id;
  int idCliente;
  float importe;
  int cuotas;
  char estado[20];
  int isEmpty;
}ePrestamo;

#endif // PRESTAMO_H_INCLUDED
int inicializarPrestamo(ePrestamo prestamos[], int tamP);
int buscarLibrePrestamo(ePrestamo prestamos[], int tam);
int mostrarPrestamos(ePrestamo prestamos[], int tam, eCliente clientes[], int tamC);
void mostrarPrestamo(ePrestamo prestamo, eCliente clientes[], int tamC);
int altaPrestamo(ePrestamo prestamos[], int tamP,int idPrestamo,eCliente clientes[],int tamCliente);

