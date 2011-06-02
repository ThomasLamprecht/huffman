#ifndef IO_H
	#define IO_H
	#include "io.h"
#endif

DOC *readFile(const char *name)
{
	FILE *f;
	DOC *r=mallocDocElement(),*actual=r;
	char puffer[PFR];
	
	if((f=fopen(name,"r"))==NULL)
	{
		uprintf("Error:: File couldn't be opened!\n");
		return NULL;
	}
	if(fgets(puffer,PFR,f)==NULL)
	{
		uprintf("Error:: File empty!\n");
		return NULL;
	}
	fseek(f,0L,SEEK_SET);	
	while(fgets(puffer, PFR, f)!=NULL)
	{
		strcpy(actual->content,puffer);
		actual->next = mallocDocElement();
		actual = actual->next;
	}
	return r;
}

void uprintf(char *text)
{
	char c,*r=text;
	while((c=*r)!='\0')
	{
		putchar(c);
		r++;
	}
	putchar(c);
	return;
}

void usprintf(const char *text, size_t l)
{
	size_t i=0;
	char c;
	while((c=text[i])!='\0'&&i<l-1)
	{
		putchar(c);
		i++;
	}
	putchar(c);
	return;
}

// Flushes the stdin
void mFlush()
{
	char c;
	while((c=getchar())!=EOF&&c!='\n')
		continue;
	return;
}
// Overwrites (one) linefeed with NUL 
void rmNl(char *s, int l)
{
	int i;
	for(i=0;s[i]!='\n'&&i<l;i++)
		continue;
	s[i]='\0';
	return;
}
// Sets a full char Array to \0
void clrs(char *s, int l)
{
	int i;
	for(i=0;i<l;i++)
		s[i]='\0';
	return;
}
