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

void graph_free(Graph *v)
{
	if (v != NULL){
		free(v->data);
		free(v);
	}
}

int get_item(int i, int j, int line)
{
	return i * line + j;
}

int min(int a, int b)
{
	return (a > b ? b : a);
}

//Пока что ищет критический путь во всем гарфе, не по определенным вершинам
int max_distance(Graph g, int vertex1, int vertex2)
{
	/*
	vertex1 -= 1; //1
	vertex2 -= 1; //3
	*/

	int i, j, t, k, m, p, count, n, critical[10]; // Path crictical number of vertex
	int e[10], l[10]; //Early start, Latest start
	n = g.column;
	int matr[g.column][g.line];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matr[i][j] = g.data[get_item(i, j, g.line)];
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
	l[n-1] = e[n-1]; 
	for (k = n-2; k >= 0; k--) {
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
				for (j=0; j < n; j++) {
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


/*
int max_distance(Graph g, int vertex1, int vertex2) //Failed
{
	vertex1 -= 1; //1
	vertex2 -= 1; //3
	int matr[g.line][g.column];
	int n = g.column;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matr[i][j] = g.data[get_item(i, j, g.line)];
			printf("%d\t", matr[i][j]);
			if (!matr[i][j]) {
				matr[i][j] = 10000;
			}
		}
		printf("\n");
	}
	for (int k = vertex1; k < vertex2; k++) {
		for (int i = vertex1; i < vertex2; i++) {
			for (int j = vertex1; j < vertex2; j++) {
				if (i != j) {
					//printf("Do%d\n", matr[i][j]);
					matr[i][j] = min(matr[i][j], matr[i][k]+matr[k][j]);
					//printf("Bef %d\n", matr[i][j]);
				}
			}
		}
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
	    		if (matr[i][j] == 10000) {
				matr[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
	    		printf("%d\t", matr[i][j]);
		}
		printf("\n");
	}
	int max = matr[vertex1][vertex2];
	printf("Do%d\n", matr[vertex1][vertex2]);
	for(int i = vertex1; i < vertex2; i++) {
		for (int j = i + 1; j < vertex2; j++) {
			printf("oi%d\n", matr[i][j]);
			if(matr[i][j] > max) {
				printf("o%d\n", matr[i][j]);
				max = matr[i][j];
			}
		}
	}

	return max;
}


int max_distance(Graph g, int vertex1, int vertex2) //Failed
{
	vertex1 -= 1; //1
	vertex2 -= 1; //3
	int max;
	int sum = 0;
	if (g.data[get_item(vertex1, vertex2, g.line)] != 0) {	
		max = g.data[get_item(vertex1, vertex2, g.line)];
	}
	else max = 0;

	for (int i = vertex1; i < vertex2; i++) {
		for (int j = i + 1; j <= vertex2; j++) {
			//printf("%d\n", g.data[get_item(i, j, g.line)]);			
			if (g.data[get_item(i, j, g.line)] != 0) {
				sum = sum + g.data[get_item(i, j, g.line)];
			}					
		}
	}
	sum = sum - max;
	printf("%d\n", sum);
	printf("%d\n", max);
	if (sum > max) {
		max = sum;
	}
				
	return max;
}*/
