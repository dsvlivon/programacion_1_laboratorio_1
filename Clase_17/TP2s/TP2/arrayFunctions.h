/*******************************************************************
*Programa:TP2
*Objetivo: Sistema para administrar nómina de empleados
*Version: 1.0 del 25 de Septiembre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/

/**
*\brief Inicializa un array de Empleados con el valor recibido
*\param arrayEmployee es el array a ser inicializado
*\param elementQty indica la longitud del array
*\param value es el valor que sera cargado en cada posición
*\return void
*/
typedef struct{
    int idEmployee;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

void initArrayEmployee(Employee arrayEmployee[],int elementQty);
/**
*\brief Busca la ocurrencia de un valor determinado en el arrayEmployee
*\param arrayEmployee es el array donde va a buscar
*\param elementQty indica la longitud del array
*\return Si no hay ocurrencia (-1) y si la hay, la posición de la misma
*/

int searchForOccurrence(Employee arrayEmployee[], int size, int* position);

int listArray(Employee arrayEmployee[],int elementQty);

