#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "check.h"

Graph *input_validation()
{
	FILE *in = fopen("graph.txt", "r");
	if (in == NULL) {
		return 0;
	}
	//Считываем кол-во вершин и тут же проверяем, первая строка
	char vertex[5];
	if (fgets(vertex, 6, in) == NULL) {
		printf("Добавьте в файл кол-во вершин до 1000\n");
		fclose(in);
		return NULL;
	}
	int num_vertex = check_vertex(vertex);
	if ((num_vertex == -1) || (num_vertex < 0)) {
		printf("Не удалось считать первую строчку\n");
		fclose(in);
		return NULL;
	}
	Graph *g;
	g = graph_create(num_vertex);

	//Запись названия городов и сразу же проверка, считываем вторую строку
	char name_city[num_vertex * 5];	
	if (fgets(name_city, (num_vertex * 5) + 1, in) == NULL) {
		printf("Добавьте в файл названия вершин\n");
		fclose(in);
		graph_free(g);
		return NULL;
	}
	if (check_city(name_city, num_vertex, g) == -1) {
		printf("Не удалось считать вторую строчку\n");
		fclose(in);
		graph_free(g);
		return NULL;
	}
	for (int i = 0; i < g->sity; i++) {
		for (int j = i + 1; j < g->sity; j++) {
			if (g->vertex[i] == g->vertex[j]) {
				printf("Вы ввели два одинаковых города\n");
				fclose(in);
				graph_free(g);
				return NULL;
			}
		}
		
	}
	//Запись матрицы и проверка матрицы
	int count = 0;
	for (int i = 0; i < num_vertex; i++) { 
		char name_city[num_vertex * 5];	
		if (fgets(name_city, (num_vertex * 5) + 1, in) == NULL) {
			printf("Нарушена матрица,возможно не хватает строки\n");
			fclose(in);
			graph_free(g);
			return NULL;
		}
		if (check_matrix(name_city, num_vertex, g, &count) == -1) {
			printf("Не удалось считать матрицу\n");
			fclose(in);
			graph_free(g);
			return NULL;
		}
		//printf("Count = %d\n", count);
	}
	fclose(in);	
	return g;
}

int check_vertex(const char str[])
{
	//printf("First %s", str);
	if (strlen(str)  > 4) {
		//printf("Вы ввели не корректное число вершин\n");
		return -1;
	}
	int vertex;
	for(int i = 0; i < strlen(str) - 1; i++) {
		if (!(isdigit(str[i]))) {
		//	printf("Вы ввели не корректное число вершин\n");
			return -1;
		}
	}
	vertex = atoi(str);
	if ((vertex != 0) && (vertex > 1)) {
		return vertex;
	}
	else {
		//printf("Кол-во вершин равно нулю\n");
		return -1;
	}
	return vertex;
}

int check_city(char str[], int num_vertex, Graph *g)
{
	//printf("Second %s", str);
	if (strlen(str)  > num_vertex * 4) {
		printf("Превышен размер второй строки\n");
		return -1;
	}
	int count = 0;
	char *pch = strtok(str, "\t\n");
	while(pch != NULL) {
		if (strlen(pch) > 3) {
			printf("Название одного из города  больше трехзначного числа\n");
			return -1;
		}
		for(int i = 0; i < strlen(pch); i++) {
			if (!(isdigit(pch[i]))) {
				printf("Название города не число\n");
				return -1;
			}
		}
		//printf("%s\n", pch);	
		g->vertex[count] = atoi(pch);
		pch = strtok(NULL, "\t\n");
		count++;
	}
	//printf("%d\n", num_vertex);
	//printf("%d\n", count);
	if (num_vertex != count) {
		printf("Кол-во вершин не совпадает с кол-вом названий городов\n");
		return -1;
	}
	
	return 1;
}

int check_matrix(char str[], int num_vertex, Graph *g, int *count)
{

	int ind = 0;
	char *pch = strtok(str, "\t\n");
	while(pch != NULL) {
		//printf("%s ", pch);
		if ((strlen(pch) > 3) || (strlen(pch)  == 0)) {
			printf("Вес вершины больше трехзначного числа или числа нет\n");
			return -1;
		}
		for(int i = 0; i < strlen(pch); i++) {
			if (!(isdigit(pch[i]))) {
				printf("Вес ребра не число, либо вес отрицательный\n");
				return -1;
			}
		}	
		g->data[*count] = atoi(pch);
		//printf("%d\n", g->data[*count]);
		pch = strtok(NULL, "\t\n");
		(*count)++;
		ind++;
	}
	if (ind != num_vertex) {
		printf("Нарушена структура матрица\n");
		return -1;
	}

	return 1;
}
