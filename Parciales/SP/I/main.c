#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Dominio.h"

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
            printf("\nIngrese el nombre del archivo: ");
            scanf("%s",archivo);
            controller_loadFromText(archivo, list);
            break;
        case 2: //Lista Ordenada
            if (ll_get(list, 0) != NULL)
            {
                ll_sort(list, dominio_sortByPatente, 0);
                controller_List(list);
            }
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 3: //Mapea
            if (ll_get(list, 0) != NULL)
            {
                LinkedList* listMap = ll_map(list, dominio_mapTipo);
                if (controller_List(listMap))
                    controller_saveAsText("data_tipo.csv",listMap);
                else
                    printf("\nNo se puede guardar el archivo.\n\n");
            }
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 4: //Filtra
            if (ll_get(list, 0) != NULL)
            {
                LinkedList* listFilter = controller_filter(list);
                if (listFilter == NULL)
                    printf("\nNo se puede guardar el archivo.\n\n");
                else
                    printf("\nArchivo Guardado con Exito\n\n");
            }
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 5: //Bandera indicando la finalizacion del programa
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
