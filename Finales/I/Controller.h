#ifndef Controller_H_INCLUDED
#define Controller_H_INCLUDED

LinkedList* controller_filter(LinkedList* pArrayList);
int controller_loadFromText(char* path , LinkedList* pArrayList);
int controller_loadFromBinary(char* path , LinkedList* pArrayList);
int controller_freeLinkedList(LinkedList* pArrayList);
int controller_add(LinkedList* pArrayList);
int controller_edit(LinkedList* pArrayList);
int controller_remove(LinkedList* pArrayList);
int controller_List(LinkedList* pArrayList);
int controller_sort(LinkedList* pArrayList);
int controller_saveAsText(char* path , LinkedList* pArrayList);
int controller_saveAsBinary(char* path , LinkedList* pArrayList);
int controller_principalMain();
int controller_sortMain();

#endif // Controller_H_INCLUDED

