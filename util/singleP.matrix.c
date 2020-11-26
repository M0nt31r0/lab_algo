#include <stdio.h>
#include <stdlib.h>

// M x N matrix
#define M 4
#define N 5

// Dynamically Allocate Memory for 2D Array
int main()
{
	// dynamically allocate memory of size M*N
	int* A = (int*)malloc(M * N * sizeof(int));

	if (A == NULL)
	{
		fprintf(stderr, "Out of memory");
		exit(0);
	}

	// assign values to allocated memory
	for (int r = 0; r < M; r++)
		for (int c = 0; c < N; c++)
			*(A + r*N + c) = rand() % 100;

	// print the 2D array
	for (int r = 0; r < M; r++)
	{
		for (int c = 0; c < N; c++)
			printf("%d ", (A + r*N)[c]);	// or *(A + r*N + c)

		printf("\n");
	}

	// deallocate memory
	free(A);

	return 0;
}
