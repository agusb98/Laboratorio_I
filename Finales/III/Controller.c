#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "entregas.h"
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
    printf("\n3_ Mapeo de Datos");
    printf("\n4_ Filtro de Datos");
    printf("\n5_ Salir");

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

/** \brief Carga los datos desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int retorna la funcion (1 - TodoOK // 0 - Error)
 *
 */

int controller_loadFromBinary(char* path, LinkedList* pArrayList)
{
    int flag = 0;
    FILE* pArchivo; //Variable puntero al archivo

    system("cls");

    printf(">> Cargar Modo Binario\n\n");

    if((pArchivo = fopen(path, "rb")) != NULL)
    {
        parser_FromBinary(pArchivo, pArrayList); //Funcion parser modo bin
        flag = 1;
    }
    else  //Si retorna NULL no encontro el archivo, por lo tanto lo creo e informo que no se encontro y se creo uno nuevo
    {
        if((pArchivo = fopen(path, "wb")) != NULL)
            printf("\tNo se encontro el archivo. Se creo uno nuevo con el nombre %s\n\n", path);
    }
    return flag;
}

int controller_List(LinkedList* pArrayList)
{
    system("cls");
    printf(">> Datos\n\n");
    printf("  ID |  TIPO  |  CANTIDAD  | PRECIO  \n\n");

    for(int i=0; i<ll_len(pArrayList); i++) //Recorro el array de datos
    {
        eEntregas* this = (eEntregas*)ll_get(pArrayList, i); //Le asigno al puntero eEntregas "this" lo que retorna "ll_get()"
        _show(this); //Imprimo los datos
    }
    printf("\n\n");
    return 1;
}

int controller_saveAsText(char* path, LinkedList* pArrayList)
{
    FILE* text = fopen(path, "w");
    int retorno = 0, id, cantidad;
    char tipo[50];
    float precio;

    if(text != NULL && pArrayList != NULL)
    {
        fprintf(text,"id,tipo,autor,precio\n");
        for(int i=0; i<ll_len(pArrayList); i++)
        {
            eEntregas* this = (eEntregas*) ll_get(pArrayList, i);
            if (_getters(this, &id, tipo, &cantidad, &precio))
                fprintf(text, "%d,%s,%d,%.1f\n", id, tipo, cantidad, precio);
        }
        retorno = 1;
    }
    fclose(text);
    return retorno;
}

/** \brief Guarda los datos en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayList)
{
    FILE* pArchivo = fopen(path, "wb");; //Puntero al archivo, abro el archivo en modo escritura binaria
    int flag = 0, datosLeidos;

    if(pArchivo != NULL && pArrayList != NULL) //Verifico que la apertura del archivo y el array de eEnvios no sea NULL, si no lo es ingreso
    {
        rewind(pArchivo); //Voy al inicio del archivo
        for(int i=0; i<ll_len(pArrayList); i++)
        {
            eEntregas* this = (eEntregas*)ll_get(pArrayList,i);
            datosLeidos = fwrite(this, sizeof(eEntregas), 1, pArchivo);
            flag = 1;
            if(datosLeidos != 1)
                printf("\nError al escribir los datos en el archivo.\n\n");
        }
        printf("\nDatos Guardados Con Exito\n\n");
    }

    else  //Si no pudo acceder al archivo lo informo
        printf("\nNo se pudo acceder al archivo.\n");

    fclose(pArchivo); //Cierro el archivo
    return flag;
}

int controller_SaveInformsAsText(char* path, LinkedList* pArrayList)
{
    FILE* text = fopen(path, "w");
    int retorno = 0;
    if(text != NULL && pArrayList != NULL)
    {
        int cant_1 = ll_countElements(pArrayList, tipo_1);
        int cant_2 = ll_countElements(pArrayList, tipo_2);
        int cant_3 = ll_countElements(pArrayList, tipo_3);
        float prom_BultosByEntregas = (float)(bultos_Total(pArrayList) / (cant_1 + cant_2 + cant_3));
        float prom_ImportByEntregas = (float)(importe_Total(pArrayList) / (cant_1 + cant_2 + cant_3));

        fprintf(text,"- Cantidad total de entregas: %d \n", cant_1 + cant_2 + cant_3);
        fprintf(text,"- Cantidad de entregas por tipo: %d(GOLD) - %d (REGULAR) - %d (PLUS) \n", cant_1, cant_2, cant_3);
        fprintf(text,"- Cantidad total de bultos entregados: %d \n", bultos_Total(pArrayList));
        fprintf(text,"- Promedio de bultos por entrega: %.1f \n", prom_BultosByEntregas);
        fprintf(text,"- Importe promedio por entrega: %.1f \n\n", prom_ImportByEntregas);

        system("cls");
        printf(">> Informes\n\n");
        printf("Archivo Cargados con Exito\n\n");

        retorno = 1;
    }
    else
        printf("Error al Cargar Archivos\n\n");

    return retorno;
}
