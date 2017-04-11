/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2015 Assignment #1 
* Full Name        : Timothy Keane Novice 
* Student Number   : s3572290
* Start up code provided by Paul Miller
***********************************************************************/
#include "helpers.h"

/**
 * @file helpers.c contains all functions used in this program that don't
 * nicely fit into another module. For example, input/output functions and
 * validation functions.
 **/

/**
 * clears the input buffer when there is leftover input in the buffer. 
 * This function should only be called when there is leftover input in the 
 * incoming buffer. Please refer to the fgets manpage (man fgets) on the 
 * university linux servers.
 **/
/* TN Moved read_rest_of_line function to player.c as per text file notes*/
/* static void read_rest_of_line(void)
{
        int ch;
        while(ch = getc(stdin), ch != '\n' && ch != EOF);
        clearerr(stdin);
}*/

enum cell random_token_allocator()
{
    if(rand() % 2 == 1)
        return C_NOUGHT;
    else
        return C_CROSS;
}
    

