#include "librerias.h"

int kSize=15;

void imprimearreglo(int* arreglo, int size) {
	for(int y=0; y<size; ++y) {
		printf("%d     ", arreglo[y]);
	}
	printf("\n");
}


void swap(int* k, int* e){
	double f;
	f=*k;
	*k=*e;
	*e=f;
}
int hoare(int a[], int g, int s) {
	int x=a[g];
	int y=g-1;
	int w=s;
	while (1) {
		do w--;
		while (a[w]>x);
		do y++;
		while (a[y]<x);
		if (y<w) {
			swap(&a[y], &a[w]);
		} else {
			return w+1;
		}
	}
}

void quicksort(int a[],int size, int inicio, int fin) {
	int h;
	if (fin-inicio<2) return;
	h=hoare(a, inicio, fin);
	quicksort(a,kSize, inicio, h);
	imprimearreglo(a, kSize);
	quicksort(a,kSize, h, fin);
	imprimearreglo(a, kSize);
}
int main(int argc, char* argv[]) {
	int arreglo[] = {121,223,69,7,11,4,10,5,6,254,3506,152,304,52,23};
	imprimearreglo(arreglo, kSize);
	quicksort(arreglo, kSize, 0, kSize);
	imprimearreglo(arreglo, kSize);
			return 0;
}
