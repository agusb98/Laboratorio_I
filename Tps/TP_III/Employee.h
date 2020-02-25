#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#endif // employee_H_INCLUDED

typedef struct
{
    int id;
    char name[128];
    int hoursWorked;
    int salary;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nameStr,char* hoursWorkedStr, char* salaryStr);

void employee_delete();
void employee_show(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setName(Employee* this,char* name);
int employee_getName(Employee* this,char* name);

int employee_setHoursWorked(Employee* this,int hoursWorked);
int employee_getHoursWorked(Employee* this,int* hoursWorked);

int employee_setSalary(Employee* this,float salary);
int employee_getSalary(Employee* this,float* salary);

int employee_findById(LinkedList* pArrayListEmployee, char* idStr);
int employee_findEmptyId(LinkedList* pArrayListEmployee);

int employee_SortByName(void* employeeA, void* employeeB);
int employee_SortById(void* employeeA, void* employeeB);
int employee_SortBySalary(void* employeeA, void* employeeB);
int employee_SortByHoursWorked(void* employeeA, void* employeeB);
