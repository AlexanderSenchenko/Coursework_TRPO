#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int act, vertex1, vertex2, paths;
	Graph *g;

	g = graph_create();
	if (g == NULL) {
		graph_free(g);
	}

	Results *res = results_create(g);

	printf("Меню\n");
	printf("1) Найти минимальное растояние между городами\n");
	printf("2) Найти максимальное растояние между городами\n");
	printf("3) Найти колличество различных путей между городами\n");
	printf("4) Сформировать и вывести граф\n");
	printf("Выберите дейсвие: ");
	scanf("%d", &act);
	
	printf("Введите города между которыми будем совершать действие.\n");
	printf("Vertex 1: ");
	scanf("%d", &vertex1);
	printf("Vertex 2: ");
	scanf("%d", &vertex2);

	switch (act) {
	case 1:
		printf("Минимальное расстояние между %d и %d: %d\n", vertex1, vertex2, min_distance(g, vertex1, vertex2, res));
		printf("Paths: %d\n", res->count);
		output_path(g, res, act);
		break;
	case 2:
		printf("Максимальное расстояние между %d и %d: %d\n", vertex1, vertex2, max_distance(g, vertex1, vertex2, res));
		printf("Paths: %d\n", res->count);
		output_path(g, res, act);
		break;
	case 3:
		paths = all_paths(vertex1, vertex2, g, res);
		printf("Кол-во путей из %d в %d: %d\n", vertex1, vertex2, paths);
		output_path(g, res, act);
		break;
	case 4:
	       	create_graph_image(g);
		system("dot -Tpng graph.gv -o graph.png");
		system("xdg-open graph.png ");
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
	graph_free(g);
	results_free(res);
	return 0;
}
