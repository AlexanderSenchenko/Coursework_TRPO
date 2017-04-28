#include <stdio.h>

int main()
{
	FILE *Matrix;
	//вводятся города которые будут использованны в функциях
	//char *city_1, *city_2;
	int matrix[5][5];

	Matrix = fopen("graph.txt", "r");
	if (Matrix == NULL) {
		return 0;
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			fscanf(Matrix, "%d", &matrix[i][j]);
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}
