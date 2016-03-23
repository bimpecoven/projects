/**
 * @file_name alias.h
 * @author Blake Impecoven
 * @date January 21, 2016
**/

#ifndef ALIAS_H
#define ALIAS_H

#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "commands.h"
#include "../tokenize/makeArgs.h"
#include "../utils/myUtils.h"

typedef struct node Node;

struct alias
{
	char * name;
	char ** command;
	int length;
};
typedef struct alias Alias;

// Prototypes
Alias * convert_data_Alias( void * passed_in );
Node * buildNode_alias(void * passedIn);
void * buildType_alias(char * s);
void printType_alias(void * passedIn);
void cleanType_alias(void * passedIn);
void executeAlias( void * passedIn, char * s);
void checkAlias( char * s, LinkedList * alias_list, int ** execute );

#endif
