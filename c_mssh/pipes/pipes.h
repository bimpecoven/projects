#ifndef PIPES_H
#define PIPES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

// Pipe protos
int containsPipe(char *s);
char ** parsePrePipe(char *s, int * preCount, char delimeter);
char ** parsePostPipe(char *s, int * postCount, char delimeter);
void pipeIt(char ** prePipe, char ** postPipe);

// Redirect protos
int containsLeftRedir( char * s );
int containsRightRedir( char * s );
void executeRedir(char ** preRedir, char ** postRedir, char type);

#endif 

