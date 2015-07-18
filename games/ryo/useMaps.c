#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <locale.h>
#include "mapdata.h"
#include "maps.h"


int main(void){
	loadMaps(15, 14, "map.txt");

	setlocale(LC_ALL, "");
	initscr();
	
	drawMaps(0, 0);
	
	refresh();
	sleep(3);
	
	endwin();
	return 0;
}
