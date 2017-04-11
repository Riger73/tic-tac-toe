/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2015 Assignment #1 
* Full Name        : Timothy Keane Novice
* Student Number   : s3572290
* Start up code provided by Paul Miller
*********************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "shared.h"


/** @file helpers.h contains the constants and data structure definitions
 * required for any functions defined in @ref helpers.c
 **/ 
#ifndef HELPERS_H 
#define HELPERS_H



/* TN added random token allocation function*/
enum cell random_token_allocator();   


/**
 * enumeration that represents the various outcomes of an i/o operation
**/

enum input_result
{
        /**
         * the input/output operation failed
         **/
        FAILURE,

        /**
         * the input/ouput operation succeeded
         **/
        SUCCESS,

        /**
         * the user pressed ctrl-d or 'enter' at the beginning of a line
         **/
        RTM
};


#endif
