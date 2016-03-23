/**
 * @file linkedList.h
 * @author Blake Impecoven
 * @date 29 Dec 2016
 * @brief The basic doubly linked list
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int HISTCOUNT;

#include "../history/history.h"
#include "../commands/alias.h"

struct node
{
    void * data;
    struct node * next;
};
typedef struct node Node;

struct linkedlist
{
    Node * head;
    Node * start;
    int size;
};
typedef struct linkedlist LinkedList;

LinkedList * linkedList();

void setStart(LinkedList * myList, int type);
void printSection(LinkedList * myList, void (*convertData)(void *), int type);
void addLast(LinkedList * theList, Node * nn);
void addFirst(LinkedList * theList, Node * nn);
void removeItem(LinkedList * theList, Node * nn, void (*removeData)(void *), int (*compare)(const void *, const void *));
void clearList(LinkedList * theList, void (*removeData)(void *));
void printList(const LinkedList * theList, void (*convertData)(void *));

#endif // LINKEDLIST_H
