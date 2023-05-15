#ifndef __SEARCH_HPP__
#define __SEARCH_HPP__

#include <iostream>
#include <vector>
#include <queue>
#include "puzzle.hpp"
#include "node.hpp"


//priority queue comparator overloading
class MyCompare {
	public:
		bool operator()(Node* a, Node* b) {
			return a->total_cost > b->total_cost;
		}
};

//class for the different searches
class Search {	
	public:
		//member variables
		std::priority_queue<Node*, std::vector<Node*>, MyCompare> queue;
		std::vector<Node*> explored;
	
		//Different searches
		Node* uniform(Node*);
		Node* misplaced(Node*);
		Node* manhattan(Node*);



};

#endif //__SEARCH_HPP__
