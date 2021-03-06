#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "tecnico.h"

int main()
{
    int exit = 0;
    char archivo[20];
    LinkedList* list = ll_newLinkedList();
    LinkedList* filterList = ll_newLinkedList();
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
                ll_sort(list, _sortById, 0);
                controller_List(list);
                controller_saveAsText("llamadas.csv", list);
            }
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 3: //Filtrar
            if (!ll_isEmpty(list))
            {
                if ((filterList = controller_filter(list)) != NULL)
                {
                    controller_List(filterList);
                    controller_saveAsText("filtrados.csv", filterList);
                }
            }
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 4: //Bandera indicando la finalizacion del programa
                exit = 1;
                if (ll_get(list, 0) != NULL)
                    printf("Datos Guardados con exito.\n\n");
                else
                    printf("\nDatos No Guardados.\n\n");
            break;
        default:
            printf("\nOpci�n incorrecta.\n\n");
            break;
        }
        system("pause");
    }
    while(!exit);   //Permanencia del bucle mientras exit sea 0
    return 0;
}
