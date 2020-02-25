#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "empleados.h"
#include "utn.h"

eEmpleado* _new()
{
    eEmpleado* this = malloc(sizeof(eEmpleado)); //Creo un nuevo empleados con memodia dinamica "malloc"
    if(this == NULL)
    {
        printf("Almacenamiento lleno.\n");
        exit(EXIT_FAILURE); //De ser NULL salgo
    }
    else //De lo contrario parseo a 0 y cadena vacia las variables
    {
        this->id = 0;
        strcpy(this->nombre, "");
        strcpy(this->empleo, "");
        this->edad = 0;
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }
    return this; //Retorno el puntero a la estructura creada
}

eEmpleado* _setters(char* var_1,char* var_2, char* var_3, char* var_4, char* var_5, char* var_6)
{
    eEmpleado* this = _new();
    int flag = 0;

    if(_setId(this,atoi(var_1)))
        flag=1;
    else
        flag = 0;

    if(_setNombre(this,var_2) && flag)
        flag=1;
    else
        flag = 0;

    if(_setEmpleo(this,var_3) && flag)
        flag=1;
    else
        flag = 0;

    if(_setEdad(this,atoi(var_4)) && flag)
        flag=1;
    else
        flag = 0;

    if(_setHorasTrabajadas(this,atoi(var_5)) && flag)
        flag=1;
    else
        flag = 0;

    if(_setSueldo(this,atof(var_6)) && flag)
        flag=1;
    else
        flag = 0;

    if(!flag)
    {
        printf("\nError al cargar datos, revise la lista.\n");
        free(this);
    }

    return this;
}

int _getters(eEmpleado* this, int* var_1, char* var_2, char* var_3, int* var_4, int* var_5, float* var_6)
{
    int flag = 0;
    if (this != NULL)
    {
        if (_getId(this, var_1))
            flag = 1;
        if (_getNombre(this, var_2) && flag)
            flag = 1;
        if (_getEmpleo(this, var_3) && flag)
            flag = 1;
        if (_getEdad(this, var_4) && flag)
            flag = 1;
        if (_getHorasTrabajadas(this, var_5) && flag)
            flag = 1;
        if (_getSueldo(this, var_6) && flag)
            flag = 1;
    }
    return flag;
}

int _setId(eEmpleado* this,int id)
{
    int flag = 0;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        flag=1;
    }
    return flag;
}

int _getId(eEmpleado* this,int* id)
{
    int flag = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        flag=1;
    }
    return flag;
}

int _setNombre(eEmpleado* this,char* nombre)
{
    int flag=0;
    if(this != NULL)
    {
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        flag=1;
    }
    return flag;
}

int _getNombre(eEmpleado* this,char* nombre)
{
    int flag = 0;
    if (this != NULL)
    {
        strncpy(nombre, this->nombre, sizeof(this->nombre));
        flag = 1;
    }
    return flag;
}

int _setEmpleo(eEmpleado* this,char* empleo)
{
    int flag=0;
    if(this != NULL)
    {
        strncpy(this->empleo, empleo, sizeof(this->empleo));
        flag=1;
    }
    return flag;
}

int _getEmpleo(eEmpleado* this,char* empleo)
{
    int flag = 0;
    if (this != NULL)
    {
        strncpy(empleo, this->empleo, sizeof(this->empleo));
        flag = 1;
    }
    return flag;
}

int _setEdad(eEmpleado* this,int edad)
{
    int flag=0;
    if(this != NULL && edad >= 0)
    {
        this->edad = edad;
        flag=1;
    }
    return flag;
}

int _getEdad(eEmpleado* this,int* edad)
{
    int flag = 0;
    if (this != NULL && edad != NULL)
    {
        *edad = this->edad;
        flag = 1;
    }
    return flag;
}

int _setHorasTrabajadas(eEmpleado* this,int horasTrabajadas)
{
    int flag=0;
    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        flag=1;
    }
    return flag;
}

int _getHorasTrabajadas(eEmpleado* this,int* horasTrabajadas)
{
    int flag = 0;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        flag=1;
    }
    return flag;
}

int _setSueldo(eEmpleado* this,float sueldo)
{
    int flag=0;
    if(this != NULL)
    {
        if (sueldo < 0)
            sueldo = 0;

        this->sueldo = sueldo;
        flag=1;
    }
    return flag;
}

int _getSueldo(eEmpleado* this,float* sueldo)
{
    int flag = 0;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        flag=1;
    }
    return flag;
}

int _show(eEmpleado* this)
{
    int flag = 0, id, horasTrabajadas, edad;
    char nombre[sizeof(this->nombre)], empleo[sizeof(this->empleo)];
    float sueldo;

    if (_getters(this, &id, nombre, empleo, &edad, &horasTrabajadas, &sueldo))
    {
        printf(" %3d | %8s | %8s | %2d | %2d  | $%.2f \n", id, nombre, empleo, edad, horasTrabajadas, sueldo);
        flag = 1;
    }
    return flag;
}

/** \brief sort envios in list by their id
 *
 * \param void* punteroA
 * \param void* punteroB
 * \return int (-1) si punteroA menor a punteroB
               (0) si punteroA igual a punteroB
               (1) si punteroA manor a punteroB
               (-2) If NULL pointer
 *
 */
int _sortById(void* punteroA, void* punteroB)
{
    int flag = -2;

    if(punteroA != NULL && punteroB != NULL)
    {
        int id_A, id_B;

        _getId(punteroA, &id_A);
        _getId(punteroB, &id_B);

        if((id_A) < (id_B)) //Si id de A en menor que id de B cambio al bandera flag a 1
            flag = 1 ;
        else if((id_A) == (id_B)) //Si id de A igual que id de B dejo la bandera igual
            flag = 0;
        else
            flag = -1;
    }
    return flag;
}
/** \brief sort in list by their name
 *
 * \param void* punteroA
 * \param void* punteroB
 * \return int (1) if OK - (0) If NULL pointer
 *
 */
int _sortByNombre(void* punteroA, void* punteroB)
{
    int flag = 0;
    if(punteroA != NULL && punteroB != NULL)
    {
        eEmpleado* pA = (eEmpleado*) punteroA;
        eEmpleado* pB = (eEmpleado*) punteroB;

        char aux_A[sizeof(pA->nombre)];
        char aux_B[sizeof(pB->nombre)];

        _getNombre(pA, aux_A);
        _getNombre(pB, aux_B);
        flag = strcmp(aux_A, aux_B);
    }
    return flag;
}

/** \brief Asigna el sueldo de determinado puntero
 *
 * \param void* this
 * \return (1) if OK - (0) if this is NULL pointer
 *
 */

int laQueMapea(void* this)
{
    int flag = 0;
    int horasTrabajadas;
    if (this != NULL)
    {
        _getHorasTrabajadas(this, &horasTrabajadas);
        _setSueldo(this, horasTrabajadas * 300);
        flag = 1;
    }
    return flag;
}

/** \brief Asigna el sueldo de determinado puntero
 *
 * \param void* this
 * \return (1) if OK - (-1) if this is NULL pointer - (0) if cant find
 *
 */

int laQueFiltra(void* this)
{
    eEmpleado* pA = (eEmpleado*) this;
    int flag = 0, edad;
    char empleo[sizeof(pA->empleo)];

    if (pA != NULL)
    {
        _getEmpleo(pA, empleo);
        _getEdad(pA, &edad);

        if(!strcmp(empleo, "programador") && edad > 20)
            flag = 1;
    }
    return flag;
}
