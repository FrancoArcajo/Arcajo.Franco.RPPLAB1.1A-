#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctype.h"
#include "validaciones.h"


int validarCliente(eCliente clientes[], int tam, int idCliente)
{
    int esValido = 1;

    for(int i =  0; i < tam; i++)
    {

        if(clientes[i].id == idCliente)
        {

            esValido = 0;

            break;
        }
    }
    return esValido;
}

int validacionCadena(char cadena[])
{
    int error = 0;
    int flag = 0;
    int tamanio;

    tamanio = strlen(cadena);
    for(int i = 0; i < tamanio; i++)
    {
        if(!((cadena[i] >= 65 && cadena[i] <= 90) || (cadena[i] >= 97 && cadena[i] <= 122) || cadena[i] == ' '))
        {
            flag = 1;
            error = 1;
        }
    }
    if(cadena[0] == '\0' || cadena[0] == ' ')
    {
        flag = 1;
        error = 1;
    }
    if(flag == 1)
    {
        printf("Ingrese cadena valida(solo letras o espacios).\n");
    }
    return error;
}

int strLwr(char* str)
{
	int todoOk = -1;
	int i = 0;

	if(str != NULL)
	{
		while(str[i] != '\0')
		{
			str[i] = tolower(str[i]);
			i++;
		}
		todoOk = 0;
	}
	return todoOk;
}

int normalizeStr(char* str)
{
	int todoOk = -1;
	int i = 0;

	if(str != NULL)
	{
		strLwr(str);
		str[0] = toupper(str[0]);

		while(str[i] != '\0')
		{
			if(str[i] == ' ')
			{
				str[i + 1] = toupper(str[i + 1]);
				todoOk = 0;
			}
			i++;
		}
	}
	return todoOk;
}

int utn_getEntero(int* pEntero, int reintentos, char* mensaje, char* mensajeError, int minimo, int maximo)
{
    int todoOk = -1;
    int auxInt;

    if(pEntero != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s", mensaje);

            if(getInt(&auxInt) == 0 && auxInt >= minimo && auxInt <= maximo)
            {
                *pEntero = auxInt;
                todoOk = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
        while(reintentos >= 0);
    }
    return todoOk;
}

int getInt(int* pAux)
{
    char auxString[400];
    int todoOk = -1;

    if(getCadena(auxString, sizeof(auxString)) == 0 && isInt(auxString ) == 0)
    {
        *pAux = atoi(auxString);
        todoOk = 0;
    }
    return todoOk;
}

int isInt(char *pAux)
{
    int todoOk = -1;
    int i = 0;
    int stringLong = strlen(pAux);

    do
    {
        if(*(pAux + i) < '0' || *(pAux + i) > '9')
        {
            break;
        }

        i++;

    }while (i < stringLong);

    if(i == stringLong)
    {
        todoOk = 0;
    }

    return todoOk;
}

int getCadena(char* pAux, int limit)
{
    char auxString[4000];
    int todoOk = -1;

    if (pAux != NULL && limit > 0)
    {
        fflush(stdin);
        fgets(auxString,sizeof(auxString),stdin);

        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= limit)
        {
            strncpy(pAux, auxString, limit);
            todoOk = 0;
        }
    }
    return todoOk;
}
