#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "mapc.h"

void cookie(int x, int y){
	int max_x,max_y;
	
	getmaxyx(stdscr,max_y,max_x);
	**matrix = mat(max_y,max_x);
	matrix[x][y] = 0;
}

