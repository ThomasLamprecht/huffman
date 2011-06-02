/*
This is (part of) a simple dynamical menu based on lists
Copyright (C) 2011  Thomas Lamprecht

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
or look at http://www.gnu.org/licenses/gpl-2.0-standalone.html
*/
#ifndef DYN_MENU_H
	#define DYN_MENU_H
	#include "dyn_menu.h"
#endif

// EXAMPLE
/*int main(void)
{
	srand(time(NULL));
	GSentry *r,*l;
	int selection=-1,id=0,run=1;
	unsigned long int i;
	
	r = initMenu("Add Menu point");
	appendMenuEntry(r,"Nothing (:",++id);
	appendMenuEntry(r,"Sort",++id);
	appendMenuEntry(r,"Quit",++id);
	l = getListEnd(r);
	for(i=0;i<7;i++)
	{
		appendMenuEntryHere(l,"Point",rand()%100);
		l=l->next;
	}
	while(run)
	{
		selection = menuIO(r,_printMenu);
		//selection = menuIO(r,NULL);
		switch(selection)
		{
			case 0: appendMenuEntry(r,"Point",rand()%100); break;
			case 1: printf("Nothing... -.-\nSize: %d\n",countEntrys(r));waitKey('\n'); break;
			case 2:			
			{
				printf("Sorting List\n\n");
				sortListBubbled(&r,(rand()%2)?ASC:DESC);
				printList(r);
				printf("\n-----------------\n\nPress Enter to continue...\n");
				waitKey('\n');
				break;
			}
			case 3:run=0;break;
		}
	}
	freeMenu(r);
	return 0;
} */



void printMenu(GSentry *r, int selected)
{
	GSentry *actual;
	int i;
	system("clear");
	printf("-----------------------\n");
	for(i=0,actual=r;actual!=NULL;actual=actual->next,i++)
	{
		if(i==selected) printf("→");
		printf("\t%d%s%s \n",actual->id,(actual->id>10)?" ":"  ",actual->entry);
	}
	printf("-----------------------\n");
	return;
}

void _printMenu(GSentry *r, GSentry *selected)
{
	GSentry *actual=r;
	system("clear");
	printf("-----------------------\n");
	while(actual!=NULL)
	{
		if(actual==selected) printf("→");
		printf("\t%d%s%s \n",actual->id,(actual->id>10)?"  ":(actual->id>100)?" ":"   ",actual->entry);
		actual = actual->next;
	}
	printf("-----------------------\n");
	return;
}

int menuIO(GSentry *r, void (*echo_func)(GSentry *r, GSentry *selected))
{
	int selected=r->id;
	char sel,size=countEntrys(r);
	GSentry *actual=r;
	if(echo_func!=NULL)(*echo_func)(r,actual);
	while(1)
	{
		sel=getch_nonblock();
		if(sel=='s')
		{
			actual = (actual->next!=NULL)?actual->next:r;
			// selected = (selected+1)%size;
			if(echo_func!=NULL)(*echo_func)(r,actual);			
		}
		if(sel=='w')
		{
			actual = getELWhereNext(r,actual);
			// selected = (selected+size-1)%size;
			if(echo_func!=NULL)(*echo_func)(r,actual);
		}
		if(sel=='\n') return actual->id;
		if(sel=='q')
		{
			GSentry *last=getMenuListEnd(r);
			return last->id;
		}
		usleep(10000);
	}
}

void waitKey(char key)
{
	int run=1;
	while(run)
	{
		usleep(20000);
		if(getch_nonblock()==key) run=0;
	}
	return;	
}

int getch_nonblock(void)
{
	struct termios term, oterm;
	int fd = 0;
	int c = 0;
	tcgetattr(fd, &oterm);
	memcpy(&term, &oterm, sizeof(term));
	term.c_lflag = term.c_lflag & (!ICANON);
	term.c_cc[VMIN] = 0;
	term.c_cc[VTIME] = 1;
	tcsetattr(fd, TCSANOW, &term);
	c = getchar();
	tcsetattr(fd, TCSANOW, &oterm);
	return c; // gibt -1 zurück, wenn kein Zeichen gelesen wurde
}
