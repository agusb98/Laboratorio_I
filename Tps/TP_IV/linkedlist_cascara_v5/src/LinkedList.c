#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);
/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = (LinkedList*)malloc(sizeof(LinkedList));  //Solicito memoria determinada por LinkedList y lo asigna a this
    if (this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if (this != NULL && this->size >= 0)
        returnAux = this->size;     //Asigna a returnAux el valor asociado a la LinkedList en size
    return returnAux;
}
/** \brief  Obtiene un nodo de la lista
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    if (this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)) //Entra si el puntero es distinto a NULL y la posicion esta dentro de los parametros del LinkedList
    {
        pNode = this->pFirstNode;   //Asigno la direccion de memoria del primer nodo a pNode
        for (int i=0; i<nodeIndex; i++)
            pNode = pNode->pNextNode; //Asigno la direccion de memoria del siguiente nodo a pNode
    }
    return pNode;
}
/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}
/** \brief Agrega y enlaza un nuevo nodo a la lista
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser cobreakntenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    int returnAux = -1; //Variable a retornar por la funcion
    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)) //Verifico que this no sea NULL, el indice del nodo sea positivo y mayor al tamanio del LinkedList
    {
        Node* newNode = (Node*)malloc(sizeof(Node)); //Puntero a newNode, solicito memoria dinamicamente para crearlo
        if(!nodeIndex) //Si el indice es 0, es el primer elemento del array
        {
            newNode->pNextNode = this->pFirstNode; //Le asigno al pNextNode del nuevo nodo la direccion del primer nodo
            this->pFirstNode = newNode; //Se la asigno a pFirstNode
        }
        else //Indice entre 1 y el largo
        {
            Node* lastNode = getNode(this, nodeIndex-1); //Asigno al nodo anterior el nodo del indice anterior al indice ingresado por parametro.
            Node* nextNode = lastNode->pNextNode;        //Asigno al siguiente el valor del nodo a agregar.

            newNode->pNextNode = nextNode;               //asigno al nuevo nodo el valor del siguiente.
            lastNode->pNextNode = newNode;               //Asigno al anterior el nuevo nodo.
        }
        this->size++; //Aumento en 1 el tamanio
        newNode->pElement = pElement; //Le asigno el tamanio de elemento al nuevo nodo
        returnAux = 0; //Cambio el flag returnAux a 0
    }
    return returnAux; //Retorno el valor de la variable a la funcion
}
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}
/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;     //Variable a retornar por la funcion
    if(this != NULL )
    {
        addNode(this, ll_len(this), pElement);
        returnAux = 0;
    }
    return returnAux;
}
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 */
void* ll_get(LinkedList* this, int index)
{
    void* pElement = NULL; //Puntero a nodo inicializado en NULL
    if (this != NULL && getNode(this, index) != NULL) //Entra si this y la direccion de memoria que retorne getNode son distintas a NULL
        pElement = (getNode(this, index))->pElement;   //Asigno a pElement el valor del elemento que tiene el nodo
    return pElement;
}
/** \brief Modifica un elemento de la lista
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int flag = -1;
    if (this != NULL && getNode(this, index) != NULL) //Entra si this y la direccion de memoria que retorne getNode son distintas a NULL
    {
        (getNode(this, index))->pElement = pElement;//Asigno al nodo el valor del elemento ingresado como parametro
        flag = 0;
    }
    return flag;
}
/** \brief Elimina un elemento de la lista
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 */
int ll_remove(LinkedList* this, int index)
{
    int flag = -1;
    if (this != NULL && index >= 0 && index < ll_len(this))
    {
        if (!index) //Entra si el indice es igual a 0
            this->pFirstNode = NULL;
        else
            getNode(this, index-1)->pNextNode = getNode(this, index)->pNextNode;
        //free(getNode(this, index)); //Libero el Nodo
        this->size--;               //Reduzco el size en 1
        flag = 0;
    }
    return flag;
}
/** \brief Elimina todos los elementos de la lista
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if (this != NULL)
    {
        for (int i=0; i<ll_len(this); i++)
            ll_remove(this, i);  //Recorre todos los datos y los elimina en cada iteracion
        returnAux = 0;
    }
    return returnAux;
}
/** \brief Elimina todos los elementos de la lista y la lista
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if (this != NULL)
    {
        ll_clear(this); //elimino todos los empleados
        free(this);     //libera la direccion de memoria
        returnAux = 0;
    }
    return returnAux;
}
/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int index = -1;
    if (this != NULL)  //con pElement != NULL, falla el programa
    {
        for(int i=0; i<ll_len(this); i++)
        {
            if (ll_get(this, i) == pElement)
            {
                index = i;  //asigna a index el valor de la posicion del elemento
                break;
            }
        }
    }
    return index;
}
/** \brief Indica si la lista esta o no vacia
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 */
int ll_isEmpty(LinkedList* this)
{
    int flag = -1;
    if (this != NULL)
    {
        if (!ll_len(this))
            flag = 1;
        else
            flag = 0;
    }
    return flag;
}
/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this, index, pElement);
}
/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 */
void* ll_pop(LinkedList* this, int index)
{
    void* aux = ll_get(this, index);  //Obtiene el puntero pElement
    ll_remove(this, index);
    return aux;
}
/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int flag= -1;   //Bandera indicando que contiene elemento
    if (this != NULL)
    {
        if (ll_indexOf(this, pElement) == -1)   //Condicional, si la funcion no encuentra indice
            flag = 0;
        else
            flag = 1;
    }
    return flag;
}
/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this, LinkedList* this2)
{
    int flag= -1;
    if (this != NULL && this2 != NULL)
    {
        flag = 1;
        for (int i=0; i<ll_len(this); i++)
        {
            flag = ll_contains(this2, ll_get(this, i)); //Asigno a flag lo que retorna la funcion ll_contains()
            if(flag == -1 || flag == 0)
            {
                break;  //Rompo bucle si flag es (-1) o (0)
            }
        }
    }
    return flag;
}
/** \brief Crea y retorna una nueva lista con los elementos indicados
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this, int from, int to)
{
    void* subList = NULL; //asigno al puntero subList la no direccion de memoria
    if (this != NULL && from >= 0 && to <= ll_len(this))
    {
        subList = ll_newLinkedList();    //le asigno una nueva lista a subList
        if (subList != NULL)
        {
            for (int i=from; i<to; i++)
                ll_add(subList, ll_get(this, i));//Le paso como parametro el valor del elemento a ll_add y lo enlaza con los demas nodos
        }
    }
    return subList;
}
/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    return ll_subList(this, 0, ll_len(this));
}
/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;
    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
        for(int i=0; i<(ll_len(this)-1); i++)
        {
            void* pNodeUno = ll_get(this, i);     //Asigno a pNodeUno la direccion que retorna ll_get()
            for(int j=i+1; j<ll_len(this); j++)
            {
                void* pNodeDos = ll_get(this, j); //Asigno a pNodeDos la direccion que retorna ll_get()
                if(order)
                {
                    if(pFunc(pNodeUno, pNodeDos) > 0) //Aplico Burbujeo si la funcion llamada es mayor a cero
                    {
                        void* pNodeAux = pNodeDos;
                        pNodeDos = pNodeUno;
                        pNodeUno = pNodeAux;
                    }
                }
                else
                {
                    if(pFunc(pNodeUno, pNodeDos) < 0) //Aplico Burbujeo si la funcion llamada es menor a cero
                    {
                        void* pNodeAux = pNodeUno;
                        pNodeUno = pNodeDos;
                        pNodeDos = pNodeAux;
                    }
                }
                ll_set(this, i, pNodeUno);  //Hago el swap en la lista
                ll_set(this, j, pNodeDos);
            }
        }
        returnAux = 0;
    }
    return returnAux;
}
/** \brief Filtra los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param this LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* filterList = NULL;  //Inicializo el puntero filterList en NULL
    if (this != NULL && pFunc != NULL )
    {
        filterList = ll_newLinkedList();    //Le asigno a filterList un nuevo linkedList
        if (filterList != NULL)
        {
            for (int i=0; i<ll_len(this); i++)
            {
                if (pFunc(ll_get(this, i)))                  //Condicional de la funcion a escoger
                    ll_add(filterList, ll_get(this, i));    //Asigna empleados del linkedList a la nueva lista
            }
        }
    }
    return filterList;
}
