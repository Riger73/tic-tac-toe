/*tic-tac-toeTictactoe implementation made the following assuption:

1) cur_token was intended for use in holding token to test for win scenario.
2) The provided static "read_end_of_line()" function could be moved for usage within the file needing it.
I moved it to test EOL in player.c
3) Where magic numbers were used I believed they were the must robust solution given available options and commented clearly their purpose. 
4) To keep startup code recognisable from markable code I have labelled my own comments with my initials 'TN'.


The following functions were crewated to facility modular functionality:

char *trim() // trim the end of line of raw user input

enum cell random_token_allocator() // used to randomely allocate tokens in a modular way.

Application shortcomings:

I was unable to implement scoreboard in time for submission so have commented out my coding attempts. At the bottom of scoreboard.c I have included psuedocode for this file functions. */

