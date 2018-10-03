#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaUtn.h"
#include "arrayEmployee.h"
#define TRUE 1
#define FALSE -1
#define T 5
#include <string.h>


static int PersonalId()
{
    static int id = -1;

    id ++;

    return id;
}

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int initEmployees(Employee *list, int len)
{
    int i;
    int numberReturn= -1;

    if(list!= NULL)
    {
        for(i=0; i<len; i++)
        {
            list[i].isEmpty= TRUE;
            numberReturn= 0;
        }

    }

    return numberReturn;
}

/** \brief add in a existing list of employees
 * \param list employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/

int addEmployee(Employee *list,int len)
{
    int index;
    int numberReturn= -1;

    index= findFree(list, len);

    if(list !=NULL)
    {
        if(index != FALSE)
        {
            list[index]= enterEmployee(list);
            numberReturn= 0;
        }

    }

    return numberReturn;
}

/** \brief add a employee
 *
 * \param list Employee[]
 * \return Return myEmployee list
 */
Employee enterEmployee(Employee list[])
{
    Employee myEmployee;

    if(!getStringLetras("ingrese nombre: ", myEmployee.name))
    {
        printf("\nintroduzca solo letras\n");
    }

    if(!getStringLetras("ingrese apellido: ", myEmployee.lastName))
    {

        printf("\nintroduzca solo letras\n");
    }

    myEmployee.salary= getFloat("ingrese salario: ");
    myEmployee.sector= getInt("ingrese sector: ");
    myEmployee.id= PersonalId();

    myEmployee.isEmpty = 0;

    return myEmployee;
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */

int findEmployeeById(Employee* list, int len,int id)
{
    int i;
    int numberReturn= -1;

    if(list!= NULL)
    {
        id= getInt("ingrese el id del empleado: \n");

        for(i=0; i<len; i++)
        {
            if(list[i].id== id)
            {
                numberReturn= i;
            }

        }

    }

    return numberReturn;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */

int removeEmployee(Employee* list, int len)
{
    int auxId= 0;
    int index;
    int numberReturn= -1;
    int answer= 'n';



    index = findEmployeeById(list, len, auxId);

    printOneEmployee(list, index);

    if(index == FALSE)
    {
        printf("No se encuentra ese Id.\n");

    }

    else
    {
        answer= getChar("\nEsta seguro que desea dar de baja?(s/n): ");
        if(answer == 's')
        {
            list[index].isEmpty = TRUE;
            numberReturn = 0;
        }
    }
    return numberReturn;

}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

void sortEmployeesByLastName(Employee* list, int len)
{
    int i;
    int j;

    Employee index;

    for( i =0 ; i<len -1 ; i ++)
    {
        for(j= i+1 ; j<len; j++)
        {
            if(list[i].isEmpty== 0)
            {
                if(strcmp(list[i].lastName,list[j].lastName)>0)
                {
                    index = list[i];
                    list[i] = list[j];
                    list[j] = index;
                }
            }
        }
    }
    printEmployees(list,len);
}
/** \brief Sort the elements by sector
 *
 * \param list Employee*
 * \param len int
 * \return void
 *
 */

void sortEmployeesBySector(Employee* list, int len)
{
    int i;
    int j;

    Employee index;

    for( i =0 ; i<len -1 ; i ++)
    {
        for(j= i+1 ; j<len; j++)
        {
            if(list[i].isEmpty== 0)
            {

                if(list[i].sector > list[j].sector)
                {
                    index = list[i];
                    list[i] = list[j];
                    list[j] = index;
                }
            }
        }
    }

    printEmployees(list,len);
}

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */

int printEmployees(Employee* list, int len)
{
    int i;
    int numberReturn= -1;

    if(list !=NULL)
    {

        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty!= TRUE)
            {

                printOneEmployee(list, i);
                numberReturn= 0;

            }

        }

    }

    return numberReturn;
}

/** \brief  find free space
 *
 * \param list Employee*
 * \param length int
 * \return (-1) no free space, (i) position of free space
 *
 */
int findFree(Employee* list, int len)
{

    int i;
    int numberReturn= -1;

    if(list!=NULL)
    {
        for(i=0; i<len ; i++)
        {
            if(list[i].isEmpty==TRUE)
            {
                numberReturn=i;
                break;
            }
        }
    }

    return numberReturn;
}

/** \brief  print only one employee
 *
 * \param list Employee*
 * \param index position of employee
 * \return void
 *
 */
void printOneEmployee(Employee *list, int index)
{

    if(list!=NULL)
    {
        if(list[index].isEmpty == 0)
        {
            printf("id: %d---- name: %s---- Last name: %s ----  Salary: %f  ---- Sector: %d \n",list[index].id, list[index].name, list[index].lastName, list[index].salary, list[index].sector);
        }

    }
}

/** \brief  print salary and promedy
 *
 * \param list Employee*
 * \param length int
 * \return void
 *
 */
void salaryAndPromedy(Employee *list, int len)
{
    int i;
    float sumSalary= 0;
    int indexSalary=0;
    float totalPromedy;
    int indexMaxSalary=0;

    for(i= 0; i<len; i++)
    {
        if(list[i].isEmpty== 0)
        {

            sumSalary= sumSalary + list[i].salary;
            indexSalary++;

        }
    }

    totalPromedy=  sumSalary/ indexSalary;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {

            if(list[i].salary > totalPromedy)
            {
                indexMaxSalary++;
            }
        }
    }

    printf("\n Total del salario : %.4f\n Promedio: %.4f\n Personas con salario mayor al promedio: %d\n", sumSalary, totalPromedy, indexMaxSalary);
}

/** \brief modify information about an employee
 *
 * \param listEmployees[] sEmployee array of employee
 * \param length int
 * \param id
 * \return int (-1) if error, (0) if ok
 *
 */
int modifyEmployee(Employee *list, int len, int id)
{
    int i;
    int auxId;
    int auxOpcion= 0;
    int numberReturn= -1;
    char auxName[50];
    char auxLastName[50];
    int auxSalary;
    int auxSector;

    auxId = getInt("\ningrese el id del empleado que desea modificar: \n");

    auxOpcion= getInt(" 1. Modificar nombre\n 2. Modificar apellido\n 3. Modificar salario\n 4. modificar sector\n");

    for(i= 0; i<len; i++)
    {
        if(list[i].isEmpty== 0 && list[i].id== auxId)
        {
            if(auxOpcion == 1)
            {
                getString("\ningrese nuevo nombre: \n",auxName);
                strcpy(list[i].name, auxName);
                numberReturn= 0;
            }

            else if(auxOpcion== 2)

            {
                getString("\ningrese nuevo apellido: \n", auxLastName);
                strcpy(list[i].lastName, auxLastName);
                numberReturn= 0;
            }

            else if(auxOpcion== 3)
            {
                auxSalary= getFloat("\ningrese el nuevo salario: \n");
                list[i].salary= auxSalary;
                numberReturn= 0;
            }

            else if(auxOpcion== 4)
            {
                auxSector= getInt("\ningrese el nuevo sector: \n");
                list[i].sector= auxSector;
                numberReturn= 0;
            }

            else
            {
                printf("\nopcion ingresada incorrecta\n");
            }

        }

    }

    return numberReturn;
}




