/*
 * C program to calculate the congruence matrix of a giver number.
 * Compile: gcc -Wall matrizClasseEquivalencia.c -lm -o matrizClasseEquivalencia.x
 * Run: $ ./matrizClasseEquivalencia.x <mod> <col>
 * */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
	if(argc != 3){
		printf("Error! Run: $./matrizClasseEquivalencia <mod> <col>\n");
		exit(1);
	}

	//Init
	int mod = atoi(argv[1]);
	int col = atoi(argv[2]); //Number of columns
	if(col % 2 != 1){
		printf("Number of columns must be odd\n");
		exit(1);
	}
	//int classes[mod-1][col];

	//Finding the first element in the matrix
	int aux = floor(col/2);
	int first = 0; //Element in the 00 position in the matrix
	for(int i=0; i<aux; i++){
		first -= mod;
	}
	printf("\n%d", first);
	
	//Finding the last element in the matrix
	int last = mod-1; //Element in the ij position in the matrix
	for(int i=0; i<aux; i++){
		last += mod;
	}
	printf("\n%d\n", last);


	return 0;
}
