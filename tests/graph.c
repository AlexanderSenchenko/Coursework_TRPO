#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int get_item(int i, int j, Graph *g);
int get_index(int vertex, Graph *g);

Graph *graph_create(int num)
{
	Graph *g = malloc(sizeof(Graph));
	if (g == NULL) {
		free(g);
		return 0;
	}
	g->sity = num;
	g->data = malloc(sizeof(int) * g->sity * g->sity);
	if (g->data == NULL) {
		free(g);
		return NULL;
	}

	g->vertex = malloc(sizeof(int) * g->sity * 2);
	if (g->vertex == NULL) {
		free(g);
		return NULL;
	}
	return g;
}

Results *results_create(Graph *g)
{
	Results *res = malloc(sizeof(Results));
	if (res == NULL) {
		results_free(res);
		return NULL;
	}
	res->paths = malloc(sizeof(int) * g->sity * 2);
	if (res->paths == NULL) {
		results_free(res);
		return NULL;
	}
	res->buf_path = malloc(sizeof(int) * g->sity * 2);
	if (res->buf_path == NULL) {
		results_free(res);
		return NULL;
	}
	res->ind_max_or_min_path = malloc(sizeof(int)*g->sity * 2);
	if (res->ind_max_or_min_path == NULL) {
		results_free(res);
		return NULL;
	}
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

int get_index(int vertex, Graph *g)
{	
	for (int i = 0; i < g->sity; i++) {
		if (vertex == g->vertex[i]) {	
			return i + 1;
		}
	}
	return -1;
}

void results_free(Results *res)
{
	if (res != NULL){
		for (int i = 0; i < res->ind_path; i++) {
			free(res->paths[i].vert);
		}
		free(res->paths);
		free(res->buf_path);
		free(res->ind_max_or_min_path);
		free(res);
	}
}

int get_item(int i, int j, Graph *g)
{
	return i * g->sity + j;
}

int all_paths(int a, int b, Graph *g, Results *res)
{
	int mass[g->sity], z = 0;
	
	for (int i = 0; i < g->sity; i++) {
		mass[i] = 0;
	}
	path_in_graph(a - 1, b, g, mass, z, res);
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
	res->paths[res->ind_path].vert = malloc(sizeof(int) * g->sity * 2);
	for (int i = 0; i < g->sity + 1; i++) {
		res->paths[res->ind_path].vert[i] = 0;
	}
	for (int i = 0; i < g->sity + 1; i++) {
		res->paths[res->ind_path].vert[i] = res->buf_path[i];
	}
}

void free_max_or_min_paths(Results *res)
{
	for(int i = 0; i < res->count; i++) {
		res->ind_max_or_min_path[i] = 0;
	}
	res->count = 0;
}

int max_sum(Graph *g, Results *res) 
{
	int max = 0;
	int sum = 0;
	int ind = 0;
	for (int i = 0; i < res->ind_path; i++) {
		int j = 0;
		while ((res->paths[i].vert[j] > 0) && (res->paths[i].vert[j + 1] > 0)) {	
			sum = sum + g->data[get_item(res->paths[i].vert[j] - 1, res->paths[i].vert[j + 1] - 1, g)];
			j++;
		}
		if (sum > max) {
			max = sum;
			free_max_or_min_paths(res);
			ind = 0;
			res->ind_max_or_min_path[ind] = i;
			res->count++;
			ind++;
		}
		else if (sum == max) {
			res->ind_max_or_min_path[ind] = i;
			ind++;
			res->count++;
		}
		sum = 0;
	}
	return max;
}

int max_distance(Graph *g, int vertex1, int vertex2, Results *res)
{
	res->count = 0;
	all_paths(vertex1, vertex2, g, res);

	return max_sum(g, res);
}

int min_sum(Graph *g, Results *res) 
{
	int min = INT_MAX;
	int sum = 0;
	int ind = 0;
	for (int i = 0; i < res->ind_path; i++) {
		int j = 0;
		while ((res->paths[i].vert[j] > 0) && (res->paths[i].vert[j + 1] > 0)) {	
			sum = sum + g->data[get_item(res->paths[i].vert[j] - 1, res->paths[i].vert[j + 1] - 1, g)];
			j++;
		}
		if (sum < min) {
			min = sum;
			free_max_or_min_paths(res);
			ind = 0;
			res->ind_max_or_min_path[ind] = i;
			res->count++;
			ind++;
		}
		else if (sum == min) {
			res->ind_max_or_min_path[ind] = i;
			ind++;
			res->count++;
		}
		sum = 0;
	}
	if (min == INT_MAX) {
		min = 0;
	}

	return min;
}

int min_distance(Graph *g, int vertex1, int vertex2, Results *res)
{
	res->count = 0;
	all_paths(vertex1, vertex2, g, res);

	return min_sum(g, res);
}
