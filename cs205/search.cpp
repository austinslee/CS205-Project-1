#include "search.hpp"
//Searches
Node* Search::uniform(Node* initial) {

	//variables
	int num_explored = 0;
	int max_queue = 0;
	Node* temp_node;
	Node* temp_node2;
	bool temp_bool = false;
	
	//nodes = MAKE_QUEUE(MAKE_NODE(problem.INITIAL_STATE))
	queue.push(initial);

	//loop do
	while(1) {

		//keeping track of nodes expanded and max queue size
		++num_explored;
		if(queue.size() > max_queue) {
			max_queue = queue.size();
		}
		//if EMPTY(nodes) then return "failure"
		if(queue.empty()) {
			std::cout << "\n\n ERROR: Uniform Cost Search, queue empty. search.cpp \n\n";
			return NULL;
		}
		
		//node = REMOVE_FRONT(nodes)
		temp_node = queue.top();
		queue.pop();

		//if problem.GOAL_TEST(node.STATE) succeeds then return node

		if(temp_node->puzzle.curr_state == temp_node->puzzle.goal_state) {
			std::cout << "\n\nSolution Found!\n" << "Solution depth: " << temp_node->g_cost << "\nNumber of nodes expanded: " << num_explored << "\nMax queue size: " << max_queue << "\n";
		
			std::cout << "\n\nRoute Taken";
			while(temp_node->parent != NULL) {
				std::cout << "\n";
				temp_node->puzzle.draw_puzzle();
				std::cout << "\n";
				temp_node = temp_node->parent;
			}
			return temp_node;
		}

		//nodes = QUEUEING_FUNCTION(nodes, EXPAND(node, problem.OPERATORS))
		temp_node2 = new Node(temp_node->puzzle);
		if(temp_node2->puzzle.blank_position() / 3 != 0) {
			for(int i = 0; i < explored.size(); ++i) {
				if(temp_node2->puzzle.curr_state == explored.at(i)->puzzle.curr_state) {
					temp_bool = true;
				}
			}
			if(temp_bool == false) {
				temp_node2->puzzle.op_up();
				temp_node2->parent = temp_node;
				if(temp_node2->parent != NULL) {
					temp_node2->g_cost = temp_node2->parent->g_cost + 1;
				}
				temp_node2->total_cost = temp_node2->g_cost;
				queue.push(temp_node2);
			}
			temp_bool = false;
		}

		temp_node2 = new Node(temp_node->puzzle);
                if(temp_node2->puzzle.blank_position() / 3 != 2) {
                        for(int i = 0; i < explored.size(); ++i) {
                                if(temp_node2->puzzle.curr_state == explored.at(i)->puzzle.curr_state) {
                                        temp_bool = true;
                                }
                        }
                        if(temp_bool == false) {
                                temp_node2->puzzle.op_down();
                                temp_node2->parent = temp_node;
                                if(temp_node2->parent != NULL) {
                                        temp_node2->g_cost = temp_node2->parent->g_cost + 1;
                                }
                                temp_node2->total_cost = temp_node2->g_cost;
                                queue.push(temp_node2);
                        }
			temp_bool = false;
                }

		temp_node2 = new Node(temp_node->puzzle);
                if(temp_node2->puzzle.blank_position() % 3 != 0) {
                        for(int i = 0; i < explored.size(); ++i) {
                                if(temp_node2->puzzle.curr_state == explored.at(i)->puzzle.curr_state) {
                                        temp_bool = true;
                                }
                        }
                        if(temp_bool == false) {
                                temp_node2->puzzle.op_left();
                                temp_node2->parent = temp_node;
                                if(temp_node2->parent != NULL) {
                                        temp_node2->g_cost = temp_node2->parent->g_cost + 1;
                                }
                                temp_node2->total_cost = temp_node2->g_cost;
                                queue.push(temp_node2);
                        }
			temp_bool = false;
                }

		temp_node2 = new Node(temp_node->puzzle);
                if(temp_node2->puzzle.blank_position() % 3 != 2) {
                        for(int i = 0; i < explored.size(); ++i) {
                                if(temp_node2->puzzle.curr_state == explored.at(i)->puzzle.curr_state) {
                                        temp_bool = true;
                                }
                        }
                        if(temp_bool == false) {
                                temp_node2->puzzle.op_right();
                                temp_node2->parent = temp_node;
                                if(temp_node2->parent != NULL) {
                                        temp_node2->g_cost = temp_node2->parent->g_cost + 1;
                                }
                                temp_node2->total_cost = temp_node2->g_cost;
                                queue.push(temp_node2);
                        }
			temp_bool = false;
                }
	}
}

