#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "empleados.h"

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
                ll_sort(list, _sortByNombre, 1);
                controller_List(list);
            }
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 3: //Mapea
            if (!ll_isEmpty(list))
            {
                LinkedList* listMap = ll_map(list, laQueMapea);
                if (controller_List(listMap) && listMap != NULL)
                    controller_saveAsText("mapeado.csv",listMap);
                else
                    printf("\nNo se puede guardar el archivo.\n\n");
            }
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 4: //Filtra
            if (!ll_isEmpty(list))
            {
                LinkedList* listFilter = ll_filter(list, laQueFiltra);
                if (controller_List(listFilter) && listFilter != NULL)
                    controller_saveAsText("filtrado.csv", listFilter);
                else
                    printf("\nNo se puede guardar el archivo.\n\n");
            }
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 5: //Bandera indicando la finalizacion del programa
            exit = 1;
            printf("\nGracias por utilizar el sistema.\n\n");
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
