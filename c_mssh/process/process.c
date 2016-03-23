/* 
 * @filename Process.c
 * 
 * @author Blake Impecoven
 * @date 1/16/2016
 *
**/

#include "process.h"

void forkIt(char ** argv)
{
	int status;
	pid_t pid = fork();
	if(pid != 0) // -- If its the parent process
	{
		waitpid(pid, &status, 0);
	}//end if
	else// -- else, it's the child process
	{
		int ret = execvp(argv[0], argv);
		
		if(ret == -1)
			exit(-99);
	}//end else
}//end forkIt
