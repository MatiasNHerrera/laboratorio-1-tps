#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "bibliotecaUtn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int opcionDos=0;
    int flag= 1;
    LinkedList* listaEmpleados= ll_newLinkedList();

    do{
        printf("-----MENU-----");
        printf("\n1. Cargar en archivo de texto\n2. Cargar en archivo binario\n3. Alta empleado\n4. Modificar empleado\n5. Baja empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar en archivo de texto\n9. Guardar en archivo binario\n10. Salir");
        printf("\nIngrese opcion que desee utilizar\n");
        scanf("%d", &option);
        flag= ll_isEmpty(listaEmpleados);
        switch(option)
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados)==0)
                {
                    printf("\nSe ha cargado de forma correcta\n");
                }
                else
                {
                    printf("\nNo se ha podido cargar de forma correcta\n");
                }
                break;
            case 2:
                if(controller_loadFromBinary("data.bin", listaEmpleados)==0)
                {
                    printf("\nSe ha cargado de forma correcta");
                }
                else
                {
                    printf("\nNo se ha podido cargar de forma correcta\n");
                }

                break;
            case 3:
                if(!controller_addEmployee(listaEmpleados))
                {
                    printf("\nLos datos han sido cargados con exito\n");
                }
                else
                {
                    printf("\nNo se han podido cargar los datos\n");
                }

                break;
            case 4:
                if(flag == 0)
                {
                    if(controller_editEmployee(listaEmpleados)==0)
                    {
                        printf("\nSe ha modificado de forma correcta\n");
                    }
                    else
                    {
                        printf("\nNo se ha podido modificar de forma correcta\n");
                    }
                }
                else
                {
                    printf("\nNo se han cargado datos todavia\n");
                }
                break;
            case 5:
                if(flag==0)
                {
                    if(controller_removeEmployee(listaEmpleados)==0)
                    {
                        printf("\nSe ha removido de forma correcta\n");
                    }
                    else
                    {
                        printf("\nNo se ha podido remover de forma correcta\n");
                    }
                }
                else
                {
                    printf("\nNo se ha ingresado nada todavia\n");
                }
                break;
            case 6:
                if(flag == 0)
                {
                    if(controller_ListEmployee(listaEmpleados)==0)
                    {
                        printf("\nListado de forma correcta\n");
                    }
                    else
                    {
                        printf("\nNo se ha podido listar empleados\n");
                    }
                }
                else
                {
                    printf("\nNo se ha cargado nada todavia\n");
                }
                break;

            case 7:
                if(flag== 0)
                {
                    if(controller_sortEmployee(listaEmpleados)==0)
                   {
                        printf("\nSe ha ordenado de forma correcta\n");
                   }
                   else
                   {
                       printf("\nNo se ha podido ordenar de forma correcta\n");
                   }
                }
                else
                {
                    printf("\nNo se han cargado datos todavia\n");
                }
                break;
            case 8:
                if(flag== 0)
                {
                    if(controller_saveAsText("data.csv", listaEmpleados)==0)
                    {
                        printf("\nSe ha guardado de forma correcta\n");
                    }
                    else
                    {
                        printf("\nNo se ha podido guardar de forma correcta\n");
                    }
                }
                else
                {
                    printf("\nNo se ha cargado nada todavia\n");
                }
                break;
            case 9:
                if(flag==0)
                {
                      if(controller_saveAsBinary("data.bin", listaEmpleados)==0)
                      {
                          printf("\nSe ha guardado de forma correcta\n");
                      }
                      else
                      {
                          printf("\nNo se ha podido guardar de forma correcta\n");
                      }
                }
                else
                {
                    printf("\nNo se han ingresado datos todavia\n");
                }

                break;

            case 10:
                opcionDos=getIntOnly("\n1. Salir sin borrar lista\n2. Salir y borrar lista");
                if(opcionDos== 2)
                {
                    ll_deleteLinkedList(listaEmpleados);
                }
                else
                {
                    break;
                }

                break;

        }
            system("pause");
            system("cls");


    }while(option != 10);
    return 0;
}
