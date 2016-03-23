// Blake Impecoven - CSCD340 - Generic Linked List - January, 2016.

/* Linked List Data Structure
The following implementation of the linked
list data structure is singly linked and
contains a dummy head node.
**/

#include "linkedList.h"

//Constructor
LinkedList * linkedList() //--Creates list with a Dummy Head and Tail Node
{
	LinkedList * myList = ( LinkedList * )calloc( 1, sizeof( LinkedList ));
	myList->head = ( Node * )calloc( 1, sizeof( Node )); 
	myList->start = myList->head;
	return myList;
}//end constructor

void setStart(LinkedList * myList, int type)
{
	int diff, x;

	if(type == 0) // Type is HISTCOUNT
	{
		if( myList->size > HISTCOUNT )
		{
			diff = myList->size - HISTCOUNT;
		
			for( x = 0; x < diff; x++ )
			{
				myList->start = myList->start->next;
			}//end for
		}//end if
	}//end if

	else if(type == 1)// type is HISTFILECOUNT
	{
		if( myList->size > HISTFILECOUNT )
		{
			diff = myList->size - HISTFILECOUNT;
		
			for( x = 0; x < diff; x++ )
			{
				myList->start = myList->start->next;
			}//end for
		}//end if
	}//end else
}//end setStart

void printSection(LinkedList * myList, void (*convertData)(void *), int type)
{
	Node * cur;
	
	if(type == 0)
	{
		if(myList->size > HISTCOUNT)
			cur = myList->start;
		else
			cur = myList->head->next;

		while( cur != NULL )
		{
			convertData( cur->data );
			cur = cur->next;
		}//end while
	}//end if

	else if(type == 1)
	{
		if(myList->size > HISTFILECOUNT)
			cur = myList->start;
		else
			cur = myList->head->next;

		while( cur != NULL )
		{
			convertData( cur->data );
			cur = cur->next;
		}//end while
	}//end if
}//end printSection



void addLast(LinkedList * myList, Node * newNode)
{
	if( newNode == NULL )
	{
		printf("Error!\nCannot add Empty Node to the list.\n");
		exit(-99);
	}	
	
	if( myList->head->next == NULL ) // is the list empty?
		addFirst( myList, newNode );

	Node * cur = myList->head;

	while( cur->next != NULL )
	{
		cur = cur->next;
	}//end while

	cur->next = newNode;
	newNode->next = NULL;
	myList->size = myList->size + 1;

}//end addLast

void addFirst(LinkedList * myList, Node * newNode)
{
	newNode->next = myList->head->next;
	myList->head->next = newNode;
	myList->size = myList->size + 1;
}//end addFirst

void removeItem(LinkedList * myList, Node * deleteMe, void (*removeData)(void *), int (*compare)(const void *first, const void *second))
{
	Node * cur = myList->head->next;
	Node * prev = NULL;

	if(compare( cur->data, deleteMe->data ) == 0) // check if its the first item
	{
		myList->head->next = cur->next;
		removeData( &cur->data );
		myList->size = myList->size - 1;
	}//end if
	
	else
	{
		while( compare( cur->data, deleteMe->data ) != 0 && cur->next != NULL )
		{	
			prev = cur;
			cur = cur->next;
		}//end while

		if( cur == NULL )
		{
			printf( "Item not in list!\n" );
			exit( -99 );
		}//end if

		else
		{
			if( compare( cur->data, deleteMe->data ) == 0 )
			{
				prev->next = cur->next;
				removeData( cur->data );	
				myList->size = myList->size - 1;
			}//end if
		}//end else
	}//end else
	free( deleteMe->data );
	free( deleteMe );
}//end removeItem

void clearList(LinkedList * myList, void (*cleanType)(void *))
{
	Node * cur = myList->head->next;
	Node * freeMe;
	
	while( cur != NULL )
	{
		myList->head->next = cur->next;
		cleanType( cur->data );
		freeMe = cur;
		cur = myList->head->next;
		free( freeMe );
	}//end while
	myList->size = 0;
	free( myList->head );
	//free(cur);
}//end clearList

void printList(const LinkedList * myList, void (*convertData)(void *))
{
	if( myList->size < 1 )
		printf( "Empty List\n" );

	Node * cur = myList->head->next;

	while( cur != NULL )
	{
		convertData( cur->data );
		cur = cur->next;
	}//end while

}//end printList


