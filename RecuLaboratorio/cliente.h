#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct {
 int id;
 char nombre[20];
 char apellido[20];
 int cuil;
 int isEmpty;
}eCliente;

#endif // CLIENTE_H_INCLUDED

int inicializarClientes(eCliente clientes[], int tamC);
int buscarLibre(eCliente clientes[], int tam);
int buscarClientes(eCliente clientes[], int tam, int id);
void mostrarCliente(eCliente cliente);
int buscarClientesPorId(int idCliente, eCliente clientes[], int tamC);
int mostrarClientes(eCliente clientes[], int tam);
int cargarNombreCliente(eCliente clientes[], int tam, int id, char nombre[]);
int altaCliente(eCliente clientes[], int tamCliente, int id);
int modificarCliente(eCliente clientes[], int tamCliente);
int bajaCliente(eCliente clientes[], int tamCliente);
