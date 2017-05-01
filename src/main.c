#include "graph.h"

int main()
{
	FILE *Matrix;
	int arr_city[5], act, numder_city = 0;
	Graph *v;

	Matrix = fopen("graph.txt", "r");
	if (Matrix == NULL) {
		return 0;
	}

	//Запись городов
	for (int i = 0; i < 5; i++) {
		fscanf(Matrix, "%d", &arr_city[i]);
		numder_city++;
	}

	v = graph_add(Matrix, numder_city);
	if (v == NULL) {
		graph_free(v);
	} 
	printf("\n%d %d\n", v->line, v->column);

	/*
	//Запсь расстояний
	for (int i = 0; i < 25; i++) {
		fscanf(Matrix, "%d", &matrix[i]);
	}
	*/

	//Менюшка
	printf("Выберите действие:\n");
	printf("1) Найти минимальное растояние между городами\n");
	printf("2) Найти максимальное растояние между городами\n");
	printf("3) Найти колличество различных путей между городами\n");
	scanf("%d", &act);
	
	if (act == 2) {
		int vertex1;
		int vertex2;
		printf("Введите города между которыми будем искать максимальный путь\n");
		scanf("%d", &vertex1);
		scanf("%d", &vertex2);
		printf("\nMax distacne %d\n", max_distance(*v, vertex1, vertex2));
	}
	/*//test get_item
	int test = get_item(0, 1, v->line);
	printf("\n%d\n", test);
	printf("%d\n", v->data[test]);

	
	//Вывод городов
	printf("\t");
	for (int i = 0; i < 5; i++) {
		printf("%d\t", arr_city[i]);
	}
	printf("\n");
	

	
	//Вывод мтрицы связность + столбец городов
	for (int i = 0; i < 25; i++) {
		//printf("%d\t", arr_city[i]);
		printf("%d\t", v->data[i]);
	}
	printf("\n");
	*/

	fclose(Matrix);

	return 0;
}
