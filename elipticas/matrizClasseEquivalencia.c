/*
 * C program to calculate the congruence matrix of a giver number.
 * Compile: gcc -Wall matrizClasseEquivalencia.c -lm -o matrizClasseEquivalencia.x
 * Run: $ ./matrizClasseEquivalencia.x
 * */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mixMatrix(int mod, int col);
void positiveSide(int mod, int col);
void negativeSide(int mod, int col);

int main(){
	int op, mod, col;
	printf("Options\n1 - Mixed matrix (negative and positive)\n2 - Positive side\n3 - Negative side\n4 - Exit\nChoice: ");
	scanf("%d", &op);

	switch(op){
		case 1:
			printf("Enter <mod> and <col>:\n");
			scanf("%d %d", &mod, &col);
			mixMatrix(mod, col);
			break;
		case 2:
			printf("Enter <mod> and <col>:\n");
			scanf("%d %d", &mod, &col);
			positiveSide(mod, col);
			break;
		case 3:
			printf("Enter <mod> and <col>:\n");
			scanf("%d %d", &mod, &col);
			negativeSide(mod, col);
			break;
		case 4:
			exit(1);
		default:
			printf("Error\n");
			break;
	}

	return 0;
}

void mixMatrix(int mod, int col){
	//Init
	if(col % 2 != 1){
		printf("Number of columns must be odd.\n\n");
		main();
	}
	int classes[mod][col];

	//Finding the first element in the matrix
	int aux = floor(col/2);
	int first = 0; //Element in the 00-th position in the matrix

	for(int i=0; i<aux; i++)
		first -= mod;

	int count = first; //This will help the correct assigning

	//Assigning
	for(int i=0; i<mod; i++){
		if(i > 0) first++;
		count = first;
		for(int j=0; j<col; j++){
			classes[i][j] = count;
			count += mod;
		}
	}

	//Printing
	for(int i=0; i<mod; i++){
		for(int j=0; j<col; j++){
			printf("%d\t", classes[i][j]);
		}
		printf("\n");
	}

	exit(1);
}

void positiveSide(int mod, int col){
	//Init
	int classes[mod][col];

	//First element
	int first = 0, count = 0;

	//Assingning 
	for(int i=0; i<mod; i++){
		if(i > 0) first++;
		count = first;
		for(int j=0; j<col; j++){
			classes[i][j] = count;
			count += mod;
		}
	}

	//Printing
	for(int i=0; i<mod; i++){
		for(int j=0; j<col; j++){
			printf("%d\t", classes[i][j]);
		}
		printf("\n");
	}

	exit(1);
}

void negativeSide(int mod, int col){
	//Init
	int classes[mod][col];

	//Finding the first element in the matrix
	int first = 0;
	for(int i=0; i<col-1; i++)
		first -= mod;

	int count = first;

	//Assigning
	for(int i=0; i<mod; i++){
		if(i > 0) first++;
		count = first;
		for(int j=0; j<col; j++){
			classes[i][j] = count;
			count += mod;
		}
	}

	//Printing
	for(int i=0; i<mod; i++){
		for(int j=0; j<col; j++){
			printf("%d\t", classes[i][j]);
		}
		printf("\n");
	}

	exit(1);
}
