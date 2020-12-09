#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "cliente.h"
#include "menu.h"
#include "prestamo.h"

#define TAM_P 50
#define TAM_CL 50


int main()
{
    char seguir = 's';
    char confirma;
    int proximoId = 100;
    int rta;
    int idPrestamo = 1;

   eCliente listaCliente[TAM_CL];
   ePrestamo prestamos[TAM_P];

   inicializarPrestamo(prestamos, TAM_P);
   inicializarClientes(listaCliente, TAM_CL);

    do
    {
        switch(menu())
        {

        case 1:
            if(!altaCliente(listaCliente, TAM_CL, proximoId))
            {
                proximoId++;
                printf("Alta realizada con exito\n\n");
            }
            else
            {
                printf("No se pudo realizar el alta.\n\n");
            }
            break;
        case 2:
              rta = modificarCliente(listaCliente, TAM_CL);

                if(!rta)
                {
                    printf("Se ha modificado con exito.\n\n");
                }
                else if(rta == 2)
                {
                    printf("Modificacion cancelada por el usuario. \n\n");
                }
                else
                {
                    printf("Hubo un problema al intentar realizar la modificacion. \n\n");
                }
            break;
        case 3:
                rta = bajaCliente(listaCliente, TAM_CL);

                if(!rta)
                {
                    printf("Se ha dado de baja con exito.\n\n");
                }
                else if(rta == 2)
                {
                  printf("baja cancelada por el usuario. \n\n");
                }
                else
                {
                  printf("Hubo un problema al intentar realizar la baja. \n\n");
                }
            break;
          case 4:
              if(!altaPrestamo(prestamos, TAM_P, idPrestamo, listaCliente, TAM_CL))
               {
                  idPrestamo++;
               }
            else
            {
                 printf("Primero debe realizar un alta. \n");
            }
            break;
        /*case 5:
            if(flagAltaAlquiler)
            {
                finalizarAlquiler(listaCliente, TAM_CL, alquileres, TAMALQ, equipos, TAMEQUIPO, operadores, TAMOPERADOR);
            }
            else
            {
                printf("Primero debe realizar un alta de alquiler. \n");
            }
			break;*/

		case 5:
            system("cls");
            mostrarPrestamos(prestamos, TAM_P, listaCliente, TAM_CL);
            break;
        case 6:
            printf("Confirma salida?(s/n): ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
              seguir = 'n';
            }
            break;
            default:
                printf("Opcion invalida!!!\n");
            }
        system("pause");
    }while(seguir == 's');

    return 0;
}
