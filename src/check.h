#ifndef CHECK_H
#define CHECK_H

Graph *input_validation();
int check_vertex(char str[]);
int check_city(char str[], int num_vertex, Graph *g);
int check_matrix(char str[], int num_vertex, Graph *g, int *count);

#endif
