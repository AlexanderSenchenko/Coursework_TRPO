#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include "print.h"
#include "vald.h"

int get_index(int vertex, Graph *g);

int main()
{
	int act, vertex1, vertex2, paths, vert1, vert2;
	Graph *g;
	if ((g = input_validation()) == NULL) {
		return 0;
	}

	Results *res = results_create(g);


	menu();//Menu
	if (check_scan(&act, &vertex1, &vertex2, g, &vert1, &vert2) == -1) {
		graph_free(g);
		results_free(res);
		return 0;
	}	
	switch (act) {
	case 1:
		printf("Минимальное расстояние между %d и %d: %d\n", vertex1, vertex2, min_distance(g, vert1, vert2, res));
		printf("Paths: %d\n", res->count);
		output_path(g, res, act);
		break;
	case 2:
		printf("Максимальное расстояние между %d и %d: %d\n", vertex1, vertex2, max_distance(g, vert1, vert2, res));
		printf("Paths: %d\n", res->count);
		output_path(g, res, act);
		break;
	case 3:
		paths = all_paths(vert1, vert2, g, res);
		printf("Кол-во путей из %d в %d: %d\n", vertex1, vertex2, paths);
		output_path(g, res, act);
		break;
	case 4:
	       	create_graph_image(g);
		system("dot -Tpng graph.gv -o graph.png");
		system("xdg-open graph.png ");
		break;
	case 5:
	       	graph_free(g);
		results_free(res);
		return 0;
	default:
		break;
	}

	graph_free(g);
	results_free(res);
	return 0;
}
