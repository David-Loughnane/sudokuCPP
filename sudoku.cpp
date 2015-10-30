#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"

using namespace std;

/* You are pre-supplied with the functions below. Add your own 
   function definitions to the end of this file. */

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char *filename, char board[9][9]) {

  cout << "Loading Sudoku board from file '" << filename << "'... ";

  ifstream in(filename);
  if (!in)
    cout << "Failed!" << endl;
  assert(in);

  char buffer[512];

  int row = 0;
  in.getline(buffer,512);
  while (in && row < 9) {
    for (int n=0; n<9; n++) {
      assert(buffer[n] == '.' || isdigit(buffer[n]));
      board[row][n] = buffer[n];
    }
    row++;
    in.getline(buffer,512);
  }

  cout << ((row == 9) ? "Success!" : "Failed!") << endl;
  assert(row == 9);
}

/* internal helper function */
void print_frame(int row) {
  if (!(row % 3))
    cout << "  +===========+===========+===========+" << endl;
  else
    cout << "  +---+---+---+---+---+---+---+---+---+" << endl;
}

/* internal helper function */
void print_row(const char *data, int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<9; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
  }
  cout << "|" << endl;
}

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]) {
  cout << "    ";
  for (int r=0; r<9; r++) 
    cout << (char) ('1'+r) << "   ";
  cout << endl;
  for (int r=0; r<9; r++) {
    print_frame(r);
    print_row(board[r],r);
  }
  print_frame(9);
}


/* add your functions here */


//function tests to see if the board contains numbers 1-9 in all positions
bool is_complete(const char board[9][9]) {
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      if (isdigit(board[row][col]) && board[row][col] != '0')
	return 1;
    }
  }
  return 0;
}


//function tests if digit is valid at position on the given board
bool make_move(const char position[2], char digit, char board[9][9]) {
  int row_try, col_try;
  row_try = position[0] - 65; // ASCII capitalised letter char converted to int, from 0
  col_try = position[1] - 49; // ASCII number char converted to int, from 0

  // test if position within board range
  if ((row_try < 0 || row_try > 8) || (col_try < 0 || col_try > 8)) {
    return 0; 
  }
 
  // test if position is blank
  if (board[row_try][col_try] != '.') {
    return 0;
  }
 
  //test if digit already in the chosen column
  for (int row = 0; row < 9; row++) {
    if (board[row][col_try] == digit) {
      return 0;
    }
  }

  // test if digit already in the chosen row
  for (int col = 0; col < 9; col++) {
    if (board[row_try][col] == digit) {
      return 0;
    }
  }

  // test if digit already within sub-matrix
  for (int i = row_try - (row_try%3); i < row_try - (row_try%3) + 3; i++) {
    for (int j = col_try - (col_try%3); j < col_try - (col_try%3) + 3; j++) {
      if (board[i][j] == digit) {
	  return 0;
	}
    } 
  }

  // if none of the previous conditions are met then it must be a valid move - return True
  //  assign the correct guess to the position
  board[row_try][col_try] = digit;
  return 1;
}


bool save_board(const char *filename, char board[9][9]) {
  ofstream output_file;
  output_file.open(filename);

  if (output_file.is_open()) {
    for (int row = 0; row < 9; row++) {
      for (int col = 0; col < 9; col++) {
	output_file.put(board[row][col]);
      }
      output_file.put('\n');
    }
    output_file.close();
    return 1;
  }
  else { 
    return 0;
  }
}


bool solve_board(char board[9][9]) {
  char position[2];
  for (position[0] = 'A'; position[0] <= 'I'; position[0]++) {
     for (position[1] = '1'; position[1] <= '9'; position[1]++) {
         if (board[(position[0]-65)][(position[1]-49)] != '.') // if the current cell is not blank skip over it
	   continue;
       for (char guess = '1'; guess <= '9'; guess++) {
	 if (make_move(position, guess, board)) { // test if the guess is valid
	   if(solve_board(board)) { //recursive call of function to move onto next empty cell
	     return 1; 
	   }
	 }
	 board[(position[0]-65)][(position[1]-49)] = '.'; // if we have iterated though all the guess    
       }
       return 0; // indicates that no guess are correct, recursive call returns 0, cell is set to '.' and guess loop continues
     }
  }  
  return 1; // if flow of control reaches the end we have iterated through whole board.
}

