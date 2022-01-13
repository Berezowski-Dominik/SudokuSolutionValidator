/* SudokuSolutionValidator.cpp : This file contains the 'main' function.Program execution begins and ends there.
* Sudoku Background
Sudoku is a game played on a 9x9 grid. The goal of the game is to fill all cells of the grid with digits from 1 to 9, so that each column, each row, and each of the nine 3x3 sub-grids (also known as blocks) contain all of the digits from 1 to 9.
(More info at: http://en.wikipedia.org/wiki/Sudoku)

Sudoku Solution Validator
Write a function validSolution/ValidateSolution/valid_solution() that accepts a 2D array representing a Sudoku board, and returns true if it is a valid solution, or false otherwise. The cells of the sudoku board may also contain 0's, which will represent empty cells. Boards containing one or more zeroes are considered to be invalid solutions.

The board is always 9 cells by 9 cells, and every cell only contains integers from 0 to 9.

Examples
validSolution([
  [5, 3, 4, 6, 7, 8, 9, 1, 2],
  [6, 7, 2, 1, 9, 5, 3, 4, 8],
  [1, 9, 8, 3, 4, 2, 5, 6, 7],
  [8, 5, 9, 7, 6, 1, 4, 2, 3],
  [4, 2, 6, 8, 5, 3, 7, 9, 1],
  [7, 1, 3, 9, 2, 4, 8, 5, 6],
  [9, 6, 1, 5, 3, 7, 2, 8, 4],
  [2, 8, 7, 4, 1, 9, 6, 3, 5],
  [3, 4, 5, 2, 8, 6, 1, 7, 9]
]); // => true
validSolution([
  [5, 3, 4, 6, 7, 8, 9, 1, 2], 
  [6, 7, 2, 1, 9, 0, 3, 4, 8],
  [1, 0, 0, 3, 4, 2, 5, 6, 0],
  [8, 5, 9, 7, 6, 1, 0, 2, 0],
  [4, 2, 6, 8, 5, 3, 7, 9, 1],
  [7, 1, 3, 9, 2, 4, 8, 5, 6],
  [9, 0, 1, 5, 3, 7, 2, 1, 4],
  [2, 8, 7, 4, 1, 9, 6, 3, 5],
  [3, 0, 0, 4, 8, 1, 1, 7, 9]
]); // => false
*/

#include <iostream>
#include <vector>

using namespace std;

bool validSolution(unsigned int board[9][9]);

int main()
{
    unsigned int board[9][9] = {
    {5, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9} };

    cout << validSolution(board);
}

bool validSolution(unsigned int board[9][9])
{
    vector <int> numbers{0,0,0,0,0,0,0,0,0,0};
          
    for (int i = 0; i <= 9; i++)                        //  We check first three squares in left vertical
    {
        if (i % 3 == 0 && i != 0)                       //  This loop we can determine rows
        {
            for (int k = 1; k < 10; k++)                //  We check number in square, good square have one number from 1-9
            {
                if (numbers[k] != 1)                    //  If we have more number, that 1 we have fail square
                    return 0;                           //  return false

                numbers[k] = 0;                         //  We change value in vector number
            }
            if (i == 9)                                 //  If i have value 9 we must break loop because, array
                break;                                  //  don't have 9 element last is 8
        }

        for (int j = 0; j < 3 ; j++)                    //  This loop we use to columns
        {
            numbers[board[i][j]]++;
        }
    }

    for (int i = 0; i <= 9; i++)                        //  We check second three squares in middle vertical 
    {                                                   
        if (i % 3 == 0 && i != 0)
        {
            for (int k = 1; k < 10; k++)
            {
                if (numbers[k] != 1)
                    return 0;

                numbers[k] = 0;
            }

            if (i == 9)
                break;
        }

        for (int j = 3; j < 6; j++)                     //  change this scope
        {
            numbers[board[i][j]]++;
        }
    }
    
    for (int i = 0; i <= 9; i++)                        //  We check second three squares in right vertical 
    {
        if (i % 3 == 0 && i != 0)
        {
            for (int k = 1; k < 10; k++)
            {
                if (numbers[k] != 1)
                    return 0;

                numbers[k] = 0;
            }

            if (i == 9)
                break;
        }

        for (int j = 6; j < 9; j++)                     //  change this scope
        {
            numbers[board[i][j]]++;
        }
    }

    return 1;
}