#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "peliculas.h"

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
            }
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 3: //Categorias
            if (!ll_isEmpty(list))
            {
                depurarPeliculas(list);
                controller_List(list);
            }
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 4: //Filtrar por Categoria
            if (!ll_isEmpty(list))
            {
                filterList = ll_filter(list, filterByCategoria);
                controller_List(filterList);
            }
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 5: //Bandera indicando la finalizacion del programa
                exit = 1;
                if (controller_saveAsText("depurados.csv", list) && controller_saveAsText("filtrados.csv", filterList) && ll_get(list, 0) != NULL)
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
