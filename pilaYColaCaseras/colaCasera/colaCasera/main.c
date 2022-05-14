#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int telementoc;

typedef struct nodoc{

    telementoc elem;
    struct nodoc* sig;

}NODOC;

typedef NODOC* SCOLA;

typedef struct{

    SCOLA pri;
    SCOLA ult;

}TCOLA;

void iniciac(TCOLA* c);
int vaciac(TCOLA* c);
void consultac(TCOLA *c, telementoc *celem);
int llenac(TCOLA c);
void ponec(TCOLA* c, telementoc celem);
void sacac(TCOLA *c, telementoc *celem);


int main()
{
    telementoc celem;
    TCOLA cola;
    iniciac(&cola);
    printf("Ingrese los numeros a la cola dinamica: \n");
    while(!llenac(cola) && scanf("%d",&celem) == 1){
        ponec(&cola,celem);
    }
    consultac(&cola,&celem);
    printf("\n\nEl elemento del consultac es: %d\n\n",celem);
    printf("\n\nLa cola quedo conformada asi: \n");
    ponec(&cola,243);
    while(!vaciac(&cola)){
        sacac(&cola,&celem);
        printf("%d, ",celem);
    }
    return 0;
}

void iniciac(TCOLA *c){

    c->pri = NULL;
    c->ult = NULL;
}

int vaciac(TCOLA* c){

    return c->pri == NULL;
}

void consultac(TCOLA *c, telementoc *celem){

    if(c->pri != NULL)
        *celem = c->pri->elem;
}

int llenac(TCOLA c){

    return 0;
}

void ponec(TCOLA* c, telementoc celem){

    SCOLA aux;
    aux = (SCOLA)malloc(sizeof(NODOC));
    aux->elem = celem;
    aux->sig = NULL;
    if(c->pri == NULL){
        c->pri = aux;
        c->ult = aux;
    }
    else{
        c->ult->sig = aux;
        c->ult = aux;
    }
}

void sacac(TCOLA *c, telementoc *celem){

    SCOLA aux;
    if(c->pri != NULL){
        *celem = c->pri->elem;
        aux = c->pri;
        c->pri = c->pri->sig;
        free(aux);
    }
}
