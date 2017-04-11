/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2015 Assignment #1 
* Full Name        : Timothy Keane Novice
* Student Number   : s3572290
* Start up code provided by Paul Miller
***********************************************************************/
#include "game.h"
#include "player.h"

/**
 * @file game.c contains the functions required for management of the game
 * while it is being played.
 **/

/**
 * @param human a pointer to the human player struct
 * @param computer a pointer to the computer player struct
 * @return a pointer to the winning player or NULL if there was no
 * winner
 **/
struct player * play_game(struct player * human, struct player * computer)
{  
    /* TN Declaration */ 
    game_board board;
    enum cell human_token;
    struct player * first, * second;
    enum game_result result;
    
    
    /* TN initialize game board */
    init_board(board);
        
    /* TN initialize players and test for successful init conditions*/
    if(init_human_player(human, &human_token) != SUCCESS) 
    {
        printf("\nFailed to initialize human player\n");
        return NULL;
    }
    if(init_computer_player(computer, human_token) != SUCCESS)
    {
        printf("\nFailed to initialize computer player\n");
        return NULL;
    }
    if(human->token == C_NOUGHT)
    {
        first = human;
        second = computer;
    }
    else
    {
        first = computer;
        second = human;
    }
    
    /* Main game loop set to ongoing until interrupted*/
    for(;;)
    {
        /* TN Displays game board, then determines first turn and tests 
         * each turn for win conditions. At the end of a none winning turn 
         * swaps player */
        display_board(board);
        switch(take_turn(board, first))
        {
            case SUCCESS:
            {    
                result = test_for_winner(board, first->token); 
                switch(result)
                {
                    case GR_NOUGHT:
                    case GR_CROSS:
                        display_board(board);
                        return first;
                    case GR_DRAW:
                        display_board(board);
                        return NULL;
                    case GR_NOWINNER:
                        swap_players(&first, &second);
                        /* TN proceed to next take_turn() */
                }
                break;
            }
            case FAILURE:
                printf("\ntake_turn failed\n");
                return NULL; 
            case RTM:
                printf("\ntake_turn RTM \n");
                return NULL;
        }
    }
}

/*
 * @param first the first player passed in
 * @param second the second player passed in
 **/
void swap_players(struct player** first, struct player** second)
{
    struct player* temp_player = *first;
    *first = *second; 
    *second = temp_player; 	
}

/**
 * @param board the game_board passed in
 * @param cur_token
 **/
enum game_result test_for_winner(game_board board, enum cell cur_token)
{
    int row, col;
    /* TN Assumption: That cur_token is for latest move. Only this cell type can
     * be winner*/
    BOOLEAN three_in_row = FALSE;
    BOOLEAN blank_cell = FALSE;
    /* check row */
    for(row = 0; row < BOARDHEIGHT; row++) 
    {
        if((board[row][0] == cur_token) &&
           (board[row][1] == cur_token) &&
           (board[row][2] == cur_token)) 
            three_in_row = TRUE;
    }
    /* check columns */
    for(col = 0; col < BOARDWIDTH; col++)
    {
        if((board[0][col] == cur_token) &&
           (board[1][col] == cur_token) && 
           (board[2][col] == cur_token))
            three_in_row = TRUE;
    }
    /* test diagonals */
    if((board[0][0] == cur_token) &&
       (board[1][1] == cur_token) &&
       (board[2][2] == cur_token))
        three_in_row = TRUE;

    if((board[0][2] == cur_token) &&
       (board[1][1] == cur_token) &&
       (board[2][0] == cur_token))
        three_in_row = TRUE;


    /* TN check for blank cells */
    for(row = 0; row < BOARDHEIGHT; row++)
    {
        for(col = 0; col < BOARDWIDTH; col++)
        {
            if(board[row][col] == C_EMPTY)
                blank_cell = TRUE;
        }
    }
    /* TN Test for correct handling of empty cells*/
    if(blank_cell == TRUE)
        printf("\nDEBUG: Blank cells found\n");
    else
        printf("\nDEBUG: No blank cells found \n");

    /* TN tests and returns game result value*/
    if(three_in_row == TRUE)
    {
        switch(cur_token)
        {
            case C_NOUGHT:
                return GR_NOUGHT;
            case C_CROSS:
                return GR_CROSS;
            /* TN Result returning placekeeper*/
            case C_EMPTY:
            case C_INVALID:    
                return GR_NOWINNER;                       
        }
    }
    /* TN Test for draw or no result*/    
    if(blank_cell == FALSE)
        return GR_DRAW;
    else 
        return GR_NOWINNER;
}


