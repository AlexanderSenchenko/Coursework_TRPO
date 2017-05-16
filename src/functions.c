#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

Graph *graph_create()
{
	FILE *in = fopen("graph.txt", "r");
	if (in == NULL) {
		return 0;
	}
	
	Graph *g = malloc(sizeof(Graph));
	if (g == NULL) {
		return NULL;
	}
	
	fscanf(in, "%d", &g->sity);

	g->data = malloc(sizeof(int) * g->sity * g->sity);
	if (g->data == NULL) {
		free(g);
		return NULL;
	}

	g->vertex = malloc(sizeof(int) * g->sity);
	if (g->vertex == NULL) {
		free(g);
		return NULL;
	}
	
	//Запись городов
	for (int i = 0; i < g->sity; i++) {
		fscanf(in, "%d", &g->vertex[i]);
	}

	for (int i = 0; i < g->sity * g->sity; i++) {
		fscanf(in, "%d", &g->data[i]);
	}

	//fclose(in);

	return g;
}

Results *results_create(Graph *g)
{
	Results *res = malloc(sizeof(Results));
	res->paths = malloc(sizeof(int) * g->sity);
	res->buf_path = malloc(sizeof(int) * (g->sity + 1));
	for (int i = 0; i < g->sity + 1; i++) {
		res->buf_path[i] = 0;
	}
	res->ind_path = 0;
	return res;
}

void graph_free(Graph *g)
{
	if (g != NULL){
		free(g->data);
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
	int mass[g->sity], z = 0;
	Results *res = results_create(g);
	
	for (int i = 0; i < g->sity; i++) {
		mass[i] = 0;
	}
	path_in_graph(a - 1, b, g, mass, z, res);

	output_path(g, res);

	return res->ind_path;
}

void path_in_graph(int a, int b, Graph *g, int mass[], int z, Results *res)
{
	for (int  i = a; i < g->sity; i++) {
		if (mass[i] != 0) {
			return;
		}
		mass[i]++;
		for (int j = 0; j < g->sity; j++) {
			if (g->data[get_item(i, j, g)] > 0) {
				res->buf_path[z] = i + 1;
				if (j == b - 1) {
					res->buf_path[z + 1] = j + 1;
					create_all_path(res, g);
					res->ind_path++;				
					res->buf_path[z + 1] = 0;
					continue;
				}
				path_in_graph(j, b, g, mass, z + 1, res);
			}
		}
		res->buf_path[z] = 0;
		mass[i]--;
		return;
	}
	return;
}

void create_all_path(Results *res, Graph *g)
{
	if (res->paths[res->ind_path].vert == NULL) {
		res->paths[res->ind_path].vert = malloc(sizeof(int) * (g->sity + 1));
		for (int i = 0; i < g->sity + 1; i++) {
			res->paths[res->ind_path].vert[i] = 0;
		}
	}
	for (int i = 0; i < g->sity + 1; i++) {
		res->paths[res->ind_path].vert[i] = res->buf_path[i];
	}
}

void output_path(Graph *g, Results *res)
{
	for (int i = 0; i < res->ind_path; i++) {
		for (int j = 0; j < g->sity + 1; j++) {
			if (res->paths[i].vert[j] == 0) {
				continue;
			}
			printf("%d ", res->paths[i].vert[j]);
			if (res->paths[i].vert[j + 1] != 0 && j + 1 != g->sity + 1) {
				printf("-> ");
			}
		}
		printf("\n");
	}
}

/*
void print_max_path(Graph *g)
{
	for(int i = 0; i < g->k; i++) {
		for (int j = 0; j < g->max[g->max_path[i]].count; j++) {	
				printf("%d ", g->max[g->max_path[i]].vert[j]);
				if (j != g->max[g->max_path[i]].count - 1){
					printf("-> ");
				}
		}
		printf("\n");
	}
}

void free_max_paths(Graph *g)
{
	for(int i = 0; i < g->k; i++) {
		g->max_path[i] = 0;
	}
	g->k = 0;
}
int max_sum(Graph *g) 
{
	int max = 0;
	int sum = 0;
	int ind = 0;
	g->max_path = malloc(sizeof(int)*g->sity*2);
	for (int i = 0; i < g->ind_max_path; i++) {
		for (int j = 0; j < g->max[i].count - 1; j++) {	
			sum = sum + g->data[get_item(g->max[i].vert[j] - 1, g->max[i].vert[j + 1] - 1, g)];
		}
		if (sum > max) {
			max = sum;
			free_max_paths(g);
			ind = 0;
			g->max_path[ind] = i;
			g->k++;
			ind++;
		}
		else if (sum == max) {
			g->max_path[ind] = i;
			ind++;
			g->k++;
		}
		sum = 0;
	}

	return max;
}

int max_distance(Graph *g, int vertex1, int vertex2, int act)
{
	g->ind_max_path = 0;
	all_paths(vertex1, vertex2, g, act);
	int j = 0;
	for (int i = 0; i < g->ind_max_path; i++) {
		g->max[i].count = 0;
		while ((g->max[i].vert[j] > 0) && (j < 10)) {
				j++;
				g->max[i].count = g->max[i].count + 1;
		}
		j = 0;
	}
	return max_sum(g);
}*/