Node* Search::misplaced(Node* initial) {
	//variables
        int num_explored = 0;
        int max_queue = 0;
        Node* temp_node;
        Node* temp_node2;
        bool temp_bool = false;

        //nodes = MAKE_QUEUE(MAKE_NODE(problem.INITIAL_STATE))
        queue.push(initial);
	initial->total_cost = initial->misplaced_cost();

        //loop do
        while(1) {
		//keeping track of nodes expanded and max queue size
                ++num_explored;
                if(queue.size() > max_queue) {
                        max_queue = queue.size();
                }
                //if EMPTY(nodes) then return "failure"
                if(queue.empty()) {
                        std::cout << "\n\n ERROR: Uniform Cost Search, queue empty. search.cpp \n\n";
                        return NULL;
                }
                //if EMPTY(nodes) then return "failure"
                if(queue.empty()) {
                        std::cout << "\n\n ERROR: Uniform Cost Search, queue empty. search.cpp \n\n";
                        return NULL;
                }

                //node = REMOVE_FRONT(nodes)
                temp_node = queue.top();
                queue.pop();

                //if problem.GOAL_TEST(node.STATE) succeeds then return node

                if(temp_node->puzzle.curr_state == temp_node->puzzle.goal_state) {
                        std::cout << "\n\nSolution Found!\n" << "Solution depth: " << temp_node->g_cost << "\nNumber of nodes expanded: " << num_explored << "\nMax queue size: " << max_queue << "\n";

                        std::cout << "\n\nRoute Taken";
                        while(temp_node->parent != NULL) {
                                std::cout << "\n";
                                temp_node->puzzle.draw_puzzle();
                                std::cout << "\n";
                                temp_node = temp_node->parent;
                        }
                        return temp_node;
                }
		//nodes = QUEUEING_FUNCTION(nodes, EXPAND(node, problem.OPERATORS))
                temp_node2 = new Node(temp_node->puzzle);
                if(temp_node2->puzzle.blank_position() / 3 != 0) {
                        for(int i = 0; i < explored.size(); ++i) {
                                if(temp_node2->puzzle.curr_state == explored.at(i)->puzzle.curr_state) {
                                        temp_bool = true;
                                }
                        }
                        if(temp_bool == false) {
                                temp_node2->puzzle.op_up();
                                temp_node2->parent = temp_node;
                                if(temp_node2->parent != NULL) {
                                        temp_node2->g_cost = temp_node2->parent->g_cost + 1;
                                }
                                temp_node2->total_cost = temp_node2->g_cost + temp_node2->misplaced_cost();
                                queue.push(temp_node2);
                        }
                        temp_bool = false;
                }

                temp_node2 = new Node(temp_node->puzzle);
                if(temp_node2->puzzle.blank_position() / 3 != 2) {
                        for(int i = 0; i < explored.size(); ++i) {
                                if(temp_node2->puzzle.curr_state == explored.at(i)->puzzle.curr_state) {
                                        temp_bool = true;
                                }
                        }
			if(temp_bool == false) {
                                temp_node2->puzzle.op_down();
                                temp_node2->parent = temp_node;
                                if(temp_node2->parent != NULL) {
                                        temp_node2->g_cost = temp_node2->parent->g_cost + 1;
                                }
                                temp_node2->total_cost = temp_node2->g_cost + temp_node2->misplaced_cost();
                                queue.push(temp_node2);
                        }
                        temp_bool = false;
                }
		temp_node2 = new Node(temp_node->puzzle);
                if(temp_node2->puzzle.blank_position() % 3 != 0) {
                        for(int i = 0; i < explored.size(); ++i) {
                                if(temp_node2->puzzle.curr_state == explored.at(i)->puzzle.curr_state) {
                                        temp_bool = true;
                                }
                        }
                        if(temp_bool == false) {
                                temp_node2->puzzle.op_left();
                                temp_node2->parent = temp_node;
                                if(temp_node2->parent != NULL) {
                                        temp_node2->g_cost = temp_node2->parent->g_cost + 1;
                                }
                                temp_node2->total_cost = temp_node2->g_cost + temp_node2->misplaced_cost();
                                queue.push(temp_node2);
                        }
                        temp_bool = false;
                }

                temp_node2 = new Node(temp_node->puzzle);
                if(temp_node2->puzzle.blank_position() % 3 != 2) {
                        for(int i = 0; i < explored.size(); ++i) {
                                if(temp_node2->puzzle.curr_state == explored.at(i)->puzzle.curr_state) {
                                        temp_bool = true;
                                }
                        }
                        if(temp_bool == false) {
                                temp_node2->puzzle.op_right();
                                temp_node2->parent = temp_node;
                                if(temp_node2->parent != NULL) {
                                        temp_node2->g_cost = temp_node2->parent->g_cost + 1;
                                }
                                temp_node2->total_cost = temp_node2->g_cost + temp_node2->misplaced_cost();
                                queue.push(temp_node2);
                        }
                        temp_bool = false;
                }
	}
}

