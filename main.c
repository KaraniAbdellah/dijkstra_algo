#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


int main() {
	
	int n = 10;
	List *graph = (List *) malloc(sizeof(List) * n); // graph pointe to "n space"
	init_graph(n, graph);
	
	add_node_to_graph(graph, 0, 1, 2);
	add_node_to_graph(graph, 2, 1, 3);
	add_node_to_graph(graph, 2, 3, 1);
	add_node_to_graph(graph, 1, 1, 5);

	display_graph(graph, n);
		
		
	return 0;
}






// if (src >= n || dest >= n) printf(RED "Out of range" RESET);




