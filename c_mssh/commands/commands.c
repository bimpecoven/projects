/**
 * @file_name commands.c
 * @author Blake Impecoven
 * @date January 21, 2016
**/

#include "../linkedlist/linkedList.h"
#include "commands.h"
#include "alias.h"
#include "../utils/fileUtil.h"

void init_boot(FILE * fin, LinkedList * alias_list, char ** path)
{
	char whitespace[MAX];
	char temp[1000];
	char *count_int = NULL;
	char *file_int = NULL;
	int len;

	// We are guarenteed these lines
	fgets( temp, MAX, fin );
	len = strlen(temp) - 10;
	count_int = (char *)calloc(len + 1, sizeof(char));
	strncpy(count_int, temp + 10, len);
	HISTCOUNT = atoi(count_int);
	free(count_int);
	count_int = NULL;

	fgets( temp, MAX, fin );
	len = strlen(temp) - 14;
	file_int = (char *)calloc(len + 1, sizeof(char));
	strncpy(file_int, temp + 14, len);
	HISTFILECOUNT = atoi(file_int);
	free(file_int);
	file_int = NULL;
	
	// file format ensures empty line here
	fgets( whitespace, MAX, fin );

	readAlias(fin, alias_list);

	memset(temp, 0, sizeof(temp));
	fscanf( fin, "%s", temp );
	strip( temp );
	*path = temp;

	fclose(fin);
	
}//end init_boot

void readAlias(FILE * fin, LinkedList * alias_list)
{
	char temp[MAX];
	char * s;

	fgets( temp, MAX, fin );

	while( temp[0] != '\n')
	{
		Node * newAlias = buildNode_alias( buildType_alias( temp ));
		addLast( alias_list, newAlias);
		fgets( temp, MAX, fin );
	} // end while

}//end readAlias

int read_hist_file(FILE * hist_fin, LinkedList * hist_list)
{
	int hist_count = countRecords(hist_fin, 1);
	printf("Records: %d", hist_count);
	//LinkedList * hist_list = linkedList();
	int x;
	char **argv = NULL, s[MAX];

	for(x = 0; x < hist_count; x++)
	{
		fgets(s, MAX, hist_fin);
  		strip(s);
		int argc = makeargs( s, &argv, " \t\n" );
		addLast( hist_list, buildNode_hist( buildType_hist( argc, argv, hist_list->size + 1 )));
	}//end for

	fclose(hist_fin);

	return hist_count;
}//end read_hist_file


/*
char * get_last(LinkedList * hist_list)
{
	Node * cur = hist_list->head;
	int x, size = 0;

	while( cur != NULL )
	{
		cur = cur->next;
	}//end while
	
	for( x = 0; x < cur->data->argc; x++ )
	{
		size = size + strlen( cur->data->*( argv + x )) + 1; //1 is for whitespace
	}//end for

	char * ret = ( char * )calloc( size + 1, sizeof( char ) );
	
	strncpy( ret, cur->data->*( argv ), 0 );
	size = strlen( cur->data->*( argv ) ) + 1;
	for( x = 1; x < cur->data->argc; x++ )
	{
		strncpy( ret, cur->data->*( argv + x ), size );
		size = size + strlen( cur->data->*( argv ) ) + 1;
	}//end for

	return ret;
	
}//end get_last
*/
