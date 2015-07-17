#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "pacman.h"
#include "mapc.h"
#include "hantei.h"
void map(void){
	int j,i;
	int max_x,max_y;
  int tmp;
	getmaxyx(stdscr,max_y,max_x);
  mapc(max_y, max_x);
  for(i=0;i<15;i++){
    j = 0;
    while(j<20){
      tmp = matrix[i][j];
      if(tmp == 1){
				mvprintw(j, i,"■" );
      }
      if(tmp == 2){
				mvprintw(j, i,"‥");
      }
      j++;
    }
  }
}


int main(void){
  /*int i,j;*/
	double x,y;/*自機の座標*/
  int plus = 0;/*移動判別*/
  int inp = 'o';
	FLAG flag;
	
/*  i = 0;
  j = 0;	*/

  setlocale(LC_ALL,"");
  initscr();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  
  x = 10;
  y = 7;
  while(""){
	mvprintw(19,0,"x = %d  y = %d",x,y);
	refresh();
	plus = pacman(inp, x, y);
	flag = hantei(x, y);
    if(plus == 1 && flag.ue == 1){
      y--;
    }else if(plus == 2 && flag.sita == 1){
      y++;
    }else if(plus == 3 && flag.migi == 1){
      x=x-2;
    }else if(plus == 4 && flag.hidari == 1){
      x=x+2;
    }
	clear();
	mvprintw(20,0,"x = %d  y = %d",x,y);
	map();
	refresh();
	mvprintw(y,x,"Ｏ");  
	refresh();
	inp=getch();
  }
	mapcfree();

  
  endwin();

  
  return 0;
}
