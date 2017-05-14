#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

Graph *graph_create(int n)
{
	int num = 0;
	FILE *in = fopen("graph.txt", "r");
	if (in == NULL) {
		return 0;
	}
	
	Graph *g = malloc(sizeof(Graph));
	if (g == NULL) {
		return NULL;
	}

	g->data = malloc(sizeof(int) * num * num);
	if (g->data == NULL) {
		free(g);
		return NULL;
	}

	g->vertex = malloc(sizeof(int) * 5);
	if (g->vertex == NULL) {
		free(g);
		return NULL;
	}

	//Запись городов
	for (int i = 0; i < n; i++) {
		fscanf(in, "%d", &g->vertex[i]);
		num++;
	}

	for (int i = 0; i < num * num; i++) {
		fscanf(in, "%d", &g->data[i]);
	}

	g->sity = num;

	//fclose(in);

	return g;
}

void graph_free(Graph *g)
{
	if (g != NULL){
		free(g->data);
		free(g->p_path);
		free(g->vertex);
		free(g);
	}
}

int get_item(int i, int j, Graph *g)
{
	return i * g->sity + j;
}

int all_paths(int a, int b, Graph *g)
{
	int index = 0, mass[g->sity], z = 0;
	g->p_path = malloc(sizeof(int) * g->sity);
	g->max = malloc(sizeof(int) * g->sity);
	for (int i = 0; i < g->sity; i++) {
		g->p_path[i] = 0;
	}
	for (int i = 0; i < g->sity; i++) {
		mass[i] = 0;
	}
	index = path_in_graph(index, a - 1, b, g, mass, z);

	return index;
}

int path_in_graph(int index, int a, int b, Graph *g, int mass[], int z)
{
	for (int  i = a; i < g->sity; i++) {
		if (mass[i] != 0) {
			return index;
		}
		mass[i]++;
		for (int j = 0; j < g->sity; j++) {
			if (g->data[get_item(i, j, g)] > 0) {
				g->p_path[z] = i + 1;
				if (j == b - 1) {
					index++;
					g->p_path[z + 1] = j + 1;
					output_path(g);
					g->p_path[z + 1] = 0;
					continue;
				}
				index = path_in_graph(index, j, b, g, mass, z + 1);
			}
		}
		g->p_path[z] = 0;
		mass[i]--;
		return index;
	}
	return index;
}

void entry_path(Graph *g, int x)
{
	for (int i = 0; i < g->sity; i++) {
		if (g->p_path[i] == 0 && x != 0) {
			g->p_path[i] = x + 1;
			break;
		} else if (g->p_path[i] != 0 && x == 0) {
			g->p_path[g->sity - i] = x;
			break;
		}
	}
}

void output_path(Graph *g)
{
	for (int i = 0; i < g->sity; i++) {
		if (g->p_path[i] == 0) {
			continue;
		}
		printf("%d ", g->p_path[i]);
		g->max[g->ind_max_path].vert[i] = g->p_path[i];
		if (g->p_path[i + 1] != 0 && i + 1 != g->sity) {
			printf("-> ");
		}
	}
	g->ind_max_path = g->ind_max_path + 1;
	printf("\n");
}

void print_max_path(Graph *g)
{
	for (int j = 0; j < g->max[g->max_path].count; j++) {	
			printf("%d ", g->max[g->max_path].vert[j]);
			if (j != g->max[g->max_path].count - 1){
				printf("-> ");
			}
	}
	printf("\n");
}

int max_sum(Graph *g) 
{
	int max = 0;
	int sum = 0;
	for (int i = 0; i < g->ind_max_path; i++) {
		for (int j = 0; j < g->max[i].count - 1; j++) {	
			sum = sum + g->data[get_item(g->max[i].vert[j] - 1, g->max[i].vert[j + 1] - 1, g)];
		}
		if (sum > max) {
			max = sum;
			g->max_path = i;
		}
		sum = 0;
	}

	return max;
}

int max_distance(Graph *g, int vertex1, int vertex2)
{
	g->ind_max_path = 0;
	all_paths(vertex1, vertex2, g);
	int j = 0;
	for (int i = 0; i < g->ind_max_path; i++) {
		while (g->max[i].vert[j] > 0) {
				j++;
				g->max[i].count++;
		}
		j = 0;
	}
	return max_sum(g);
}
