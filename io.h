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
#ifndef PFR
	#define PFR 255
#endif



DOC *readFile(const char *name);
void uprintf(char *text);
void usprintf(const char *text, size_t l);
void mFlush();
void rmNl(char *s, int l);
void clrs(char *s, int l);
