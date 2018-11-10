#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}
/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/** \brief pide un string, verifica si es un entero y devuelve el numero en formato int
 *
 * \param char[] mensaje a ser mostrado
 * \return int el numero en formato int
 *
 */
int getIntOnly(char mensaje[])
{
    char aux[256];
    int number;
    int flag = 0;

    do
    {
        getString(mensaje, aux);
        if(esNumerico(aux))
        {
            number = atoi(aux);
            flag = 1;
        }
        else
        {
            printf("\n(Debe ser un numero entero.)\n\n");
            flag = 0;
            system("pause");
            system("cls");
        }
    }
    while(flag == 0);
    return number;
}

/** \brief pide un string y verifica si es solo letras
 *
 * \param char[] mensaje a ser mostrado
 * \param char[] lugar donde guardar el string
 * \return void
 *
 */
void getStringOnly(char mensaje[], char input[])
{
    char aux[500];
    int flag = 0;

    do
    {
        getString(mensaje, aux);
        if(esSoloLetras(aux))
        {
            strcpy(input, aux);
            flag = 1;
        }
        else
        {
            printf("\nDebe ser solo letras.\n");
            flag = 0;
            system("pause");
            system("cls");
        }
    }
    while(flag == 0);
}

/** \brief verifica si es un numero flotante
 *
 * \param char[] array a verificar
 * \return int 1 si es numero flotante, 0 si no
 *
 */
int isFloat(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   int flag = 1;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;
       }
       if(str[i] < '0' || str[i] > '9')
       {
           flag = 0;
       }
       i++;
   }

   return flag;
}

/** \brief pide un string, verifica que sea numero flotante y lo devuelve en formato float
 *
 * \param char[] mensaje a ser mostrado
 * \return float numero en formato float
 *
 */
float getFloatOnly(char mensaje[])
{
    char aux[256];
    float num;
    int flag = 0;

    do
    {
        getString(mensaje, aux);
        if(isFloat(aux))
        {
            num = atof(aux);
            flag = 1;
        }
        else
        {
            printf("\n(Debe ser un numero.)\n\n");
            flag = 0;
            system("pause");
            system("cls");
        }
    }
    while(flag == 0);
    return num;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
