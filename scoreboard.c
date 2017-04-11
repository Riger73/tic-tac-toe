/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2015 Assignment #1 
* Full Name        : Timothy Keane Novice
* Student Number   : s3572290
* Start up code provided by Paul Miller
***********************************************************************/
#include "scoreboard.h"

/**
 * @file scoreboard.c contains the implementation of functions to manage the
 * scoreboard
 **/

/**
 * @param scoreboard the scoreboard to initialise to an empty board
 **/
void init_scoreboard(score * scoreboard)
{/* TN Attempted implementation
    int num;
    for(num = 0; num < NUM_SCORE; num++)
    {
        memset(scoreboard[num].name, 0, NAMELEN);
        scoreboard[num].type = computer;
        scoreboard[num].token = C_EMPTY;
    } */
}

/**
 * @param scoreboard the scoreboard to add the score to
 * @param newscore the new score to add too the scoreboard
 * @return TRUE when a score is successfully added and FALSE otherwise
 **/
/* TN Started inmplimenting BOOLEAN function to test score insertion on board*/
/*BOOLEAN insert_score(score * scoreboard, const score* newscore, int pos)
{*/
 /* TN Attempted implementation
 * int num;
    for(num = NUM_SCORES - 1; num > 0; num--)
    {
        if(scoreboard[num] > pos)
           return insert 
    }*/
  /*  return FAILURE;
}*/

BOOLEAN add_to_scoreboard(score * scoreboard, const score* newscore )
{
    return FAILURE;
}
   /* TN Attempted implementation
 * int num;
    for(num = 0; num < NUM_SCORES; num++)
    {
        if(scoreboard[num].cur_token == C_EMPTY)
        {
            return insert_score(scoreboard, newscore, num);
        }
        else
        {
            if(strcmp(scoreboard[num].name, newscore->name) > 0)       
                return insert_score(scoreboard, newscore, num); 
        }    
  } */  


/**
 * @param scoreboard the scoreboard to display
 **/
void display_scores(score * scoreboard)
{
}

/* TN  ************** Psuedocode for scoreboard: *******************/
/* * BOOLEAN insert_to_scoreboard(score  scoreboard, const score newscore, 
 * int pos)
 *
 * {
 *
 *  / so that we can shift names down as we need to, we will start from the 
 *     bottom of the list and work up /
 *
 *  * Example 
 *
 *     * We havd two existing scores in a 4 slot scoreboard (NUMSCORES = 4)
 *
 *       * and we want to add "Fred"
 *
 *         * We have already determined that "Fred" belongs in slot index [1]
 *
 *           * The current board is:
 *
 *             * [0] Computer
 *
 *               * [1] Smith
 *
 *                 * [2] <blank>
 *
 *                   * [3] <blank>
 *
 *                     *
 *
 *                       * Then we need to do the following:
 *
 *                         * Score [2] -> [3]
 *
 *                           * Score [1] -> [2]
 *
 *                             * "Fred"    -> [1]
 *
 *                               * 
 *
 *                                 * So we need to start shifting scores down
 *                                     from Score [NUMSCORES-2] -> [NUMSCORES-1]*
 *
 *                                   * until we reach 'pos' (the index
 *                                        where the new score is to be copied)
 *
 *              */

/*

 int index;
*/
 /* so we iterate from the bottom of the list till we get to 'pos'*/

 /* for (index = NUMSCORES - 1; index >= pos; index--)

 {

  if (index == pos)

  {

   / copy score /

   / Pseudocode: scoreboard[index] = newscore */

  /* return TRUE;

  }

  else

  { */

  /* / we need to move a score down / */

   /* even if the score is empty, as we are always storing new scores at the top, it doesnt matter if we copy empty scores as well*/

  /* / Pseudocode: scoreboard[index] = scoreboard[index-1] /

  }

 }



 return FALSE; / program error /

} 
*/
