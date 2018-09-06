#include "biblioteca.h"
#include <stdio.h>

float suma(float operando1, float operando2)
{
    float resultado;

    resultado= operando1 + operando2;

    return resultado;
}

float resta(float operando1, float operando2)
{
    float resultado;

    resultado= operando1 - operando2;

    return resultado;
}

float division(float operando1, float operando2)
{
    float resultado;

    resultado= operando1 / operando2;

    return resultado;
}

float multiplicacion(float operando1, float operando2)
{
    float resultado;

    resultado= operando1 * operando2;

    return resultado;
}

int factorizacion1(int operando1)
{
    int numero= operando1;
    int contador1=0;
    int resultadoFactorialUno= 1;


    if(operando1== 0)
    {
        resultadoFactorialUno= 1;
    }

    else
    {

    for(contador1= numero; contador1>= 1; contador1--)
    {
        resultadoFactorialUno= resultadoFactorialUno* contador1;
    }

    }

    return resultadoFactorialUno;
}

int factorizacion2(int operando2)
{
    int numero= operando2;
    int contador2=0;
    int resultadoFactorialDos= 1;

    if(operando2== 0)
    {
        resultadoFactorialDos= 1;
    }
    else
    {

    for(contador2= numero; contador2>= 1; contador2--)
    {
        resultadoFactorialDos= resultadoFactorialDos * contador2;
    }


    }
    return resultadoFactorialDos;
}
