#ifndef STDIO_H
	#define SDTIO_H
	#include <stdio.h>
#endif
#ifndef STDLIB_H
	#define SDTLIB_H
	#include <stdlib.h>
#endif
#ifndef LIST_H
	#define LIST_H
	#include "list.h"
#endif

typedef struct _tree
{
	unsigned long int n;
	unsigned loved :1;
	struct _tree *r,*l,*next,*parent;
} tree;

tree *initTree(unsigned long int n); // deprecated
tree *getTreeListEnd(tree *r);
tree *appendTreeEntry(tree *r, unsigned long int n);
tree *appendTreeEntryHere(tree *here, unsigned long int n);
tree *mallocTreeNode(void);
tree *cpCinfo(cinfo *src);
void printTreeList(tree *r);
int countTreeEntrys(tree *start);
void freeTreeRow(tree *start);
