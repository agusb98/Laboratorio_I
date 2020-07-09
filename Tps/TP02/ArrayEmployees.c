#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "eject.h"
#include "utn.h"

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list eEmployee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int initEmployees(eEmployee* list, int len)
{
    int flag = -1;
    if(list != NULL && len > 0)
    {
        for(int i=0; i<len; i++)
            (list+i)->isEmpty = 1; //Inicializa a todos los empleados con el estado vacio
        flag = 1;
    }
    return flag;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list eEmployee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (1) if Ok
 */

int addEmployee(eEmployee* list, int len, int id, char name[],char lastName[],float salary, int sector)
{
    int flag = -1;
    if(list != NULL && len > 0)
    {
        int index = findEmptyPlace(list, len);
        strcpy((list+index)->name, name);
        strcpy((list+index)->lastName, lastName);
        (list+index)->salary = salary;
        (list+index)->idSector = sector;
        (list+index)->id = id;
        (list+index)->isEmpty = 0;
        flag = 1;
    }
    return flag;
}

/** \brief find an eEmployee by Id en returns the index position in array.
 *
 * \param list eEmployee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */

int findEmployeeById(eEmployee* list, int len,int id)
{
    int flag = -1;
    if(list != NULL && len > 0)
    {
        for (int i=0; i<len; i++)
        {
            if ((list+i)->id == id && !(list+i)->isEmpty)
            {
                flag = i;
                break;
            }
        }
    }
    return flag;
}

/** \brief Remove a eEmployee by Id (put isEmpty Flag in 1)
 *
 * \param list eEmployee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (1) if Ok
 *
 */

int removeEmployee(eEmployee* list, int len, int id)
{
    int flag = -1;
    if(list != NULL && len > 0)
    {
        for (int i=0; i<len; i++)
        {
            if ((list+i)->id == id)
            {
                (list+i)->isEmpty = 1;
                flag = 1;
                break;
            }
        }
    }
    return flag;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list *
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int sortEmployees(eEmployee* list, int len, int order)
{
    int flag= -1;
    if (list != NULL && len > 0)
    {
        eEmployee aux;
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(order)
                {
                    if(strcmp((list+i)->lastName, (list+j)->lastName) > 0 )//Ascendente
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                    else if(!strcmp((list+i)->lastName, (list+j)->lastName) && (list+i)->idSector > (list+j)->idSector)
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                    flag= 0;
                }
                else
                {
                    if(strcmp((list+i)->lastName, (list+j)->lastName) < 0)//Descendente
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                    else if(!strcmp((list+i)->lastName, (list+j)->lastName) && (list+i)->idSector < (list+j)->idSector)
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                    flag= 0;

                }
            }
        }
    }
    return flag;
}

/** \brief print the content of employees array
 *
 * \param list eEmployee*
 * \param length int
 * \return int
 *
 */

int printEmployees(eEmployee* list, int list_len, eSector* sector, int sector_len)
{
    printf(">> Empleados\n\n");
    printf("ID | APELLIDO  |   NOMBRE  | SALARIO  |   SECTOR \n\n");

    for (int i=0; i<list_len; i++)
    {
        if ((list+i)->isEmpty == 0)
        {
            int j = findSectorById(sector, sector_len,(list+i)->idSector);
            printEmployeer(list+i, sector+j);
        }
    }
    printf("\n\n");
    return 0;
}

/** \brief print the content of an employeer
 *
 * \param list eEmployee*
 * \return void
 *
 */

void printEmployeer(eEmployee* x, eSector* sector)
{
    printf("%2d | %9s | %9s | $%.1f |  %s \n", x->id, x->lastName, x->name, x->salary, sector->description);
}

/** \brief print the content of sectores array
 *
 * \param sectores eSector*
 * \param len int
 * \return void
 *
 */

void printSectores(eSector* sectores, int len)
{
    printf("\n>> Sectores\n\n");
    printf("ID | DESCRIPCION\n\n");

    for (int i=0; i<len; i++)
        printSector((sectores+i));
    printf("\n\n");

}

/** \brief print the content of an employeer
 *
 * \param list eEmployee*
 * \return void
 *
 */

void printSector(eSector* x)
{
    printf("%2d | %9s\n", x->id, x->description);
}

/** \brief search a determinate employeer by id in the list of employees
 *
 * \param list eEmployee*
 * \param lent int
 * \return id or (-1) if could not find
 *
 */

