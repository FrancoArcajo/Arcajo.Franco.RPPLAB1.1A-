#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "prestamo.h"
#include "validaciones.h"

int inicializarPrestamo(ePrestamo prestamos[], int tamP)
{
    int error = 1;

    if(prestamos != NULL && tamP > 0)
    {
        for(int i=0; i<tamP; i++)
        {
            prestamos[i].isEmpty = 0;
        }
        error = 0;
    }
    return error;
}

int buscarLibrePrestamo(ePrestamo prestamos[], int tam)
{
    int indice = -1;
    for(int i = 0; i < tam; i++)
    {
        if(prestamos[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarPrestamo(ePrestamo prestamo, eCliente clientes[], int tamC)
{
    char nombreCliente[20];
    if(!cargarNombreCliente(clientes, tamC, prestamo.idCliente, nombreCliente)){
    printf(" %02d    %20s       %20f     %2d  %20s  \n", prestamo.id, nombreCliente, prestamo.importe, prestamo.cuotas, prestamo.estado);
    }
}

int mostrarPrestamos(ePrestamo prestamos[], int tam, eCliente clientes[], int tamC)
{
    int flag = 0;
    int error = 1;

    if(prestamos != NULL && tam > 0)
    {
        printf("                                      * PRESTAMOS *  \n\n");
        printf("   ID               NOMBRE         IMPORTE             CUOTAS      ESTADO\n\n");
        for(int i = 0; i < tam; i++)
        {
            if(!prestamos[i].isEmpty)
            {
                mostrarPrestamo(prestamos[i], clientes, tamC);
                flag = 1;
            }
        }
        if(!flag)
        {
            printf("        No hay prestamos en la lista\n");
        }
        error = 0;
    }
    return error;
}

/*int altaPrestamo(ePrestamo prestamos[], int tamP,int idPrestamo,eCliente clientes[],int tamCliente)
{
    int error = 1;
    ePrestamo nuevoPrestamo;
    int indice;
    int auxPrestamo;

    if( prestamos != NULL && idPrestamo > 0 && tamP > 0 && clientes != NULL && tamCliente > 0)
    {
        indice = buscarLibrePrestamo(prestamos,tamP);

        if(indice == 1)
        {
            printf("SISTEMA COMPLETO\n");
        }
        else
        {
            error = 0;
            nuevoPrestamo.id = idPrestamo;
            nuevoPrestamo.isEmpty = 0;

            system("cls");

            mostrarClientes(clientes, tamCliente);
            printf("Ingrese id del cliente: \n");
            fflush(stdin);
            scanf("%d",&auxPrestamo);
            while(validarCliente(clientes,tamCliente,auxPrestamo))
            {
                system("cls");
                mostrarClientes(clientes, tamCliente);
                printf("Error, Reingrese id: \n");
                fflush(stdin);
                scanf("%d",&auxPrestamo);
            }
            nuevoPrestamo.idCliente = auxPrestamo;

            printf("Ingrese el importe del prestamo: \n");
            scanf("%f", &auxPrestamo);
            while(auxPrestamo < 0)
            {
                printf("Error, Reingrese el importe del prestamo: \n");
                scanf("%f",&auxPrestamo);
            }
            nuevoPrestamo.importe = auxPrestamo;

            printf("Ingrese la cantidad de cuotas del prestamo: \n");
            scanf("%d", &auxPrestamo);
            while(auxPrestamo < 0)
            {
                printf("Error, Reingrese la cantidad de cuotas del prestamo: \n");
                scanf("%d",&auxPrestamo);
            }
            nuevoPrestamo.cuotas = auxPrestamo;

            prestamos[indice] = nuevoPrestamo;
            printf("ALTA DE PRESTAMOS EXITOSA\n\n");
        }
    }
    return error;
}*/
int altaPrestamo(ePrestamo prestamos[], int tamP,int idPrestamo,eCliente clientes[],int tamCliente)
{
    int error = 1;
    ePrestamo nuevoPrestamo;
    int indice;
    int auxPrestamo;
    float auxFloat;
    char estado[20] = "activo";

    if( prestamos != NULL && idPrestamo > 0 && tamP > 0 && clientes != NULL && tamCliente > 0)
    {
        indice = buscarLibrePrestamo(prestamos,tamP);

        if(indice == 0)
        {
            printf("SISTEMA COMPLETO\n");
        }
        else
        {
            error = 0;
            nuevoPrestamo.id = idPrestamo;
            nuevoPrestamo.isEmpty = 0;

            system("cls");

            mostrarClientes(clientes, tamCliente);
            printf("Ingrese id del cliente: \n");
            fflush(stdin);
            scanf("%d",&auxPrestamo);
            while(validarCliente(clientes,tamCliente,auxPrestamo))
            {
                system("cls");
                mostrarClientes(clientes, tamCliente);
                printf("Error, Reingrese id: \n");
                fflush(stdin);
                scanf("%d",&auxPrestamo);
            }
            nuevoPrestamo.idCliente = auxPrestamo;

            printf("Ingrese el importe del prestamo: \n");
            scanf("%f", &auxFloat);
            while(auxPrestamo < 0)
            {
                printf("Error, Reingrese el importe del prestamo: \n");
                scanf("%f",&auxFloat);
            }
            nuevoPrestamo.importe = auxPrestamo;

            printf("Ingrese la cantidad de cuotas del prestamo: \n");
            scanf("%d", &auxPrestamo);
            while(auxPrestamo < 0)
            {
                printf("Error, Reingrese la cantidad de cuotas del prestamo: \n");
                scanf("%d",&auxPrestamo);
            }
            nuevoPrestamo.cuotas = auxPrestamo;
            strcpy(nuevoPrestamo.estado, estado);

            prestamos[indice] = nuevoPrestamo;

            //mostrarPrestamo(prestamos[indice],clientes,tamCliente);
            printf("ALTA DE PRESTAMOS EXITOSA\n\n");
        }
    }
    return error;
}


