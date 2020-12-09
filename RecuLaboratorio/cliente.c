#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cliente.h"
#include "validaciones.h"

int inicializarClientes(eCliente clientes[], int tamC)
{
    int error = 1;

    if(clientes != NULL && tamC > 0)
    {
        for(int i=0; i < tamC; i++)
        {
            clientes[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

int buscarLibre(eCliente clientes[], int tam)
{
    int indice = -1;
    for(int i = 0; i < tam; i++)
    {
        if(clientes[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarClientes(eCliente clientes[], int tam, int id)
{
    int indice = -1;
    for(int i = 0; i < tam; i++)
    {
        if(clientes[i].id == id && !clientes[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarCliente(eCliente cliente)
{
    printf(" %02d    %20s       %20s     %20d  \n", cliente.id, cliente.nombre, cliente.apellido, cliente.cuil);

}

int mostrarClientes(eCliente clientes[], int tam)
{
    int flag = 0;
    int error = 1;

    if(clientes != NULL && tam > 0)
    {

        printf("                                      * CLIENTES *  \n\n");
        printf("   ID               NOMBRE         APELLIDO             CUIL      \n\n");
        for(int i = 0; i < tam; i++)
        {
            if(!clientes[i].isEmpty)
            {
                mostrarCliente(clientes[i]);
                flag = 1;
            }
        }
        if(!flag)
        {
            printf("        No hay clientes en la lista\n");
        }
        error = 0;
    }
    return error;
}

int buscarClientesPorId(int idCliente, eCliente clientes[], int tamC)
{
    int indice = -1;

    for(int i=0; i < tamC; i++)
    {
        if(clientes[i].id == idCliente && clientes[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaCliente(eCliente clientes[], int tamCliente, int id)
{
    int error = 1;
    int indice;
    eCliente nuevoCliente;

    if(clientes != NULL && tamCliente > 0)
    {

        system("cls");
        printf("  *** ALTA DE CLIENTE ***\n\n");

        indice = buscarLibre(clientes, tamCliente);
        if(indice == -1)
        {
          printf("Sistema Completo.\n");
        }
        else
        {
            nuevoCliente.id = id;
            nuevoCliente.isEmpty = 0;

            printf("Ingrese nombre: ");
            fflush(stdin);
            normalizeStr(gets(nuevoCliente.nombre));

            while(validacionCadena(nuevoCliente.nombre) == 1)
            {
                printf("Nombre invalido. Reingrese nombre: ");
                fflush(stdin);
                normalizeStr(gets(nuevoCliente.nombre));
            }

            printf("Ingrese apellido: ");
            fflush(stdin);
            normalizeStr(gets(nuevoCliente.apellido));

            while(validacionCadena(nuevoCliente.apellido) == 1)
            {
                printf("Apellido invalido. Reingrese apellido: ");
                fflush(stdin);
                normalizeStr(gets(nuevoCliente.apellido));
            }

            utn_getEntero(&nuevoCliente.cuil, 2, "Ingrese cuil: ", "Error\n", 1000000, 50000000);

            clientes[indice] = nuevoCliente;

            error = 0;
        }
    }
    return error;
}

int modificarCliente(eCliente clientes[], int tamCliente)
{
    char confirmacion;
    int id;
    int indice;
    int error = 1;
    int opcion;
    int flagSalir = 0;
    int flagDef = 0;
    eCliente auxClientes;

    if(clientes != NULL && tamCliente > 0)
    {

        system("cls");
        printf("        *** MODIFICAR CLIENTE ***\n\n");

        mostrarClientes(clientes, tamCliente);
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = buscarClientes(clientes, tamCliente, id);
        auxClientes = clientes[indice];

        if(indice == -1)
        {
            printf("No hay ningun cliente con ese ID\n");
        }
        else
        {
            system("cls");

            printf("*** MODIFICAR CLIENTES ***\n\n");
            printf("1) MODIFICAR NOMBRE.\n");
            printf("2) MODIFICAR APELLIDO.\n");
            printf("3) MODIFICAR C.U.I.L.\n");
            printf("4) MENU ANTERIOR.\n");
            printf("Seleccione una opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);

            switch(opcion)
            {
            case 1:
                 printf("Ingrese nuevo Nombre: ");
                fflush(stdin);
                normalizeStr(gets(auxClientes.nombre));

                while(validacionCadena(auxClientes.nombre) == 1)
                {
                   printf("Nombre invalido. Reingrese Nombre: ");
                  fflush(stdin);
                  normalizeStr(gets(auxClientes.nombre));
               }
                break;
            case 2:
            printf("Ingrese nuevo apellido: ");
            fflush(stdin);
            normalizeStr(gets(auxClientes.apellido));

            while(validacionCadena(auxClientes.apellido) == 1)
            {
                printf("Apellido invalido. Reingrese Apellido: ");
                fflush(stdin);
                normalizeStr(gets(auxClientes.apellido));
            }
                break;
            case 3:
                 utn_getEntero(&auxClientes.cuil, 2, "Ingrese nuevo cuil: ", "Error\n", 1000000, 50000000);
                break;
            case 4:
                flagSalir = 1;
                error = 2;
                break;
            default:
                flagDef = 1;
                printf("Opcion no valida\n");
                break;
            }
            if(!flagSalir && !flagDef)
            {
                printf("Confirma la modificacion(s/n)? ");
                fflush(stdin);
                scanf("%c", &confirmacion);
                if(confirmacion == 's')
                {
                    clientes[indice] = auxClientes;
                    error = 0;
                }
                else
                {
                    error = 2;
                }
            }
        }
    }
    return error;
}

int bajaCliente(eCliente clientes[], int tamCliente)
{
    int id;
    int indice;
    int error = 1;
    char confirma;

    if(clientes != NULL && tamCliente > 0 )
    {
        system("cls");
        printf("  *** BAJA DE CLIENTE ***\n\n");

        mostrarClientes(clientes, tamCliente);
        printf("Ingrese id: ");
        fflush(stdin);
        scanf("%d", &id);

        indice = buscarClientes(clientes, tamCliente, id);

        if(indice == -1)
        {
            printf("No hay ningun cliente con ese id\n");
        }
        else
        {
            mostrarCliente(clientes[indice]);
            printf("Confirma baja(s/n)? ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's' || confirma == 'S')
            {
                clientes[indice].isEmpty = 1;
                error = 0;
            }
            else
            {
                error = 2;
            }
        }
    }
return error;
}

int cargarNombreCliente(eCliente clientes[], int tam, int id, char nombre[])
{
    int error = 1;
    if(clientes != NULL && tam > 0 && id > 0 && nombre != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(clientes[i].id == id)
            {
                strcpy(nombre, clientes[i].nombre);
                error = 0;
                break;
            }
        }
    }
    return error;
}
