#ifndef HUFFMAN_H
	#define HUFFMAN_H
	#include "huffman.h"
#endif

cinfo *buildCinfo(DOC *doc_r)
{
	cinfo *r = mallocCinfoElement(), *actual = r, *last = r, *tmp=NULL;
	DOC *doc_actual = doc_r;
	short int i;
	char c;
	r->c = doc_r->content[0];
		
	while(doc_actual!=NULL)
	{
		for(i=0;(c=doc_actual->content[i])!='\0';i++)
		{
			if((tmp=isInCinfo(r,c))!=NULL)
			{
				tmp->n++;
			}
			else
			{
				last = appendCinfoEntryHere(last,c);
				last->n++;
			}
		}
		doc_actual = doc_actual->next;
	}
	
	return r;
}


