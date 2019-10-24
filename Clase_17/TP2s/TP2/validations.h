/*******************************************************************
*Programa:TP2
*Objetivo: Sistema para administrar nómina de empleados
*Version: 1.0 del 25 de Septiembre de 2019
*Autor:Daniel S.Vizgarra Livon
*Curso:1°E T.N.
********************************************************************/

/** getInput
* \brief Solicita al usuario un string y lo valída mediante las funciones IS enrutadas por un moderador
* \param pResult es el transito del entero
* \param pMsg el mensaje q pide X / pMsgFail el mensaje de error de X
* \param rango minimo / rango maximo / n° d intentos
* \param mode es el moderador que enruta que validacion se pide
* \return 0 si el resultado es exitoso. -1 de lo contrario.
*/
int getInput(char *pResult, char *pMsg, char *pMsgFail, int min, int max, int try, int mode);
//////////////
/** isNumeric
* \brief Verifica si el valor recibido contiene solo numeros
* \param str Array con la cadena a ser analizada
* \return 1 si contiene numeros del '0' al '9' por orden ASCII y 0 si no
*/
int isNumeric(char aux[], int len);
/////////////
/** isDecimal
* \brief Verifica si el valor recibido contiene telefonos
* \param str Array con la cadena a ser analizada
* \return 0 si contiene solo numeros, espacios, un + y un guion.
*/
int isDecimal(char aux[], int len);
////////////
/** isLetter
* \brief Verifica si el valor recibido contiene letras
* \param str Array con la cadena a ser analizada
* \return 0 si contiene solo ' ' y/o letras y -1 si no
*/
int isLetter(char aux[], int len, int *auxStrCounter);
//////////////////
/** isAlphaNumeric
* \brief Verifica si el valor recibido contiene solo letras, números y un grupo de excepciones
* \param str Array con la cadena a ser analizada
* \return 0 si contiene solo espacio o letras y números, y -1 si no lo es
*/
int isAlphaNumeric(char aux[], int len, int *auxStrCounter);
/////////////////
/** isOnlyNumber
* \brief Verifica si el valor recibido q contiene solo numeros entre 0 y 9
* \param str Array con la cadena a ser analizada y el largo de la cadena
* \return 0 si contiene solo numeros, -1 si no
*/
int isOnlyNumber(char aux[], int len);
////////////////
/** isAnswer
* \brief Verifica si el valor recibido q contiene como confirmacion solo (y,Y)
* \param str Array con la cadena a ser analizada y el largo de la cadena
* \return 0 si contiene solo (y,Y)
*/
int isAnswer(char aux[], int len);






