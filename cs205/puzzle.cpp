#include "puzzle.hpp"

//contsructors
	// 0 represents the blank space
	Puzzle::Puzzle(int option) {
		if(option == 1) {
			curr_state = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    		} else if(option == 2) {
                        curr_state = {1, 2, 3, 4, 5, 6, 0, 7, 8};
                } else if(option == 3) {
                        curr_state = {1, 2, 3, 5, 0, 6, 4, 7, 8};
                } else if(option == 4) {
                        curr_state = {1, 3, 6, 5, 0, 2, 4, 7, 8};
                } else if(option == 5) {
                        curr_state = {1, 3, 6, 5, 0, 7, 4, 8, 2};
                } else if(option == 6) {
                        curr_state = {1, 6, 7, 5, 0, 3, 4, 8, 2};
                } else if(option == 7) {
                        curr_state = {7, 1, 2, 4, 8, 5, 6, 3, 0};
                } else if(option == 8) {
                        curr_state = {0, 7, 2, 4, 6, 1, 3, 5, 8};
                }

		goal_state = {1, 2, 3, 4, 5, 6, 7, 8, 0};
		success = false;
	}



//movement operators
	//movement operators do nothing if the move is illegal. Example trying to move up when the blank is already at the very top of the board.

	void Puzzle::op_up() {
		int blank = blank_position();
		if(blank <= 2) { return; }
		else if(blank == 404) { 
			std::cout << "ERROR in movement\n";
			return;
		}

		curr_state[blank] = curr_state[blank-3];
		curr_state[blank-3] = 0;
		return;
	}

	void Puzzle::op_down() {
                int blank = blank_position();
                if(blank >= 6) { return; }
                else if(blank == 404) { 
                        std::cout << "ERROR in movement\n";
                        return;
                }
                
                curr_state[blank] = curr_state[blank+3];
                curr_state[blank+3] = 0;
                return;
        }

	void Puzzle::op_left() {
                int blank = blank_position();
                if(blank % 3 == 0) { return; }
                else if(blank == 404) { 
                        std::cout << "ERROR in movement\n";
                        return;
                }
                
                curr_state[blank] = curr_state[blank-1];
                curr_state[blank-1] = 0;
                return;
        }

	void Puzzle::op_right() {
                int blank = blank_position();
                if(blank % 3 == 2) { return; }
                else if(blank == 404) { 
                        std::cout << "ERROR in movement\n";
                        return;
                }
                
                curr_state[blank] = curr_state[blank+1];
                curr_state[blank+1] = 0;
                return;
        }


//helper functions
	//gets the position of the blank tile in order to perform movement operators. Returns 404 in case of errors.
	int Puzzle::blank_position() {
		for(int i = 0; i < curr_state.size(); ++i) {
			if(curr_state.at(i) == 0) {
				return i;
			}
		}
		return 404;
	}

	void Puzzle::draw_puzzle() {
		for(int i = 0; i < 3; ++i ) {
			std::cout << curr_state.at(i) << " ";
		}
		std::cout << "\n";
		
		for(int i = 3; i < 6; ++i ) {
                        std::cout << curr_state.at(i) << " ";
                }
                std::cout << "\n";

		for(int i = 6; i < 9; ++i ) {
                        std::cout << curr_state.at(i) << " ";
                }
                std::cout << "\n";
	}
