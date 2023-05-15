#ifndef __MAIN_CPP__
#define __MAIN_CPP__

#include <iostream>
#include <chrono>
#include "puzzle.hpp"
#include "node.hpp"
#include "search.hpp"

int main() {
	std::cout << "There are 8 different preset puzzles to choose from.\n";
	std::cout << "Option 1 corresponds to the test case with depth 0, Option 2 corresponds to the test case with depth 2, and so on up to option 8 which corresponds to the test case with depth 24.\n\n";
	std::cout << "Please enter from option 1-8\n\n";

	int option;
	int search;

	std::cin >> option;

	std::cout << "1 for Uniform Cost Search, 2 for A* with misplaced tiles, 3 for A* with manhattan distance.\n\n";

	std::cin >> search;

	Puzzle temp_puzzle(option);
	Node* temp_node = new Node(temp_puzzle);
	Search temp_search;
	auto time_start = std::chrono::high_resolution_clock::now();
	if(search == 1) {
		temp_search.uniform(temp_node);
	} else if( search == 2) {
		temp_search.misplaced(temp_node);
	} else if( search == 3) {
		temp_search.manhattan(temp_node);
	}
	auto time_stop = std::chrono::high_resolution_clock::now();
	auto time_duration = std::chrono::duration_cast<std::chrono::microseconds>(time_stop - time_start);
	std::cout << "Time taken: " << time_duration.count() << " microseconds\n";

}


#endif //__MAIN_CPP__
