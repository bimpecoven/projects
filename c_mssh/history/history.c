#include "../linkedlist/linkedList.h"
#include "history.h"

Node * buildNode_hist(void * passedIn)
{
	Node * ret = (Node *)calloc(1, sizeof(Node));
	history * hist = (history *)passedIn;
	ret->data = hist;

	return (void *)ret;
}//end buildNode_type

void * buildType_hist(int argc, char **argv, int num)
{
	if(argc < 1 || argv == NULL)
		exit(-99);

	history * hist = (history *)calloc(1, sizeof(history));	
	hist->argv = (char **)calloc(argc, sizeof(char *));
	int x;
	
	hist->argc = argc;
	for(x = 0; x < argc; x++)
	{
		hist->argv[x] = argv[x];
	}//end for
	free(argv);	

	hist->num = num;

	return (void *)hist;
}//end buildType_Args

void printType_hist(void * passedIn)
{
	history * hist = (history *)passedIn;
	int x;
	
	printf("%d ", hist->num);
	for(x = 0; x < hist->argc; x++)
	{
		printf( "%s ", hist->argv[x] );
	}//end for
	printf( "\n" );
}//end printType

void printType_histfile(void * passedIn)
{
	history * hist = (history *)passedIn;
	int x;

	FILE * fout = fopen(".mssh_history", "w");
	
	//printf("%d ", hist->num);
	for(x = 0; x < hist->argc; x++)
	{
		fprintf( fout, "%s ", hist->argv[x] );
	}//end for
	fprintf(fout, "\n" );
}//end printType

void cleanType_hist(void * passedIn)
{
	history * hist = (history *)passedIn;
	int x;

	for(x = 0; x < hist->argc; x++)
	{
		free(hist->argv[x]);
	}//end for
	free(hist->argv);
	free(hist);
	
}//end cleanType




