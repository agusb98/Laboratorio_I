#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Dominio.h"
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
    printf("\n3_ Calculo de Tipo.");
    printf("\n4_ Filtro por Auto/Moto.");
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
    printf("\n1_ Mayor a 50km");
    printf("\n2_ Menor a 50km");
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
    printf(">> Imprimir\n\n");
    printf("  ID |  DOMINIO  | ANIO |  TIPO  \n\n");

    for(int i=0; i<ll_len(pArrayList); i++) //Recorro el array de datos
    {
        eDominio* this = (eDominio*)ll_get(pArrayList, i); //Le asigno al puntero eDominio "this" lo que retorna "ll_get()"
        dominio_show(this); //Imprimo los datos
    }
    printf("\n\n");
    return 1;
}

int controller_saveAsText(char* path, LinkedList* pArrayList)
{
    FILE* text = fopen(path, "w");
    int retorno = 0, id, anio;
    char dominio[50], tipo;

    if(text != NULL && pArrayList != NULL)
    {
        fprintf(text,"id,dominio,anio,tipo\n");
        for(int i=0; i<ll_len(pArrayList); i++)
        {
            eDominio* this = (eDominio*) ll_get(pArrayList, i);
            if (dominio_getters(this, &id, dominio, &anio, &tipo))
                fprintf(text, "%d,%s,%d,%c\n", id, dominio, anio, tipo);
        }
        retorno = 1;
        printf("\nDatos Guardados Con Exito.\n\n");
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
            eDominio* this = (eDominio*)ll_get(pArrayList,i);
            datosLeidos = fwrite(this, sizeof(eDominio), 1, pArchivo);
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

LinkedList* controller_filter(LinkedList* pArrayList)
{
    LinkedList* newList = ll_clone(pArrayList);
    if (newList != NULL)
    {
        switch (controller_filterMain())
        {
        case 1:
            newList = ll_filter(pArrayList,dominio_filterAutos);
            if (newList != NULL)
            {
                controller_List(newList);
                controller_saveAsText("auto.csv",newList);
            }
            break;
        case 2:
            newList = ll_filter(pArrayList, dominio_filterMotos);
            if (newList != NULL)
            {
                controller_List(newList);
                controller_saveAsText("moto.csv",newList);
            }
            break;
        case 3:
            break;
        default:
            printf("\nOpcion ingresada Invalida\n\n");
            break;
        }
    }
    return newList;
}
