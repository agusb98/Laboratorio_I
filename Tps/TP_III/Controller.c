#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#include "conio.h"

/** \brief Menu de opciones
 *
 * \return int La opcion elegida por el usuario
 *
 */
int controller_principalMain()
{
    system("cls");

    printf(">> Menu de Opciones\n");
    printf("\n1_ Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
    printf("\n2_ Cargar los datos de los empleados desde el archivo data.bin (modo binario).");
    printf("\n3_ Alta de empleado");
    printf("\n4_ Modificar datos de empleado");
    printf("\n5_ Baja de empleado");
    printf("\n6_ Listar empleados");
    printf("\n7_ Ordenar empleados");
    printf("\n8_ Guardar los datos de los empleados en el archivo data.csv (modo texto).");
    printf("\n9_ Guardar los datos de los empleados en el archivo data.bin (modo binario).");
    printf("\n10_ Salir");

    fflush(stdin);
    return getInt("\n\nIngrese opcion: ");
}

/** \brief Menu de opciones de Ordenamientos
 *
 * \return int La opcion elegida por el usuario
 *
 */
int controller_sortMain()
{
    system("cls");

    printf(">> Menu de Ordenamientos\n");
    printf("\n1_ Nombre");
    printf("\n2_ Id");
    printf("\n3_ Salario");
    printf("\n4_ Horas Trabajadas");
    printf("\n5_ Salir");

    fflush(stdin);
    return getInt("\n\nIngrese opcion: ");
}

/** \brief Menu de opciones de Modificaciones
 *
 * \return int La opcion elegida por el usuario
 *
 */
int controller_editMain()
{
    system("cls");

    printf(">> Menu de Modificaciones\n");
    printf("\n1_ Nombre");
    printf("\n2_ Id");
    printf("\n3_ Salario");
    printf("\n4_ Horas Trabajadas");
    printf("\n5_ Salir");

    fflush(stdin);
    return getInt("\n\nIngrese opcion: ");
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna la funcion (1 - TodoOK // 0 - Error)
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo; //Variable puntero al archivo

    system("cls");
    printf(">> Cargar Modo Texto\n\n");
    if((pArchivo = fopen(path, "r")) != NULL)  //Verifico si la lectura del archivo, si no retorna NULL accedo al parse_Employee
    {
        if(parser_EmployeeFromText(pArchivo, pArrayListEmployee)) //Funcion parser empleados modo texto
            printf("\tEmpleados Cargados\n\n");
    }
    else  //Si retorna NULL no encontro el archivo, por lo tanto lo creo e informo que no se encontro y se creo uno nuevo
    {
        if((pArchivo = fopen(path, "w")) != NULL)
            printf("\tNo se encontro el archivo. Se creo uno nuevo con el nombre %s\n\n", path);
    }
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna la funcion (1 - TodoOK // 0 - Error)
 *
 */

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int flag = 0;
    FILE* pArchivo; //Variable puntero al archivo

    system("cls");
    printf(">> Cargar Modo Binario\n\n");

    if((pArchivo = fopen(path, "rb")) != NULL)
    {
        parser_EmployeeFromBinary(pArchivo, pArrayListEmployee); //Funcion parser empleados modo texto
        flag = 1;
    }
    else  //Si retorna NULL no encontro el archivo, por lo tanto lo creo e informo que no se encontro y se creo uno nuevo
    {
        if((pArchivo = fopen(path, "wb")) != NULL)
            printf("\tNo se encontro el archivo. Se creo uno nuevo con el nombre %s\n\n", path);
    }
    return flag;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    char auxId[128], auxName[128], auxHoursWorked[128], auxSalary[128]; //Variables buffer
    int flag = 0, status = 0;
    Employee* thisX = employee_new(); //Creo un nuevo empleado

    system("cls");
    printf(">> Alta Empleado\n\n");

    if (thisX != NULL && pArrayListEmployee != NULL)
    {
        //SOLICITO Y VALIDO LOS DATOS INGRESADOS AL NUEVO EMPLEADO

        status = getStringNumeros("ID: ", auxId);
        while(status != 1 || employee_findById(pArrayListEmployee, auxId) != -1)  //Valido que el id ingresado no se encuentre dado de alta en sistema, de estar dado de alta pide uno nuevo
        {
            printf("El ID ingresado ya se encuentra dado de alta en sistema. Reintente.\n\n");
            status = getStringNumeros("ID: ", auxId); //Solicito y valido el id (string)
        }

        if (getValidString("\nNombre: ", "Error de ingreso, reintente.", "Error de ingreso, reintente.", auxName, 128, 128))
        {
            if (getStringNumeros("\nHoras trabajadas: ", auxHoursWorked) == 1)
            {
                if(getStringNumerosFlotantes("\nSueldo: ", auxSalary))
                {
                    thisX = employee_newParametros(auxId, auxName, auxHoursWorked, auxSalary);  //Le asigno a "thisX" las variables casteadas en la funcion

                    if (thisX == NULL)
                        printf("\nError en Atenticacion de datos\n\n");

                    else if (confirmation() && !ll_add(pArrayListEmployee, thisX)) //Agrego "thisX" al final del array de empleados
                    {
                        printf("\nEmpleado Agregado.\n\n");
                        flag = 1;
                    }
                }
            }
        }
    }
    else
        printf("\tInsuficiente Espacio en Memoria");

    if (!flag)
        printf("\nOperacion Cancelada.\n\n");

    return flag;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int que retorna la funcion (1 - TodoOK // 0 - Error)
 *
 */

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    char auxName[128], auxId[128];
    int auxHoursWorked, status = 0, flag = 0;
    float auxSalary;
    Employee* thisX; //Creo un nuevo empleado

    if (pArrayListEmployee != NULL)
    {
        flag = 1;
        thisX = (Employee*)ll_get(pArrayListEmployee, controller_getIndexInEmployee(pArrayListEmployee)); //Le asigno a "thisX" lo que retorna "ll_get()"

        if (thisX != NULL)
        {
            switch(controller_editMain())
            {
            case 1: //Modifica Nombre
                if (getValidString("\nNombre: ", "Error de ingreso, reintente.", "Error de ingreso, reintente.", auxName, 128, 128))
                {
                    if ( confirmation() && employee_setName(thisX, auxName));
                    status = 1;
                }
                break;
            case 2: //Modifica ID
                if (getStringNumeros("ID: ", auxId) == 1)
                {
                    if (employee_findById(pArrayListEmployee, auxId) == -1) //Entra si no encuentra el Id
                    {
                        if(confirmation())
                        {
                            employee_setId(thisX, atoi(auxId));
                            status = 1;
                        }
                    }
                    else
                        printf("\nID ingresado ya se encuentra en uso.\n");
                }
                break;
            case 3: //Modifica Salario
                if (getValidFloat("\nSueldo: ", "Error de ingreso, reintente.\n", &auxSalary, 0, 999999, 3))
                {
                    if (confirmation() && employee_setSalary(thisX, auxSalary))
                        status = 1;
                }
                break;
            case 4: //Modifica Horas Trabajadas
                if (getValidInt("\nHoras Trabajadas: ", "Error de ingreso, reintente.\n", &auxHoursWorked, 0, 999999, 3))
                {
                    if (confirmation() && employee_setHoursWorked(thisX, auxHoursWorked))
                        status = 1;
                }
                break;
            }
        }
        else
            printf("\nEmpleado No Encontrado\n\n");
        if (status)
            printf("\nEmpleado Modificado con Exito\n\n");
        else
            printf("\nOperacion Cancelada\n\n");
    }
    return flag;
}


/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int 1
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* thisX; //Creo puntero a empleado

    system("cls");
    printf(">> Empleados\n\n");
    printf("      ID |      NOMBRE  | HS. TRABAJADAS |     SUELDO\n\n");

    for(int i=0; i<ll_len(pArrayListEmployee); i++) //Recorro el array de empleados
    {
        thisX = (Employee*)ll_get(pArrayListEmployee, i); //Le asigno a "thisX" lo que retorna "ll_get()"
        employee_show(thisX); //Imprimo los datos del empleado
    }
    printf("\n\n");
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int status = 0, flag = 0;
    if (pArrayListEmployee != NULL)
    {
        flag = 1;
        switch(controller_sortMain())
        {
        case 1:
            if ( !ll_sort(pArrayListEmployee, employee_SortByName, 1) )
                status = 1;
            break;
        case 2:
            if ( !ll_sort(pArrayListEmployee, employee_SortById, 0) )
                status = 1;
            break;
        case 3:
            if ( !ll_sort(pArrayListEmployee, employee_SortBySalary, 0) )
                status = 1;
            break;
        case 4:
            if ( !ll_sort(pArrayListEmployee, employee_SortByHoursWorked, 0) )
                status = 1;
            break;
        }

        if (status)
        {
            controller_ListEmployee(pArrayListEmployee);
            printf("\nEmpleados Ordenados con Exito\n\n");
        }
        else
            printf("\nOperacion Cancelada\n\n");

    }
    return flag;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int flag = 0, status = 0;
    Employee* thisX; //Creo un nuevo empleado

    if (pArrayListEmployee != NULL)
    {
        flag = 1;
        int index = controller_getIndexInEmployee(pArrayListEmployee);
        thisX = (Employee*)ll_get(pArrayListEmployee, index); //Le asigno a "thisX" lo que retorna "ll_get()"

        if (thisX != NULL)
        {
            if(confirmation() && !ll_remove(pArrayListEmployee, index))
                status = 1;
        }
        else
            printf("\nEmpleado No Encontrado\n");

        if (status)
            printf("\nEmpleado Eliminado Con Exito\n\n");
        else
            printf("\nOperacion Cancelada\n\n");
    }
    return flag;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* text = fopen(path, "w");
    int retorno = 0;
    if(text != NULL && pArrayListEmployee != NULL)
    {
        fprintf(text, "id,nombre,horasTrabajadas,sueldo\n");
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            Employee* thisX = (Employee*) ll_get(pArrayListEmployee, i);
            fprintf(text, "%d,%s,%d,%d\n", thisX->id, thisX->name, thisX->hoursWorked, thisX->salary);
        }
        retorno = 1;
        printf("\nDatos Guardados Con Exito.\n\n");
    }
    fclose(text);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo = fopen(path, "wb");; //Puntero al archivo, abro el archivo en modo escritura binaria
    Employee* thisX;
    int flag = 0, datosLeidos;

    if(pArchivo != NULL && pArrayListEmployee != NULL) //Verifico que la apertura del archivo y el array de empelados no sea NULL, si no lo es ingreso
    {
        rewind(pArchivo); //Voy al inicio del archivo
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            thisX = (Employee*)ll_get(pArrayListEmployee,i);
            datosLeidos = fwrite(thisX, sizeof(Employee), 1, pArchivo);
            flag = 1;
            if(datosLeidos != 1)
                printf("\nError al escribir los datos en el archivo.\n\n");
        }
        printf("\nDatos Guardados Con Exito\n\n");
    }

    else  //Si no pudo acceder al archivo lo informo
        printf("\nNo se pudo acceder al archivo.\n");

    fclose(pArchivo); //Cierro el archivo
    return flag;
}

int controller_freeLinkedList(LinkedList* pArrayListEmployee)
{
    int flag = -1;
    if(pArrayListEmployee != NULL)
    {
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
            ll_remove(pArrayListEmployee, i);

        ll_deleteLinkedList(pArrayListEmployee);
        flag = 0;
    }
    printf("\nSe elimino la lista de empleados.\n\n");
    return flag;
}

int controller_getIndexInEmployee(LinkedList* pArrayListEmployee)
{
    char id[128];
    int flag= -1;
    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        int valid = getStringNumeros("ID: ", id);
        int index = employee_findById(pArrayListEmployee, id);

        if (valid == 1 && index != -1)
            flag = index;
    }
    return flag;
}
