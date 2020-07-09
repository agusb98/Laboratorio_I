#ifndef empleados_h_INCLUDED
#define empleados_h_INCLUDED

#endif

typedef struct
{
    int id;
    char nombre[50];
    char empleo[50];
    int edad;
    int horasTrabajadas;
    float sueldo;

}eEmpleado;

eEmpleado* _new();
eEmpleado* _setters(char* var_1,char* var_2, char* var_3, char* var_4, char* var_5, char* var_6);


int _show(eEmpleado* this);
int _getters(eEmpleado* this, int* var_1, char* var_2, char* var_3, int* var_4, int* var_5, float* var_6);

int _setId(eEmpleado* this,int id);
int _getId(eEmpleado* this,int* id);

int _setNombre(eEmpleado* this,char* nombre);
int _getNombre(eEmpleado* this,char* nombre);

int _setEmpleo(eEmpleado* this,char* empleo);
int _getEmpleo(eEmpleado* this,char* empleo);

int _setEdad(eEmpleado* this,int edad);
int _getEdad(eEmpleado* this,int* edad);

int _setHorasTrabajadas(eEmpleado* this,int horasTrabajadas);
int _getHorasTrabajadas(eEmpleado* this,int* horasTrabajadas);

int _setSueldo(eEmpleado* this,float sueldo);
int _getSueldo(eEmpleado* this,float* sueldo);

int _sortById(void* datoA, void* datoB);
int _sortByNombre(void* punteroA, void* punteroB);

int laQueMapea(void* this);
int laQueFiltra(void* this);

