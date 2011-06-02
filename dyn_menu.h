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
#ifndef LIST_H
	#define LIST_H
	#include "list.h"
#endif
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define ASC 0
#define DESC 1



// Key stuff
int getch_nonblock(void);
void waitKey(char key);
// I/O
void printMenu(GSentry *start, int selected);
void _printMenu(GSentry *r, GSentry *selected);
int menuIO(GSentry *start, void (*echo_func)(GSentry *start, GSentry *selected));
