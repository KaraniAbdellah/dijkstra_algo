#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"



// this for test
void printHello() {
	printf(RED "Hello Abdellah Karani\n" RESET);
}

// initialize the graph
void init_graph(int n, List *graph) {
	
	for (int i = 0; i < n; i++) {
		graph[i].head = NULL;
	}
	return;
	
}

// create a node
Node *create_node() {
	
	Node *new_node = (Node *) malloc(sizeof(Node));
	if (new_node == NULL) {
		exit(1);
	}
	new_node->next = NULL;
	new_node->data = -1;
	return new_node;
	
}

// add node to graph
void add_node_to_graph(List *graph, int src, int dest, int weight) {
	
	Node *new_node = create_node(); 
	new_node->data = dest;
	new_node->weight = weight;
	
	if(graph[src].head == NULL) {
		graph[src].head = new_node;
		return;
	}
	
	Node *temp = graph[src].head;
	while (temp->next != NULL) temp = temp->next;
	temp->next = new_node;	
	
}

// display nodes graph's
void display_graph(List *graph, int n) {

	// open dot file
	FILE *p_file = fopen("dot/g.dot", "w");
	fprintf(p_file, "digraph G {\n");
	
	printf(BLUE "---------- Graph ----------\n" RESET);
	for (int i = 0; i < n; i++) {
		Node *temp = graph[i].head;
		printf("Node %d: ", i);
		while (temp != NULL) {
		
			printf(WARNING "[%d, %d] --> ", temp->data, temp->weight);
			
			// Write the edge to the DOT file
            fprintf(p_file, "%d -> %d;\n", i, temp->data);
            
			temp = temp->next;
			
		}
		printf("\n" RESET);
	}
	
	fprintf(p_file, "}\n");
	fclose(p_file);

}











