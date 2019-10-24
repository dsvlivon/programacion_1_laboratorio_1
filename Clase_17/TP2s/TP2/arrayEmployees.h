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

Employee* new_EmpleadoParam( int idEmployee, char* name, char* lastName, float salary, int sector, int isEmpty);
Employee* new_Empleado();

void initEmployees(Employee arrayEmployee[],int size);

int addEmployee(Employee arrayEmployee[], int size);

int searchForEmpty(Employee arrayEmployee[], int size, int* position);

int findEmployeeById(Employee arrayEmployee[], int size, int *auxId);

int ModifEmployee(Employee arrayEmployee[], int size);

int printEmployees(Employee arrayEmployee[],int size, int *auxCounterId);

int removeEmployee(Employee arrayEmployee[], int size);

int searchForOccurrence(Employee arrayEmployee[], int size, int* auxCounterId);

int hardCode(Employee arrayEmployee[], int size);

int sortEmployees(Employee arrayEmployee[], int size, int pOrder);

