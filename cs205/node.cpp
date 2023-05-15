#include "node.hpp"

//Constructors

Node::Node(Puzzle input) {
	puzzle = input;
	depth = 0;
	g_cost = 0;
	h_cost = 0;
	total_cost = 0;
}

int Node::misplaced_cost() {
	int to_return = 0;
	for(int i = 0; i < puzzle.curr_state.size(); ++i) {
		if(puzzle.curr_state.at(i) != puzzle.goal_state.at(i)) {
			if(puzzle.curr_state.at(i) != 0) {
				++to_return;
			}
		}
	}
	return to_return;
}

int Node::manhattan_cost() {
	int to_return = 0;
	int temp_int;

	int currX;
	int currY;
	int goalX;
	int goalY;

	for(int i = 0; i < puzzle.curr_state.size(); ++i) {
		if(puzzle.curr_state.at(i) != puzzle.goal_state.at(i)) {
			if(puzzle.curr_state.at(i) != 0) {
				currX = i % 3;
				currY = i / 3;

				goalX = (puzzle.curr_state.at(i) - 1) % 3;
				goalY = (puzzle.curr_state.at(i) - 1) / 3;

				to_return += abs(currX - goalX) + abs(currY - goalY);
			}
		}
	}
	return to_return;
}
