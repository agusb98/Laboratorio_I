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
    printf("\n1_ Cargar los datos de los dominios desde el archivo(modo texto).");
    printf("\n2_ Listar dominios.");
    printf("\n3_ Seteo de tipo.");
    printf("\n4_ Filtrar dominios.");
    printf("\n5_ Salir");

    fflush(stdin);
    return getInt("\n\nIngrese opcion: ");
}

/** \brief Menu de opciones de Ordenamientos
 *
 * \return int La opcion elegida por el usuario
 *
 */
int controller_sortMain()
{
    system("cls");

    printf(">> Menu de Ordenamientos\n");
    printf("\n1_ Nombre");
    printf("\n2_ Id");
    printf("\n3_ Salario");
    printf("\n4_ Horas Trabajadas");
    printf("\n5_ Salir");

    fflush(stdin);
    return getInt("\n\nIngrese opcion: ");
}

/** \brief Menu de opciones de Modificaciones
 *
 * \return int La opcion elegida por el usuario
 *
 */
int controller_editMain()
{
    system("cls");

    printf(">> Menu de Modificaciones\n");
    printf("\n1_ Nombre");
    printf("\n2_ Id");
    printf("\n3_ Salario");
    printf("\n4_ Horas Trabajadas");
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
    printf("\n1_ Moto");
    printf("\n2_ Auto");
    printf("\n3_ Volver al Menu Principal");

    fflush(stdin);
    return getInt("\n\nIngrese opcion: ");
}
/** \brief Carga los datos de los desde el archivo data.csv (modo texto).
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
    if(pArchivo != NULL)  //Verifico si la lectura del archivo, si no retorna NULL accedo al parse_Employee
    {
        flag = parser_FromText(pArchivo, pArrayList);
        if(flag == 1) //Funcion parser modo texto
            printf("\tDominios Cargados\n\n");
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

/** \brief Alta de dato
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
 /*
int controller_add(LinkedList* pArrayList)
{
    char auxId[128], auxName[128], auxHoursWorked[128], auxSalary[128]; //Variables buffer
    int flag = 0, status = 0;
    Employee* this = employee_new(); //Creo un nuevo empleado

    system("cls");
    printf(">> Alta\n\n");

    if (this != NULL && pArrayList != NULL)
    {
        //SOLICITO Y VALIDO LOS DATOS INGRESADOS AL NUEVO EMPLEADO

        status = getStringNumeros("ID: ", auxId);
        while(status != 1 || employee_findById(pArrayList, auxId) != -1)  //Valido que el id ingresado no se encuentre dado de alta en sistema, de estar dado de alta pide uno nuevo
        {
            printf("El ID ingresado ya se encuentra dado de alta en sistema. Reintente.\n\n");
            status = getStringNumeros("ID: ", auxId); //Solicito y valido el id (string)
        }

        if (getValidString("\nNombre: ", "Error de ingreso, reintente.", "Error de ingreso, reintente.", auxName, 128, 128))
        {
            if (getStringNumeros("\nHoras trabajadas: ", auxHoursWorked) == 1)
            {
                if(getStringNumerosFlotantes("\nSueldo: ", auxSalary))
                {
                    this = employee_newParametros(auxId, auxName, auxHoursWorked, auxSalary);  //Le asigno a "this" las variables casteadas en la funcion

                    if (this == NULL)
                        printf("\nError en Atenticacion de datos\n\n");

                    else if (confirmation() && !ll_add(pArrayList, this)) //Agrego "this" al final del array de empleados
                    {
                        printf("\nEmpleado Agregado.\n\n");
                        flag = 1;
                    }
                }
            }
        }
    }
    else
        printf("\tInsuficiente Espacio en Memoria");

    if (!flag)
        printf("\nOperacion Cancelada.\n\n");

    return flag;
}

 * \brief Modificar datos
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int que retorna la funcion (1 - TodoOK // 0 - Error)
 *
 */
/*
int controller_edit(LinkedList* pArrayList)
{
    char auxName[128], auxId[128];
    int auxHoursWorked, status = 0, flag = 0;
    float auxSalary;
    Employee* this; //Creo un nuevo empleado

    if (pArrayList != NULL)
    {
        flag = 1;
        this = (Employee*)ll_get(pArrayList, employee_getIndexInList(pArrayList)); //Le asigno a "this" lo que retorna "ll_get()"

        if (this != NULL)
        {
            switch(controller_editMain())
            {
            case 1: //Modifica Nombre
                if (getValidString("\nNombre: ", "Error de ingreso, reintente.", "Error de ingreso, reintente.", auxName, 128, 128))
                {
                    if ( confirmation() && employee_setName(this, auxName));
                    status = 1;
                }
                break;
            case 2: //Modifica ID
                if (getStringNumeros("ID: ", auxId) == 1)
                {
                    if (employee_findById(pArrayList, auxId) == -1) //Entra si no encuentra el Id
                    {
                        if(confirmation())
                        {
                            employee_setId(this, atoi(auxId));
                            status = 1;
                        }
                    }
                    else
                        printf("\nID ingresado ya se encuentra en uso.\n");
                }
                break;
            case 3: //Modifica Salario
                if (getValidFloat("\nSueldo: ", "Error de ingreso, reintente.\n", &auxSalary, 0, 999999, 3))
                {
                    if (confirmation() && employee_setSalary(this, auxSalary))
                        status = 1;
                }
                break;
            case 4: //Modifica Horas Trabajadas
                if (getValidInt("\nHoras Trabajadas: ", "Error de ingreso, reintente.\n", &auxHoursWorked, 0, 999999, 3))
                {
                    if (confirmation() && employee_setHoursWorked(this, auxHoursWorked))
                        status = 1;
                }
                break;
            }
        }
        else
            printf("\nEmpleado No Encontrado\n\n");
        if (status)
            printf("\nEmpleado Modificado con Exito\n\n");
        else
            printf("\nOperacion Cancelada\n\n");
    }
    return flag;
}


* \brief Listar datos
 *
 * \param pArrayList LinkedList*
 * \return int 1
 *
 */
