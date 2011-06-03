#ifndef TREE_H
	#define TREE_H
	#include "tree.h"
#endif

// ## tree LIST START
tree *initTree(unsigned long int n) // <- deprecated ... 
{
	tree *r=(tree *) malloc(sizeof(tree));
	r->l = r->r = r->parent = r->next = NULL;
	r->n = n;
	r->loved = 0;
	
	return r;
}

tree *appendTreeEntry(tree *r, unsigned long int n)
{	
	if(r==NULL)
	{
		r = (tree *) malloc(sizeof(tree));
		r->l = r->r = r->parent = r->next = NULL;
		r->n = n;
		r->loved = 0;
		return r;
	}
	tree *actual = getTreeListEnd(r);
	
	actual->next = (tree *) malloc(sizeof(tree));
	actual->next->l = actual->next->r = actual->next->parent = actual->next->next = NULL;
	actual->next->n = n;
	actual->next->loved = 0;
	
	return r;	
}

tree *appendTreeEntryHere(tree *here, unsigned long int n)
{
	if(here==NULL)
	{
		here = (tree *) malloc(sizeof(tree));
		here->l = here->r = here->parent = here->next = NULL;
		here->n = n;
		here->loved = 0;
		return here;
	}
	here->next = (tree *) malloc(sizeof(tree));
	here->next->l = here->next->r = here->next->parent = here->next->next = NULL;
	here->next->n = n;
	here->next->loved = 0;
	
	return here;
}

tree *mallocTreeNode(void)
{
	tree *e=(tree *) malloc(sizeof(tree));
	e->next->l = e->next->r = e->next->parent = e->next->next = NULL;
	e->next->loved = 0;
	
	return e;
}

tree *getTreeListEnd(tree *r)
{
	tree *l=r;
	while(l->next!=NULL)
	{
		l=l->next;
	}
	return l;
}

tree *cpCinfo(cinfo *src)
{
	cinfo *lc=src;
	tree *lt = mallocTreeNode();
	while(lc!=NULL)
	{
		lt->n = lc->n;
		lc = lc->next;
		lt = lt->next = mallocTreeNode();
	}
	return lt;
}

void printTreeList(tree *r)
{
	tree *actual=r;
	while(actual!=NULL)
	{
		printf("%lu\n",actual->n);
		actual=actual->next;
	}
	return;
}

void freeTreeRow(tree *r)
{
	tree *actual=r;
	while(actual!=NULL)
	{
		actual = r->next;			
		free(r);
		r=actual;
	}
	free(r);
}

int countTreeEntrys(tree *r)
{
	tree *actual=r;
	int i=0;
	while(actual!=NULL)
	{
		actual = actual->next;
		i++;
	}
	return i;
}
// ## tree LIST END
