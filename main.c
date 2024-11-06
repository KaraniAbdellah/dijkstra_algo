#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/header.h"


int main() {
	
	int n;
	printf("Enter number of nodes: ");
	scanf("%d", &n);
	printf(BLUE "\nwe want to go from 0 to %d\n\n", n - 1); printf(RESET);
	
	List *graph = (List *) malloc(sizeof(List) * n); // graph pointe to "n space"
	init_graph(graph, n);
	
	int src, dest, weight;
	char choice;

	while (1) {
		printf("Enter source node: ");
		scanf("%d", &src);
		printf("Enter destination node: ");
		scanf("%d", &dest);
		printf("From %d to %d what is weight: ", src, dest);
		scanf("%d", &weight);

		add_node_to_graph(graph, src, dest, weight, n);

		printf("Do you want to add another connection? (y/n): ");
		scanf(" %c", &choice);
		if (choice != 'y' && choice != 'Y') {
		    break;
		}
	}

	
	display_graph(graph, n);
	
	find_short_path(graph, n);


	return 0;
}


