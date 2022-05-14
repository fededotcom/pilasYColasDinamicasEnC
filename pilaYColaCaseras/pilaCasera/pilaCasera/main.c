#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int telementop;

typedef struct pila{

    telementop elem;
    struct pila* sig;

}PILA;

typedef PILA* tpila;

int vaciap(tpila pila);
int llenap(tpila pila);
void consultap(tpila pila, telementop *pelem);
void iniciap(tpila *pila);
void ponep(tpila *pila, telementop pelem);
void sacap(tpila *pila, telementop *pelem);
void muestraP(tpila pila);

int main()
{
    tpila p;
    telementop pelem;
    iniciap(&p);
    printf("ingrese los numeros de la pila, ctrl + z para finalizar\n");
    while(scanf("%d",&pelem) == 1){
        ponep(&p,pelem);
    }
    printf("\nel resultado del vaciap es: %d\n",vaciap(p));
    printf("\nel resultado del llenap es: %d\n",llenap(p));
    consultap(p,&pelem);
    printf("\nel elemento del consultap es: %d\n",pelem);
    printf("la pila quedo conformada asi: \n");
    while(!vaciap(p)){
        sacap(&p,&pelem);
        printf("%d ",pelem);
    }

    return 0;
}

int vaciap(tpila pila){

    return pila == NULL;
}

int llenap(tpila pila){

    return 0;
}

void consultap(tpila pila, telementop *pelem){

    if(!vaciap(pila)){
        *pelem = pila->elem;
    }
}

void iniciap(tpila *pila){

    *pila=NULL;
}

void ponep(tpila *pila, telementop pelem){

    tpila aux = NULL;
    aux = (tpila)malloc(sizeof(PILA));
    aux->elem = pelem;
    aux->sig = NULL;
    if(*pila == NULL)
        *pila = aux;
    else{
        aux->sig = *pila;
        *pila = aux;
    }
}

void sacap(tpila *pila, telementop *pelem){

    tpila aux = NULL;
    if(!vaciap(*pila)){
        aux = *pila;
        *pelem = aux->elem;
        *pila = (*pila)->sig;
        free(aux);
    }
}

void muestraP(tpila pila){

    tpila aux;
    aux = pila;
    printf("\n\nLa lista esta conformada asi: \n");
    while(aux != NULL){
        printf("%d ",aux->elem);
        aux = aux->sig;
    }
    printf("\n");
}
