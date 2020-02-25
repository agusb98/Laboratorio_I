#include "cars.h"

#ifndef INCLUDE_H_MARCA
#define INCLUDE_H_MARCA

typedef struct
{
    int id;
    char description[21];

}eMarca;

int marca_init(eMarca marca[], int len);

int marca_getIdInList(eMarca marca[], int len);

void marca_hardcore(eMarca y[]);

int findMarcaById(eMarca marca[], int len,int id);

void printMarca(eMarca marca);

void printMarcas(eMarca marca[], int len);

void marca_hardcore(eMarca y[]);

#endif // INCLUDE_H_MARCA

