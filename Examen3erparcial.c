#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>
#include <stdbool.h>


typedef struct tCell{
	int payload;
	struct tCell *next;
} Cell;


Cell* agrega(Cell *base, int entrada){
	Cell* reg;
	reg=malloc(sizeof(Cell));
    if (reg == NULL) {
        printf("nulo");
        return NULL;
    }
	reg->payload=entrada;
    reg->next = NULL;
	Cell* cursor = base;
	while(cursor->next !=NULL){
		cursor=(Cell*)cursor->next;
	}
	cursor->next=reg;
	return base;
}

void imprime(Cell *raiz){
	while(raiz->next !=NULL){
		printf("%d->",raiz->next->payload);
		raiz=raiz->next;
	}
}

Cell pop(Cell *ruta){
	if(ruta->next==NULL){return *ruta;}
	Cell* cursor=ruta;
	while(((Cell*)cursor->next)->next !=NULL){
		//printf("%d", cursor->payload);
		cursor=(Cell*)cursor->next;
		//printf("%d", cursor->payload);
	}
	//printf("%d", cursor->payload);
	free((void *)cursor->next);
	//printf("%d", cursor->payload);
	cursor->next=NULL;
	return *ruta;
}

Cell erase(Cell *celda){
	while(celda->next!=NULL)
		pop(celda);
	return *celda;
}

Cell opciones(Cell *base){
	int opcion=0;
	bool ev=false;
	int num;
	while(ev==false){
		printf("Dame una opción: \n0 - Agrega nodo\n1 - Borra último nodo\n2 - Imprime lista\n3 - Salir\n");
		scanf("%d", &opcion);
		if(opcion==0){
			
			//printf("%d", base->payload);
			printf("Dame un numero\n");
			scanf("%d", &num);	
			//printf("%d", base->payload);
			agrega(base, num);
			//printf("%d", ((Cell*)base->next)->payload);
			//imprime(base); 
		} else if(opcion==1){
			pop(base);
			printf("Último elemento borrado\n");
		} else if(opcion==2){
			printf("imprimiendo la lista\n");
			imprime(base);
		} else if(opcion==3){
			//imprime(base);
			erase(base);
			ev=true;
		} else {
			printf("Error, por favor ingrese una opcion valida\n");
		}
	}
	return *base;
}

int main(int argc, char* argv[]) {
	Cell *root;
	root = (Cell *)malloc(sizeof(Cell));
	root->payload = -1;
    root->next = NULL;
	opciones(root);
	return 0;
}
