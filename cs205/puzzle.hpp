#ifndef __PUZZLE_HPP__
#define __PUZZLE_HPP__

#include <iostream>
#include <vector>


class Puzzle {
	public:
		//member variables
		
		std::vector<int> curr_state;
		bool success;
		std::vector<int> goal_state;

		//constructors
		Puzzle(int);

		//movement operators
		void op_up();
		void op_down();
		void op_left();
		void op_right();
		
		//helper functions
		int blank_position();
		void draw_puzzle();

};

#endif //__PUZZLE_HPP__
