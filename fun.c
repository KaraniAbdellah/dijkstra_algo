#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"



// this for test
void printHello() {
	printf(RED "Hello Abdellah Karani\n" RESET);
}

// initialize the graph
void init_graph(int n, List** graph) {
	
	for (int i = 0; i < n; i++) {
		graph[i]->head = (Node *) malloc(sizeof(Node *));
	}
	return;
	
}










