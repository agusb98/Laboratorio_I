#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "utn.h"
#include "eject.h"
#define EMPLOYEE_QUANTITY 1000
#define SECTOR_QUANTITY 4

int main()
{
    int exit=0; //indica si se solicita salida del programa
    int flag=0; //controla si se ingresan empleados

    //DECLARACION E INICIALIZACION DE EMPLEADOS Y FECHAS:
    eEmployee list[EMPLOYEE_QUANTITY];
    eSector sector[SECTOR_QUANTITY];
    initEmployees(list,EMPLOYEE_QUANTITY);

    //HARDCOREO DE EMPLEADOS Y FECHAS:
    //hardcoreEmployees(list);
    hardcoreSectores(sector);

    do
    {
        switch(principalMain())
        {
        case 1:
            if (eject_addEmployee(list,EMPLOYEE_QUANTITY, sector, SECTOR_QUANTITY))
                flag=1;
            break;
        case 2:
            if (flag) //Si se ingreso un empleado
                eject_editEmployee(list,EMPLOYEE_QUANTITY, sector, SECTOR_QUANTITY);
            else
                printf("\nIngrese Empleados\n\n");
            break;
        case 3:
            if (flag) //Si se ingreso un empleado
                eject_deleteEmployee(list,EMPLOYEE_QUANTITY, sector, SECTOR_QUANTITY);
            else
                printf("\nIngrese Empleados\n\n");
            break;
        case 4:
            if (flag) //Si se ingreso un empleado
                eject_reportEmployees(list,EMPLOYEE_QUANTITY, sector, SECTOR_QUANTITY);
            else
                printf("\nIngrese Empleados\n\n");
            break;
        case 5:
            exit=1;
            break;
        default://Se limpia la pantalla y reaparece el menu
            printf("\nOpcion Invalida\n\n");
            break;
        }
        system("pause");
    }
    while(!exit);
    return 0;
}
