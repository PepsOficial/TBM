#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int a = 4, b, signo =1;
	double pi, suma;
	for (b = 1; b <= 999999; b+=2){
		suma = signo*((double)a/b);
		pi = pi + suma;
		signo = signo*-1;
	}
	printf("El valor de π es: \n%1.54f", pi);
	return 0;
}
