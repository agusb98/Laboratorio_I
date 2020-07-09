#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char description[51];

} eSector;

typedef struct
{
    int id;
    int idSector;
    int isEmpty;
    float salary;
    char name[51];
    char lastName[51];

} eEmployee;

#endif // ARRAYEMPLOYEES_H_INCLUDED

int initEmployees(eEmployee* list, int len);

int addEmployee(eEmployee* list, int len, int id, char name[],char lastName[],float salary,int sector);

int findEmployeeById(eEmployee* list, int len,int id);

int removeEmployee(eEmployee* list, int len, int id);

int sortEmployees(eEmployee* list, int len, int order);

int printEmployees(eEmployee* list, int list_len, eSector* sector, int sector_len);

void printEmployeer(eEmployee* x, eSector* sector);

void printSectores(eSector* sectores, int len);

void printSector(eSector* x);

int findEmptyPlace(eEmployee* list, int len);

int findNextId(eEmployee* list, int len);

int getIdInList(eEmployee* list, int len, eSector* sector, int sector_len);

int editEmployee(eEmployee* list, int len, int pos, eSector* sector,int sector_len);

int reportEmployees(eEmployee* list, int len, int opt);

void hardcoreEmployees(eEmployee y[]);

void hardcoreSectores(eSector y[]);

int findSectorById(eSector* x, int len,int id);
