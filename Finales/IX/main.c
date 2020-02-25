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
    LinkedList* mapperList = ll_newLinkedList();
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
        case 2: //Mapeo
            if (ll_get(list, 0) != NULL)
            {
                if ((mapperList = controller_mapper(list)) != NULL)
                {
                    ll_sort(list, _sortById, 0);
                    controller_List(mapperList);
                    if (controller_saveAsText("info.csv", mapperList))
                        printf("\nArchivo guardado con exito\n\n");
                }
            }
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 3: //Bandera indicando la finalizacion del programa
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
