#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "entregas.h"

int main()
{
    int exit = 0;
    char archivo[20];
    LinkedList* list = ll_newLinkedList();

    do
    {
        switch(controller_principalMain())
        {
        case 1: //Cargar CSV
            if (ll_isEmpty(list))
            {
                printf("\nIngrese el nombre del archivo: ");
                scanf("%s",archivo);
                controller_loadFromText(archivo, list);
            }
            else
                printf("\nArchivo previamente cargado.");
            break;
        case 2: //Lista Ordenada
            if (!ll_isEmpty(list))
            {
                ll_sort(list, _sortByNombre, 0);
                controller_List(list);
            }
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 3: //Informes
            if (!ll_isEmpty(list))
                controller_SaveInformsAsText("informes.txt",list);
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 4: //Bandera indicando la finalizacion del programa
            exit = 1;
            printf("\nGracias por utilizar el sistema.\n\n");
            break;
        default:
            printf("\nOpción incorrecta.\n\n");
            break;
        }
        system("pause");
    }
    while(!exit);   //Permanencia del bucle mientras exit sea 0
    return 0;
}
