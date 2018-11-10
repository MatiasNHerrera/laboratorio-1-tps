#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) si algo salio mal, (0) si todo salio bien
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno= -1;
    char auxId[128];
    char auxNombre[128];
    char auxHorasTrabajadas[128];
    char auxSueldo[128];

    Employee* employeeParser;

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);

    if(pArrayListEmployee !=NULL && pFile != NULL)
    {
        while(!feof(pFile))
        {

            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
            employeeParser= employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
            ll_add(pArrayListEmployee, employeeParser);
            retorno=0;
        }

    }
    else
    {
        printf("\nNo se pudo parsear\n");
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) si algo salio mal, (0) si todo salio bien
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno= -1;
    int cant;

    Employee* employeeParser;

    if(pArrayListEmployee !=NULL && pFile != NULL)
    {
        retorno=0;
        do
        {
            employeeParser= employee_new();
            cant = fread(employeeParser, sizeof(Employee), 1, pFile);
            if(cant!= 1)
            {
                break;
            }
            else
            {
                ll_add(pArrayListEmployee, employeeParser);
            }
        }
        while(!feof(pFile));

    }
    else
    {
        printf("\nNo se pudo parsear\n");
    }

    return retorno;

}
