#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "clientes.h"
#include "abonos.h"

int main()
{
    int exit = 0;
    char archivo[20];
    LinkedList* list = ll_newLinkedList();
    LinkedList* binary_list = ll_newLinkedList();
    LinkedList* listAbonados = ll_newLinkedList();

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
        case 2: //Listar
            if (!ll_isEmpty(list))
            {
                ll_sort(list, cliente_sortByNombre, 1);
                controller_List(list);
            }
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 3: //Cargar Abonos
            if (!ll_isEmpty(list))
                listAbonados = controller_addAbono(list);
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 4: //Listar Abonos
            if (!ll_isEmpty(list))
            {
                ll_sort(listAbonados, abono_sortByImport, 0);
                controller_ListComplete(list, listAbonados);
            }
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 5: //Guarda Archivos
            if (!ll_isEmpty(list))
            {
                controller_saveAsText("abonados.csv", listAbonados);
                controller_saveAsBinary("cliente.bin", binary_list);
            }
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 10: //Bandera indicando la finalizacion del programa
            exit = 1;
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
