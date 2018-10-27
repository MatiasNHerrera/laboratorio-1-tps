#ifndef ARRAYEMPLOYEE_H_INCLUDED
#define ARRAYEMPLOYEE_H_INCLUDED
#define T 1000
#define TRUE 1
#define FALSE -1

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
int addEmployee(Employee *list,int);
int findEmployeeById(Employee* list, int len ,int id);
Employee enterEmployee(Employee list[]);
int removeEmployee(Employee *list, int len);
int sortEmployees(Employee *list, int len);
int printEmployees(Employee *list, int len);
int findFree(Employee *list, int len);
void printOneEmployee(Employee *list, int index);
void sortEmployeesByLastName(Employee* list, int len);
void sortEmployeesBySector(Employee* list, int len);
void salaryAndPromedy(Employee *list, int);
int modifyEmployee(Employee *list, int len, int id);

#endif
