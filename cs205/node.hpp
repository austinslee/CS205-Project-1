#ifndef __NODE_HPP__
#define __NODE_HPP__

#include <iostream>
#include <vector>
#include "puzzle.hpp"


//class for Nodes
class Node {
	public:
	//member variables
		Node* parent;
		Puzzle puzzle = NULL;
		int total_cost;
		//g_cost is the cost to get to a node
		int g_cost;
		//h_cost is the estimated distance to the goal or the heuristic
		int h_cost;

		int depth;

	//constructors
		Node(Puzzle);

	//helper functions
		int misplaced_cost();
		int manhattan_cost();

		
		
		
		

};

#endif //__NODE_HPP__
