#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    int tam;

    if(this != NULL)
    {
        tam= this->size;
        returnAux = tam;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode=NULL;
    int i;

    if(this != NULL && nodeIndex>=0 && ll_len(this) > nodeIndex)
    {
        pNode= this->pFirstNode;

        for(i=0; pNode != NULL && i<nodeIndex; i++)
        {
            pNode = pNode->pNextNode;
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int retorno = -1;

    if(this != NULL && nodeIndex>= 0 &&  nodeIndex<=ll_len(this))
    {
        Node* pNodo=NULL;
        Node* auxNodo=(Node*)malloc(sizeof(Node));

        if(auxNodo != NULL)
        {
            if(nodeIndex !=0)
            {
                pNodo = getNode(this, nodeIndex-1);
                auxNodo->pNextNode= pNodo->pNextNode;
                pNodo->pNextNode= auxNodo;
                auxNodo->pElement= pElement;
                this->size++;
                retorno=0;
            }
            else
            {
                auxNodo->pNextNode= this->pFirstNode;
                this->pFirstNode= auxNodo;
                auxNodo->pElement= pElement;
                this->size++;
                retorno=0;
            }
        }
    }

    return retorno;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
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
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int retorno = -1;

    if(this != NULL)
    {
        if(addNode(this, this->size, pElement)==0)
        {
            retorno=0;
        }
    }

    return retorno;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* retorno = NULL;
    Node* pNodo= NULL;

    if(this!= NULL && index >= 0 && ll_len(this)>= index)
    {
        pNodo= getNode(this, index);
        if(pNodo != NULL)
        {
            retorno= pNodo->pElement;
        }
    }

    return retorno;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int retorno = -1;
    Node* pNodo= NULL;

    if(this != NULL && index >=0 && ll_len(this)>=0)
    {
        pNodo=getNode(this, index);

        if(pNodo != NULL)
        {
            pNodo->pElement= pElement;
            retorno= 0;
        }
    }

    return retorno;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int retorno = -1;
    Node* pNode= NULL;
    Node* nodoAnterior= NULL;

    if(this != NULL && index >= 0 && ll_len(this)> index)
    {
        pNode= getNode(this, index);
        nodoAnterior=getNode(this, index-1);
        retorno=0;

        if(pNode != NULL)
        {
            if(nodoAnterior != NULL)
            {
                nodoAnterior->pNextNode= pNode->pNextNode;
            }
            else
            {
                this->pFirstNode= NULL;
            }

            this->size--;
            free(pNode);
        }

    }

    return retorno;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int retorno = -1;
    Node* pNode= NULL;
    int i;

    if(this != NULL)
    {
        for(i=0; i< ll_len(this); i++)
        {
            if(ll_len(this)>=0)
            {
                getNode(this, i);
                free(pNode);
                this->size--;
                retorno=0;
            }
        }
    }

    return retorno;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int retorno = -1;

    if(this!= NULL)
    {
        free(this);
        retorno=0;
    }

    return retorno;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int retorno= -1;
    void* indexElement= NULL;
    int i;

    if(this != NULL)
    {
        for(i=0; i< ll_len(this); i++)
        {
            indexElement=ll_get(this, i);

            if(indexElement== pElement)
            {
                retorno= i;
                break;
            }
        }
    }

    return retorno;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        if(this->pFirstNode == NULL)
        {
            retorno= 1;
        }
        else
        {
            retorno= 0;
        }
    }

    return retorno;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int retorno = -1;

    if(this != NULL && index>= 0 && ll_len(this)>=index)
    {
        if(addNode(this, index, pElement)==0);
        {
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* retorno = NULL;
    Node* pNodo= NULL;

    if(this != NULL && index >=0 && ll_len(this)> index)
    {
        pNodo= ll_get(this, index);
        retorno= pNodo;
        ll_remove(this, index);
    }


    return retorno;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int retorno= -1;

    if(this != NULL)
    {
        if(ll_indexOf(this,pElement) == -1)
        {
            retorno = 0;
        }
        else
        {
            retorno = 1;
        }
    }
    return retorno;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int retorno = -1;
    void* element = NULL;
    int i;

    if(this != NULL && this2 != NULL)
    {
        retorno = 1;
        for(i=0; i<ll_len(this2); i++)
        {
            element = ll_get(this2, i);
            if(!ll_contains(this, element))
            {
                retorno= 0;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* nuevoElemento= NULL;
    int i;

    if(this != NULL && from >= 0 && ll_len(this)> from && to >= from && ll_len(this)>= to)
    {
        cloneArray= (LinkedList*)malloc(sizeof(LinkedList));

        if(cloneArray != NULL)
        {
            for(i=from; i<to; i++)
            {
                nuevoElemento=ll_get(this, i);

                if(nuevoElemento!= NULL)
                {
                    {
                        ll_add(cloneArray, nuevoElemento);
                    }
                }
            }
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    Node* pNodo= NULL;
    int i;

    if(this != NULL)
    {
        cloneArray= (LinkedList*)malloc(sizeof(LinkedList));

        if(cloneArray!=NULL)
        {
            for(i=0; i< ll_len(this); i++)
            {
                pNodo= ll_get(this, i);
                addNode(cloneArray, i, pNodo);
            }
        }
    }

    return cloneArray;
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
    int retorno =-1;
    int i;
    Node* pElemento= NULL;
    Node* pElementoAnterior= NULL;
    void* aux;
    int seguir;
    int resultadoEsperado=1;

    if(this != NULL && pFunc!= NULL && order >= 0 && order<=1)
    {
        retorno=0;

        do
        {
            seguir= 0;

            if(order)
            {
                resultadoEsperado= -1;
            }

            for(i=0; i< ll_len(this); i++)
            {
                pElemento= getNode(this, i);
                pElementoAnterior= getNode(this, i-1);

                if(pElemento !=NULL && pElementoAnterior != NULL)
                {

                    if(pFunc(pElemento->pElement, pElementoAnterior->pElement)== resultadoEsperado)
                    {

                        aux= pElemento->pElement;
                        pElemento->pElement= pElementoAnterior->pElement;
                        pElementoAnterior->pElement= aux;

                        seguir= 1;
                    }
                }
            }


            }while(seguir);

    }

    return retorno;

}

