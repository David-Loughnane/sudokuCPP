#ifndef SUDOKU_H
#define SUDOKU_H


//reads from file named filename, and assigns value to 2 dimensional character array
void load_board(const char *filename, char board[9][9]);

//prints sudoku board to screen
void display_board(const char board[9][9]);

//test if board contains characters '1' to '9' at all positions
//returns true if board is complete
//returns false otherwise
bool is_complete(const char board[9][9]);

//test if digit is valid at position on the board based on sudoku rules
//returns true if digit is valid and inserts digit at position
//returns false if digit is not valid, board not modified 
bool make_move(const char position[2], char digit, char board[9][9]);

//saves board into file named by input parameter filename
//returns true if file opened correctly
//returns false if error in opening file
bool save_board(const char *filename, char board[9][9]);

//attempts to fill board with valid digits to complete sudoku
//returns true if a solution can be found
//returns false if no solution can be found
bool solve_board(char board[9][9]);

#endif
