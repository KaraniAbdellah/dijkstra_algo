#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/header.h"


int main() {
	
	List *graph = (List *) malloc(sizeof(List) * n); // graph pointe to "n space"
	init_graph(graph);
	
	add_node_to_graph(graph, 0, 1, 3);
	add_node_to_graph(graph, 0, 2, 1);
	add_node_to_graph(graph, 1, 3, 3);
	add_node_to_graph(graph, 2, 4, 5);
	add_node_to_graph(graph, 1, 2, 1);
	add_node_to_graph(graph, 2, 3, 3);
	add_node_to_graph(graph, 3, 5, 3);
	add_node_to_graph(graph, 3, 4, 1);
	add_node_to_graph(graph, 4, 5, 1);

	display_graph(graph);
	
	find_short_path(graph);


	return 0;
}


