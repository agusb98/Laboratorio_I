#ifndef EJECT_H_INCLUDED
#define EJECT_H_INCLUDED
#include "ArrayEmployees.h"

#endif // EJECT_H_INCLUDED

int eject_addEmployee(eEmployee* list, int list_len, eSector* sector, int sector_len);

int eject_deleteEmployee(eEmployee* list, int list_len, eSector* sector, int sector_len);

int principalMain();

int editMain();

int eject_editEmployee(eEmployee* list, int list_len, eSector* sector, int sector_len);

int eject_reportEmployees(eEmployee* list, int len, eSector* sector, int sector_len);

float acumSalaryies(eEmployee* list, int len);

float contActiveEmployees(eEmployee* list, int len);

int contSalaryiesUpProm(eEmployee* list, int len, float prom);
