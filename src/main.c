#include "graph.h"

int main()
{
	int act;
	Graph *g;

	g = graph_create(5);
	if (g == NULL) {
		graph_free(g);
	} 

	printf("\n%d\n", g->sity);

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
		printf("\nMax distacne %d\n", max_distance(g, vertex1, vertex2));
	}

	//test all_wey
	printf("\n%d\n", all_wey(4, 5, g));

	/*
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

	return 0;
}