int getIdInList(eEmployee* list, int len, eSector* sector, int sector_len)
{
    int id, valid, flag= -1;

    printEmployees(list, len, sector, sector_len);
    valid = getValidInt("ID: ","\nFuera de Rango\n", &id, 0, len, 3);

    if (!valid && findEmployeeById(list, len, id) != -1)
        flag = id;

    else
        printf("\nEmpleado no encontrado\n\n");

    return flag;
}

/** \brief search an empty position
 *
 * \param eEmployee* list
 * \param len int
 * \return int place or (-1) if there is no place or NULL pointer
 *
 */

int findEmptyPlace(eEmployee* list, int len)
{
    int flag = -1;
    if(list != NULL && len > 0)
    {
        for(int i=0; i<len; i++)
        {
            if((list+i)->isEmpty)
            {
                flag = i;
                break;
            }
        }
    }
    return flag;
}

/** \brief search an empty id
 *
 * \param eEmployee* list
 * \param len int
 * \return
 *
 */

int findNextId(eEmployee* list, int len)
{
    int flag = -1;
    if(list != NULL && len > 0)
    {
        for(int i=0; i<len; i++)
        {
            if((list+i)->isEmpty == 1)
            {
                flag = i+1;
                break;
            }
        }
    }
    return flag;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list eEmployee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param idSector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
           free space] - (1) if Ok - (0) invalid option
 */

int editEmployee(eEmployee* list, int list_len, int id, eSector* sector, int sector_len)
{
    int flag;
    int pos;
    int status = 0;
    char name[51], lastName[51];
    float salary;
    int idSector;

    pos = findEmployeeById(list, list_len, id);

    if (pos != -1)
    {
        switch (editMain())
        {
        case 1:
            flag = getValidString("\nNombre: ","\nNo es un nombre valido","\nLongitud maxima 51", name,52,3);

            if(!flag && confirmation())
            {
                strcpy((list+pos)->name, name);
                status = 1;
            }
            break;
        case 2:
            flag = getValidString("\nApellido: ","\nNo es un apellido valido","\nLongitud maxima 51", lastName,52,3);

            if(!flag && confirmation())
            {
                strcpy((list+pos)->lastName, lastName);
                status = 1;
            }
            break;
        case 3:
            flag = getValidFloat("\nSalario: ","\nFuera de Rango",&salary,0,999999,3);

            if(!flag && confirmation())
            {
                (list+pos)->salary = salary;
                status = 1;
            }
            break;
        case 4:
            printSectores(sector, sector_len);
            flag = getValidInt("\nSector: ","\nFuera de Rango",&idSector,1,4,3);

            if(!flag && confirmation())
            {
                (list+pos)->idSector = idSector;
                status = 1;
            }
            break;
        case 5:
            break;
        }
        return status;
    }
    return -1;
}

/** \brief create employers to see if program run OK
 *
 * \param eEmployee y[]
 * \return void
 *
 */

void hardcoreEmployees(eEmployee y[])
{
    eEmployee x[]=
    {
        {1,"Roberto","Gimenez",12000,1,0},
        {2,"Franco","Gonzalez",15000,1,0},
        {3,"Juan","Perez",45300,3,0},
        {4,"Gonzalo","Mey",43670,1,0},
        {5,"Brian","Lamela",45100,1,0},
        {6,"Alan","Martinez",21300,2,0},
        {7,"Anuel","AA",31400,3,0},
        {8,"Ezequiel","Iturriaga",14800,1,0},
        {9,"Carlos","Friz",25000,4,0},
    };
    for(int i=0; i<9; i++)
        y[i] = x[i];
}

/** \brief create sectores to see if program run OK
 *
 * \param eSector y[]
 * \return void
 *
 */

void hardcoreSectores(eSector y[])
{
    eSector x[]=
    {
        {1,"Contador"},
        {2,"RRHH"},
        {3,"Tecnico"},
        {4,"Analista"},
    };
    for(int i=0; i<4; i++)
        y[i] = x[i];
}

/** \brief find a Sector by Id en returns the index position in array.
 *
 * \param x eSector*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */

int findSectorById(eSector* x, int len,int id)
{
    int flag = -1;
    if(x != NULL && len > 0)
    {
        for (int i=0; i<len; i++)
        {
            if ((x+i)->id == id)
            {
                flag = i;
                break;
            }
        }
    }
    return flag;
}
