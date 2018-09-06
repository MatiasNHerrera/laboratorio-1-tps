#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

float suma(float, float);
float resta(float,float);
float division(float,float);
float multiplicacion(float,float);
int factorizacion1(int);
int factorizacion2(int);

int main()
{

    int opcion;
    float operandoUno=0;
    float operandoDos=0;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;
    int resultadoFactorizacionUno;
    int resultadoFactorizacionDos;

    do
    {
        printf("1.ingrese el primer operando: %.2f\n", operandoUno);
        printf("2.ingrese el segundo operando: %.2f\n", operandoDos);
        printf("3.calcular todas las operaciones\n");
        printf("4.informar todos los resultados\n");
        printf("5.salir\n");
        printf("ingrese una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            printf("ingrese el primer operando: ");
            scanf("%f", &operandoUno);
            break;
        case 2:
            printf("ingrese el segundo operando: ");
            scanf("%f", &operandoDos);
            break;
        case 3:
            resultadoSuma=suma(operandoUno, operandoDos);
            resultadoResta=resta(operandoUno, operandoDos);
            resultadoDivision= division(operandoUno, operandoDos);
            resultadoMultiplicacion=multiplicacion(operandoUno, operandoDos);
            resultadoFactorizacionUno= factorizacion1(operandoUno);
            resultadoFactorizacionDos= factorizacion2(operandoDos);

            break;
        case 4:
            printf("el resultado de la suma es: %.2f\n", resultadoSuma);
            printf("el resultado de la resta es: %.2f\n", resultadoResta);
            if(operandoDos== 0)
            {
                printf("no se puede dividir por cero!!\n");
            }
            else
            {
                printf("el resultado de la division es: %.2f\n", resultadoDivision);
            }
            printf("el resultado de la multiplicacion es: %.2f\n", resultadoMultiplicacion);


            if(operandoUno >= 0 && operandoDos <0)
            {
                printf("el factorial del primer operando es: %d y el segundo operando es negativo: no se puede factorizar por negativos!\n",resultadoFactorizacionUno);
            }
            else if(operandoUno<0 && operandoDos>= 0)
            {
                printf("el operando del primer factorial es negativo: no se puede factorizar por numeros negativos!! y el factorial del segundo operando es: %d\n",resultadoFactorizacionDos);
            }
            else
            {
                printf("el factorial del primer operando es: %d y el factorial del segundo operando es: %d\n", resultadoFactorizacionUno, resultadoFactorizacionDos);
            }


        case 5: printf("\ngracias por utilizar la calculadora de matias!\n");

        default:
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcion!=5);
    return 0;
}

