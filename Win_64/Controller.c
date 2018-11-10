#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "bibliotecaUtn.h"
#include <string.h>
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) si algo salio mal, (0) si todo salio bien
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno= -1;
    FILE* pArchivo;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        pArchivo= fopen(path, "r");

        if(pArchivo !=NULL)
        {
            parser_EmployeeFromText(pArchivo, pArrayListEmployee);
            retorno= 0;
        }
        else
        {
            printf("\nNo fue posible abrir el archivo\n");
        }
    }
    else
    {
        printf("\nNo fue posbile abrir el archivo\n");
        exit(EXIT_SUCCESS);
    }

    fclose(pArchivo);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) si algo salio mal, (0) si todo salio bien
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno= -1;
    FILE* pArchivo;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        pArchivo= fopen(path, "rb");

        if(pArchivo !=NULL)
        {
            parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
            retorno= 0;
        }
        else
        {
            printf("\nNo fue posible abrir el archivo\n");
        }
    }
    else
    {
        printf("\nNo fue posbile abrir el archivo\n");
        exit(EXIT_SUCCESS);
    }

    fclose(pArchivo);
    return retorno;

    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) si algo salio mal, (0) si todo salio bien
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    Employee* agregarEmpleado;
    int auxIdInt;
    char auxIdStr[128];
    char auxNombre[128];
    char auxHorasTrabajadas[128];
    char auxSueldo[128];

    auxIdInt= controller_personalId(pArrayListEmployee);
    itoa(auxIdInt,auxIdStr, 10);

    getStringLetras("Ingrese nombre: \n", auxNombre);

    getStringNumeros("Ingrese horas trabajadas: \n", auxHorasTrabajadas);

    getStringNumeros("Ingrese sueldo: \n", auxSueldo);

    agregarEmpleado= employee_newParametros(auxIdStr, auxNombre, auxHorasTrabajadas, auxSueldo);

    if(agregarEmpleado !=NULL)
    {
        ll_add(pArrayListEmployee, agregarEmpleado);
        retorno= 0;
    }

    return retorno;


    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) si algo salio mal, (0) si todo salio bien
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* employeeEdit;
    int flag= 0;
    int retorno= 1;
    int i;
    int tam;
    int opcion = 0;
    char auxNombre[128];
    int auxId;
    int auxHorasTrabajadas;
    int auxSueldo;

    tam= ll_len(pArrayListEmployee);

        auxId= getIntOnly("\nIngrese id del empleado que desea modificar\n");
        for(i=0; i<tam; i++)
        {
            employeeEdit= ll_get(pArrayListEmployee, i);
            if(auxId== employeeEdit->id)
            {
                printf("\n%d---%s---%d---%d\n", employeeEdit->id, employeeEdit->nombre, employeeEdit->horasTrabajadas, employeeEdit->sueldo);

                flag= 1;
                printf("\n1. Modificar nombre\n2. Modificar horas trabajadas\n3. Modificar sueldo\n");
                opcion=getIntOnly("\nIngrese opcion que desee utilizar\n");

                if(opcion== 1)
                {
                    getStringLetras("\nIngrese el nuevo nombre\n", auxNombre);
                    strcpy(employeeEdit->nombre, auxNombre);
                    retorno=0;
                }

                else if(opcion==2)
                {
                    auxHorasTrabajadas=getIntOnly("\nIngrese nueva cantidad de horas trabajadas\n");
                    employeeEdit->horasTrabajadas= auxHorasTrabajadas;
                    retorno=0;
                }

                else if(opcion==3)
                {
                    auxSueldo=getIntOnly("\nIngrese nuevo sueldo\n");
                    employeeEdit->sueldo= auxSueldo;
                    retorno=0;
                }
            }
        }

        if(flag==0)
        {
            printf("\nNo se ha encontrado el id\n");
        }



    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) si algo salio mal, (0) si todo salio bien
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* employeeRemove;
    int auxId;
    char pregunta= 's';
    int i;
    int retorno= -1;
    int tam= ll_len(pArrayListEmployee);

    auxId=getIntOnly("\nIngrese id del usuario que desee eliminar\n");

    for(i=0; i< tam; i++)
    {
        employeeRemove= (Employee*)ll_get(pArrayListEmployee, i);

        if(employeeRemove->id== auxId)
        {
            printf("\n%d---%s---%d---%d\n", employeeRemove->id, employeeRemove->nombre, employeeRemove->horasTrabajadas, employeeRemove->sueldo);

            pregunta=getChar("\nSeguro que desea dar de baja este empleado?(s/n)\n");
            if(pregunta== 's')
            {
                ll_remove(pArrayListEmployee, i);
                retorno= 0;
                break;
            }
            else
            {
                printf("\nNo se ha dado de baja\n");
            }

        }

    }

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) si algo salio mal, (0) si todo salio bien
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int tam;
    char auxNombre[128];
    Employee* empleados;

    tam= ll_len(pArrayListEmployee);



        for(i=0; i< tam; i++)
        {
            empleados = (Employee*)(ll_get(pArrayListEmployee, i));
            employee_getId(empleados);
            employee_getNombre(empleados,auxNombre);
            employee_getHorasTrabajadas(empleados);
            employee_getSueldo(empleados);
            printf("\n%d--- %s--- %d--- %d\n", empleados->id, empleados->nombre, empleados->horasTrabajadas, empleados->sueldo);
            retorno=0;
        }


    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) si algo salio mal, (0) si todo salio bien
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno= -1;
    int opcion= 0;

    if(pArrayListEmployee!= NULL)
    {

        opcion=getIntOnly("\n1. Ordenar ascendente\n2. Ordenar descendente\n");

        if(opcion== 1)
        {
            ll_sort(pArrayListEmployee, controller_sortName, 1);
            retorno = 0;
        }
        else if(opcion== 2)
        {
            ll_sort(pArrayListEmployee, controller_sortName, 0);
            retorno= 0;
        }
        else
        {
            printf("\nOpcion ingresada incorrecta, no se pudo ordenar\n");
        }
    }

    return retorno;

}

