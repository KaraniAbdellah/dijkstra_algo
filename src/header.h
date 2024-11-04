
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
	
	#define n 10

	// Define Colors
	#define RED "\033[1;31m"
	#define GREEN "\033[1;32m"
	#define WARNING "\033[1;33m"
	#define RESET "\033[0m"
	#define MENU_COLOR "\033[1;36m"
	#define GRAY "\033[1;90m"
	#define BLUE "\033[1;34m"


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
	void init_graph(List *graph);
	void add_node_to_graph(List *graph, int src, int dest, int weight);
	void display_graph(List *graph);
	void find_short_path(List *graph);



#endif







