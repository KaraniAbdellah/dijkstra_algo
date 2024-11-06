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
void init_graph(List *graph, int n) {
	
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
void add_node_to_graph(List *graph, int src, int dest, int weight, int n) {
	
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
void display_graph(List *graph, int n) {

	// open dot file
	FILE *p_file = fopen("dot/g.dot", "w");
	fprintf(p_file, "graph G {\n");
	
	int visited[n];
	for (int i = 0; i < n; i++) visited[i] = -1;
	
	printf(BLUE "\n---------- Graph ----------\n" RESET);
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
	printf(BLUE "---------------------------\n" RESET);

}


int is_exit_connection(int choosed_ele, List *graph, int searched_ele) {
	
	Node *temp = graph[choosed_ele].head;
	while (temp != NULL) {
		if (temp->data == searched_ele) return temp->weight;
		temp = temp->next;
	}
	return -1;
	
}

int is_visited(int *R, int searched_ele, int count) {
	
	for (int i = 0; i < count + 1; i++) {
		if (R[i] != -1 && R[i] == searched_ele) return 1;
	}
	return 0;
}

void find_min_in_row(int n, int matrix[n][n], int nodes[n], int nodes_len, int row, int *min, int *new_node) {
	
	for (int k = 0; k < nodes_len; k++) {
		if ((matrix[row][k] != -1 && matrix[row][k] < *min) || *min == -1) {
			*min = matrix[row][k];
			*new_node = nodes[k];
			// printf("min = %d\n", min);
		}
	}
	
}

void display_short_path(int *R, int n) {
	
	printf("Shortest path: ");
	for (int i = 0; i < n; i++) {
		if (R[i] != -1) printf("%d ", R[i]);
	}
	printf("\n");
	
}

void initialize(int n, int *R, int *Min, int (*matrix)[n], int *nodes) {
	
	for (int i = 0; i < n; i++) R[i] = -1;
	for (int i = 0; i < n; i++) Min[i] = -1;
	for (int i = 0; i < n; i++) nodes[i] = i;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = -1;
		}
	}

}

int get_distance(int *Min, int n) {
	
	for (int i = n - 1; i >= 0; i--) {
		if (Min[i] != -1) return Min[i];
	} return -1;
	
}

void display_theory(int n, int (*matrix)[n], int *R, int *Min, int *nodes) {

	printf(BLUE "\n---------------------------\n" RESET);
    for (int i = 0; i < n; i++) printf("%d | ", nodes[i]);
    printf("selection sommet\n");
    printf(WHITE "---------------------------\n" RESET);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != -1) 
                printf("%d | ", matrix[i][j]);
            else 
                printf("& | ");
        }
        printf("%d (%d)\n", R[i], Min[i]);
    }
    printf(BLUE "---------------------------\n\n" RESET);
}


void find_short_path(List *graph, int n) {
	
	// create & initialze
	int matrix[n][n];
	int R[n];
	int Min[n];
	int nodes[n];
	initialize(n, R, Min, matrix, nodes);
	int nodes_len = sizeof(nodes) / sizeof(nodes[0]);

	// start searching about short path
	R[0] = 0;
	Min[0] = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		int choosed_ele = R[count];
		if (choosed_ele == n) break;
		
		// is graph[choosed_ele] contains nodes eles
		for (int j = 0; j < nodes_len; j++) {
			if (nodes[j] != choosed_ele) {
				int searched_ele = nodes[j];
				// check if node already visited
				int check_visited_node = is_visited(R, searched_ele, count);
				if (check_visited_node == 0) {
					int weight = is_exit_connection(choosed_ele, graph, searched_ele);
					if (weight != -1) {
						if (count > 0) {
							matrix[i][j] = weight + Min[count];
							if (i > 0 && matrix[i - 1][j] != -1) {
								matrix[i][j] = (matrix[i - 1][j] < matrix[i][j]) ? matrix[i - 1][j] : matrix[i][j];
							}
						}
						else matrix[i][j] = weight;
						// printf("weight = %d, searched_ele = %d, choosed_ele = %d, x = %d\n", weight,
						/// searched_ele, choosed_ele, matrix[i][j]);
					}
				}
			}
		}
		
		// find the min number
		int min = matrix[i][0];
		int new_node;
		
		find_min_in_row(n, matrix, nodes, nodes_len, i, &min, &new_node);
		
		
		
		// add visited node & add Min ele
		count++;
		Min[count] = min;
		R[count] = new_node;
		
	}
	
	// display the shortest path
	display_short_path(R, n);
	
	// display the distance
	int distance = get_distance(Min, n);
	printf("Distance = %d\n", distance);
	
	// display the Theory
	display_theory(n, matrix, R, Min, nodes);
	
	
	
}




















