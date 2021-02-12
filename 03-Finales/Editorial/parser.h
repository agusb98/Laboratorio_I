#include "LinkedList.h"

#ifndef parser_H_INCLUDED
#define parser_H_INCLUDED

int parser_FromText(FILE* pFile , LinkedList* pArrayList);
int parser_FromBinary(FILE* pFile , LinkedList* pArrayList);

#endif // parser_H_INCLUDED

