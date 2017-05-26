#include <ctest.h>
#include <vald.h>
#include <stdio.h>
#include <stdlib.h>

//CHECK_VERTEX
CTEST(check_vertex, single_valued)
{
	// Given
	const char  vertex[5] = "3\n";

	// When
	const int result = check_vertex(vertex);

	// Then
	const int expected = 3;
	ASSERT_EQUAL(expected, result);
}

CTEST(check_vertex, double_digit)
{
	// Given
	const char  vertex[5] = "99\n";

	// When
	const int result = check_vertex(vertex);

	// Then
	const int expected = 99;
	ASSERT_EQUAL(expected, result);
}

CTEST(check_vertex, three_digit)
{
	// Given
	const char  vertex[5] = "999\n";

	// When
	const int result = check_vertex(vertex);

	// Then
	const int expected = 999;
	ASSERT_EQUAL(expected, result);
}

CTEST(check_vertex, four_digit)
{
	// Given
	const char  vertex[5] = "1000\n";

	// When
	const int result = check_vertex(vertex);

	// Then
	const int expected = -1;
	ASSERT_EQUAL(expected, result);
}

CTEST(check_vertex, negative_digit)
{
	// Given
	const char  vertex[5] = "-5\n";

	// When
	const int result = check_vertex(vertex);

	// Then
	const int expected = -1;
	ASSERT_EQUAL(expected, result);
}

CTEST(check_vertex, letter)
{
	// Given
	const char  vertex[5] = "a\n";

	// When
	const int result = check_vertex(vertex);

	// Then
	const int expected = -1;
	ASSERT_EQUAL(expected, result);
}

CTEST(check_vertex, one_vertex)
{
	// Given
	const char  vertex[5] = "1\n";

	// When
	const int result = check_vertex(vertex);

	// Then
	const int expected = -1;
	ASSERT_EQUAL(expected, result);
}

CTEST(check_vertex, nothing)
{
	// Given
	const char  vertex[5] = "\n";

	// When
	const int result = check_vertex(vertex);

	// Then
	const int expected = -1;
	ASSERT_EQUAL(expected, result);
}

CTEST(check_vertex, null_vertex)
{
	// Given
	const char  vertex[5] = "0\n";

	// When
	const int result = check_vertex(vertex);

	// Then
	const int expected = -1;
	ASSERT_EQUAL(expected, result);
}

//CHECK_CITY
CTEST(check_city, correct)
{
	// Given
	int num_vertex = 5;	
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	char name_city[5 * 5] = "11\t12\t13\t14\t156\n";
	// When
	const int result = check_city(name_city, num_vertex, g);
	graph_free(g);
	// Then
	const int expected = 1;
	ASSERT_EQUAL(expected, result);
}

CTEST(check_city, uncorrect)
{
	// Given
	int num_vertex = 4;	
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	char name_city[4 * 5] = "11\t12\t13\t14\t156\n";
	// When
	const int result = check_city(name_city, num_vertex, g);
	graph_free(g);
	// Then
	const int expected = -1;
	ASSERT_EQUAL(expected, result);
}

CTEST(check_city, name_city_letter)
{
	// Given
	int num_vertex = 5;	
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	char name_city[5 * 5] = "11\t12\t13\tb\t156\n";
	// When
	const int result = check_city(name_city, num_vertex, g);
	graph_free(g);
	// Then
	const int expected = -1;
	ASSERT_EQUAL(expected, result);
}

CTEST(check_city, uncorrect_size_line)
{
	// Given
	int num_vertex = 5;	
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	char name_city[5 * 5] = "11\t12\t13\tb\t156\t45\t455\n";
	// When
	const int result = check_city(name_city, num_vertex, g);
	graph_free(g);
	// Then
	const int expected = -1;
	ASSERT_EQUAL(expected, result);
}

CTEST(check_city, name_city_four_digit)
{
	// Given
	int num_vertex = 5;	
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	char name_city[5 * 5] = "11\t12\t1000\t6\t156\n";
	// When
	const int result = check_city(name_city, num_vertex, g);
	graph_free(g);
	// Then
	const int expected = -1;
	ASSERT_EQUAL(expected, result);
}

CTEST(check_city, name_city_negative)
{
	// Given
	int num_vertex = 5;	
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	char name_city[5 * 5] = "11\t-12\t1000\t6\t156\n";
	// When
	const int result = check_city(name_city, num_vertex, g);
	graph_free(g);
	// Then
	const int expected = -1;
	ASSERT_EQUAL(expected, result);
}

CTEST(check_city, same_name_city)
{
	// Given
	int num_vertex = 5;	
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	char name_city[5 * 5] = "11\t12\t11\t6\t156\n";
	// When
	const int result = check_city(name_city, num_vertex, g);
	graph_free(g);
	// Then
	const int expected = -1;
	ASSERT_EQUAL(expected, result);
}

CTEST(check_city, all_name_city_three_digit)
{
	// Given
	int num_vertex = 5;	
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	char name_city[5 * 5] = "111\t112\t113\t116\t156\n";
	// When
	const int result = check_city(name_city, num_vertex, g);
	graph_free(g);
	// Then
	const int expected = 1;
	ASSERT_EQUAL(expected, result);
}

//CHECK_MATRIX
CTEST(check_matrix, correct)
{
	// Given
	int num_vertex = 5;	
	int count = 0;
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	char name_city[5 * 5] = "111\t112\t113\t116\t156\n";
	// When
	const int result = check_matrix(name_city, num_vertex, g, &count);
	graph_free(g);
	// Then
	const int expected = 1;
	ASSERT_EQUAL(expected, result);
}

CTEST(check_matrix, uncorrect)
{
	// Given
	int num_vertex = 4;	
	int count = 0;
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	char name_city[5 * 5] = "111\t112\t113\t116\t156\n";
	// When
	const int result = check_matrix(name_city, num_vertex, g, &count);
	graph_free(g);
	// Then
	const int expected = -1;
	ASSERT_EQUAL(expected, result);
}

CTEST(check_matrix, weight_vertex_four_digit)
{
	// Given
	int num_vertex = 5;	
	int count = 0;
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	char name_city[5 * 5] = "111\t112\t113\t116\t1564\n";
	// When
	const int result = check_matrix(name_city, num_vertex, g, &count);
	graph_free(g);
	// Then
	const int expected = -1;
	ASSERT_EQUAL(expected, result);
}

CTEST(check_matrix, negative_digit)
{
	// Given
	int num_vertex = 5;	
	int count = 0;
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	char name_city[5 * 5] = "111\t112\t113\t116\t-98\n";
	// When
	const int result = check_matrix(name_city, num_vertex, g, &count);
	graph_free(g);
	// Then
	const int expected = -1;
	ASSERT_EQUAL(expected, result);
}

CTEST(check_matrix, weight_letter)
{
	// Given
	int num_vertex = 5;	
	int count = 0;
	Graph *g = graph_create(num_vertex);
	if (g == NULL) {
		printf("Не удалось выделить память в тесте\n");
		exit(EXIT_FAILURE);
	}
	char name_city[5 * 5] = "111\t112\tb3\t116\t98\n";
	// When
	const int result = check_matrix(name_city, num_vertex, g, &count);
	graph_free(g);
	// Then
	const int expected = -1;
	ASSERT_EQUAL(expected, result);
}
