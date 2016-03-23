/**
 * @file history.h
 * @author Stu Steiner
 * @date 12 Jan 2016
 * @brief Supporting functions for the history
 *
 * The purpose of this file is to outline functions to help build a basic
 * history linked list
 *
 * @note This file will never be changed
 */

#ifndef HISTORY_H
#define HISTORY_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../tokenize/makeArgs.h"
#include "../utils/fileUtil.h"
#include "../utils/myUtils.h"

#define MAX 100

typedef struct node Node;
//typedef struct linkedList LinkedList;

struct hist
{
	int argc;
	int num;
	char ** argv;
}; 

typedef struct hist history;

Node * buildNode_hist(void * passedIn);
void * buildType_hist(int argc, char **argv, int num);
void printType_hist(void * passedIn);
void printType_histfile(void * passedIn);
void cleanType_hist(void * passedIn);

#endif
