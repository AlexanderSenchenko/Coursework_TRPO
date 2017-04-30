#include "graph.h"

Graph *graph_add(FILE *in, int num)
{
	Graph *v = malloc(sizeof(Graph));
	if (v == NULL) {
		return NULL;
	}

	v->data = malloc(sizeof(int) * num * num);
	if (v->data == NULL) {
		free(v);
		return NULL;
	}

	for (int i = 0; i < num * num; i++) {
		fscanf(in, "%d", &v->data[i]);
	}

	v->line = num;
	v->column = num;
	return v;
}

void graph_free(Graph *v){
	if (v != NULL){
		free(v->data);
		free(v);
	}
}

int get_item(int i, int j, int line)
{
	return i * line + j;
}
