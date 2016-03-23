// Blake Impecoven -- October, 2015.

//      --fileUtil.h--      //

#ifndef FILEUTIL_H
#define FILEUTIL_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//     --PROTOTYPES--      //
int countRecords(FILE * fin, int linesPerRecord);

FILE * openInputFile_Args(int argc, char *argv[]);
FILE * openInputFile_String(char *fileName);
FILE * openOutputFile_FileName(char *fileName);

void displayFileContents(int num, FILE * fin);
void displayFile_OutputFile(FILE * fin, FILE * fout);
void displayFile_FilePointer(FILE * fin);

void readFileName(char *fileName);

FILE * openInputFile_Prompt();
FILE * openOutputFile_Prompt();

#endif
