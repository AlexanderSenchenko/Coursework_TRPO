#include "graph.h"
#include <stdio.h>
#include "print.h"

int get_item(int i, int j, Graph *g);
int get_index(int vertex, Graph *g);

void menu()
{
	printf("Меню\n");
	printf("1) Найти минимальное растояние между городами\n");
	printf("2) Найти максимальное растояние между городами\n");
	printf("3) Найти колличество различных путей между городами\n");
	printf("4) Сформировать и вывести граф\n");
	printf("5) Выход\n");
	printf("Выберите дейсвие: ");
}

void output_path(Graph *g, Results *res, int act)
{
	if (act == 3) {
		for (int i = 0; i < res->ind_path; i++) {
			for (int j = 0; j < g->sity + 1; j++) {
				if (res->paths[i].vert[j] == 0) {
					continue;
				}
				printf("%d ", g->vertex[res->paths[i].vert[j] - 1]);
				if (res->paths[i].vert[j + 1] != 0 && j + 1 != g->sity + 1) {
					printf("-> ");
				}
			}
			printf("\n");
		}
	}
	else { 
		for (int i = 0; i < res->count; i++) {
			for (int j = 0; j < g->sity + 1; j++) {
				if (res->paths[res->ind_max_or_min_path[i]].vert[j] == 0) {
					continue;
				}
				printf("%d ", g->vertex[res->paths[res->ind_max_or_min_path[i]].vert[j] - 1]);
				if (res->paths[res->ind_max_or_min_path[i]].vert[j + 1] != 0 && j + 1 != g->sity + 1) {
					printf("-> ");
				}
			}
			printf("\n");
		}
	}
}

void create_graph_image(Graph *g)
{
	FILE *out = fopen("graph.gv", "w");
	if (out == NULL) {
		return;
	}
	int weight;
	fprintf(out, "digraph HelloWorld {\n");
	for (int i = 0; i < g->sity; i++) {
		for (int j = 0; j < g->sity; j++) {
			if ((weight = g->data[get_item(i, j, g)]) > 0) {
				fprintf(out, "\t%d -> %d[label=%d];\n", i + 1, j + 1, weight);
			}
		}
	}
	fprintf(out, "}\n");
	fclose(out);
}

int check_scan(int *act, int *vertex1, int *vertex2, Graph *g, int *vert1, int *vert2)
{
	scanf("%d", act);
	if ((*act > 0) && (*act < 4)) {
		printf("Введите города между которыми будем совершать действие.\n");
		printf("Vertex 1: ");
		scanf("%d", vertex1);
		*vert1 = get_index(*vertex1, g);
		if ((*vert1 == -1)) {
			printf("Вы ошиблись при вводе вершин\n");
			return -1;	
		}
		printf("Vertex 2: ");
		scanf("%d", vertex2);
		*vert2 = get_index(*vertex2, g);
		if ((*vert2 == -1)) {
			printf("Вы ошиблись при вводе вершин\n");
			return -1;	
		}
	}
	return 0;
}
