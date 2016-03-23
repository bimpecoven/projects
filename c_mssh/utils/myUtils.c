/**
 * @file_name myUtils.c
 * @author Blake Impecoven
 * @date January 21, 2016
**/

#include "myUtils.h"

int HISTCOUNT;
int HISTFILECOUNT;

void strip(char *array)
{
	if(array == NULL)
	{
		perror("array is null");
		exit(-99);
	}// end if

	int len = strlen(array), x = 0;
   
	while(array[x] != '\0' && x < len)
	{
		if(array[x] == '\r')
			array[x] = '\0';

		else if(array[x] == '\n')
		 	array[x] = '\0';
		 x++;
	}// end while
   
}// end strip