int controller_List(LinkedList* pArrayList)
{
    system("cls");
    printf(">> Dominios\n\n");
    printf("  ID |DOMINIO | ANIO |TIPO\n\n");

    for(int i=0; i<ll_len(pArrayList); i++) //Recorro el array de datos
    {
        Dominio* this = (Dominio*)ll_get(pArrayList, i); //Le asigno al puntero empleado "this" lo que retorna "ll_get()"
        dominio_show(this); //Imprimo los datos del empleado
    }
    printf("\n\n");
    return 1;
}

/** \brief Ordenar datos
 *
 * \param path char*
 * \param pArrayList LinkedList*
 *
 *//*
int controller_sort(LinkedList* pArrayList)
{
    int status = 0, flag = 0;
    if (pArrayList != NULL)
    {
        flag = 1;
        switch(controller_sortMain())
        {
        case 1:
            if ( !ll_sort(pArrayList, employee_SortByName, 1) )
                status = 1;
            break;
        case 2:
            if ( !ll_sort(pArrayList, employee_SortById, 0) )
                status = 1;
            break;
        case 3:
            if ( !ll_sort(pArrayList, employee_SortBySalary, 0) )
                status = 1;
            break;
        case 4:
            if ( !ll_sort(pArrayList, employee_SortByHoursWorked, 0) )
                status = 1;
            break;
        }

        if (status)
        {
            controller_List(pArrayList);
            printf("\nEmpleados Ordenados con Exito\n\n");
        }
        else
            printf("\nOperacion Cancelada\n\n");

    }
    return flag;
}

int controller_remove(LinkedList* pArrayList)
{
    int flag = 0, status = 0;
    Employee* this; //Creo un nuevo empleado

    if (pArrayList != NULL)
    {
        flag = 1;
        int index = employee_getIndexInList(pArrayList);
        this = (Employee*)ll_get(pArrayList, index); //Le asigno a "this" lo que retorna "ll_get()"

        if (this != NULL)
        {
            if(confirmation() && !ll_remove(pArrayList, index))
                status = 1;
        }
        else
            printf("\nEmpleado No Encontrado\n");

        if (status)
            printf("\nEmpleado Eliminado Con Exito\n\n");
        else
            printf("\nOperacion Cancelada\n\n");
    }
    return flag;
}

* \brief Guarda los datos en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayList)
{
    FILE* text = fopen(path, "w");
    int retorno = 0;
    int auxId, auxAnio;
    char auxTipo, auxDominio[50];

    if(text != NULL && pArrayList != NULL)
    {
        fprintf(text,"id,dominio,anio,tipo\n");
        for(int i=0; i<ll_len(pArrayList); i++)
        {
            Dominio* this = (Dominio*) ll_get(pArrayList, i);
            if (dominio_getters(this, &auxId, auxDominio, &auxAnio, &auxTipo))
                fprintf(text, "%d,%s,%d,%c\n", auxId, auxDominio, auxAnio, auxTipo);
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
 *//*
int controller_saveAsBinary(char* path, LinkedList* pArrayList)
{
    FILE* pArchivo = fopen(path, "wb");; //Puntero al archivo, abro el archivo en modo escritura binaria
    Employee* this;
    int flag = 0, datosLeidos;

    if(pArchivo != NULL && pArrayList != NULL) //Verifico que la apertura del archivo y el array de empelados no sea NULL, si no lo es ingreso
    {
        rewind(pArchivo); //Voy al inicio del archivo
        for(int i=0; i<ll_len(pArrayList); i++)
        {
            this = (Employee*)ll_get(pArrayList,i);
            datosLeidos = fwrite(this, sizeof(Employee), 1, pArchivo);
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

* \brief Elimina todos los datos dentro de la lista y la lista misma
 *
 * \param LinkedList* pArrayList
 * \return (0) if Ok - (-1) if failled
 *
 */

/*
int controller_freeLinkedList(LinkedList* pArrayList)
{
    int flag = -1;
    if(pArrayList != NULL)
    {
        for(int i=0; i<ll_len(pArrayList); i++)
            ll_remove(pArrayList, i);

        ll_deleteLinkedList(pArrayList);
        flag = 0;
    }
    printf("\nSe elimino la lista.\n\n");
    return flag;
}
*/

LinkedList* controller_filter(LinkedList* pArrayList)
{
    LinkedList* newList = ll_clone(pArrayList);
    if (newList != NULL)
    {
        switch (controller_filterMain())
        {
        case 1:
            newList = ll_filter(pArrayList, dominio_filterMotos);
            if (newList != NULL)
            {
                controller_List(newList);
                controller_saveAsText("motos.csv",newList);
            }
            break;
        case 2:
            newList = ll_filter(pArrayList, dominio_filterCars);
            if (newList != NULL)
            {
                controller_List(newList);
                controller_saveAsText("autos.csv",newList);
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
