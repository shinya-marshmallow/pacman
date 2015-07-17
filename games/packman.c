#include <ncurses.h>
#include <unistd.h>
#include <locale.h>

int main(int argc, char *argv[]){
	int max_x, max_y;
	int x, y;
	char ch = 'o';
	char och[] = "　";
	int inp;
	setlocale(LC_ALL,"");
	initscr();
	getmaxyx(stdscr, max_y, max_x);
	
	x = max_x / 2;
	y = max_y / 2;
	
	keypad(stdscr, TRUE);
	crmode();
	curs_set(0);
	noecho();
	while( inp != 'q' ){
		mvaddch(y, x, ch);
		refresh();
		inp = getch();
		switch( inp ){
			case KEY_UP:
				if( (y - 1) >= 0 ){
					mvprintw(y ,x, och);
					y--;
				}
				break;
			case KEY_DOWN:
				if( (y + 1) < max_y ){
					mvprintw(y ,x, och);
					y++;
				}
				break;
			case KEY_LEFT:
				if( (x - 1) >= 0 ){
					mvprintw(y, x, och);
					x--;
				}
				break;
			case KEY_RIGHT:
				if( (x + 1) < max_x ){
					mvprintw(y, x, och);
					x++;
				}
				break;
				
		}
	clear();
	}
	
	endwin();
	return 0;
}
