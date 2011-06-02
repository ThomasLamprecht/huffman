#ifndef LIST_H
	#define LIST_H
	#include "list.h"
#endif

// ## DOC LIST START
DOC *initDOC(char *content) // <- deprecated ... 
{
	DOC *r=(DOC *) malloc(sizeof(DOC));
	r->next=NULL;
	strncpy(r->content,content,PFR);
	
	return r;
}

DOC *appendDocEntry(DOC *r,char *content)
{	
	if(r==NULL)
	{
		r = (DOC *) malloc(sizeof(DOC));
		r->next = NULL;
		strncpy(r->content, content, PFR);
		return r;
	}
	DOC *actual = getDocListEnd(r);
	
	actual->next = (DOC *) malloc(sizeof(DOC));
	actual->next->next=NULL;
	strncpy(actual->next->content,content,PFR);
	
	return r;	
}

DOC *appendDocEntryHere(DOC *here,char *content)
{
	if(here==NULL)
	{
		here = (DOC *) malloc(sizeof(DOC));
		here->next = NULL;
		strncpy(here->content, content, PFR);
		return here;
	}
	here->next = (DOC *) malloc(sizeof(DOC));
	here->next->next=NULL;
	strcpy(here->next->content,content);
	
	return here;	
}

DOC *mallocDocElement(void)
{
	DOC *e=(DOC *) malloc(sizeof(DOC));
	e->next=NULL;
	
	return e;
}

DOC *getDocListEnd(DOC *r)
{
	DOC *l=r;
	while(l->next!=NULL)
	{
		l=l->next;
	}	
	return l;
}

void printDocList(DOC *r)
{
	DOC *actual=r;
	while(actual!=NULL)
	{
		printf("%s",actual->content);
		actual=actual->next;
	}
	return;
}

void freeDoc(DOC *r)
{
	DOC *actual=r;
	while(actual!=NULL)
	{
		actual = r->next;			
		free(r);
		r=actual;
	}
	free(r);
}

int countDocEntrys(DOC *r)
{
	DOC *actual=r;
	int i=0;
	while(actual!=NULL)
	{
		actual = actual->next;
		i++;
	}
	return i;
}
// ## DOC LIST END

// ## MENU LIST START
GSentry *initMenu(char *name)
{
	GSentry *r=(GSentry *) malloc(sizeof(GSentry));
	int tmp;
	r->next=NULL;
	r->id=0;
	tmp = strlen(name)+1;
	r->entry = (char *) malloc(tmp*sizeof(char));
	strcpy(r->entry,name);
	
	return r;
}

GSentry *getMenuListEnd(GSentry *r)
{
	GSentry *l=r;
	while(l->next!=NULL)
	{
		l=l->next;
	}	
	return l;
}

void appendMenuEntry(GSentry *r,char *name, int id)
{
	int tmp;
	GSentry *actual=getMenuListEnd(r);
	
	actual->next = (GSentry *) malloc(sizeof(GSentry));
	actual->next->next=NULL;
	tmp = strlen(name)+1;
	actual->next->entry = (char *) malloc(tmp*sizeof(char));
	strcpy(actual->next->entry,name);
	actual->next->id = id;
	
	return;	
}

void appendMenuEntryHere(GSentry *here,char *name, int id)
{
	int tmp;
	here->next = (GSentry *) malloc(sizeof(GSentry));
	here->next->next=NULL;
	tmp = strlen(name)+1;
	here->next->entry = (char *) malloc(tmp*sizeof(char));
	strcpy(here->next->entry,name);
	here->next->id = id;
	
	return;	
}

// Sortieren

void sortListBubbled(GSentry **r, char sort_order)
{
	int i=0,j=0,qlen=countEntrys(*r);
	GSentry *actual=*r,*sorted=NULL,*last=NULL;
	// ASCENDING
	if(sort_order==ASC)
	{
		for(i=0;i<qlen;i++)
		{			
			last=NULL;
			while(actual->next!=sorted)
			{
				if(actual->id > actual->next->id)
				{
					swapListElements(r,last,actual);
					actual = (last!=NULL)?last->next:*r;
				}
				else
				{
					last = actual;
					actual = actual->next;
				}
			}
			sorted=actual;
			actual=*r;
		}
	}
	// DESCENDING
	else if(sort_order==DESC)
	{
		for(i=0;i<qlen;i++)
		{			
			last=NULL;
			while(actual->next!=sorted)
			{
				if(actual->id < actual->next->id)
				{
					swapListElements(r,last,actual);
					actual = (last!=NULL)?last->next:*r;
				}
				else
				{
					last = actual;
					actual = actual->next;
				}
			}
			sorted=actual;
			actual=*r;
		}
	}
	return;
}

// swaps two list elements; to swap the root element use NULL as parameter for one of the previous elements
void *swapListElements(GSentry **r,GSentry *prev_el1,GSentry *prev_el2)
{
	if(prev_el1==NULL&&prev_el2==NULL) return NULL;
	if(prev_el1!=NULL)
	{
		if(prev_el1->next==NULL) return NULL;
	}
	if(prev_el2!=NULL)
	{
		if(prev_el2->next==NULL) return NULL;
	}
	GSentry *el1=(prev_el1!=NULL)? prev_el1->next: *r, *el2=(prev_el2!=NULL)? prev_el2->next: *r;
	GSentry *tmp_nxt=NULL;
	
	// Elemente vertauschen
	tmp_nxt = (el1!=prev_el2)?el1->next:el1;
	el1->next = el2->next;
	el2->next = tmp_nxt;
	
	// Prä Elemente vertauschen
	if(prev_el1!=NULL)
		prev_el1->next = el2;
	else *r=el2;
	if(el1!=prev_el2&&prev_el2!=NULL)
		prev_el2->next = el1;
	else if(prev_el2==NULL) *r=el1;
	
	
	return (void *)1;
}

