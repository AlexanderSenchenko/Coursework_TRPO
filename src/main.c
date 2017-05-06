#include "graph.h"

int main()
{
	int act, vertex1, vertex2, paths;
	Graph *g;

	g = graph_create(5);
	if (g == NULL) {
		graph_free(g);
	}


	//Менюшка
	printf("Выберите действие:\n");
	printf("1) Найти минимальное растояние между городами\n");
	printf("2) Найти максимальное растояние между городами\n");
	printf("3) Найти колличество различных путей между городами\n");
	scanf("%d", &act);
	
	printf("Введите города между которыми будем совершать действие\n");
	printf("Vertex 1: ");
	scanf("%d", &vertex1);
	printf("Vertex 2: ");
	scanf("%d", &vertex2);

	switch (act) {
	case 2:
		printf("\nMax distacne %d\n", max_distance(g, vertex1, vertex2));
	case 3:
		paths = all_paths(vertex1, vertex2, g);
		printf("Кол-во путей из %d в %d: %d\n", vertex1, vertex2, paths);
	default:
		break;
	}

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
