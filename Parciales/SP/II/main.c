#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Dominio.h"

int main()
{
    int exit = 0;
    char archivo[20];
    LinkedList* listDominios = ll_newLinkedList();
    LinkedList* listMapDominios = ll_newLinkedList();
    do
    {
        switch(controller_principalMain())
        {
        case 1://Cargar CSV
            printf("\nIngrese el nombre del archivo: ");
            scanf("%s",archivo);
            controller_loadFromText(archivo,listDominios);
            break;
        case 2://Lista de Dominios Ordenado
            if (ll_get(listDominios, 0) != NULL)
            {
                ll_sort(listDominios, dominio_SortByDominio, 1);
                controller_List(listDominios);
            }
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 3://Mapea Tipo de Dominios
            if (ll_get(listDominios, 0) != NULL)
            {
                listMapDominios = ll_map(listDominios, dominio_mapTipo);
                if (controller_List(listMapDominios))
                    controller_saveAsText("data.csv",listMapDominios);
                else
                printf("\nNo se puede guardar el archivo.\n\n");
            }
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 4: //Filtra Dominios
            if (ll_get(listDominios, 0) != NULL)
                controller_filter(listDominios);
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
