/**
 * @file_name commands.h
 * @author Blake Impecoven
 * @date January 21, 2016
**/

#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct linkedlist LinkedList;

int HISTCOUNT;
int HISTFILECOUNT;

//--Prototypes
void init_boot(FILE * fin, LinkedList * alias_list, char ** path);
void readAlias(FILE * fin, LinkedList * alias_list);
int read_hist_file(FILE * hist_fin, LinkedList * hist_list);

//char * get_last(LinkedList * hist_list);

#endif
