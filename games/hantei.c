#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "hantei.h"
#include "mapc.h"
FLAG hantei(int x, int y){
	int max_x,max_y;
	getmaxyx(stdscr,max_y,max_x);
  mapc(max_y, max_x);
	**matrix = mat(max_y,max_x);

	FLAG f;
	if(matrix[x+1][y] == 1){
		f.migi = 0;
	}else if(matrix[x+1][y] == 2){
		f.migi = 1;
	}

	if(matrix[x-1][y] == 1){
		f.hidari = 0;
	}else if(matrix[x-1][y] == 2){
		f.hidari = 1;
	}

	if(matrix[x][y+1] == 1){
		f.sita = 0;
	}else if(matrix[x][y+1] == 2){
		f.sita = 1;
	}
	

	if(matrix[x][y-1] == 1){
		f.ue = 0;
	}else if(matrix[x][y-1] == 2){
		f.ue = 1;
	}	
	return f;
}
