#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <dirent.h>

#ifndef MYLS_C
#define MYLS_C

//--Prototypes
void print_perms(struct stat *sys);
void print_ids(struct dirent * dirp);
void print_sys(struct stat * sys)

#endif //myLS
