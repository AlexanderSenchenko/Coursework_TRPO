#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int act, vertex1, vertex2, paths;
	Graph *g;

	g = graph_create(5);
	if (g == NULL) {
		graph_free(g);
	}

	printf("Меню\n");
	printf("1) Найти минимальное растояние между городами\n");
	printf("2) Найти максимальное растояние между городами\n");
	printf("3) Найти колличество различных путей между городами\n");
	printf("Выберите дейсвие: ");
	scanf("%d", &act);
	
	printf("Введите города между которыми будем совершать действие.\n");
	printf("Vertex 1: ");
	scanf("%d", &vertex1);
	printf("Vertex 2: ");
	scanf("%d", &vertex2);

	switch (act) {
	case 2:
		printf("\nМакимальное расстояние между %d и %d: %d\n", max_distance(g, vertex1, vertex2));
		printf("Path: ");
		print_max_path(g);
		break;
	case 3:
		paths = all_paths(vertex1, vertex2, g);
		printf("Кол-во путей из %d в %d: %d\n", vertex1, vertex2, paths);
		break;
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
