#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "dominios.h"

int main()
{
    int exit = 0;
    char archivo[20];
    LinkedList* list = ll_newLinkedList();
    LinkedList* mapperList = ll_newLinkedList();
    LinkedList* filterList = ll_newLinkedList();
    do
    {
        switch(controller_principalMain())
        {
        case 1: //Cargar CSV
            if (ll_get(list, 0) == NULL)
            {
                printf("\nIngrese el nombre del archivo: ");
                scanf("%s",archivo);
                if (controller_loadFromText(archivo, list))
                    printf("\tDatos Cargados\n\n");
            }
            else
                printf("\nArchivo previamente cargado.");
            break;
        case 2: //Listar
            if (ll_get(list, 0) != NULL)
            {
                    ll_sort(list, _sortByNombre, 1);
                    controller_List(list);
            }
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 3: //Mapeo
            if (ll_get(list, 0) != NULL)
            {
                if ((mapperList = controller_mapper(list)) != NULL)
                {
                    controller_List(mapperList);
                    if (controller_saveAsText("info.csv", mapperList))
                        printf("\nArchivo guardado con exito\n\n");
                }
            }
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
                    case 4: //Filtro
            if (ll_get(list, 0) != NULL)
            {
                if ((filterList = controller_filter(list)) != NULL)
                {
                    controller_List(filterList);
                    if (controller_saveAsText("filtro.csv", filterList))
                        printf("\nArchivo guardado con exito\n\n");
                }
            }
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 5: //Bandera indicando la finalizacion del programa
            exit = 1;
            if (ll_get(list, 0) != NULL)
                printf("Datos Guardados con exito.\n\n");
            else
                printf("\nDatos No Guardados.\n\n");
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
