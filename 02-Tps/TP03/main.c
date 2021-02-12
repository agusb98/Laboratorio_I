#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int main()
{
    int exit = 0, statusText = 0, statusBinary  = 0;
    LinkedList* listEmployees = ll_newLinkedList();
    do
    {
        switch(controller_principalMain())
        {
        case 1:
            if (!statusBinary && controller_loadFromText("data.csv",listEmployees))
                statusText = 1;   //Bandera Indicando que ya esta en modo Texto
            else
                printf("\nArchivos previamente Abiertos en modo Binario\n\n");
            break;
        case 2:
            if (!statusText && controller_loadFromBinary("data.bin",listEmployees))
                statusBinary = 1;   //Bandera Indicando que ya esta en modo Binario
            else
                printf("\nArchivos previamente Abiertos en modo Texto\n\n");
            break;
        case 3:
            if (statusBinary || statusText)
                controller_addEmployee(listEmployees);
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 4:
            if (statusBinary || statusText)
                controller_editEmployee(listEmployees);
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 5:
            if (statusBinary || statusText)
                controller_removeEmployee(listEmployees);
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 6:
            if (statusBinary || statusText)
                controller_ListEmployee(listEmployees);
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 7:
            if (statusBinary || statusText)
                controller_sortEmployee(listEmployees);
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 8:
            if (statusText)
                controller_saveAsText("data.csv",listEmployees);
            else
                printf("\nPrimero abra el tipo de Archivo modo Texto\n\n");
            break;
        case 9:
            if (statusBinary)
                controller_saveAsBinary("data.bin",listEmployees);
            else
                printf("\nPrimero abra el tipo de Archivo modo Binario\n\n");
            break;
        case 10:
            exit = 1;
            break;
        }
        system("pause");
    }
    while(!exit);
    return 0;
}
