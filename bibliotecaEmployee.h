#ifndef BIBLIOTECAEMPLOYEE_H_INCLUDED
#define BIBLIOTECAEMPLOYEE_H_INCLUDED

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;


}Employee;

int initEmployees(Employee* list, int len);
int addEmployee(Employee*list, int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee* list, int len ,int id);
int removeEmployee(Employee *list, int len, int id);
int sortEmployees(Employee *list, int len);
int printEmployees(Employee *list, int len);
int findFree(Employee *list, int len);
int printOneEmployee(Employee *list, int index);


#endif
