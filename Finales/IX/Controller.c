#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "empleados.h"
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
    printf("\n2_ Info");
    printf("\n3_ Salir");

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
    printf("\n1_ No enciende PC");
    printf("\n2_ No funciona mouse");
    printf("\n3_ No funciona teclado");
    printf("\n4_ No hay internet");
    printf("\n5_ No funciona telefono");
    printf("\n6_ Volver al Menu Principal");

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
    if(pArchivo != NULL && pArrayList != NULL)  //Verifico si la lectura del archivo, si no retorna NULL accedo al parse
        flag = parser_FromText(pArchivo, pArrayList);
    else
        printf("\nArchivo No Encontrado\n\n");
    return flag;
}

int controller_List(LinkedList* pArrayList)
{
    system("cls");
    printf(">> Datos\n\n");
    printf("  ID  |  NOMBRE  |  HORAS T  | SUELDO \n\n");

    for(int i=0; i<ll_len(pArrayList); i++) //Recorro el array de datos
    {
        eEmpleado* this = (eEmpleado*)ll_get(pArrayList, i); //Le asigno al puntero eEmpleado "this" lo que retorna "ll_get()"
        _show(this); //Imprimo los datos
    }
    printf("\n\n");
    return 1;
}

int controller_saveAsText(char* path, LinkedList* pArrayList)
{
    char var_2[50];
    int var_1, var_3;
    float var_4;
    FILE* text = fopen(path, "w");

    if(text != NULL && pArrayList != NULL && confirmation())
    {
        fprintf(text,"id,fecha,nombre,horas_trabajadas,sueldo\n");
        for(int i=0; i<ll_len(pArrayList); i++)
        {
            eEmpleado* this = (eEmpleado*) ll_get(pArrayList, i);
            if (_getters(this, &var_1, var_2, &var_3, &var_4))
                fprintf(text, "%d,%s,%d,%.0f\n", var_1, var_2, var_3, var_4);
        }
        return 1;
    }
    fclose(text);
    return 0;
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
            eEmpleado* this = (eEmpleado*)ll_get(pArrayList,i);
            datosLeidos = fwrite(this, sizeof(eEmpleado), 1, pArchivo);
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

/** \brief Guarda los datos en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
/*LinkedList* controller_filter(LinkedList* pArrayList)
{
    if (pArrayList != NULL)
    {
        switch(controller_filterMain())
        {
        case 1:
            return ll_filter(pArrayList, filter_1);
        case 2:
            return ll_filter(pArrayList, filter_2);
        case 3:
            return ll_filter(pArrayList, filter_3);
        case 4:
            return ll_filter(pArrayList, filter_4);
        case 5:
            return ll_filter(pArrayList, filter_5);
        }
    }
    return NULL;
}
*/

/** \brief Guarda los datos en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
LinkedList* controller_mapper(LinkedList* pArrayList)
{
    if (pArrayList != NULL)
        return ll_map(pArrayList, _mapSueldo);
    return NULL;
}





