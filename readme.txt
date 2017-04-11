/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2015 Assignment #1 
*         : Timothy Keane Novice Student Number   : 
s3572290 Start up code provided by Paul Miller
***********************************************************************/

Please write any comments about your implementation which may be useful for
 your marker or a user of your program.



Tictactoe implementation made the following assuption:

1) All elements already provided were intended to be used. 
2) cur_token was intended for use in holding token to test for win scenario.
3) The provided static "read_end_of_line()" function could be moved for usage within the file needing it.
I moved it to test EOL in player.c
4) Where magic numbers were used I believed they were the must robust solution given available options and commented clearly their purpose. 
5) To keep startup code recognisable from markable code I have labelled my own comments with my initials 'TN'.


The following functions were crewated to facility modular functionality:

char *trim() // trim the end of line of raw user input

enum cell random_token_allocator() // used to randomely allocate tokens in a modular way.

Application shortcomings:

I was unable to implement scoreboard in time for submission so have commented out my coding attempts. At the bottom of scoreboard.c I have included psuedocode for this file functions. 