/** \brief obtiene los nombres a ordenar por medio de getters
 *
 * \param nombreUno void*
 * \param nombreDos void*
 * \return int(-2) si algo salio mal, (1) si todo salio bien (-1) si todo salio bien
 *
 */
int controller_sortName(void* nombreUno, void* nombreDos)
{
    int retorno= -2;
    char auxNombreUno[128];
    char auxNombreDos[128];

    employee_getNombreLowerCase(nombreUno, auxNombreUno);
    employee_getNombreLowerCase(nombreDos, auxNombreDos);

    if(strcmp(auxNombreUno, auxNombreDos) > 0)
    {
        retorno= 1;
    }
    else if(strcmp(auxNombreUno, auxNombreDos)< 0)
    {
        retorno= -1;
    }
    else
    {
        retorno=0;
    }

    return retorno;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) si algo salio mal, (0) si todo salio bien
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int i;
    int tam;
    int retorno= -1;
    FILE* pArchivo;
    tam= ll_len(pArrayListEmployee);


    pArchivo= fopen(path, "w");

    if(pArchivo != NULL && pArrayListEmployee != NULL)
    {
        for(i=0; i< tam; i++)
        {
            Employee* empleados = ll_get(pArrayListEmployee, i);
            fprintf(pArchivo, "%d,%s,%d,%d\n", empleados->id, empleados->nombre, empleados->horasTrabajadas, empleados->sueldo);
            retorno=0;
        }
    }

    fclose(pArchivo);

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (-1) si algo salio mal, (0) si todo salio bien
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int i;
    int tam;
    int retorno= -1;
    Employee* empleados;
    FILE* pArchivo;
    tam= ll_len(pArrayListEmployee);

    pArchivo= fopen(path, "wb");

    if(pArchivo != NULL && pArrayListEmployee != NULL)
    {
        retorno=0;

        for(i=0; i< tam; i++)
        {
            empleados =(Employee*)ll_get(pArrayListEmployee, i);
            fwrite(empleados, sizeof(Employee), 1, pArchivo);
        }
    }

    fclose(pArchivo);

    return retorno;

}

/** \brief obtiene un id unico para cada empleado leyendo desde el ultimo que se ingreso
 *
 * \param pArrayListEmployee LinkedList*
 * \return int valor del id + 1
 *
 */
int controller_personalId(LinkedList* pArrayListEmployee)
{
    int i;
    int tam;
    Employee* EmployeeId;
    int retornoId=0;

    tam= ll_len(pArrayListEmployee);

    for(i=0; i< tam; i++)
    {
        EmployeeId= (Employee*)ll_get(pArrayListEmployee, i);
        if(EmployeeId->id >retornoId)
        {
            retornoId= EmployeeId->id;
        }
    }

    return retornoId + 1;
}


