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
#define ID_FAIL "No se puede completar un legajo con datos erroneos.\n\n"

////////////////////////////////////////////////////////////////////////// IE
void initEmployees(Employee arrayEmployee[],int size){
    int i;

    for(i=1000; i<size; i++)
    {
        arrayEmployee[i].isEmpty=-1;//LIBRE=-1 // OCUPADO=0
    }
    for(i=0; i<999; i++)
    {
        arrayEmployee[i].isEmpty=-2;//LIBRE=-1 // OCUPADO=0
    }
}
/////////////////////////////////////////////////////////////////////////  AE
int addEmployee(Employee arrayEmployee[], int size){
    int auxReturn=0;
    //int freeSpotFlag,freeSpot;
    char aux[50];
    /////////////
    int bufId;
    char bufName[51];
    char bufLname[51];
    float bufSalary;
    int bufSector;
    int bufIsEmpty;
    ////////////////
    int flagRealloc=0;
    int cont=0;

    Employee** lista = (Employee**) malloc(sizeof(Employee*));
    Employee** pAuxEmpleado;
    Employee* nuevoEmpleado = new_Empleado();

    //freeSpotFlag = searchForEmpty(arrayEmployee, size ,&freeSpot);
    /*if(freeSpotFlag == 0)
    {
        printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
    }
    else if(freeSpotFlag == -1)
    {
        printf("\nAlta Legajo Nro.%d: \n", freeSpot);*/
        if(flagRealloc==1)
        {
            cont++;
            pAuxEmpleado = (Employee**) realloc(lista, sizeof(Employee*) *(cont+1));
            if(pAuxEmpleado == NULL){
                printf("no hay espacio para agregar un nuevo empleado");
            }
            else
            lista = pAuxEmpleado;
        }
        /////////////////////////////////////
        auxReturn = getInput(aux, "Ingrese el/los Nombre/s: ","\nIngreso invalido!",0,50,2,3);
        if(auxReturn == 0)
        {
            strcpy(bufLname,aux);
            //printf("El nombre validado es: %s\n", arrayEmployee[freeSpot].name);
        }
        if(auxReturn == 0)
        {
            auxReturn = getInput(aux, "Ingrese el/los Apellido/s: ","\nIngreso invalido!",0,50,2,3);
            if(auxReturn == 0)
            {
                strcpy(bufLname,aux);
                //printf("El apellido validado es: %s\n", arrayEmployee[freeSpot].lastName);
            }
        }
        else
            {
                auxReturn=-1;
            }
        if(auxReturn == 0)
        {
            auxReturn = getInput(aux, "Ingrese el Sueldo: ","\nIngreso invalido!",0,1999999,2,2);
            if(auxReturn == 0)
            {
                bufSalary = atof(aux);
                //printf("El sueldo validado es: $%.2f \n\n", arrayEmployee[freeSpot].salary);
            }
        }
        else
        {
            auxReturn=-1;
        }
        if(auxReturn == 0)
        {
            auxReturn = getInput(aux, "Ingrese el Sector: ","\nIngreso invalido!",1,5,2,1);
            if(auxReturn == 0)
            {
                bufSector = atoi(aux);
                //printf("El sector validado es: %d \n\n", arrayEmployee[freeSpot].sector);
            }
        }
         else
        {
            auxReturn=-1;
        }
        /*if(searchForEmpty(arrayEmployee,size,&freeSpot)== 0)
        {
            printf("\n\nEL LEGAJO YA EXISTE!!!\n");
        } //BUSCA REPETIDOS
        arrayEmployee[freeSpot].isEmpty=0;
        arrayEmployee[freeSpot].idEmployee=freeSpot;
        freeSpotFlag=0;*/
        bufIsEmpty=0;
        flagRealloc=1;
        nuevoEmpleado = new_EmpleadoParam(bufId, bufName,bufLname,bufSalary, bufSector, bufIsEmpty);
        //////////////////////////////////////////// testeo
        /*printf("\nAuxReturn: %d\n\n",  auxReturn);
        printf("freeSpotFlag: %d\n",  freeSpotFlag);
        printf("id empleado: %d\n", arrayEmployee[freeSpot].idEmployee);
        printf("freeSpot: %d  isEmpty: %d\n", freeSpot, arrayEmployee[freeSpot].isEmpty);
        printf("freeSpot: %d  isEmpty: %d\n", freeSpot+1, arrayEmployee[freeSpot+1].isEmpty);*/
    }
    free(lista);
    free(pAuxEmpleado);
    free(nuevoEmpleado);

    return auxReturn;
}

