/**
 * @file_name alias.c
 * @author Blake Impecoven
 * @date January 21, 2016
**/

#include "alias.h"
#include "../linkedlist/linkedList.h"
#include "../process/process.h"

Alias * convert_data_Alias( void * passed_in )
{
	Alias * al = (Alias *)passed_in;
	
	return al;
}//end convert_data_Alias

Node * buildNode_alias(void * passedIn)
{
	Node * ret = (Node *)calloc(1, sizeof(Node));
	Alias * al = (Alias *)passedIn;
	ret->data = al;
	
	return (void *)ret;
}//end 

void * buildType_alias(char * s)
{
	Alias * al = (Alias *)calloc(1, sizeof(Alias));
	
	//remove "alias " from the front of string and ' from end
	char * noAlias = (char *)calloc(strlen(s) - 5, sizeof(char));
	strncpy(noAlias, s + 6, strlen(s) - 7);

	//snip and copy name portion of string into al->name
	//remove =' from the front of the remaining string
	int x, pos = 0;
	for( x = 0; x < strlen(noAlias); x++ )
		if(noAlias[x] == '=' && pos == 0)
			pos = x;

	al->name = (char *)calloc(pos + 1, sizeof(char));
	strncpy(al->name, noAlias, pos);

	char * noName = (char *)calloc(strlen(noAlias) - (pos + 1), sizeof(char));
	strncpy(noName, noAlias + (pos + 2), strlen(noAlias) - (pos + 2));

	//parse remaining string with makeargs
	int argc = makeargs( noName, &al->command, " \t\n");
	al->length = argc;

	//free up allocated memory
	free(noAlias);
	free(noName);
	
	return (void *)al;
 	
}//end buildType_alias

void printType_alias(void * passedIn)
{
	Alias * al = (Alias *)passedIn;
	int x;

	printf("%s: ", al->name);

	for( x = 0; x < al->length; x++ )
	{
		printf("%s ", al->command[x]);
	}//end for
	
	printf("\n");
}//end printType

void cleanType_alias(void * passedIn)
{
	Alias * al = (Alias *)passedIn;
	int x;

	free(al->name);

	for( x = 0; x < al->length; x++ )
	{
		free(al->command[x]);
	}//end for

	free(al->command);
	free(al);
}//end cleanType


void executeAlias( void * passedIn, char * s )
{
	Alias * al = (Alias *)passedIn;

	strip(s);

	char * stored = (char *)calloc(strlen(s) + 1, sizeof(char));

	strncpy(stored, s, strlen(s));
	
	printf("user: %s, stored: %s\n", stored, al->name);
	
	if(strcmp(al->name, stored) == 0) //is this the alias
		forkIt(al->command);
}//end executeAlias

void checkAlias( char * s, LinkedList * alias_list, int ** ret )
{
	//int * ret;
	*ret = (int *)calloc(2, sizeof(int));
	int count = -1;
	Node * cur = alias_list->head;
	Alias * al;

	do{
		cur = cur->next;// move to next node
		count++;
		al = convert_data_Alias( cur );
		if( strcmp( al->name, s ) == 0 )
			**ret = 1;
	}while(cur->next != NULL );
	
	**(ret + 1) = count;
	
	//return ret;
	
}//end check alias



