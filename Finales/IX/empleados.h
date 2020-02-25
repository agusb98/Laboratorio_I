#ifndef empleados_h_INCLUDED
#define empleados_h_INCLUDED

#endif

typedef struct
{
    int id;
    char nombre[50];
    int horasTrabajadas;
    float sueldo;

}eEmpleado;

eEmpleado* _new();
eEmpleado* _setters(char* var_1, char* var_2, char* var_3, char* var_4);

int _getters(eEmpleado* this, int* var_1, char* var_2, int* var_3, float* var_4);

int _setId(eEmpleado* this,int id);
int _getId(eEmpleado* this,int* id);

int _setNombre(eEmpleado* this,char* nombre);
int _getNombre(eEmpleado* this,char* nombre);

int _setHorasTrabajadas(eEmpleado* this,int horasTrabajadas);
int _getHorasTrabajadas(eEmpleado* this,int* horasTrabajadas);

int _setSueldo(eEmpleado* this,float sueldo);
int _getSueldo(eEmpleado* this,float* sueldo);

int _show(eEmpleado* this);
int _mapSueldo (void* this);
int _sortById(void* datoA, void* datoB);