GSentry *getELWhereNext(GSentry *r, GSentry *next)
{
	GSentry *actual=r;
	if(r==NULL||next==NULL) return NULL;
	if(next==r) return getMenuListEnd(r);
	while(actual->next!=next)
	{
		actual = actual->next;
	}
	return actual;
}

void printList(GSentry *r)
{
	GSentry *actual=r;
	while(actual!=NULL)
	{
		printf("%d\t%s\n",actual->id,actual->entry);
		actual=actual->next;
	}
	return;
}

int countEntrys(GSentry *r)
{
	GSentry *actual=r;
	int i=0;
	while(actual!=NULL)
	{
		actual = actual->next;
		i++;
	}
	return i;
}

void freeMenu(GSentry *r)
{
	GSentry *actual=r;
	while(actual!=NULL)
	{
		actual = r->next;			
		free(r);
		r=actual;
	}
	free(r);
}
// ## MENU LIST END

// ## CINFO LIST START
cinfo *initCinfo(char c)
{
	cinfo *r=(cinfo *) malloc(sizeof(cinfo));
	int tmp;
	r->next=NULL;
	r->c = c;
	
	return r;
}

cinfo *getCinfoListEnd(cinfo *r)
{
	cinfo *l=r;
	while(l->next!=NULL)
	{
		l=l->next;
	}	
	return l;
}

cinfo *appendCinfoEntry(cinfo *r,char c)
{
	if(r==NULL)
	{
		r = (cinfo *) malloc(sizeof(cinfo));
		r->next = NULL;
		r->c = c;
		r->n = 0;
		return r;
	}
	cinfo *actual=getCinfoListEnd(r);
	
	actual->next = (cinfo *) malloc(sizeof(cinfo));
	actual->next->next=NULL;
	actual->next->c = c;
	actual->next->n = 0;
	return actual->next;	
}

cinfo *appendCinfoEntryHere(cinfo *here, char c)
{
	if(here==NULL)
	{
		here = (cinfo *) malloc(sizeof(cinfo));
		here->next = NULL;
		here->c = c;
		here->n = 0;
		return here;
	}
	here->next = (cinfo *) malloc(sizeof(cinfo));
	here->next->next=NULL;
	here->next->c = c;
	
	return here->next;	
}

void printCinfoList(cinfo *r)
{
	cinfo *actual=r;
	while(actual!=NULL)
	{
		printf("'%c' (%d)\tn:= %lu\n",actual->c,actual->c,actual->n);
		actual=actual->next;
	}
	return;
}

cinfo *mallocCinfoElement(void)
{
	cinfo *e=(cinfo *) malloc(sizeof(cinfo));
	e->next=NULL;
	e->n = 0;
	return e;
}

cinfo *isInCinfo(cinfo *r, char c)
{
	cinfo *l=r;
	while(l!=NULL)
	{
		if(l->c==c) return l;
		l=l->next;
	}	
	return NULL;
}

void freeCinfo(cinfo *r)
{
	cinfo *actual=r;
	while(actual!=NULL)
	{
		actual = r->next;			
		free(r);
		r=actual;
	}
	free(r);
}

int countCinfoEntrys(cinfo *r)
{
	cinfo *actual=r;
	int i=0;
	while(actual!=NULL)
	{
		actual = actual->next;
		i++;
	}
	return i;
}

// Do insert 'prev_el' as root element use NULL as 'prev_ins' parameter
cinfo *inserCinfoElement(cinfo *r, cinfo *prev_el, cinfo *prev_ins)
{
	cinfo *el;
	if(prev_el==NULL) return r;
	el = prev_el->next;
	prev_el->next = el->next;
	if(prev_ins==NULL)
	{		
		el->next = r;
		return el;
	}
	el->next = prev_ins->next;
	prev_ins->next = el;
	return r;	
}

// swaps two list elements; to swap the root element use NULL as parameter for one of the previous elements
void *swapCinfoElements(cinfo **r,cinfo *prev_el1,cinfo *prev_el2)
{
	if(prev_el1==NULL&&prev_el2==NULL) return NULL;
	if(prev_el1!=NULL)
	{
		if(prev_el1->next==NULL) return NULL;
	}
	if(prev_el2!=NULL)
	{
		if(prev_el2->next==NULL) return NULL;
	}
	cinfo *el1=(prev_el1!=NULL)? prev_el1->next: *r, *el2=(prev_el2!=NULL)? prev_el2->next: *r;
	cinfo *tmp_nxt=NULL;
	
	// Elemente vertauschen
	tmp_nxt = (el1!=prev_el2)?el1->next:el1;
	el1->next = el2->next;
	el2->next = tmp_nxt;
	
	// Prä Elemente vertauschen
	if(prev_el1!=NULL)
		prev_el1->next = el2;
	else *r=el2;
	if(el1!=prev_el2&&prev_el2!=NULL)
		prev_el2->next = el1;
	else if(prev_el2==NULL) *r=el1;
	
	
	return (void *)1;
}
// ## CINFO LIST END
