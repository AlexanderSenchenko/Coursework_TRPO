#ifndef VALD_H
#define VALD_H

#include "graph.h"

Graph *input_validation();
int check_vertex(const char str[]);
int check_city(char str[], int num_vertex, Graph *g);
int check_matrix(char str[], int num_vertex, Graph *g, int *count);

#endif
