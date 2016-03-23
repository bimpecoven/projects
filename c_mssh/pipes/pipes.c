/**
 * @file_name pipes.c
 * @author Blake Impecoven
 *
**/
#include "pipes.h"
#include "../tokenize/makeArgs.h"

int containsPipe(char *s) //--returns number of pipes - This lab only 1
{
	if(strlen(s) == 0)
		exit(-99);
	
	int x, pipes = 0, letters = strlen(s);

	for(x = 0; x < letters; x++)
	{
		if(s[x] == '|') //--Is the letter a pipe
			pipes++;
	}//end for

	return pipes;
}//end containsPipe

char ** parsePrePipe(char *s, int * preCount, char delimeter)
{
	char ** argv = NULL;
	char * preString;

	int x, count = 0, letters = strlen(s);

	for(x = 0; x < letters; x++)
	{
		if(s[x] == delimeter)
		{
			if(s[x - 1] == ' ') //--SPACE before the pipe
			{
				preString = (char *)calloc(x, sizeof(char));
				strncpy(preString, s, x - 1);
			}//end if
			else //--No SPACE before the pipe
			{
				preString = (char *)calloc(x + 1, sizeof(char));
				strncpy(preString, s, x);
			}//end else
		}//end if	
	}//end for

	int argc = makeargs(preString, &argv, " \t\n");
	*preCount = argc;

	free(preString);

	return argv;
}//end parsePrePipe

char ** parsePostPipe(char *s, int * postCount, char delimeter)
{
	char ** argv = NULL;
	char * postString;

	int x, count = 0, letters = strlen(s);

	for(x = 0; x < letters; x++)
	{
		if(s[x] == delimeter)
		{
			if(s[x + 1] == ' ') //--SPACE after the pipe
			{
				postString = (char *)calloc((letters - x) - 1, sizeof(char));
				strncpy(postString, s + (x + 2), (letters - x) - 1);
			}//end if
			else //--No SPACE after the pipe
			{
				postString = (char *)calloc(letters - x, sizeof(char));
				strncpy(postString, s + (x + 1), letters - x);
			}//end else
		}//end if	
	}//end for

	int argc = makeargs(postString, &argv, " \t\n");
	*postCount = argc;

	free(postString);

	return argv;
}//end parsePostPipe

void pipeIt(char ** prePipe, char ** postPipe)
{
	pid_t pid, pid2;
	int fd[2], res, res2, status;	

	pid = fork();
	res = pipe(fd);

	if(res < 0)
	{
		printf("Pipe Failure\n");
		exit(-1);
	}// end if

	if(pid != 0)
	{
		waitpid(pid, &status, 0);
	}//end if parent
		
	else
	{
		pid2 = fork();
		if(pid2 != 0)
		{
			waitpid(pid2, &status, 0);
			close(fd[1]);
			close(0);
			dup(fd[0]);
			close(fd[0]);
			res = execlp(*postPipe, *postPipe, *(postPipe + 1), NULL);
			
			if(res == -1) //--check process
				exit(-99);
		}//end Parent

		else
		{
			close(fd[0]);
			close(1);
			dup(fd[1]);
			close(fd[1]);
			res = execlp(*prePipe, *prePipe, *(prePipe + 1), NULL);
	
			if(res == -1) //--check process
				exit(-99);
		}//end child

	}//end else child

}//end pipeIt




//      	Redirect code






int containsLeftRedir( char * s )
{
	if(strlen(s) == 0)
		exit(-99);
	
	int x, redir = 0, letters = strlen(s);

	for(x = 0; x < letters; x++)
	{
		if(s[x] == '<') 
			redir++;
	}//end for

	return redir;
}//end containsLeftRedir

int containsRightRedir( char * s )
{
	if(strlen(s) == 0)
		exit(-99);
	
	int x, redir = 0, letters = strlen(s);

	for(x = 0; x < letters; x++)
	{
		if(s[x] == '>') 
			redir++;
	}//end for

	return redir;
}//end containsRightRedir

void executeRedir(char ** preRedir, char ** postRedir, char type)
{
	pid_t pid, pid2;
	int fd[2], res, res2, status;	
	FILE * redirect = NULL;

	pid = fork();
	res = pipe(fd);

	if(res < 0)
	{
		printf("Pipe Failure\n");
		exit(-1);
	}// end if

	if(pid != 0)
	{
		waitpid(pid, &status, 0);
	}//end if parent
		
	else
	{
		pid2 = fork();
		if(pid2 != 0)
		{
			waitpid(pid2, &status, 0);
			close(fd[1]);
			redirect = fopen(*postRedir, "w");
				
				//dup(fd[0]);
			fd[1] = fileno(redirect);
			res = execlp(*postRedir, *postRedir, *(postRedir + 1), NULL);
			
			if(res == -1) //--check process
				exit(-99);
		}//end Parent

		else
		{
			
			close(fd[1]);
			redirect = fopen(*postRedir, "w");
				
				//dup(fd[0]);
			fd[1] = fileno(redirect);
			res = execlp(*preRedir, *preRedir, *(preRedir + 1), NULL);
	
			if(res == -1) //--check process
				exit(-99);
		}//end child

	}//end else child
}//end executeRedir

