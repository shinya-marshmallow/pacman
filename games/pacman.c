#include <ncurses.h>
#include <unistd.h>
#include <locale.h>
#include "pacman.h"

int pacman(int inp,int x, int y){
	int max_x, max_y;
	getmaxyx(stdscr, max_y, max_x);
	
		
		switch( inp ){
			case KEY_UP:
				if( (max_y - 1) >= 0 ){
					return 1;/*y--;*/
				}
			case KEY_DOWN:
				if( (y + 1) < max_y ){
					return 2;/*y++;*/
				}
			case KEY_LEFT:
				if( (x - 1) >= 0 ){
					return 3; /*x--;*/
				}
			case KEY_RIGHT:
				if( (x + 1) < max_x ){
					return 4; /*x++;*/
				}
			default	:
				return 0;
		}	

	return -1;			
}

