/**
 * @file_name makeArgs.c
 * @author Blake Impecoven
 * @date January 21, 2016
**/

#include "makeArgs.h"

void clean(int argc, char **argv)
{
	int x;
	
	for(x = 0; x < argc; x++)
	{
		free(argv[x]);
	}//end for
	
	free(argv);
	argv = NULL;

}// end clean

void printargs(int argc, char **argv)
{
	int x;
	for(x = 0; x < argc; x++)
		printf("%s\n", argv[x]);

}// end printargs

int makeargs(char *s, char *** argv, const char *delimeter)
{
	char * temp = (char *)calloc(strlen(s) + 1, sizeof(char)); //--Copy the string entered by user
	strcpy(temp, s);
	char * temp2 = NULL;
	char * bkpt;
	int x = 0, tokens = 0;
	
	temp2 = strtok_r(temp, delimeter, &bkpt);
	
	while(temp2 != NULL)
	{
		tokens++;
		temp2 = strtok_r(NULL, delimeter, &bkpt);
	}//end while

	*argv = (char **)calloc(tokens + 1, sizeof(char *)); //--Tokens + 1 because we need a null bit
	strcpy(temp, s); //--re-copy s into temp for read into argv

	temp2 = strtok_r(temp, delimeter, &bkpt);
	strip(temp2);
	*((*argv) + x) = (char *)calloc(strlen(temp2) + 1, sizeof(char));
	strcpy(*((*argv) + x), temp2);

	for(x = 1; x < tokens; x++)
	{
		temp2 = strtok_r(NULL, delimeter, &bkpt);
		strip(temp2);
		*((*argv) + x) = (char *)calloc(strlen(temp2) + 1, sizeof(char));
		strcpy(*((*argv) + x), temp2);
	}//end for

	free(temp);
	temp = NULL;

	return tokens;
	
}// end makeArgs
