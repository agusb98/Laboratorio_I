#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

Employee* employee_new()
{
    Employee* this = malloc(sizeof(Employee)); //Creo un nuevo empleado con memodia dinamica "malloc"
    if(this == NULL) //Verifico que no sea NULL
    {
        printf("No hay lugar para crear nuevo empleado.\n");
        exit(EXIT_FAILURE); //De ser NULL salgo
    }
    else //De lo contrario parseo a 0 y cadena vacia las variables
    {
        this->id = 0;
        strcpy(this->name, "");
        this->hoursWorked = 0;
        this->salary = 0;
    }
    return this; //Retorno el puntero a la estructura creada
}

Employee* employee_newParametros(char* idStr,char* nameStr,char* hoursWorkedStr, char* salaryStr)
{
    int flag = 0;
    Employee* this = employee_new();

    if(employee_setHoursWorked(this,atoi(hoursWorkedStr)))
        flag=1;

    if(employee_setId(this,atoi(idStr)) && flag)
        flag=1;

    if(employee_setName(this,nameStr) && flag)
        flag=1;

    if(employee_setSalary(this, atof(salaryStr)) && flag)
        flag=1;

    if(!flag)
    {
        printf("\nError al cargar datos, revise la lista.\n");
        free(this);
    }

    return this;
}

int employee_setId(Employee* this,int id)
{
    int flag = 0;
    if(this != NULL && id > 0)
    {
        this->id = id;
        flag=1;
    }
    return flag;
}

int employee_getId(Employee* this,int* id)
{
    int flag = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        flag=1;
    }
    return flag;
}

int employee_setName(Employee* this,char* name)
{
    int flag=0;
    if(this != NULL && strlen(name) > 0 && name != NULL)
    {
        strcpy(this->name, name);
        flag=1;
    }
    return flag;
}

int employee_getName(Employee* this,char* name)
{
    int flag = 0;
    if(this != NULL && name != NULL)
    {
        strcpy(name, this->name);
        flag = 1;
    }
    return flag;
}

int employee_setHoursWorked(Employee* this,int hoursWorked)
{
    int flag=0;
    if(this != NULL && hoursWorked > 0)
    {
        this->hoursWorked = hoursWorked;
        flag=1;
    }
    return flag;
}

int employee_getHoursWorked(Employee* this,int* hoursWorked)
{
    int flag = 0;
    if(this != NULL && hoursWorked != NULL)
    {
        *hoursWorked = this->hoursWorked;
        flag=1;
    }
    return flag;
}

int employee_setSalary(Employee* this,float salary)
{
    int flag=0;
    if(this != NULL && salary > 0)
    {
        this->salary = salary;
        flag=1;
    }
    return flag;
}

int employee_getSalary(Employee* this,float* salary)
{
    int flag=0;
    if(this != NULL && salary != NULL)
    {
        *salary = this->salary;
        flag=1;
    }
    return flag;
}

void employee_show(Employee* this)
{
    if (this != NULL)
        printf("   %5d | %12s |          %4d  |    $ %d\n", this->id, this->name, this->hoursWorked, this->salary);
}

int employee_findById(LinkedList* pArrayListEmployee, char* idStr)
{
    Employee* this; //Puntero a estructura
    int flag = -1;
    int id = atoi(idStr); //Variable ID casteada a entero

    if(pArrayListEmployee != NULL)
    {
        for(int i=0; i<ll_len(pArrayListEmployee); i++) //Recorro el array en busca del ID ingresado
        {
            this = (Employee*)ll_get(pArrayListEmployee, i);     //Le asigno a this la estructura que retorna ll_get()
            if(this->id == id)   //Si se encuentra el id ingresado se cambia la bandera y se rompe l iteraccion
            {
                flag = i;
                break;
            }
        }
    }
    return flag;
}

/** \brief sort employees in list by their id
 *
 * \param void* employeeA
 * \param void* employeeB
 * \return int (1) if OK - (0) If NULL pointer
 *
 */

int employee_SortById(void* employeeA, void* employeeB)
{
    int flag = 0;
    Employee* empA; //Puntero a la estructura empA
    Employee* empB; //Puntero a la estructura empB

    if(employeeA != NULL && employeeB != NULL)
    {
        empA = (Employee*) employeeA; //Casteo la estructura employeeA puntero
        empB = (Employee*) employeeB; //Casteo la estructura employeeA puntero

        if((empA->id) < (empB->id)) //Si id de A en menor que id de B cambio al bandera flag a 1
            flag = 1 ;

        else if((empA->id) == (empB->id)) //Si id de A igual que id de B dejo la bandera igual
            flag = 0;

        else
            flag = -1;
    }
    return flag;
}

/** \brief sort employees in list by their name
 *
 * \param void* employeeA
 * \param void* employeeB
 * \return int (1) if OK - (0) If NULL pointer
 *
 */

int employee_SortByName(void* employeeA, void* employeeB)
{
    int flag = 0;
    Employee* empA; //Puntero a la estructura empA
    Employee* empB; //Puntero a la estructura empB

    if(employeeA != NULL && employeeB != NULL)
    {
        empA = (Employee*) employeeA; //Casteo la estructura employeeA puntero
        empB = (Employee*) employeeB; //Casteo la estructura employeeA puntero
        flag = strcmp(empA->name, empB->name);
    }
    return flag;
}

/** \brief sort employees in list by their hours in work
 *
 * \param void* employeeA
 * \param void* employeeB
 * \return int (1) if OK - (0) If NULL pointer
 *
 */

int employee_SortByHoursWorked(void* employeeA, void* employeeB)
{
    int flag = 0;
    Employee* empA; //Puntero a la estructura empA
    Employee* empB; //Puntero a la estructura empB

    if(employeeA != NULL && employeeB != NULL)
    {
        empA = (Employee*) employeeA; //Casteo la estructura employeeA puntero
        empB = (Employee*) employeeB; //Casteo la estructura employeeA puntero

        if((empA->hoursWorked) < (empB->hoursWorked)) //Si hoursWorked de A en menor que hoursWorked de B cambio al bandera flag a 1
            flag = 1 ;

        else if((empA->hoursWorked) == (empB->hoursWorked)) //Si hoursWorked de A igual que hoursWorked de B dejo la bandera igual
            flag = 0;

        else
            flag = -1;
    }
    return flag;
}

/** \brief sort employees in list by their salary
 *
 * \param void* employeeA
 * \param void* employeeB
 * \return int (1) if OK - (0) If NULL pointer
 *
 */

int employee_SortBySalary(void* employeeA, void* employeeB)
{
    int flag = 0;
    Employee* empA; //Puntero a la estructura empA
    Employee* empB; //Puntero a la estructura empB

    if(employeeA != NULL && employeeB != NULL)
    {
        empA = (Employee*) employeeA; //Casteo la estructura employeeA puntero
        empB = (Employee*) employeeB; //Casteo la estructura employeeA puntero

        if((empA->salary) < (empB->salary)) //Si salary de A en menor que salary de B cambio al bandera flag a 1
            flag = 1;

        else if((empA->salary) == (empB->salary)) //Si salary de A igual que salary de B dejo la bandera igual
            flag = 0;

        else
            flag = -1;
    }
    return flag;
}
