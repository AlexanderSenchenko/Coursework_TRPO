#include "graph.h"

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
		free(g->vertex);
		free(g);
	}
}

int get_item(int i, int j, Graph *g)
{
	return i * g->sity + j;
}

//Работает только в одном напрвалении
//Например: из 1 в 4 работрает, а из 4 в 1 не работает
int all_paths(int a, int b, Graph *g)
{
	int index = 0, mass[g->sity];
	for (int i = 0; i < g->sity; i++) {
		mass[i] = 0;
	}
	index = path_in_graph(index, a - 1, b, g, mass);
	for (int i = 0; i < g->sity; i++) {
		printf("%d\t", mass[i]);
	}
	printf("\n");

	return index;
}

int path_in_graph(int index, int a, int b, Graph *g, int mass[])
{
	for (int  i = a; i < g->sity; i++) {
		if (mass[i] != 0) {
			return index;
		} //else if (i == b - 1) {
			//continue;
		//}
		mass[i]++;
		for (int j = 0; j < g->sity; j++) {
			if (g->data[get_item(i, j, g)] > 0) {
				if (j == b - 1) {
					index++;
					//mass[i]--;
					continue;
					//return index;
				}
				index = path_in_graph(index, j, b, g, mass);
			}
			//if (j + 1 == g->sity) {
			//	mass[i]--;
			//	return index;
			//}
		}
		//if (i < g->sity) {
		//	return index;
		//}
		mass[i]--;
		return index;
	}
	return index;
}

int min(int a, int b)
{
	return (a > b ? b : a);
}

//Пока что ищет критический путь во всем гарфе, не по определенным вершинам
int max_distance(Graph *g, int vertex1, int vertex2)
{
	/*
	vertex1 -= 1; //1
	vertex2 -= 1; //3
	*/

	int i, j, t, k, m, p, count, n, critical[10]; // Path crictical number of vertex
	int e[10], l[10]; //Early start, Latest start
	n = g->sity;
	int matr[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matr[i][j] = g->data[get_item(i, j, g)];
			printf("%d\t", matr[i][j]);

		}
		printf("\n");
	}
	e[0] = 0;   
	for (k = 1; k < n; k++) {
		count = 0;
		for (i = 0; i < n; i++) {
			if (matr[i][k] != 0) {
				count++;   
				m = i;
			}
		}
		if(count == 1) {
			e[k] = e[m] + matr[m][k];
		}
		else{
			e[k] = 0;
			for (i = 0; i < n; i++) {
				if (matr[i][k] != 0) {
					t = e[i] + matr[i][k];
					if (t > e[k])        
					e[k] = t;
				}
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d ", e[i]);
	}
	printf("\n");
	l[n - 1] = e[n - 1]; 
	for (k = n - 2; k >= 0; k--) {
		count = 0;
		for (j = 0; j < n; j++) {
			if (matr[k][j] != 0) {
				count++;
				p = j;
			}
		}
		if (count == 1)
			l[k] = l[p] - matr[k][p];
		else {
			l[k] = 1000;
				for (j = 0; j < n; j++) {
					if (matr[k][j] != 0) {
						t = l[j] - matr[k][j];
						if (t < l[k])
						l[k] = t;     
					}	
				}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d ", l[i]);
	}
	printf("\n");

	for(i = 1, k = 0; i < n; i++){
		if(e[i] == l[i]) {
			critical[k++] = i;
		}
	}
	printf("\nThe critical path is: 0");
	for(i = 0; i < k; i++) {
		printf("->%d", critical[i]);
	}

	return e[i];
}
