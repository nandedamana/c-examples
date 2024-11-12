// 2024-11-12

// In C, you can store an `m`x`n` matrix as a 2-D array `arr[m][n]`, accessing 
// element [i, j] as `arr[i][j]`.
//
// You can also store it as a 1-D array of `m * n` elements, accessing the 
// element [i, j] as `arr[i * n + j]` (remember, `n` is the number of elements 
// per row).
//
// Another way is to store each row in a different array, and have a master 
// array contain all these pointers. This program demonstrates that method.

#include <stdio.h>
#include <stdlib.h>

const int ROWS = 4;
const int COLS = 3;

int main()
{
	// Allocating ROWS _pointers_ (not integers)
	int **mat = malloc(ROWS * sizeof(int *));
	if(!mat) { perror(NULL); exit(EXIT_FAILURE); }

	for(int i = 0; i < ROWS; i++) {
		// Allocating COLS _integers_ (not pointers)
		mat[i] = malloc(COLS * sizeof(int));
		if(!mat[i]) { perror(NULL); exit(EXIT_FAILURE); }
	}

	// Filling up with 0-11
	for(int i = 0; i < ROWS; i++)
		for(int j = 0; j < COLS; j++)
			mat[i][j] = i * COLS + j;

	// Printed using subscripts
	for(int i = 0; i < ROWS; i++) {
		for(int j = 0; j < COLS; j++)
			printf("%3d ", mat[i][j]);

		putchar('\n');
	}

	putchar('\n');

	// Printed using pointers
	for(int **rowptr = mat; rowptr < mat + ROWS; rowptr++) {
		for(int *cellptr = *rowptr; cellptr < *rowptr + COLS; cellptr++)
			printf("%3d ", *cellptr);

		putchar('\n');
	}

	// Don't forget to free each row.
	for(int i = 0; i < ROWS; i++)
		free(mat[i]);

	free(mat);

	return 0;
}
