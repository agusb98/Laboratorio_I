#ifndef Controller_H_INCLUDED
#define Controller_H_INCLUDED

LinkedList* controller_mapper(LinkedList* pArrayList);
LinkedList* controller_filter(LinkedList* pArrayList);
int controller_editIngrediente(LinkedList* pArraylist);
int controller_ListReceta(LinkedList* pArrayList);
int controller_addIngrediente(LinkedList* pArrayList);
int controller_loadFromText_Recetas(char* path, LinkedList* pArrayList);
int controller_addReceta(LinkedList* pArraylist, LinkedList* pArraylist_1);
int controller_removeIngrediente(LinkedList* pArraylist);
int controller_addReceta(LinkedList* pArrayList_1, LinkedList* pArrayList_2);
int controller_loadFromText(char* path , LinkedList* pArrayList);
int controller_loadFromBinary(char* path , LinkedList* pArrayList);
int controller_freeLinkedList(LinkedList* pArrayList);
int controller_remove(LinkedList* pArrayList);
int controller_List(LinkedList* pArrayList);
int controller_sort(LinkedList* pArrayList);
int controller_saveAsText(char* path , LinkedList* pArrayList);
int controller_saveAsBinary(char* path , LinkedList* pArrayList);
int controller_principalMain();
int controller_sortMain();

#endif // Controller_H_INCLUDED