Node* Search::manhattan(Node* initial) {
	//variables
        int num_explored = 0;
        int max_queue = 0;
        Node* temp_node;
        Node* temp_node2;
        bool temp_bool = false;

        //nodes = MAKE_QUEUE(MAKE_NODE(problem.INITIAL_STATE))
        queue.push(initial);
        initial->total_cost = initial->manhattan_cost();

        //loop do
        while(1) {
		//keeping track of nodes expanded and max queue size
                ++num_explored;
                if(queue.size() > max_queue) {
                        max_queue = queue.size();
                }
                //if EMPTY(nodes) then return "failure"
                if(queue.empty()) {
                        std::cout << "\n\n ERROR: Uniform Cost Search, queue empty. search.cpp \n\n";
                        return NULL;
                }
                //if EMPTY(nodes) then return "failure"
                if(queue.empty()) {
                        std::cout << "\n\n ERROR: Uniform Cost Search, queue empty. search.cpp \n\n";
                        return NULL;
                }

                //node = REMOVE_FRONT(nodes)
                temp_node = queue.top();
                queue.pop();

                //if problem.GOAL_TEST(node.STATE) succeeds then return node

                if(temp_node->puzzle.curr_state == temp_node->puzzle.goal_state) {
                        std::cout << "\n\nSolution Found!\n" << "Solution depth: " << temp_node->g_cost << "\nNumber of nodes expanded: " << num_explored << "\nMax queue size: " << max_queue << "\n";

                        std::cout << "\n\nRoute Taken";
                        while(temp_node->parent != NULL) {
                                std::cout << "\n";
                                temp_node->puzzle.draw_puzzle();
                                std::cout << "\n";
                                temp_node = temp_node->parent;
                        }
                        return temp_node;
                }
		//nodes = QUEUEING_FUNCTION(nodes, EXPAND(node, problem.OPERATORS))
                temp_node2 = new Node(temp_node->puzzle);
                if(temp_node2->puzzle.blank_position() / 3 != 0) {
                        for(int i = 0; i < explored.size(); ++i) {
                                if(temp_node2->puzzle.curr_state == explored.at(i)->puzzle.curr_state) {
                                        temp_bool = true;
                                }
                        }
                        if(temp_bool == false) {
                                temp_node2->puzzle.op_up();
                                temp_node2->parent = temp_node;
                                if(temp_node2->parent != NULL) {
                                        temp_node2->g_cost = temp_node2->parent->g_cost + 1;
                                }
                                temp_node2->total_cost = temp_node2->g_cost + temp_node2->manhattan_cost();
                                queue.push(temp_node2);
                        }
                        temp_bool = false;
                }

                temp_node2 = new Node(temp_node->puzzle);
                if(temp_node2->puzzle.blank_position() / 3 != 2) {
                        for(int i = 0; i < explored.size(); ++i) {
                                if(temp_node2->puzzle.curr_state == explored.at(i)->puzzle.curr_state) {
                                        temp_bool = true;
                                }
                        }
                        if(temp_bool == false) {
                                temp_node2->puzzle.op_down();
                                temp_node2->parent = temp_node;
                                if(temp_node2->parent != NULL) {
                                        temp_node2->g_cost = temp_node2->parent->g_cost + 1;
                                }
                                temp_node2->total_cost = temp_node2->g_cost + temp_node2->manhattan_cost();
                                queue.push(temp_node2);
                        }
                        temp_bool = false;
                }
		temp_node2 = new Node(temp_node->puzzle);
                if(temp_node2->puzzle.blank_position() % 3 != 0) {
                        for(int i = 0; i < explored.size(); ++i) {
                                if(temp_node2->puzzle.curr_state == explored.at(i)->puzzle.curr_state) {
                                        temp_bool = true;
                                }
                        }
                        if(temp_bool == false) {
                                temp_node2->puzzle.op_left();
                                temp_node2->parent = temp_node;
                                if(temp_node2->parent != NULL) {
                                        temp_node2->g_cost = temp_node2->parent->g_cost + 1;
                                }
                                temp_node2->total_cost = temp_node2->g_cost + temp_node2->manhattan_cost();
                                queue.push(temp_node2);
                        }
                        temp_bool = false;
                }

                temp_node2 = new Node(temp_node->puzzle);
                if(temp_node2->puzzle.blank_position() % 3 != 2) {
                        for(int i = 0; i < explored.size(); ++i) {
                                if(temp_node2->puzzle.curr_state == explored.at(i)->puzzle.curr_state) {
                                        temp_bool = true;
                                }
                        }
                        if(temp_bool == false) {
                                temp_node2->puzzle.op_right();
                                temp_node2->parent = temp_node;
                                if(temp_node2->parent != NULL) {
                                        temp_node2->g_cost = temp_node2->parent->g_cost + 1;
                                }
                                temp_node2->total_cost = temp_node2->g_cost + temp_node2->manhattan_cost();
                                queue.push(temp_node2);
                        }
                        temp_bool = false;
                }
	}
}