Employee* new_Empleado(){
    Employee* emp = (Employee*)malloc( sizeof(Employee));

    if(emp != NULL)
    {
        emp->idEmployee = 0;
        strcpy(emp->name, "");
        strcpy(emp->lastName, "");
        emp->salary = 0;
        emp->sector = 0;
        emp->isEmpty = 0;
    }
    return emp;
}


Employee* new_EmpleadoParam( int pId, char* pName, char* pLastName, float pSalary, int pSector, int pIsEmpty){

    Employee* emp = (Employee*)malloc( sizeof(Employee));

    if(emp != NULL)
    {
        emp->idEmployee = leg;
        strcpy(emp->name, pName);
        strcpy(emp->lastName, pLastName);
        emp->salary = pSalary;
        emp->sector = pSector;
        emp->isEmpty = pIsEmpty;
    }
return emp;
}





/////////////////////////////////////////////////////////////////////////  SFE
int searchForEmpty(Employee arrayEmployee[], int size, int* position){
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
/////////////////////////////////////////////////////////////////////////  FEID
int findEmployeeById(Employee arrayEmployee[], int size, int *auxId){
    int auxReturn=-1;
    int i, value;
    char aux[6];

    if(arrayEmployee!= NULL && size>=0)
    {
        auxReturn = getInput(aux, "Ingrese el ID: ","\nIngreso invalido!",1000,2000,2,1);
        if(auxReturn == 0)
        {
            value= atoi(aux);
            for(i=1000;i<size;i++)
            {
                if(arrayEmployee[i].idEmployee==value)
                {
                    *auxId = value;
                    auxReturn=0;
                    break;
                }
                else
                printf("\nId No disponible.");
                break;
            }
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  FEBID
int ModifEmployee(Employee arrayEmployee[], int size){
    int auxReturn=-1;
    int option, value;
    char aux[6];

    if(arrayEmployee!= NULL && size>=0)
    {
        auxReturn=findEmployeeById(arrayEmployee, QTY_EMPLOYEES, &value);
        if(auxReturn==0)
        {

            do{
                system ("cls");
                /////////////////////////////////////
                printf("\nMENU MODIFICACIONES: \n\nLegajo Nro.%d: \n", value);
                printf("\n1)Nombre: %s\n2)Apellido: %s\n3)Sueldo: $%.2f\n4)Sector: %d\n5)VOLVER\n", arrayEmployee[value].name, arrayEmployee[value].lastName, arrayEmployee[value].salary, arrayEmployee[value].sector);
                auxReturn = getInput(aux, "\nIngrese una opcion: ","\nIngreso invalido!",1,5,2,1);
                if(auxReturn == 0){
                    option= atoi(aux);
                }
                fflush(stdin); //__fpurge para Linux
                switch(option)
                {
                    case 1:
                    auxReturn = getInput(aux, "Ingrese el/los Nombre/s: ","\nIngreso invalido!",0,50,2,3);
                    if(auxReturn == 0)
                    {
                        strcpy(arrayEmployee[value].name,aux);
                    }
                    break;
                    case 2:
                    auxReturn = getInput(aux, "Ingrese el/los Apellido/s: ","\nIngreso invalido!",0,50,2,3);
                    if(auxReturn == 0)
                    {
                        strcpy(arrayEmployee[value].lastName,aux);
                    }
                    break;
                    case 3:
                    auxReturn = getInput(aux, "Ingrese el Sueldo: ","\nIngreso invalido!",0,1999999,2,2);
                    if(auxReturn == 0)
                    {
                        arrayEmployee[value].salary = atof(aux);
                    }
                    break;
                    case 4:
                    auxReturn = getInput(aux, "Ingrese el Sector: ","\nIngreso invalido!",1,5,2,1);
                    if(auxReturn == 0)
                    {
                        arrayEmployee[value].sector = atoi(aux);
                    }
                    break;
                    case 5:
                    printf("Volviendo... ");
                    break;
                    default:
                    printf("Opcion invalida\n");
                    break;
                }
                system("pause");
            }while (option !=5);
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  RE
int removeEmployee(Employee arrayEmployee[], int size){
    int auxReturn=-1;
    int i, value;
    char aux[10];
    char empty[50];

    if(arrayEmployee!= NULL && size>=0)
    {
        auxReturn = getInput(aux, "Ingrese el ID para Baja: ","\nIngreso invalido!",1000,2000,2,1);
        if(auxReturn == 0)
        {
            value = atoi(aux);
        }
        for(i=1000;i<size;i++)
        {
            if(arrayEmployee[i].idEmployee!=value)
            {
                continue;
            }
            else if(arrayEmployee[i].idEmployee==value)
            {
                printf("\nBaja Legajo Nro.%d: \n", value);
                printf("\nNombre: %s\nApellido: %s\nSueldo: $%.2f\nSector: %d", arrayEmployee[value].name, arrayEmployee[value].lastName, arrayEmployee[value].salary, arrayEmployee[value].sector);
                ///////////////////////////////////////////////////////////////////////////////////////
                auxReturn = getInput(aux, "\nConfirma la baja? Y/N: ","\nLa Baja no se realizo.",0,2,1,5);
                if(auxReturn==0)
                {
                    printf("Baja en curso ...");
                    strcpy(arrayEmployee[value].name, empty);
                    strcpy(arrayEmployee[value].lastName, empty);
                    arrayEmployee[value].salary = 0;
                    arrayEmployee[value].sector = 0;
                    arrayEmployee[value].isEmpty = -1;
                }
            }
            break;
        }
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  SFO
int searchForOccurrence(Employee arrayEmployee[], int size, int *auxCounterId){
    int flag = -1;
    int i;
    if(arrayEmployee != NULL && size>=0)
    {
        for(i=1000;i<size;i++)
        {
            if(arrayEmployee[i].isEmpty == -1)
                continue;
            else if(arrayEmployee[i].isEmpty == 0)
            {
                flag = arrayEmployee[i].isEmpty;
                auxCounterId++;
            }
        }
        printf("\n\nContador id dsd SFO: %dc\n", *auxCounterId);
    }
    return flag;
}
/////////////////////////////////////////////////////////////////////////  PE
int printEmployees(Employee arrayEmployee[],int size, int *auxCounterId){
    int auxReturn=-1;
    int i, order;
    char aux[50];

    if(arrayEmployee!=NULL && size>=0)
    {
        printf("\nContador id dsd PE: %d\n", *auxCounterId);
        auxReturn = getInput(aux, "\n1)Orden Descendente \n2)Orden Ascendente\n\nIngrese una opcion: ","\nIngreso invalido!",1,2,1,1);
        if(auxReturn==0)
        {
            order = atoi(aux);
            auxReturn = sortEmployees(arrayEmployee, QTY_EMPLOYEES, order);
        }
        if(auxReturn==0)
        {
            printf("ID NOMBRE APELLIDO SUELDO SECTOR\n");
            for(i=1000;i<size;i++)
            {
                if(arrayEmployee[i].isEmpty==-1)
                    continue;
                else if(arrayEmployee[i].isEmpty==0)
                printf("%d %s %s %.2f %d\n", arrayEmployee[i].idEmployee, arrayEmployee[i].lastName, arrayEmployee[i].name, arrayEmployee[i].salary, arrayEmployee[i].sector);
                else
                break;
            }
            auxReturn=0;
        }
    }
    else{
        printf("PRIMERO INGRESE DATOS VALIDOS");
    }
    return auxReturn;
}
/////////////////////////////////////////////////////////////////////////  SE - INCOMPLETA
int sortEmployees(Employee arrayEmployee[], int size, int pOrder){
    int auxReturn=-1;
    int i,j;
    char auxChar[50];
    int auxInt;

    if(arrayEmployee!=NULL && size>=0)
    {
        if(pOrder==0)
        {
            for(i=1000;i<size-1;i++) //swap por sector Orden Desendente
            {
                if(strcmp(arrayEmployee[i].name,arrayEmployee[i+1].name)==0)
                {
                    for(j=1000;j<size;j++) //swap por sector Orden Desendente
                    {
                        auxInt = arrayEmployee[i].sector;
                        arrayEmployee[i].sector = arrayEmployee[i+1].sector;
                        arrayEmployee[i].sector = auxInt;
                    }
                }
                else if(strcmp(arrayEmployee[i].name,arrayEmployee[i+1].name)>=1)
                {
                    strcpy(auxChar, arrayEmployee[i].lastName);
                    strcpy(arrayEmployee[i].lastName, arrayEmployee[i+1].lastName);
                    strcpy(arrayEmployee[i].lastName, auxChar);

                    /*auxInt = arrayEmployee[i].idEmployee;
                    arrayEmployee[i].idEmployee = arrayEmployee[i+1].idEmployee;
                    arrayEmployee[i].idEmployee = auxInt;

                    strcpy(auxChar, arrayEmployee[i].name);
                    strcpy(arrayEmployee[i].name, arrayEmployee[i+1].name);
                    strcpy(arrayEmployee[i].name, auxChar);

                    auxFloat = arrayEmployee[i].salary;
                    arrayEmployee[i].salary = arrayEmployee[i+1].salary;
                    arrayEmployee[i].salary = auxFloat;

                    auxInt = arrayEmployee[i].sector;
                    arrayEmployee[i].sector = arrayEmployee[i+1].sector;
                    arrayEmployee[i].sector = auxInt;*/
                }
                else
                    continue;
            break;
            }
        }
        if(pOrder==1)
        {
            for(i=1000;i<size;i++) //swap por sector Orden Desendente
            {
                if(strcmp(arrayEmployee[i].name,arrayEmployee[i+1].name)==0)
                {
                    for(j=1000;j<size;j++) //swap por sector Orden Desendente
                    {
                        auxInt = arrayEmployee[i].sector;
                        arrayEmployee[i].sector = arrayEmployee[i+1].sector;
                        arrayEmployee[i].sector = auxInt;
                    }
                }
                else if(strcmp(arrayEmployee[i].name,arrayEmployee[i+1].name)>=1)
                {
                    strcpy(auxChar, arrayEmployee[i].lastName);
                    strcpy(arrayEmployee[i].lastName, arrayEmployee[i+1].lastName);
                    strcpy(arrayEmployee[i].lastName, auxChar);
                }
                else
                    continue;
            break;
            }
        }
        auxReturn=0;
    }
    return auxReturn;
}
//////////////////////////////////////////////////////
int hardCode(Employee arrayEmployee[], int size){
    int i=1000;
    int auxReturn=0;
    int base=20000;
    int sector=1;

    strcpy(arrayEmployee[i].name,"jon");
    strcpy(arrayEmployee[i].name,"doe");
            arrayEmployee[i].salary=base;
            arrayEmployee[i].salary=sector;  // o  = {FLAG_ON, "jane","doe","15000",2}

    strcpy(arrayEmployee[i+1].name,"jane");
    strcpy(arrayEmployee[i+1].name,"doe");
            arrayEmployee[i+1].salary=base+5000;
            arrayEmployee[i+1].salary=sector+1;

    strcpy(arrayEmployee[i+1].name,"jimmy");
    strcpy(arrayEmployee[i+1].name,"doe");
            arrayEmployee[i+1].salary=base+5000;
            arrayEmployee[i+1].salary=sector+1;

    strcpy(arrayEmployee[i+1].name,"judy");
    strcpy(arrayEmployee[i+1].name,"doe");
            arrayEmployee[i+1].salary=base+5000;
            arrayEmployee[i+1].salary=sector+1;

    return auxReturn;
}
