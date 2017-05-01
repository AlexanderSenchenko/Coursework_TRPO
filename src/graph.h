#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *data;
	int line;
	int column;
} Graph;

Graph *graph_add(FILE *in, int num);
void graph_free(Graph *v);
int get_item(int i, int j, int line);
int max_distance(Graph g, int vertex1, int vertex2);

#endif
