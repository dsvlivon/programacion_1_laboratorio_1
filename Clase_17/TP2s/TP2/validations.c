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
//////////////////////////
/* INDICE DE USO
getInput  0)isNumeric   1)isOnlyNumber  2)isDecimal   3)isLetter    4)isAlphaNumeric    5) isAnswer 6)Empty Request
auxReturn = getInput(&capSpace, "msg", "msgFail", min, max, try, mode);
*/
//////////////////////////////////////////////////////////////////////////////////
int getInput(char *pResult, char *pMsg, char *pMsgFail, int min, int max, int try, int mode){
    int auxReturn = -1;
	int iBuffer=0;
	int strCounter=0;
	int j, length;
	int strQty;
	float fBuffer=0;
	char input[50];
	char cBuffer[100];

	if(pResult!= NULL && (max>min) && try>0 )
	{
		for(j=0;j<try;j++)
		{
            printf("%s", pMsg);
            fflush(stdin);
            fgets (input, sizeof(input), stdin);
           	length=strlen(input);

			switch (mode)
			{
			    case 0:
                auxReturn = isNumeric(input, length);
                break;
			    case 1:
                auxReturn = isOnlyNumber(input, length);
                break;
                case 2:
                auxReturn = isDecimal(input, length);
                break;
                case 3:
                auxReturn = isLetter(input, length, &strCounter);
                break;
                case 4:
                auxReturn = isAlphaNumeric(input, length, &strCounter);
                break;
                case 5:
                auxReturn = isAnswer(input, length);
                break;
                case 6:
                default:
                printf("invalid request");
                break;
            }
            if(auxReturn == 0) // retorno exitoso
            {
                if(mode == 0 || mode == 1) {// salida p/modes enteros
                    iBuffer = atoi(input);
                    if(iBuffer>=min && iBuffer<=max)
                    {   //printf("dentro de max y min");
                        strcpy(pResult, input);
                        break;
                    }
                    else
                    {   //printf("fuera de max y min");
                        printf("%s. ", pMsgFail);
                        auxReturn=-1;
                    }
                }
                else if(mode == 2) {// salida p/modes flotantes
                    fBuffer = atof(input);
                    if(fBuffer>=min && fBuffer<=max)
                    {
                        strcpy(pResult, input);
                        break;
                    }
                    else
                    {
                        printf("%s. ", pMsgFail);
                        auxReturn=-1;
                    }
                }
                else if(mode == 3 || mode == 4 || mode == 5) {// salida p/modes string
                    strncpy(cBuffer,pResult,max);
                    strQty=strlen(input);
                    if(strQty!=strCounter)
                    {
                        strcpy(pResult, input);
                        break;
                    }
                }
            }
            else // retorno de error
            {
                printf("%s. ", pMsgFail);
                auxReturn=-1;
            }
		}
		if(auxReturn!=0)
            printf(" Sin reintentos. \n\n");
    }
	return auxReturn;
}
/////////////////////////////////////////(0)
int isNumeric(char aux[], int len){
    int i, auxReturn=0;

    for(i=0;i<len-1;i++)
    {
        if((aux[i] < '0' || aux[i] > '9') && aux[i] != '-') //filtro numerico
        {
			auxReturn = -1;
            break;
		}
		if(aux[i]=='-'&& i!=0) // filtro p/negativos
		{
			auxReturn = -1;
			break;
		}
    }
    return auxReturn;
}
/////////////////////////////////////////(1)
int isOnlyNumber(char aux[], int len){
    int i, auxReturn=0;

    for(i=0;i<len-1;i++)
    {
        if(aux[i] < '0' || aux[i] > '9') //filtro numerico
        {
			auxReturn = -1;
            break;
		}
    }
    return auxReturn;
}
/////////////////////////////////////////(2)
int isDecimal(char aux[], int len){
    int i, auxReturn=0;

    for(i=0;i<len-1;i++)
    {
        if((aux[i] < '0' || aux[i] > '9' )&& aux[i]!= ',' && aux[i]!= '.' && aux[i]!= '-')
		{
            auxReturn = -1;
            break;
        }
		if(aux[i]=='-'&& i!=0) // filtro p/negativos
		{
			auxReturn = -1;
			break;
		}
   }
    return auxReturn;
}
/////////////////////////////////////////(3)
int isLetter(char aux[], int len, int *auxStrCounter){
 	int i, auxReturn=0;

	for(i=0;i<len-1;i++)
   	//while(aux[i] != '\0' || aux[i] != '\n')
   	{
		if((aux[i] < 'a' || aux[i] > 'z') && (aux[i] < 'A' || aux[i] > 'Z')) //filtro letras
		{
			if(aux[i] != ' ') //excepciones
			{
				auxReturn = -1;
       			break;
                //i++;
			}
   		}
   		else
            auxStrCounter++;
	}
   return auxReturn;
}
/////////////////////////////////////////(4)
int isAlphaNumeric(char aux[], int len, int *auxStrCounter){
  	int i, auxReturn=0;

	for(i=0;i<len-1;i++)
   	//while(aux[i] != '\0' || aux[i] != '\n')
	{
	   	if((aux[i] < 'a' || aux[i] > 'z') && (aux[i] < 'A' || aux[i] > 'Z')) //filtro letras
		{
            if(aux[i] < '0' || aux[i] > '9') //filtro numerico
            {
                if((aux[i] != ' ') && (aux[i] != ',') && (aux[i] != '.')) //excepciones
                {
                    auxReturn = -1;
                    //i++;
                    break;
                }
            }
		}
		else
        {
            auxStrCounter++;
        }
	}
   return auxReturn;
}
/////////////////////////////////////////(5)
int isAnswer(char aux[], int len){
 	int i, auxReturn=0;

	for(i=0;i<len-1;i++)
   	//while(aux[i] != '\0' || aux[i] != '\n')
   	{
		if((aux[i] < 'y' || aux[i] > 'y') && (aux[i] < 'Y' || aux[i] > 'Y'))  //filtro confirmacion
		{
            auxReturn = -1;
            break;
   		}
	}
   return auxReturn;
}
