#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"



// this for test
void printHello() {
	printf(RED "Hello Abdellah Karani\n" RESET);
}

// error message
void error_msg() {
	printf(RED "can not add this node\n" RESET);
}

// initialize the graph
void init_graph(List *graph) {
	
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
	
	if (src < 0 || dest < 0 || src >= n || dest >= n) {
		error_msg();
	}
	
	// connect src with dest
	Node *new_node_src = create_node(); 
	new_node_src->data = dest;
	new_node_src->weight = weight;
	
	if(graph[src].head == NULL) {
		graph[src].head = new_node_src;
	} else {
		Node *temp = graph[src].head;
		while (temp->next != NULL) temp = temp->next;
		temp->next = new_node_src;
	}
	
	
	// connect dest with src
	Node *new_node_dest = create_node(); 
	new_node_dest->data = src;
	new_node_dest->weight = weight;
	
	if(graph[dest].head == NULL) {
		graph[dest].head = new_node_dest;
	} else {
		Node *temp = graph[dest].head;
		while (temp->next != NULL) temp = temp->next;
		temp->next = new_node_dest;
	}
	
	
}

// display nodes graph's
void display_graph(List *graph) {

	// open dot file
	FILE *p_file = fopen("dot/g.dot", "w");
	fprintf(p_file, "graph G {\n");
	
	int visited[n];
	for (int i = 0; i < n; i++) visited[i] = -1;
	
	printf(BLUE "---------- Graph ----------\n" RESET);
	for (int i = 0; i < n; i++) {
		Node *temp = graph[i].head;
		printf("Node %d: ", i);
		while (temp != NULL) {
			
			printf(WARNING "[%d, %d] --> ", temp->data, temp->weight);
			
			// Write the edge to the DOT file
			if (visited[temp->data] != -1) {
	            fprintf(p_file, "%d -- %d [label=\"%d\"];\n", i, temp->data, temp->weight);
			} else visited[i] = temp->data;
            
			temp = temp->next;
			
		}
		printf("NULL\n" RESET);
	}
	
	fprintf(p_file, "}\n");
	fclose(p_file);

}



void find_short_path(List *graph) {
	
	
	
}





/*
	fprintf(p_file, "%d -> %d [label=\"%d\"];\n", i, temp->data, temp->weight);
	fprintf(p_file, "digraph G {\n");
*/


















