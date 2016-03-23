
/** 
 *  @filename cscd340hw8.c
 *  @progname mssh
 *  @author Blake Impecoven
 *  @date January 21, 2016
 *  @brief mssh is a mock shell of the bash shell
**/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./linkedlist/linkedList.h"
#include "./pipes/pipes.h"
#include "./utils/myUtils.h"
#include "./utils/fileUtil.h"
#include "./process/process.h"
#include "./tokenize/makeArgs.h"
#include "./history/history.h"
#include "./commands/alias.h"
#include "./commands/commands.h"

extern int HISTCOUNT;
extern int HISTFILECOUNT;

int main()
{
	int argc, hist_count, dir, pipeCount, x;	
 	char **argv = NULL, s[MAX];
  	int preCount = 0, postCount = 0;
  	int * execute;// (int *)calloc(2, sizeof(int));
  	char ** prePipe = NULL, ** postPipe = NULL, **preRedir = NULL, ** postRedir = NULL;
	char * path = NULL;
	LinkedList * hist_list = linkedList(); //--This will store history of size 100
	LinkedList * alias_list = linkedList(); //--This will hold our history file data

//////////--Begin initialization
	//  check for .msshrc, if it's there
	//  open it, otherwise create
	if( access( ".msshrc", F_OK ) != -1 ) //--.msshrc does exist
	{
		//--Since the file exists we are guarenteed
		//  at least the HISTCOUNT and HISTFILECOUNT
		FILE * mssh_fin = fopen( ".msshrc", "r" );
		init_boot( mssh_fin, alias_list, &path );
		printf( ".msshrc successfully loaded.\n" );
		printf("histcount: %d\nhistfilecount: %d\nPath: %s\n", HISTCOUNT, HISTFILECOUNT, path);
		
	}//end if
	else //--.msshrc does NOT exist
	{
		printf( ".msshrc not found, setting globals...\n" );

		HISTCOUNT = 100;
		HISTFILECOUNT = 1000;
	}//end else
	//
	//--Check for history files 
	if( access( ".mssh_history", F_OK ) != -1 ) //--.mssh_history does exist
	{
		FILE * hist_fin = fopen( ".mssh_history", "r" );
		//--Fill our history list
		//
		//hist_count = read_hist_file( hist_fin, hist_list);
		printf( ".mssh_history successfully loaded.\n" );
		
	}//end if
	else //--.mssh_history does NOT exist
	{
		printf( ".mssh_history not found.\n" );
	}//end else
//////////--End initialization




	printf( "Welcome to MSSH!\n\n" );

	printf( "command?: " );
  	fgets( s, MAX, stdin );
  	strip( s );

  	while( strcmp( s, "exit" ) != 0 )
  	{
		int function_flag = 0;
		argc = makeargs( s, &argv, " \t\n" );
		pipeCount = containsPipe( s ); // count pipes present
		int leftRedirCount = containsLeftRedir( s );
		int rightRedirCount = containsRightRedir( s );		

		// Whatever the command may be, must be added to history
		if(strlen( s ) > 0)
		{
			argc = makeargs( s, &argv, " \t\n" );
			addLast( hist_list, buildNode_hist( buildType_hist( argc, argv, hist_list->size + 1 )));
		}//end if

		if( strcmp( s, "history" ) == 0 ) // History command check
      		{
				setStart( hist_list, 0 );
        			printSection( hist_list, printType_hist, 0 );
				//printList( hist_list, printType_hist );
		}//end if

		if(leftRedirCount > 0 || rightRedirCount > 0 || pipeCount > 0) // contains redir or pipe
		{
			function_flag++;

			if( pipeCount > 0 ) // contains a pipe
			{
				if( leftRedirCount > 0 ) // contains pipe and a left redir '<'
				{
					if( leftRedirCount > 0 ) // contains all 3
					{
						
					}//end if
				}//end if
				if( leftRedirCount > 0 ) // contains a pipe right redir '>'
				{

				}//end if
				else // contains only a pipe
				{
					prePipe = parsePrePipe( s, &preCount, '|');
					postPipe = parsePostPipe( s, &postCount, '|');
					pipeIt( prePipe, postPipe );
					clean( preCount, prePipe );
        				clean( postCount, postPipe );
				}//end else
			}//end if
			else if( leftRedirCount > 0 ) // contains a left redir '<'
			{
				if( rightRedirCount > 0 ) // contains a left and right redir '<' & '>'
				{
					
				}//end if
				else // only contains a left redir '<'
				{

					preRedir = parsePrePipe( s, &preCount, '<');
					postRedir = parsePostPipe( s, &postCount, '<' );
					executeRedir(preRedir, postRedir, '<');
					clean( preCount, preRedir );
      				clean( postCount, postRedir );
				}//end else
			}//end if
			else // only contains a right redir '>'
			{
				preRedir = parsePrePipe( s, &preCount, '>');
				postRedir = parsePostPipe( s, &postCount, '>' );
				executeRedir(preRedir, postRedir, '>');
				clean( preCount, preRedir );
        		clean( postCount, postRedir );
			}//end else
		}//end if



		
		// If none of cases hit, just make args and run it
		if( function_flag == 0 )
		{
			argc = makeargs( s, &argv, " \t\n" );
			if( strcmp(argv[0], "alias") == 0)
			{
				argc = makeargs( s, &argv, " ");
				Node * newAlias = buildNode_alias( buildType_alias( s ));
				addLast( alias_list, newAlias);
				printf("Current list of Alias's:\n");
				printList( alias_list, printType_alias ); //See list of alias's
			}//end if
			
			
			
			
/* --was using for alias structure, currently broken, causes a segfault.
			else
			{
				//checkAlias( s, alias_list, &execute ); // lastly we should check for an alias call
				//return value of 1 will execute the alias
				
				Node * cur = alias_list->head->next;
				Alias * run_al;
				if(*(execute + 0) == 1)
				{
					for( x = 0; x < *(execute + 1); x++ )
					cur = cur->next;
				
					run_al = convert_data_Alias( cur->data );
					forkIt( run_al->command );
				}//end if
			}//end else
*/
				
			if ( strcmp( argv[0], "cd" ) == 0 )
				dir = chdir( argv[1] );

	  		if( argc != -1 )
	  			forkIt( argv );
	  
	  		clean( argc, argv );
	  		argv = NULL;
		}//end else

//////////////////////////////////////////////////////////////////////////////////////////
		
			
		
		// Re-prompt for input
		printf( "command?: " );
		fgets( s, MAX, stdin );
      		strip( s );

  	}// end while

	//--Write .mssh_history file
	setStart( hist_list, 1 );
        printSection( hist_list, printType_histfile, 1 );

	//--Clean: history
	clearList( hist_list, cleanType_hist );
   	free( hist_list );
   	hist_list = NULL;
	//
	//--Clean: alias
	clearList( alias_list, cleanType_alias );
	free( alias_list );
	alias_list = NULL;
	//free( execute );
	//
	//  Finished cleaning up memory
	//  Safe to return.

  	return 0;

}// end main

