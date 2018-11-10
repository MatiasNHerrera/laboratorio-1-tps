#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "bibliotecaUtn.h"
#include "LinkedList.h"
#include "Employee.h"
#include "string.h"


/** \brief crea espacio de forma dinamica para un empleado
 *
 * \param void
 * \return Employee*
 *
 */
Employee* employee_new()
{
    Employee* myEmployee;

    myEmployee= (Employee*)malloc(sizeof(Employee));

    return myEmployee;
}

/** \brief crea un nuevo empleado usando setters de datos
 *
 * \param char*
 * \param char*
 * \param char*
 * \param char*
 * \return Employee* si todo salio bien, NULL si hubo error
 *
 */

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo)
{
    Employee* myEmployee;
    myEmployee= employee_new();

    if(myEmployee != NULL)
    {
        employee_setId(myEmployee, atoi(idStr));
        employee_setNombre(myEmployee, nombreStr);
        employee_setHorasTrabajadas(myEmployee, atoi(horasTrabajadasStr));
        employee_setSueldo(myEmployee, atoi(sueldo));

        return myEmployee;
    }

    return NULL;
}

/** \brief realiza un set del id del empleado
 *
 * \param employee*
 * \param int
 * \return 0 si algo salio mal, 1 si todo salio bien
 *
 */

int employee_setId(Employee* this,int id)
{
    int estado= 0;
    if(this !=NULL)
    {
        this->id= id;
        estado= 1;
    }

    return estado;
}

/** \brief realiza un get del id del empleado
 *
 * \param Employee*
 * \return valor del id
 *
 */

int employee_getId(Employee* this)
{
    int id=0;

    if(this != NULL)
    {
        id= this->id;
    }

    return id;
}

/** \brief realiza un set del nombre del empleado
 *
 * \param employee*
 * \param char*
 * \return 0 si algo salio mal, 1 si todo salio bien
 *
 */
int employee_setNombre(Employee* this, char* nombre)
{

    int estado= 0;
    if(this !=NULL)
    {
        strcpy(this->nombre, nombre);
        estado= 1;
    }

    return estado;
}

/** \brief realiza un get del nombre del empleado
 *
 * \param Employee*
 * \return nombre
 *
 */
char* employee_getNombre(Employee* this, char* nombre)
{

    if(this != NULL)
    {
        strcpy(nombre, this->nombre);
    }

    return nombre;
}

/** \brief realiza un set de las horas trajadas del empleado
 *
 * \param employee*
 * \param int
 * \return 0 si algo salio mal, 1 si todo salio bien
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int estado= 0;
    if(this !=NULL)
    {
        this->horasTrabajadas= horasTrabajadas;
        estado= 1;
    }

    return estado;
}

/** \brief realiza un get de las horas trabajadas del empleado
 *
 * \param Employee*
 * \return valor de las horas trabajadas
 *
 */
int employee_getHorasTrabajadas(Employee* this)
{
    int horasTrabajadas=0;

    if(this != NULL)
    {
        horasTrabajadas= this->horasTrabajadas;
    }

    return horasTrabajadas;
}

/** \brief realiza un set del sueldo del empleado
 *
 * \param employee*
 * \param int
 * \return 0 si algo salio mal, 1 si todo salio bien
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int estado= 0;
    if(this !=NULL)
    {
        this->sueldo= sueldo;
        estado= 1;
    }

    return estado;
}

/** \brief realiza un get del sueldo del empleado
 *
 * \param Employee*
 * \return valor del sueldo
 *
 */
int employee_getSueldo(Employee* this)
{
    int sueldo=0;

    if(this != NULL)
    {
        sueldo= this->horasTrabajadas;
    }

    return sueldo;
}

char* employee_getNombreLowerCase(Employee* this, char* nombre)
{
    int i;

    if(this != NULL)
    {
        strcpy(nombre, this->nombre);
        for(i=0;i<strlen(nombre); i++)
        {
            nombre[i]= tolower(nombre[i]);
        }
    }

    return nombre;
}



