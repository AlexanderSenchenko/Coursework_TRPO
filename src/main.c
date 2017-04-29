#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *Matrix;
	int matrix[5][5], arr_city[5];

	Matrix = fopen("graph.txt", "r");
	if (Matrix == NULL) {
		return 0;
	}

	for (int i = 0; i < 5; i++) {
		fscanf(Matrix, "%d[^\n]", &arr_city[i]);	
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			fscanf(Matrix, "%d", &matrix[i][j]);
		}
	}

	printf("\t");
	for (int i = 0; i < 5; i++) {
		printf("%d\t", arr_city[i]);
	}
	printf("\n");

	for (int i = 0; i < 5; i++) {
		printf("%d\t", arr_city[i]);
		for (int j = 0; j < 5; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}
