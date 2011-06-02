/*
This is (part of) a Huffman implementation
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

#include "main.h"

int main(int countArgs, char **args)
{
	int i,j,k,run=1,selection	;
	GSentry *r,*actual;
	
	r = initMenu("Read File");
	appendMenuEntry(r,"Echo File",1);
	appendMenuEntry(r,"Count chars",2);
	appendMenuEntry(r,"Debug",DEBUG);
	appendMenuEntry(r,"Quit",QUIT);
	
	while(run)
	{		
		switch((selection = menuIO(r,_printMenu)))
		{
			case QUIT:
			{
				run = 0;
				break;
			}
			case READ:
			{
				FILE *f;
				DOC *r;
				r=readFile("test");
				printDocList(r);
				uprintf("Press Enter to continue...\n");
				waitKey('\n');
				freeDoc(r);
				break;
			}
			case DEBUG:
			{
				DOC *dr;
				cinfo *cr;
				dr=readFile("test");
				printDocList(dr);
				printf("\nSTATS:: %d LE's\n",countDocEntrys(dr));
				uprintf("Press Enter to build cinfo list...\n");				
				waitKey('\n');
				cr = buildCinfo(dr);
				printCinfoList(cr);				
				uprintf("Press Enter to continue...\n");				
				waitKey('\n');
				cr = sortCinfoInserted(cr,DESC);
				printCinfoList(cr);
				freeCinfo(cr);
				uprintf("Press Enter to continue...\n");				
				waitKey('\n');
				freeDoc(dr);
				break;
			}
		}
	}
	printf("Goodbye\n");
	return 0;
}
