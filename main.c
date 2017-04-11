/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2015 Assignment #1
* Full Name        : Timothy Keane Novice
* Student Number   : s3572290
* Start up code provided by Paul Miller
***********************************************************************/
#include "main.h"

/** @mainpage CPT220 - Assignment 1 documentation.
 *
 * This is the main html documentation of assignment 1 for CPT220 - Programming
 * in C for study period 4, 2015. You will find here a description of the
 * functions that you need to implement for your assignment.
 *
 * Please note that this should not be your first stop when starting your
 * assignment. Please read the assignment 1 specifications that are available
 * on blackboard before reading this documentation. The purpose of this
 * documentation is to clarify the actual individual requirements.
 *
 * This site presents you with the documentation for each function that you
 * need to implement broken down by the file that they exist in. Please go to
 * the <b>Files</b> tab and click on the file you wish to get more information
 * about and then click on that file. An explanation of each function
 * implemented in that file will be displayed.
 *
 **/

/**
 * @file main.c this file contains the main function call and any supporting
 * functions you may choose to implement such as for management of the main
 * menu.
 **/

/**
 * Entry point into the program - displays the main menu and controls the
 * overall flow of the program. Please interpret all comments without code in
 * this as hints at getting started with implementing this program - they are
 * the "larger dotpoints* for how the main menu is meant to work.
 **/
int main(void)
{
    /* variable that holds the menu choice selected by the user */
    enum menuchoice choice;
    char rawinput[1];
    char *end; 
    long intinput;
    /* scoreboard where the most recent games played is stored */
    score scoreboard[NUM_SCORES];
    /* structs representing the data for the human and computer players */
    struct player computer, human;
    /* a pointer to the winner - this will be NULL if the game was a draw 
     * or the human player chose to quit the game half way through */
    struct player *winner;

    /* TN Seeds the random generator for Computer player behaviour */
    srand(time(NULL));
    do  
    {            
        printf("\n\tWelcome to tictactoe\n\n");
        printf("\n1. Play Game\n");
        printf("\n2. Display High Scores\n");
        printf("\n3. Quit\n");
        printf("\n\nPlease enter your choice:\n");
        fgets(rawinput, sizeof(rawinput + 2), stdin);
        intinput = strtol(rawinput, &end, 10);
        /* TN Check if long integer input has been recorded properly 
         * then check the recorded long matches the acceptible range of 
         * selections*/		
        if((intinput < 1) || (intinput > 3))
        {
            printf("\n\nInvalid selection, try again: \n");
        }
        else
        {
            /* TN On successful input checking assign to enum variable 
             * and apply to appropriate menu case*/
            choice = intinput;
            switch(choice) 
            {
            /* TN Case 0 and 3 are there to account for Enumeration places*/
                case CHOICE_ZERO:
                    /* TN Enumeration placekeeper*/
                    break;
                case CHOICE_ONE:
                    /* TN Inititialize game loop and then make decision
                     * based on win/loss outcome*/
                    /* initialise the scoreboard */
                    init_scoreboard(scoreboard);



                    /* TN main game loop */
                    winner = play_game(&human, &computer);
                    if(winner) 
                    {
                        if(winner->type == HUMAN)
                        {
                            printf("\n%s You Win!\n",winner->name);
                        }
                        else
                        {
                            printf("\nYou got roasted by bad AI!\n");
                        }
                        add_to_scoreboard(scoreboard, winner);
                    }
                    else
                    { 
                        printf("\nThe Game is tied! Try Again.\n");
                    }     
                    break;
                case CHOICE_TWO:
                    /* Displays current leader board */
                    display_scores(scoreboard);
                    break;
                case CHOICE_THREE:
                    /* Enumeration placekeeper*/
                    break;
                default:
                    printf("\nERROR:%d Incorrect menu option\n", choice);
                    /* TN end of game options menu*/
            }
         }
    }
    while (intinput != 3);
 
    printf("\n\n Thank you for playing, see you next time\n");
   
    /* initialise the scoreboard */
    /* get input from the user - which menu item would they like to
     * select?
     */
    /* process their menu choice */
    /* handle a request to play a game */
    /* if there is a winner, display a
     * message about who the winner is and
     * add them to the scoreboard */
    /* otherwise, display a message that
     * there was no winner */
    /* handle a request to display the high
     * scores */
    /* handle any invalid input */
    /* ensure that you also handle a request to
     * quit the program
     */
    return EXIT_SUCCESS;
}
