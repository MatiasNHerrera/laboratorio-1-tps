#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaUtn.h"
#include "bibliotecaEmployee.h"
#define T 2
#define FALSE -1

int main()
{
    Employee ArrayEmployeeMain[T];
    int index;
    char name[50];
    char lastName[50];
    float salary;
    int sector;
    int optionMenu2;
    index= findFree(ArrayEmployeeMain, T);
    char optionMenu;

    initEmployees(ArrayEmployeeMain, T);

    do
    {

        printf(" a. Alta\n m. Modificar\n b. Baja\n f. Informar\n");
        optionMenu= getChar("\ningrese un caracter para la opcion que desee utilizar: ");

        switch(optionMenu)
        {
        case 'a':

            if(index!= FALSE)
            {
                  if(!getStringLetras("enter name: ", name))
                     {
                         printf("\nenter only letters\n");
                         break;
                     }

                  if(!getStringLetras("enter last name: ", lastName))
                  {

                        printf("\nenter only letters\n");
                        break;
                  }

                  salary= getFloat("enter the salary: ");
                  sector= getInt("enter the sector: ");

                  addEmployee(ArrayEmployeeMain,T, index, name, lastName, salary,sector);

            }

            else
            {
                printf("\nNo free space!\n");
            }

            break;

        case 'm':
            break;

        case 'b':
            break;

        case 'f':

            printf("\n l. listado de empleados\n p. total, promedio de salarios y cuantos superan el salario minimo\n");
            optionMenu2=getChar("\ningrese un caracter para la opcion que desee utilizar: ");

            switch(optionMenu2)
            {
                case 'l':
                    sortEmployees(ArrayEmployeeMain, T);
                    break;

                case 'n':
                    break;
            }
            break;

        }

    }
    while(optionMenu!= 's');
}



