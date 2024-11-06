
/* **********************************************************************************************/
/*                                                                                   			*/
/*                                  	::::::::  ::::     ::  :::::::::::   :::::::::::		*/ 
/*                                      :+:       :: ::	   ::  ::	    ::	 ::		  ::		*/ 
/*                                      :+:       ::  ::   ::  ::		::	 ::		  ::		*/ 
/* By: Abdellah Karani                  ::::::::  ::   ::  ::  :+:+:+:+:+:	 :+:+:+:+:+:		*/ 
/*                                      :+:       ::    :: ::  ::		::	 ::		  ::		*/ 
/* Started: 2024/10/28          		:+:       ::     ::::  ::		::	 ::		  ::		*/ 
/* Finiched: 2024/10/30           		::::::::  ::  	   ::  ::		::	 ::		  ::		*/
/*           	                                                                       			*/ 
/* **********************************************************************************************/


#ifndef TASK
#define TASK
	

	// Define Colors
	#define RED "\033[1;31m"
	#define GREEN "\033[1;32m"
	#define WARNING "\033[1;33m"
	#define RESET "\033[0m"
	#define MENU_COLOR "\033[1;36m"
	#define GRAY "\033[1;90m"
	#define BLUE "\033[1;34m"
	#define WHITE "\033[1;37m"


	// strcuture definition
	typedef struct Node {
		int data;
		int weight;
		struct Node* next;
	} Node;
	
	typedef struct List {
		struct Node* head;
	} List;
	
	


	// fonctions prototypes
	void printHello();
	void init_graph(List *graph, int n);
	void add_node_to_graph(List *graph, int src, int dest, int weight, int n);
	void display_graph(List *graph, int n);
	
	int is_exit_connection(int choosed_ele, List *graph, int searched_ele);
	int is_visited(int *R, int searched_ele, int count);
	void find_min_in_row(int n, int matrix[n][n], int nodes[n], int nodes_len, int row, int *min, int *new_node);
	void display_theory(int n, int (*matrix)[n], int *R, int *Min, int *nodes);
	
	void display_short_path(int *R, int n);
	int get_distance(int *Min, int n);
	void initialize(int n, int *R, int *Min, int (*matrix)[n], int *nodes);
	
	void find_short_path(List *graph, int n);



#endif







