/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2015 Assignment #1 
* Full Name        : Timothy Keane Novice
* Student Number   : s3572290
* Start up code provided by Paul Miller
***********************************************************************/
#include "player.h"

/* Defined "," delimiter for extracting coordinates from player input for playe
 * turn*/
/**
 * @file player.c contains functions to manage the @ref player data structure
 * which represents either a @ref HUMAN or @ref COMPUTER player
 **/

/**
 * @param human a pointer to the human player's struct @param token a pointer
 * to where a copy of the human player's token is stored so it can be accessed
 * later @return a result status indicating whether i/o was successful or not
 * or if the user pressed enter or ctrl-d on an empty line.
 **/
enum cell * token;

/* TN added function to trim end of line and test negative*/
char *trim(char *str) 
{
    int ch = strlen(str) - 1;
    if((ch > 0) && (str[ch] == '\n'))
        str[ch] = '\0';
    return str;
}

enum input_result init_human_player(struct player * human, enum cell * token)
{
    unsigned int len;
    /* collect human players name and assign token */
    printf("\nEnter your name: ");
    /* TN collect input and test for end of file */
    if(fgets(human->name, NAMELEN, stdin) == NULL)
    {
        /* TN Test for end of file*/ 
        if(feof(stdin) == RTM)
        {
            printf("\nPlayer name EOF read failure\n"); 
            return FAILURE;
        }  
    }
    len = strlen(trim(human->name));
    if(len == 0)
    {
        printf("\nInvalid Player name\n");
        return RTM;
    }
    human->name[len] = '\0';
    
    /* TN randomly allocate token*/
    human->token = random_token_allocator();
    /* TN Test code */
    if(human->token == C_NOUGHT)
        printf("\nhuman player has been assigned nought\n");
    else if(human->token == C_CROSS)
        printf("\nhuman player has been assigned cross\n"); 
    else
        printf("\n Token allocation has failed\n");

    human->type = HUMAN;    
      
    *token = human->token;
    return SUCCESS;
}

/**
 * @param computer a pointer to the computer player struct @param token the
 * token for the human player - the computer one needs to be the opposite
 * @return an indication of i/o success or failure which in this case can be
 * safely ignored as there is no i/o. It is only part of the interface so that
 * human and computer functions are called in a uniform way.
 **/
enum input_result init_computer_player(struct player * computer, enum cell token)
{
    strncpy(computer->name, "Computer", NAMELEN);
    switch(token)
    {
        case C_CROSS: computer->token = C_NOUGHT;
            break;
        case C_NOUGHT: computer->token = C_CROSS;
            break;
        default:
            printf("\nInvalid token for init_computer_player \n");
            return FAILURE;
    }
    computer->type = COMPUTER;
    return SUCCESS;
}

/**
 * @param player the player to display the name of @return a pointer to the
 * player's name
 **/
const char * player_to_string(const struct player* player)
{
    return player->name;
}

/**
 * @param board the gameboard to insert the token into @param player a pointer
 * to the player struct that represents the current player.  @return a value
 * indicating whether any i/o operations were successful
 **/
/* TN Declare supporting function for take_turn - not shared*/
enum input_result get_computer_move(game_board board, int *, int *);
enum input_result get_human_move(game_board board, int *, int *);

enum input_result take_turn(game_board board, struct player * player)
{
    enum input_result interim_result;
    int move_col, move_row;
    printf("\nThe current player is %s\n", player->name);
    if(player->type == COMPUTER)
    {
        interim_result = get_computer_move(board, &move_col, &move_row);
        if(interim_result != SUCCESS)
        {
            return interim_result;
        }
        board[move_row][move_col] = player->token;
        
        return SUCCESS;
    }
    else if(player->type == HUMAN)
    {
        interim_result = get_human_move(board, &move_col, &move_row);
        if(interim_result != SUCCESS)
        {
            return interim_result;
        }   
        board[move_row][move_col] = player->token;

        return SUCCESS;   
    }
    else
    {
        /* TN Error to catch no player type values (should never happen)*/
        printf("\nFatal Error: Failed to initialize player, aborting\n"); 
        return RTM;
    }
    return SUCCESS;
}
enum input_result get_computer_move(game_board board, 
                                    int * move_col, int * move_row)
{
    int row, col;
    int count = 0;
    int selected;
    for(row = 0; row < BOARDHEIGHT; row++)
    {
        for(col = 0; col < BOARDWIDTH; col++)
        {
            if(board[row][col] == C_EMPTY)
                count++;
        }
    }
    /* Test for run time error condition on computer turn*/
    if(count == 0)
    {
        printf("\n No cell available for computer move\n");
        return FAILURE;
    }   
    /* randomly select computer move values over empty cells*/
    selected = rand() % count + 1;
    
    for(row = 0; row < BOARDHEIGHT; row++)
    {    
        for(col = 0; col < BOARDWIDTH; col++)
        {
            if(board[row][col] == C_EMPTY)
            {
                if(--selected == 0)
                {
                    *move_row = row;
                    *move_col = col;
                    return SUCCESS;
                }
            }
        }
    }
    printf("\n Failed to find computer move\n");
    return FAILURE;
}
static void read_rest_of_line(void)
{
        int ch;
        while(ch = getc(stdin), ch != '\n' && ch != EOF)
                ;
        clearerr(stdin);
}
enum input_result get_human_move(game_board board, 
                                 int * move_col, int * move_row)
{
    int len;
    char human_turn_input[4];
    /* TN human turn input [0] = column char */
    /* TN human turn input [1] = ',' */
    /* TN human turn input [2] = row char */
    /* TN human turn input [3] = '\0' */
    BOOLEAN input_error;
    /* TN request coordinate input until input tests valid*/
    do
    {
        /* TN collect human players token coordinates*/
        input_error = FALSE;
        printf("\nPlease enter a comma separated coordinate such as \"A,1\"" 
               " for where you wish to place your token: \n");
        /* TN collect user coordinates input */
        if(fgets(human_turn_input, 4, stdin) == NULL)
        {
            printf("\nDEBUG: failed to collect human coordinate input\n");
            return RTM; 
        }
        read_rest_of_line();
        /*TN check length of input*/
        if(input_error == FALSE)     
        {
            len = strlen(trim(human_turn_input));
            if(len != 3)
            {
                printf("\nInvalid input length\n");
                input_error = TRUE;
            }
        }
        /* TN Test column input and setting value */        
        if(input_error == FALSE) 
        {
            switch(human_turn_input[0])
            {
                case 'A':
                    *move_col = 0;
                    break;
                case 'B':
                    *move_col = 1;
                    break;
                case 'C':
                    *move_col = 2;
                    break;
                default:
                    printf("\nInvalid column input\n");
                    input_error = TRUE;             
            }
        } 
        /* TN Test row input and setting value */       
        if(input_error == FALSE) 
        {   
            switch(human_turn_input[2])
            {   
                case '1':
                    *move_row = 0;
                    break;
                case '2':
                    *move_row = 1;
                    break;
                case '3':
                    *move_row = 2;
                    break;
                default:
                    printf("\nInvalid row input\n");
                    input_error = TRUE;
            }
        }
        if(input_error == TRUE)
        {
            printf("\nError: %s is not a valid coordinate string.\n", 
                   human_turn_input); 
        }
        /* TN test for empty cell*/
        if(input_error == FALSE)
        {
            if(board[*move_row][*move_col] != C_EMPTY)
            {
                printf("\nError: that location is already taken.\n");
                input_error = TRUE;
            }
        }   
    }
    while(input_error == TRUE);      
    
    return SUCCESS;
}
