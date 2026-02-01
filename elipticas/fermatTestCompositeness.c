/*
 * Naive programm to make Fermat Test of Compositeness
 * Compile: $ gcc -Wall fermatTestCompositeness.c -o fermatTestCompositeness.x
 * Run: $ ./fermatTestCompositeness.x <n>
 * */

#include <stdio.h>
#include <stdlib.h>
#define ll long long

int int_pow(ll base, int exp){
	ll ans = 1;

	for(ll i=0; i<exp; i++)
		ans *= base;

	return ans;
}

int main(int argc, char *argv[]){ //Traduzido para Python.
	if(argc != 2){
		printf("Error. Run: $ ./fermatTestCompositeness.x <n>\n");
		exit(1);
	}

	int n = atoi(argv[1]);
	int count = 0; //Congruence

	for(ll a=1; a<n; a++){
		ll z = int_pow(a, n-1);
		//printf("%lld\n", z);
		if(z != 1) count++;
		
	}

	if(count != 0)
		printf("Composto! %d\n", count);
	else
		printf("Primo! %d\n", count);

	return 0;
}
