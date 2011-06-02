#ifndef STDIO_H
	#define SDTIO_H
	#include <stdio.h>
#endif
#ifndef STDLIB_H
	#define SDTLIB_H
	#include <stdlib.h>
#endif
#ifndef STRING_H
	#define STRING_H
	#include <string.h>
#endif

#define PFR 255
#define ASC 0
#define DESC 1
// CINFO
typedef struct _cinfo
{
	char c;
	unsigned long int n;
	struct _cinfo *next;
} cinfo;

// DOC
typedef struct _doc
{
	char content[PFR];
	struct _doc *next;
} DOC;

/*typedef struct _content
{
	char content[PFR];
	struct content *next;
} content;

typedef struct _doc2
{
	content *start;
	struct _doc2 *next;
} DOC2; */

// MENU
typedef struct _GSentry
{
	char *entry;
	int id;
	struct _GSentry *next;
} GSentry;

// MENU List functions
GSentry *initMenu(char *name); // deprecated
void appendMenuEntry(GSentry *star, char *name, int id);
void appendMenuEntryHere(GSentry *here,char *name, int id);
GSentry *getMenuListEnd(GSentry *r);
GSentry *getELWhereNext(GSentry *r, GSentry *next);
void printList(GSentry *r);
int countEntrys(GSentry *start);
void freeMenu(GSentry *start);
// MENU List sorting
void *swapListElements(GSentry **r,GSentry *prev_el1,GSentry *prev_el2);
void sortListBubbled(GSentry **r, char sort_order);

// cinfo List zeugs
cinfo *initCinfo(char c); // deprecated
cinfo *getCinfoListEnd(cinfo *r);
cinfo *appendCinfoEntry(cinfo *r,char c);
cinfo *appendCinfoEntryHere(cinfo *here,char c);
cinfo *mallocCinfoElement(void);
cinfo *isInCinfo(cinfo *r, char c);
void printCinfoList(cinfo *r);
int countCinfoEntrys(cinfo *start);
void freeCinfo(cinfo *start);
// Sorting Cinfo
void *swapCinfoElements(cinfo **r,cinfo *prev_el1,cinfo *prev_el2);

// DOC List zeugs
DOC *initDOC(char *name); // deprecated
DOC *getDocListEnd(DOC *r);
DOC *appendDocEntry(DOC *r,char *content);
DOC *appendDocEntryHere(DOC *here,char *content);
DOC *mallocDocElement(void);
void printDocList(DOC *r);
int countDocEntrys(DOC *start);
void freeDoc(DOC *start);
