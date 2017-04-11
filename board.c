/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2015 Assignment #1 
* Full Name        : Timothy Keane Novice
* Student Number   : s3572290
* Start up code provided by Paul Miller
***********************************************************************/
#include "board.h"

/**
 * @file board.c contains function implementations for managing the @ref
 * game_board
 **/
/**
 * @param board the game board to display
 **/


void init_board(game_board board)
{
    int row, col;
    for(row = 0; row < BOARDHEIGHT; row++)
    {
        for(col = 0; col< BOARDWIDTH; col++)
        board[row][col] = C_EMPTY;
    }
}
/**
 * @param board the game board to display
 **/
void display_board(game_board board)
{
    int row, col;
    printf("\nCurrent game board status: \n");
    /* TN Display headings */
    /* TN Added line directly rather than iterating for code readability*/
    printf("\n|---------------|");
    printf("\n|   | A | B | C |");
    printf("\n|---------------|\n");
    for(row = 0; row < BOARDHEIGHT; row++)
    {
        /* TN Print row number */
        printf("| %i |", row + 1);
        /* TN Print cell */
        for(col = 0; col < BOARDWIDTH; col++)
        {
            if(board[row][col] == C_NOUGHT)
            {
                printf(" %c |", C_NOUGHT);
            }
            else if(board[row][col] == C_CROSS)
            {
                printf(" %c |", C_CROSS);
            }
            else if(board[row][col] == C_EMPTY)
            {
                printf(" %c |", C_EMPTY);
            }
            else
            {
                printf(" %c |", '?');
            }
        }
        printf("\n|---------------|\n");
    } 
}
