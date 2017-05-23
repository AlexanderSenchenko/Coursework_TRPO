#ifndef PRINT_H
#define PRINT_H

void menu();
void output_path(Graph *g, Results *res, int act);
void create_graph_image(Graph *g);
int check_scan(int *act, int *vertex1, int *vertex2, Graph *g, int *vert1, int *vert2);

#endif
