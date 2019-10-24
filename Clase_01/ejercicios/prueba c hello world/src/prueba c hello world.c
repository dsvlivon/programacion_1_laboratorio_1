/*
 ============================================================================
 Name        : prueba.c
 Author      : Daniel Livón
 Version     :
 Copyright   : TH
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int pideSuma(int* rsultado);


int main (void)
{
	int resultado;
	if (pideSuma(&resultado)==0);
	{
		printf("El resultado es %d", resultado);
	}
	else
	{
		printf("ERROR");
	}
	return 0;
}

int pideSuma(int* rsultado)
{
	int valorA;
	int valorB;
	printf("ingrese el valorA: ");
	scanf("%d", &valorA);
	printf("ingrese el valorB: ");
	scanf("%d", &valorB);
	resultado=valorA+valorB;
	printf("el resultado es %d", resultado);
}

