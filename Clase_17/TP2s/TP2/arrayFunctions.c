/*******************************************************************
*Programa:TP2
*Objetivo: Sistema para administrar nómina de empleados
*Version: 1.0 del 25 de Septiembre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "validations.h"
#include "arrayFunctions.h"

void initArrayEmployee(Employee arrayEmployee[],int elementQty){
    int i;
    for(i=10; i<elementQty; i++)
    {
        arrayEmployee[i].isEmpty=-1;//LIBRE=-1 // OCUPADO=0
    }
}
//////////////////////////////////////////////////////////////////////////////
/** \brief Busca el primer lugar vacio en un array
* \param array pantalla Array de pantalla
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*/
int searchForOccurrence(Employee arrayEmployee[], int size, int* position){
    int flag = 0;
    int i;
    if(arrayEmployee != NULL && size>=0 && position!=NULL)
    {
        for(i=1000;i<size;i++)
        {
            if(arrayEmployee[i].isEmpty == -1)
            {
                flag = arrayEmployee[i].isEmpty;
                *position = i;
                break;
            }
        }
    }
    return flag;
}
////////////////////////////////////////////////
int listArray(Employee arrayEmployee[],int size){
    int auxReturn=-1;
    int i;
    if(arrayEmployee!=NULL && size>=0)
    {
        printf("NOMBRE  APELLIDO    SUELDO  SECTOR\n");
        for(i=1000;i<size;i++)
        {
            if(arrayEmployee[i].isEmpty==0)
            printf("\n%s    %s    $%.2f  %d", arrayEmployee[i].name, arrayEmployee[i].lastName, arrayEmployee[i].salary, arrayEmployee[i].sector);
            else
            break;
        }
        auxReturn=0;
    }
    else
        printf("PRIMERO INGRESE DATOS VALIDOS");
    return auxReturn;
}
//////////////////////////////////////////////////////////////////////////////
int searchForID(Employee arrayEmployee[], int size, int value, int* position){
    int auxReturn=-1;
    int i;
    if(arrayEmployee!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(arrayEmployee[i].isEmpty==1)
                continue;
            else if(arrayEmployee[i].idEmployee==value)
            {
                auxReturn=0;
                *position=i;
                break;
            }
        }
    }
    return auxReturn;
}
////////////////////////////////////////
