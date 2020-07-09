#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "computer.h"
#include "utn.h"

/** \brief Menu de opciones
 *
 * \return int La opcion elegida por el usuario
 *
 */
int controller_principalMain()
{
    system("cls");

    printf(">> Menu de Opciones\n");
    printf("\n1_ Cargar desde el archivo(CVS).");
    printf("\n2_ Listar.");
    printf("\n3_ Mapeo");
    printf("\n4_ Filtro");
    printf("\n10_ Salir");

    fflush(stdin);
    return getInt("\n\nIngrese opcion: ");
}

/** \brief Menu de opciones a filtro por escoger
 *
 * \return int La opcion elegida por el usuario
 *
 */
int controller_filterMain()
{
    system("cls");

    printf(">> Menu de Filtros\n");
    printf("\n1_ Precios Altos");
    printf("\n2_ Precios Bajos");
    printf("\n3_ Volver al Menu Principal");

    fflush(stdin);
    return getInt("\n\nIngrese opcion: ");
}
/** \brief Carga los datos desde el archivo (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int retorna la funcion (1 - TodoOK // 0 - Error)
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayList)
{
    FILE* pArchivo = fopen(path, "r"); //Variable puntero al archivo
    system("cls");
    int flag = 0;

    printf(">> Cargar Modo Texto\n\n");
    if(pArchivo != NULL)  //Verifico si la lectura del archivo, si no retorna NULL accedo al parse
    {
        flag = parser_FromText(pArchivo, pArrayList);
        if(flag == 1) //Funcion parser modo texto
            printf("\tDatos Cargados\n\n");
    }
    else
        printf("\nArchivo No Encontrado\n\n");
    return flag;
}

int controller_List(LinkedList* pArrayList)
{
    system("cls");
    printf(">> Datos\n\n");
    printf("  ID |  DESCRIPCION  |  PRECIO  | TIPO | OFERTA \n\n");

    for(int i=0; i<ll_len(pArrayList); i++) //Recorro el array de datos
    {
        eComputer* this = (eComputer*)ll_get(pArrayList, i); //Le asigno al puntero eComputer "this" lo que retorna "ll_get()"
        _show(this); //Imprimo los datos
    }
    printf("\n\n");
    return 1;
}

int controller_saveAsText(char* path, LinkedList* pArrayList)
{
    FILE* text = fopen(path, "w");
    int retorno = 0, id;
    char descripcion[200], idTipo[200];
    float precio, oferta;


    if(text != NULL && pArrayList != NULL)
    {
        fprintf(text,"id,descripcion,precio,tipo,oferta\n");
        for(int i=0; i<ll_len(pArrayList); i++)
        {
            eComputer* this = (eComputer*) ll_get(pArrayList, i);
            if (_getters(this, &id, descripcion, &precio, idTipo, &oferta))
                fprintf(text, "%3d,%8s,%.1f,%8s,%.1f\n", id, descripcion, precio, idTipo, oferta);
        }
        retorno = 1;
        printf("Datos Guardados con exito.\n\n");
    }
    fclose(text);
    return retorno;
}
