#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "ingredientes.h"
#include "recetas.h"

int main()
{
    int exit = 0;
    char archivo[20];
    LinkedList* list = ll_newLinkedList();
    LinkedList* recetaList = ll_newLinkedList();
    do
    {
        switch(controller_principalMain())
        {
        case 0: //Cargar CSV
            if (ll_isEmpty(list))
            {
                printf("\nIngrese el nombre del archivo: ");
                scanf("%s",archivo);
                controller_loadFromText(archivo, list);
            }
            else
                printf("\nArchivo Previamente Cargado\n\n");
            break;
        case 1: //Alta
            if (!ll_isEmpty(list))
                controller_addIngrediente(list);
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 2: //Modificar
            if (!ll_isEmpty(list))
                controller_editIngrediente(list);
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 3: //Baja
            if (!ll_isEmpty(list))
                controller_removeIngrediente(list);
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 4: //Listar
            if (!ll_isEmpty(list))
            {
                ll_sort(list, ingrediente_sortByNombre, 1);
                controller_List(list);
            }
            else
                printf("\nPrimero abra el tipo de Archivo\n\n");
            break;
        case 5: //Alta Receta
            if (!ll_isEmpty(list))
            {
                if (recetaList != NULL && controller_loadFromText_Recetas("recetas.csv", recetaList))
                    controller_addReceta(recetaList, list);
            }
            else
                printf("\nArchivo previamente cargado.");
            break;
        case 6: //Listar
            if (!ll_isEmpty(list) && !ll_isEmpty(recetaList))
                controller_ListReceta(recetaList);
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
