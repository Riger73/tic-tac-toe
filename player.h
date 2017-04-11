/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2015 Assignment #1 
* Full Name        : Timothy Keane Novice
* Student Number   : s3572290
* Start up code provided by Paul Miller
***********************************************************************/
#include "shared.h"
#include "helpers.h"
#include "board.h"
#ifndef PLAYER_H
#define PLAYER_H
/**
 * @file player.h contains the constants and data structures required to
 * manage each @ref player. 
 **/

/**
 * the maximum length of a name of a player 
 **/
#define NAMELEN 20

/**
 * the two types of player in the game
 **/
enum player_type
{
        /**
         * represents a human player
         **/
        HUMAN,
        /**
         * represents a computer player
         **/
        COMPUTER
};

/**
 * structure that represents a player in the game
 **/
struct player
{
        /**
         * the name of the player
         **/
        char name[NAMELEN + 1];
        /**
         * the type of player
         **/
        enum player_type type;
        /**
         * the player's token
         **/
        enum cell token;
};

/**
 * initialize the human player. This includes getting the name of the 
 * player, setting the player type and randomly selecting a token for the 
 * player
 **/

enum input_result init_human_player(struct player *, enum cell *);

/**
 * initialize the computer player including setting its name to "Computer", 
 * its player type to be Computer and its token to be the opposite to the 
 * one passed in, which is the human token.
 **/
enum input_result init_computer_player(struct player *, enum cell);

/**
 * function called to allow the current player to have their turn which is 
 * different for human and computer players. Please see the assignment 
 * specifications for more detail on expected behaviour.
 **/
enum input_result take_turn(game_board, struct player *);

#endif
