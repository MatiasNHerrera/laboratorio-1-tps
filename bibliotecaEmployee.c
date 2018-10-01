#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaUtn.h"
#include "bibliotecaEmployee.h"
#define TRUE 1
#define FALSE 1
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
        }
        numberReturn= 0;
    }

    return numberReturn;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    Employee myEmployee;
    int index;
    int numberReturn= -1;

    index= findFree(list, len);

    if(list !=NULL)
    {
        if(index != FALSE)
        {

            strcpy(myEmployee.name, name);
            strcpy(myEmployee.lastName, lastName);
            myEmployee.salary=salary;
            myEmployee.sector=sector;
            myEmployee.isEmpty = 0;
            myEmployee.id= PersonalId();
            list[index]= myEmployee;

            numberReturn=0;

        }
        else

        {
            printf("\nNo free space!\n");
        }
    }
    return numberReturn;
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
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */

int removeEmployee(Employee* list, int len, int id)
{
    int i;
    int indexId;
    indexId= findEmployeeById(list, len,id);
    int numberReturn= -1;

    if(list != NULL)
    {
        id= getInt("ingrese id que desea eliminar: ");

        for(i=0; i<len; i++)
        {
            if(list[indexId].id == id)
            {

            }
        }
    }

    return -1;
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

int sortEmployees(Employee* list, int len)
{
    int i;
    int j;
    Employee indexSort;

    for( i =0 ; i<len -1 ; i ++)
    {
        for(j= i+1 ; j<len; j++)
        {
            if(strcmp(list[i].lastName,list[j].lastName)>0)
            {
                indexSort = list[i];
                list[i] = list[j];
                list[j] = indexSort;
            }
            else if(strcmp(list[i].lastName,list[j].lastName)==0 && list[j].sector>list[i].sector)
            {
                indexSort = list[i];
                list[i] = list[j];
                list[j] = indexSort;
            }
        }
    }

    printEmployees(list,len);

    return 0;
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
            if(list[i].isEmpty == 0)
            {
                printOneEmployee(list, i);
                numberReturn= 0;
            }
        }

    }

    return numberReturn;
}

int findFree(Employee* list, int len)
{

    int i;
    int numberReturn;

    if(list!=NULL)
    {
        for(i=0; i<len ; i ++)
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

int printOneEmployee(Employee *list, int index)
{
    int numberReturn= -1;

    if(list!=NULL)
    {
        if(list[index].isEmpty == 0)
        {
            printf("id: %d---- name: %s---- Last name: %s ----  Salary: %f  ---- Sector: %d \n",list[index].id, list[index].name, list[index].lastName, list[index].salary, list[index].sector);
            numberReturn= 0;
        }

    }
    return numberReturn;
}





