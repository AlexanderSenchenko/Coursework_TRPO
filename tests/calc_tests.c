#include "ctest.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int sity[5] = {1, 2, 3, 4, 5};
int data[25] = {0, 40, 0, 0, 26, 0, 0, 22, 6, 0, 0, 0, 0, 0, 0, 1, 0, 14, 0, 0, 0, 5, 0, 20, 3};

//ALL_PATHS
CTEST(all_paths, ind_1_1)
{
	// Given
	int num_vertex = 5;	
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {	
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	Results *res = results_create(g); 
	for (int i = 0; i < 5; i++) {
		g->vertex[i] = sity[i];
	}
	for (int i = 0; i < 25; i++) {
		g->data[i] = data[i];
	}
    // When
	int ind1 = 1;
	int ind2 = 1;
    const int result = all_paths(ind1, ind2, g, res);
	graph_free(g);
	results_free(res);
    // Then
    const int expected = 3;
    ASSERT_EQUAL(expected, result);
}

CTEST(all_paths, ind_1_2)
{
	// Given
	int num_vertex = 5;	
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {	
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	Results *res = results_create(g); 
	for (int i = 0; i < 5; i++) {
		g->vertex[i] = sity[i];
	}
	for (int i = 0; i < 25; i++) {
		g->data[i] = data[i];
	}
    // When
	int ind1 = 2;
	int ind2 = 3;
    const int result = all_paths(ind1, ind2, g, res);
	graph_free(g);
	results_free(res);
    // Then
    const int expected = 2;
    ASSERT_EQUAL(expected, result);
}

CTEST(all_paths, ind_1_3)
{
	// Given
	int num_vertex = 5;	
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {	
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	Results *res = results_create(g); 
	for (int i = 0; i < 5; i++) {
		g->vertex[i] = sity[i];
	}
	for (int i = 0; i < 25; i++) {
		g->data[i] = data[i];
	}
    // When
	int ind1 = 1;
	int ind2 = 3;
    const int result = all_paths(ind1, ind2, g, res);
	graph_free(g);
	results_free(res);
    // Then
    const int expected = 5;
    ASSERT_EQUAL(expected, result);
}

CTEST(all_paths, ind_1_4)
{
	// Given
	int num_vertex = 5;	
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {	
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	Results *res = results_create(g); 
	for (int i = 0; i < 5; i++) {
		g->vertex[i] = sity[i];
	}
	for (int i = 0; i < 25; i++) {
		g->data[i] = data[i];
	}
    // When
	int ind1 = 1;
	int ind2 = 4;
    const int result = all_paths(ind1, ind2, g, res);
	graph_free(g);
	results_free(res);
    // Then
    const int expected = 3;
    ASSERT_EQUAL(expected, result);
}

CTEST(all_paths, ind_1_5)
{
	// Given
	int num_vertex = 5;	
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {	
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	Results *res = results_create(g); 
	for (int i = 0; i < 5; i++) {
		g->vertex[i] = sity[i];
	}
	for (int i = 0; i < 25; i++) {
		g->data[i] = data[i];
	}
    // When
	int ind1 = 1;
	int ind2 = 5;
    const int result = all_paths(ind1, ind2, g, res);
	graph_free(g);
	results_free(res);
    // Then
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(max_distance, ind_1_1)
{
	// Given
	int num_vertex = 5;	
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {	
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	Results *res = results_create(g); 
	for (int i = 0; i < 5; i++) {
		g->vertex[i] = sity[i];
	}
	for (int i = 0; i < 25; i++) {
		g->data[i] = data[i];
	}
    // When
	int ind1 = 1;
	int ind2 = 1;
    const int result = max_distance(g, ind1, ind2, res);
	graph_free(g);
	results_free(res);
    // Then
    const int expected = 47;
    ASSERT_EQUAL(expected, result);
}

CTEST(max_distance, ind_1_2)
{
	// Given
	int num_vertex = 5;	
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {	
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	Results *res = results_create(g); 
	for (int i = 0; i < 5; i++) {
		g->vertex[i] = sity[i];
	}
	for (int i = 0; i < 25; i++) {
		g->data[i] = data[i];
	}
    // When
	int ind1 = 1;
	int ind2 = 2;
    const int result = max_distance(g, ind1, ind2, res);
	graph_free(g);
	results_free(res);
    // Then
    const int expected = 40;
    ASSERT_EQUAL(expected, result);
}

CTEST(max_distance, ind_1_3)
{
	// Given
	int num_vertex = 5;	
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {	
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	Results *res = results_create(g); 
	for (int i = 0; i < 5; i++) {
		g->vertex[i] = sity[i];
	}
	for (int i = 0; i < 25; i++) {
		g->data[i] = data[i];
	}
    // When
	int ind1 = 1;
	int ind2 = 3;
    const int result = max_distance(g, ind1, ind2, res);
	graph_free(g);
	results_free(res);
    // Then
    const int expected = 62;
    ASSERT_EQUAL(expected, result);
}

CTEST(max_distance, ind_1_4)
{
	// Given
	int num_vertex = 5;	
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {	
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	Results *res = results_create(g); 
	for (int i = 0; i < 5; i++) {
		g->vertex[i] = sity[i];
	}
	for (int i = 0; i < 25; i++) {
		g->data[i] = data[i];
	}
    // When
	int ind1 = 1;
	int ind2 = 4;
    const int result = max_distance(g, ind1, ind2, res);
	graph_free(g);
	results_free(res);
    // Then
    const int expected = 46;
    ASSERT_EQUAL(expected, result);
}

CTEST(max_distance, ind_1_5)
{
	// Given
	int num_vertex = 5;	
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {	
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	Results *res = results_create(g); 
	for (int i = 0; i < 5; i++) {
		g->vertex[i] = sity[i];
	}
	for (int i = 0; i < 25; i++) {
		g->data[i] = data[i];
	}
    // When
	int ind1 = 1;
	int ind2 = 5;
    const int result = max_distance(g, ind1, ind2, res);
	graph_free(g);
	results_free(res);
    // Then
    const int expected = 26;
    ASSERT_EQUAL(expected, result);
}

CTEST(min_distance, ind_1_1)
{
	// Given
	int num_vertex = 5;	
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {	
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	Results *res = results_create(g); 
	for (int i = 0; i < 5; i++) {
		g->vertex[i] = sity[i];
	}
	for (int i = 0; i < 25; i++) {
		g->data[i] = data[i];
	}
    // When
	int ind1 = 1;
	int ind2 = 1;
    const int result = min_distance(g, ind1, ind2, res);
	graph_free(g);
	results_free(res);
    // Then
    const int expected = 38;
    ASSERT_EQUAL(expected, result);
}

CTEST(min_distance, ind_1_2)
{
	// Given
	int num_vertex = 5;	
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {	
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	Results *res = results_create(g); 
	for (int i = 0; i < 5; i++) {
		g->vertex[i] = sity[i];
	}
	for (int i = 0; i < 25; i++) {
		g->data[i] = data[i];
	}
    // When
	int ind1 = 1;
	int ind2 = 2;
    const int result = min_distance(g, ind1, ind2, res);
	graph_free(g);
	results_free(res);
    // Then
    const int expected = 31;
    ASSERT_EQUAL(expected, result);
}

CTEST(min_distance, ind_1_3)
{
	// Given
	int num_vertex = 5;	
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {	
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	Results *res = results_create(g); 
	for (int i = 0; i < 5; i++) {
		g->vertex[i] = sity[i];
	}
	for (int i = 0; i < 25; i++) {
		g->data[i] = data[i];
	}
    // When
	int ind1 = 1;
	int ind2 = 3;
    const int result = min_distance(g, ind1, ind2, res);
	graph_free(g);
	results_free(res);
    // Then
    const int expected = 51;
    ASSERT_EQUAL(expected, result);
}

CTEST(min_distance, ind_1_4)
{
	// Given
	int num_vertex = 5;	
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {	
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	Results *res = results_create(g); 
	for (int i = 0; i < 5; i++) {
		g->vertex[i] = sity[i];
	}
	for (int i = 0; i < 25; i++) {
		g->data[i] = data[i];
	}
    // When
	int ind1 = 1;
	int ind2 = 4;
    const int result = min_distance(g, ind1, ind2, res);
	graph_free(g);
	results_free(res);
    // Then
    const int expected = 37;
    ASSERT_EQUAL(expected, result);
}

CTEST(min_distance, ind_1_5)
{
	// Given
	int num_vertex = 5;	
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {	
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	Results *res = results_create(g); 
	for (int i = 0; i < 5; i++) {
		g->vertex[i] = sity[i];
	}
	for (int i = 0; i < 25; i++) {
		g->data[i] = data[i];
	}
    // When
	int ind1 = 1;
	int ind2 = 5;
    const int result = min_distance(g, ind1, ind2, res);
	graph_free(g);
	results_free(res);
    // Then
    const int expected = 26;
    ASSERT_EQUAL(expected, result);
}
