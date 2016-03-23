#include "myLS.h"

int main(int argc, char ** argv)
{
	DIR *dp;
	struct dirent *dirp;
	struct stat sys;
	//char * path = NULL;
	//int count = 1;

	if(argc != 2)
	{
	    perror("Not enough arguments\n");
	    exit(-1);
	    
	}// end if
	
	if( (dp = opendir(argv[1])) == NULL)	//--opens the directory from args thats was passed in by the user
	    perror("Could not open directory\n");
	
	while( (dirp = readdir(dp)) != NULL)
	{
		//path = argv[count];
		stat(argv[1], &sys);		//--reassigns "sys" stat so we dont print the same info.
		
		if(S_ISREG(sys.st_mode))		//--check to see if this is a regular file, if not its a directory
		{
			printf("Regular file passed in.");
		}//end if
		else
		{
			stat(dirp->d_name, &sys);
			printf("%s ", dirp->d_name);
			print_perms(&sys);
			printf(" %G %g", sys.st_uid, sys.st_gid);
			printf("%d ", (int)sys.st_size);
			
			//printf("Total size, in bytes: %d\n", (int)sys.st_size);
			
			printf("%s\n", ctime(&sys.st_mtime));
			//printf(" %s", dirp->d_name);
			
			//printf("\n");
		}//end else
		//count++;
	}//end while

	return 0;

}// end main


void print_ids(struct dirent * dirp)
{
	
}//end prind_ids

void print_sys(struct stat * sys)
{

}//end print_sys

void print_perms(struct stat *sys)
{
	printf("-");
	
	//--User
	if(sys->st_mode & S_IRUSR)
		printf("r");
	else
		printf("-");
	if(sys->st_mode & S_IWUSR)
		printf("w");
	else
		printf("-");
	if(sys->st_mode & S_IXUSR)
		printf("x");
	else
		printf("-");

	//--Group
	if(sys->st_mode & S_IRGRP)
		printf("r");
	else
		printf("-");
	if(sys->st_mode & S_IWGRP)
		printf("w");
	else
		printf("-");
	if(sys->st_mode & S_IXGRP)
		printf("x");
	else
		printf("-");

	//--Others
	if(sys->st_mode & S_IROTH)
		printf("r");
	else
		printf("-");
	if(sys->st_mode & S_IWOTH)
		printf("w");
	else
		printf("-");
	if(sys->st_mode & S_IXOTH)
		printf("x");
	else
		printf("-");

}//end printPerms

