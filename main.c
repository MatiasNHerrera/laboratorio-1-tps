#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaUtn.h"
#include "arrayEmployee.h"

int main()
{
    Employee ArrayEmployeeMain[T];
    int optionMenu3;
    int optionMenu2;
    char optionMenu= 's';
    int flag= 0;
    int auxId=0;

    initEmployees(ArrayEmployeeMain, T);

    do
    {

        printf("\n a. Alta\n m. Modificar\n b. Baja\n f. Informar\n");
        optionMenu= getChar("\ningrese un caracter para la opcion que desee utilizar: ");

        switch(optionMenu)
        {
        case 'a':
            if(addEmployee(ArrayEmployeeMain,T)!= FALSE)
            {
                printf("\ncarga satisfactoria!!\n");
                flag= 1;
            }
            else
            {
                printf("\nno hay espacio libre!\n");

            }
            break;

        case 'm':
            if(flag== 1)
            {

                if(modifyEmployee(ArrayEmployeeMain, T, auxId)== 0)
                    {
                        printf("\nse ha modificado correctamente: \n");
                    }
                else
                    {
                        printf("\nNo se encontro id\n");
                    }
            }

            if(flag==0)
            {
                printf("\nno se han ingresado datos todavia\n");
            }

            break;

        case 'b':
            if(flag== 1)
            {

                if(removeEmployee(ArrayEmployeeMain,T) ==0)
                {
                    printf("\nSe ha removido exitosamente\n");
                }
                else
                {
                    printf("\nNo es posible remover\n");
                }
            }
            else
            {
                printf("\nNo se ha cargado nada todavia!!\n");
            }
                    break;

        case 'f':

            printf("\n l. listado de empleados\n p. total, promedio de salarios y cuantos superan el salario minimo\n");
            optionMenu2=getChar("\ningrese un caracter para la opcion que desee utilizar: ");

            switch(optionMenu2)
            {
                case 'l':
                    printf("\n 1. Ordenar por apellido albeticamente\n 2. Ordenar por sector\n");
                    optionMenu3= getInt("ingrese opcion para la funcion que desee realizar");
                    switch(optionMenu3)
                    {
                        case 1:
                        if(flag== 1)
                        {
                            sortEmployeesByLastName(ArrayEmployeeMain, T);
                            printf("\nSe ha ordenado correctamente\n");
                        }
                        else
                        {
                            printf("\nno se ha cargado nada todavia!\n");
                        }
                        break;

                        case 2:
                        if(flag== 1)
                        {
                            sortEmployeesBySector(ArrayEmployeeMain,T);
                            printf("\nSe ha ordenado correctamente\n");
                        }
                        else
                        {
                            printf("no se ha cargado nada todavia!\n");
                        }
                        break;
                    }
                break;

                case 'p':
                    if(flag== 1)
                    {

                        salaryAndPromedy(ArrayEmployeeMain, T);

                    }
                    else
                    {
                        printf("no se ha cargado nada todavia!\n");
                    }
            }       break;
            break;

        }

       system("pause");
       system("cls");
    }
    while(optionMenu!= 's');
}



