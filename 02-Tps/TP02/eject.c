#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "utn.h"
#include "eject.h"


/** \brief add in a existing list of employees the values valided
 * \param list eEmployee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (1) if Ok - (0) Operation Canceled
 */

int eject_addEmployee(eEmployee* list, int list_len, eSector* sector, int sector_len)
{
    int flag= -1;
    if (list != NULL && list_len > 0)
    {
        char name[51];
        char lastName[51];
        float salary;
        int id_sector;
        int id;

        system("cls");
        printf(">> Nuevo\n");

        if (list != NULL && list_len > 0)
        {
            id = findNextId(list, list_len); //me genera automaticamente un id

            if (id == -1) //Caso en que llega a la maxima cantidad de empleados
                printf("\nNo hay mas Bacantes\n");

            else
            {
                int flag = getValidString("\nNombre: ","\nNo es un Nombre valido","\nExceso de Caracteres\n", name,51,3);
                if(!flag)
                {
                    flag = getValidString("\nApellido: ","\nNo es un Apellido valido\n","\nExceso de Caracteres\n", lastName,51,3);
                    if(!flag)
                    {
                        flag = getValidFloat("\nSalario: ","\nNo es un salario valido\n", &salary,0,99999999,3);
                        if(!flag)
                        {
                            printSectores(sector, sector_len);
                            flag = getValidInt("\nSector: ","\nNo es un Sector valido\n", &id_sector,0,10000,3);
                            if(!flag && confirmation())
                            {
                                if (addEmployee(list, list_len, id, name, lastName, salary, id_sector))
                                {
                                    printf("\nEmpleado Agregado\n\n");
                                    flag= 1;
                                }
                            }
                            else
                            {
                                printf("\nOperacion Cancelada\n\n");
                                flag= 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return flag;
}

/** \brief search Id and wait for confirmation
 *
 * \param list eEmployee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (1) if Ok - (0) operation cancelated
 *
 */

int eject_deleteEmployee(eEmployee* list, int list_len, eSector* sector, int sector_len)
{
    int flag= -1;
    if (list != NULL && list_len > 0)
    {
        printf(">> Borrar ");
        int id;
        id = getIdInList(list, list_len, sector, sector_len);
        if (id != -1)
        {
            if (confirmation() && removeEmployee(list, list_len, id))
            {
                printf("\nEmpleado Eliminado\n\n");
                flag= 1;
            }
        }
        else
        {
            printf("Operacion Cancelada\n\n");
            flag= 0;
        }
    }
    return flag;
}

/** \brief print all option able to choose
 *
 * \param  void
 * \return int option choosed
 */

int principalMain()
{
    system("cls");

    printf(">> Menu de Opciones\n");
    printf("\n1_ ALTA");
    printf("\n2_ MODIFICAR");
    printf("\n3_ BAJA");
    printf("\n4_ INFORMES");
    printf("\n5_ Salir");

    fflush(stdin);
    int opt = getInt("\n\nIngrese opcion: ");
    return opt;
}

/** \brief print all option of Modification able to choose
 *
 * \param  void
 * \return int option choosed
 */

int editMain()
{
    printf(">> Menu de Modificaciones\n");
    printf("\n1_ Nombre");
    printf("\n2_ Apellido");
    printf("\n3_ Salario");
    printf("\n4_ Sector");
    printf("\n5_ Salir");

    fflush(stdin);
    int opt = getInt("\n\nIngrese opcion: ");
    return opt;
}

/** \brief modificate a detaille of an employee
 * \param list eEmployee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (1) if Ok - (0) if declaine operation
 */

int eject_editEmployee(eEmployee* list, int list_len, eSector* sector, int sector_len)
{
    int flag = -1, id;

    if (list != NULL && list_len > 0)
    {
        system("cls");
        printf(">> Modificar ");
        id = getIdInList(list, list_len, sector, sector_len);
        if (id != -1 && editEmployee(list, list_len, id, sector, sector_len))
        {
            printf("\nEmpleado Modificado\n\n");
            flag = 1;
        }
        else
        {
            printf("Operacion Cancelada\n\n");
            flag = 0;
        }
    }
    return flag;
}

/** \brief print reports about salaryies
 *
 * \param list eEmployee*
 * \param len int
 * \param opt
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (1) if Ok
 */

int eject_reportEmployees(eEmployee* list, int len, eSector* sector, int sector_len)
{
    int opt, flag= -1;
    system("cls");

    if (list != NULL && len > 0)
    {
        printf(">>Informes\n\n");
        printf("\t1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n");
        printf("\t2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n");
        getValidInt("\n\tOpcion: ", "Fuera de Rango\n", &opt, 1, 3, 3);

        printf("\n");
        int order=1;
        int cont = contActiveEmployees(list, len);
        float acum = acumSalaryies(list, len);
        float prom = (float) acum/cont;

        switch (opt)
        {
        case 1:
            getValidInt("\n(1)Ascendente - (0)Descendente : ", "\nFuera de Rango", &order, 0, 1, 3);
            printf("\n");
            sortEmployees(list, len, order);
            printEmployees(list, len, sector, sector_len);
            break;
        case 2:
            printf("\nTotal: $%.1f\n", acum);
            printf("Promedio: $%.1f\n", prom);

            cont = contSalaryiesUpProm(list, len, prom);
            printf("Empleados con salario mayor al promedio: %d\n\n", cont);
            break;
        default:
            break;
        }
        flag= 1;
    }
    return flag;
}

/** \brief sum all salaryies of active employees
 * \param eEmployee* list
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (sum) if Ok
 */

float acumSalaryies(eEmployee* list, int len)
{
    float acum=0;
    int flag= -1;

    if (list != NULL && len >0)
    {
        for (int i=0; i<len; i++)
        {
            if (!(list+i)->isEmpty)
                acum += (list+i)->salary;
        }
        flag = acum;
    }
    return flag;
}

/** \brief cont all active employees
 * \param eEmployee* list
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (cont) if Ok
 */

float contActiveEmployees(eEmployee* list, int len)
{
    int cont=0;
    int flag= -1;

    if (list != NULL && len >0)
    {
        for (int i=0; i<len; i++)
        {
            if (!(list+i)->isEmpty)
                cont ++;
        }
        flag= cont;
    }
    return flag;
}

/** \brief sum all salaryies of active employees
 * \param eEmployee* list
 * \param len int
 * \param prom float
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (sum) if Ok
 */

int contSalaryiesUpProm(eEmployee* list, int len, float prom)
{
    int cont=0;
    int flag= -1;

    if (list != NULL && len >0)
    {
        for (int i=0; i<len; i++)
        {
            if (!(list+i)->isEmpty && (list+i)->salary > prom)
                cont ++;
        }
        flag = cont;
    }
    return flag;
}
