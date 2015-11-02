// MCS Lab1 - C++1
// Author David Loughnane - dl4415
// Created October 19th 2015
// Last Modified October 30th 2015

#include <iostream>
#include <cstdio>
#include <ctime>
#include "sudoku.h"

using namespace std;

int main() {

  char board[9][9];

  /* This section illustrates the use of the pre-supplied helper functions. */
  /* cout << "============== Pre-supplied functions ==================" << endl << endl;

  cout << "Calling load_board():" << endl;
  load_board("easy.dat", board);

  cout << endl << "Displaying Sudoku board with display_board():" << endl;
  display_board(board);
  cout << "Done!" << endl << endl;*/
 
  cout << "====================== Question 1 ======================" << endl << endl;
  
  load_board("easy.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << endl << endl;

  load_board("easy-solution.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
    cout << "complete." << endl << endl;
  
  cout << "====================== Question 2 ======================" << endl << endl;
  
  load_board("easy.dat", board);
  
  // Should be OK
  cout << "Putting '1' into I8 is ";
  if (!make_move("I8", '1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);
  
  // write more tests
  
  cout << "====================== Question 3 ======================" << endl << endl;

  load_board("easy.dat", board);
  if (save_board("easy-copy.dat", board))
    cout << "Save board to 'easy-copy.dat' successful." << endl;
  else
    cout << "Save board failed." << endl;
    cout << endl;
  
  cout << "====================== Question 4 ======================" << endl << endl;

  load_board("easy.dat",board);
    if (solve_board(board)) {
    cout << "The 'easy' board has a solution:" << endl;
    display_board(board);
  } else 
      cout << "A solution cannot be found." << endl;
    cout << endl;
    
    
  load_board("medium.dat", board);
  if (solve_board(board)) {
    cout << "The 'medium' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;

  load_board("mystery1.dat", board);
  if (solve_board(board)) {
    cout << "The 1st mystery board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;

  load_board("mystery2.dat", board);
  if (solve_board(board)) {
    cout << "The 2nd mystery board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;

  load_board("mystery3.dat", board);
  if (solve_board(board)) {
    cout << "The 3rd mystery board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;
  
  cout << "====================== Question 5 ======================" << endl << endl;

  clock_t begin, end;
  double execution_secs;

  load_board("mystery1.dat",board);
  begin = clock();
  solve_board(board);
  end = clock();

  execution_secs = double(end - begin) / CLOCKS_PER_SEC;
  cout << "The execution time for mystery1.dat is " << execution_secs << " seconds" << endl;
  cout << endl;

  load_board("mystery3.dat",board);
  begin = clock();
  solve_board(board);
  end = clock();

  execution_secs = double(end - begin) / CLOCKS_PER_SEC;
  cout << "The execution time for mystery3.dat is " << execution_secs << " seconds" << endl;
  cout << endl;
		
  return 0;
}
