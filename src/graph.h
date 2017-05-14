#ifndef GRAPH_H
#define GRAPH_H

typedef struct {
	int *data;
	int *vertex;
	int sity;
	int *p_path;
} Graph;

typedef struct {
	struct paths {
		int *vert;
	} *paths;// массив структур для хранения всевозможных путей
	int ind_path;//индекс для записи путей в массив структур paths 	
	int *ind_max_or_min_path;// массив для хранения индексов максимальных либо минимальных путей, с помощью которого мы будем распечатывать сами пути
	int count; // счетчик количества максимальных либо минимальных путей
} Results;

Graph *graph_create(int n);
void graph_free(Graph *g);
int get_item(int i, int j, Graph *g);
int max_distance(Graph *g, int vertex1, int vertex2, int act);
int all_paths(int a, int b, Graph *g, int act);
void output_path(Graph *g, int act);
int path_in_graph(int index, int a, int b, Graph *g, int mass[], int z, int act);
int max_sum(Graph *g);
void print_max_path(Graph *g);
void free_max_paths(Graph *g);

#endif
