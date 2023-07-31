#include <stdio.h>
#include <stdlib.h>
#include "edgelist.h"

EDGELIST *new_edgelist() {
	EDGELIST *g = (EDGELIST *) malloc(sizeof(EDGELIST));
	if (g == NULL) return g;

	if (g) {
		g->size = 0;
		g->start = NULL;
		g->end = NULL;
	}
	return g;
}

void add_edge_end(EDGELIST *g, int from, int to, int weight) {
	// create new edge
	EDGE *edge = (EDGE *) malloc(sizeof(EDGE));
	if (edge == NULL) return;

	// set edge with its properties
	edge->from = from;
	edge->to = to;
	edge->weight = weight;
	edge->next = NULL; // last edge since it will be added to the end, so next is NULL

	if (g->start == NULL) {
		// empty graph
		g->start = edge;
		g->end = edge;
	} else {
		g->end->next = edge;
		g->end = edge;
	}
	g->size++;
}

void add_edge_start(EDGELIST *g, int from, int to, int weight) {
	EDGE *edge = (EDGE *) malloc(sizeof(EDGE));
	if (edge == NULL) return;

	edge->from = from;
	edge->to = to;
	edge->weight = weight;
	edge->next = NULL;

	if (g->start == NULL) {
		// empty graph
		g->start = edge;
		g->end = edge;
	} else {
		edge->next = g->start;
		g->start = edge;
	}
	g->size++;
}

int weight_edgelist(EDGELIST *g) {
	EDGE *current = g->start;
	int totalWeight = 0;

	while (current != NULL) {
		totalWeight += current->weight;
		current = current->next;
	}
	return totalWeight;
}

void clean_edgelist(EDGELIST **gp) {
  EDGELIST *g = *gp;
  EDGE *temp, *p = g->start;
  while (p) {
    temp = p;
    p = p->next;
    free(temp);
  }
  free(g);
  *gp = NULL;
}

void display_edgelist(EDGELIST *g) {
  if (g == NULL) return;
  printf("size:%d\n", g->size);
  printf("(from to weight):");
  EDGE *p = g->start;
  while (p) {
    printf("(%d %d %d) ", p->from, p->to, p->weight);
    p = p->next;
  }
}
