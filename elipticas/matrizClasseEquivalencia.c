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
void assigning(int mod, int col, int first, int count, int classes[mod][col]);
void printing(int mod, int col, int classes[mod][col]);

int main(){
	int op, mod, col;
	printf("-----MENU-----\n");
	printf("Options\n1 - Positive and negative sides\n2 - Positive side\n3 - Negative side\n4 - Help\n5 - Exit\nChoice: ");
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
			printf("This is a basic C program to help the visualization of the equivalence classes of a desired number n.\n");
			printf("There exist n - 1 equivalence classes. ");
			printf("This will always keep the main column in the matrix.\n");
			printf("The first option will print a desired odd number of columns. The second, only the positive side with any number of columns.");
			printf(" The third, the negative with any nymber of columns.\n");
			printf("<mod> means the desired number n. <col> means the number of columns.\n\n");
			main();
		case 5:
			exit(1);
		default:
			printf("Error\n");
			break;
	}

	return 0;
}

void mixMatrix(int mod, int col){
	if(col % 2 != 1){
		printf("Number of columns must be odd.\n\n");
		main();
	}
	int classes[mod][col];

	int aux = floor(col/2);
	int first = 0; 

	for(int i=0; i<aux; i++)
		first -= mod;

	int count = first;

	assigning(mod, col, first, count, classes);

	printing(mod, col, classes);

	exit(1);
}

void positiveSide(int mod, int col){
	int first = 0, count = 0;
	int classes[mod][col];

	assigning(mod, col, first, count, classes);

	printing(mod, col, classes);

	exit(1);
}

void negativeSide(int mod, int col){
	int classes[mod][col];

	int first = 0;
	for(int i=0; i<col-1; i++)
		first -= mod;

	int count = first;
	
	assigning(mod, col, first, count, classes);

	printing(mod, col, classes);

	exit(1);
}

void assigning(int mod, int col, int first, int count, int classes[mod][col]){
	for(int i=0; i<mod; i++){
		if(i > 0) first++;
		count = first;
		for(int j=0; j<col; j++){
			classes[i][j] = count;
			count += mod;
		}
	}
}

void printing(int mod, int col, int classes[mod][col]){
	printf("Equivalence classes (mod %d) with %d columns:\n", mod, col);

	for(int i=0; i<mod; i++){
		printf("(... ");
		for(int j=0; j<col; j++){
			printf("%10d,", classes[i][j]);
		}
		printf("          ...)\n");
	}
}