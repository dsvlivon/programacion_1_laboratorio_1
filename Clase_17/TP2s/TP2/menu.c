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
#include "arrayEmployees.h"

#define QTY_EMPLOYEES 2000
#define FAIL_INITMSG "\n\nNO HAY LEGAJOS HABILITADOS. \n"

 int menu()
 {
    //Employee arrayEmployee[QTY_EMPLOYEES];

    int auxReturn=-1, option;
    int counterId=0;
    char aux[50];

    //initEmployees(arrayEmployee,QTY_EMPLOYEES);//Seteo de array inicial
    do{
        system ("cls");
        printf("        BIENVENIDOS A FERRETE S.R.L. \n\n\n1) ALTAS.\n2) MODIFICAR.\n3) BAJAS.\n4) INFORMAR.\n5) SALIR.");
        ///////////////////////////////////////////////
        auxReturn = getInput(aux, "\n\nIngrese una opcion: ","\nIngreso invalido!",1,5,2,1);
        if(auxReturn == 0)
        {
            option= atoi(aux);
        }
        fflush(stdin); //__fpurge para Linux
        auxReturn=-1;
        switch(option)
        {
            case 1:
                auxReturn = addEmployee(arrayEmployee, QTY_EMPLOYEES);
                //auxReturn = hardCode(arrayEmployee, QTY_EMPLOYEES);
            break;
            case 2:
                auxReturn = searchForOccurrence(arrayEmployee, QTY_EMPLOYEES, &counterId);
                if(auxReturn== 0)
                {
                    ModifEmployee(arrayEmployee, QTY_EMPLOYEES);
                }
                else
                    printf(FAIL_INITMSG);
            break;
            case 3:
                auxReturn = searchForOccurrence(arrayEmployee, QTY_EMPLOYEES, &counterId);
                if(auxReturn== 0)
                {
                    removeEmployee(arrayEmployee, QTY_EMPLOYEES);
                }
                else
                    printf(FAIL_INITMSG);
            break;
            case 4:
                auxReturn = searchForOccurrence(arrayEmployee, QTY_EMPLOYEES, &counterId);
                if(auxReturn== 0)
                {
                    printf("INFORME: \n");
                    printEmployees(arrayEmployee,QTY_EMPLOYEES, &counterId);
                }
                else
                    printf(FAIL_INITMSG);
            break;
            case 5:
            printf("Saliendo... ");
            break;
            default:
            printf("Opcion invalida\n");
            break;
        }
        system("pause");
    }while (option !=5);
    return auxReturn;
}

