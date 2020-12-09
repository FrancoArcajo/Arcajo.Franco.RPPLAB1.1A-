#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "menu.h"
#include "validaciones.h"

int menu()
{
    int opcion;

    system("cls");

    printf("1. ALTA DEL CLIENTE.\n");
    printf("2. MODIFICAR DATOS DEL CLIENTE.\n");
    printf("3. BAJA DEL CLIENTE.\n");
    printf("4. ALTA DE PRESTAMO.\n");
    printf("5. MOSTRAR PRESTAMO.\n");
    printf("6. .\n");
    printf("10. SALIR.\n\n");

   utn_getEntero(&opcion, 9, "Ingrese opcion: ", "Error, opcion invalida\n", 1, 10);

    return opcion;
}
