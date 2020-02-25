#ifndef dominio_H_INCLUDED
#define dominio_H_INCLUDED

#endif // dominio_H_INCLUDED

typedef struct
{
    int id;
    char dominio[50];
    int anio;
    char tipo;

}Dominio;

Dominio* dominio_new();
Dominio* dominio_setters(char* idStr,char* dominioStr,char* anioStr, char* tipoStr);

void employee_delete();
int dominio_show(Dominio* this);

int dominio_setId(Dominio* this,int id);
int dominio_getId(Dominio* this,int* id);

int dominio_setDominio(Dominio* this,char* dominio);
int dominio_getDominio(Dominio* this,char* dominio);

int dominio_setAnio(Dominio* this,int anio);
int dominio_getAnio(Dominio* this,int* anio);

int dominio_setTipo(Dominio* this,char tipo);
int dominio_getTipo(Dominio* this,char* tipo);

int dominio_SortByDominio(void* dominioA, void* dominioB);
/*
int employee_getIndexInList(LinkedList* pArrayList);
int employee_findById(LinkedList* pArrayList, char* idStr);
int employee_findEmptyId(LinkedList* pArrayList);

int employee_SortByName(void* employeeA, void* employeeB);
int employee_SortById(void* employeeA, void* employeeB);
int employee_SortBySalary(void* employeeA, void* employeeB);
int employee_SortByHoursWorked(void* employeeA, void* employeeB);
*/

int dominio_getters(Dominio* this, int* id, char* dominio, int* anio, char* tipo);
int dominio_filterMotos(void* auxDominio);
int dominio_filterCars(void* auxDominio);
int dominio_mapTipo(void* auxDominio, char *tipo);

