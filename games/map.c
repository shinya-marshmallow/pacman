#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int **matrix;
struct map{
    int x;
    int y;
};

int mapc(void){

  FILE *fp;
  int i,j;
  int  tmp=0;
  char c;
  int  num;
  int inp;
  int n = 0;
  struct map ms;

  setlocale(LC_ALL,"");
  initscr();
  noecho();
  curs_set(0);
 
  getmaxyx(stdscr, ms.y, ms.x);

  if ((fp = fopen("map.txt", "r")) == NULL) {
    fprintf(stderr, "ファイル%sがありません。\n", "map.txt");
    exit(1);
  }
  
  matrix = malloc(sizeof(int *) * ms.y);
  for (i=0;i<ms.y;i++) {
    matrix[i] = malloc(sizeof(int) * ms.x);
  }

  i = 0; j = 0;
  while(fscanf(fp, "%d", &num) != EOF) {

    if(i < 20){
      if( j >= 14 ){
	i++; j = 0;
      }
    }

    matrix[j][i]=num;	
    j++;
  }
  fclose(fp);



  for(i=0;i<15;i++){
    j = 0;
    while(j<20){
      tmp = matrix[i][j];
      if(tmp == 1){
	mvprintw(j, i,"■" );
      }
      if(tmp == 2){
	mvprintw(j, i,"・");
      }
      if(tmp == 0){
	mvprintw(j,i,"　");
      }
      j++;
    }
  }
 
  refresh();
  c = getch();

  for (i=0;i<n;i++) {
    free(matrix[i]);
  }
  free(matrix);

  if(c == 'q'){endwin();}
  return 0;
}

int main(void){
	setlocale(LC_ALL,"");
	initscr();
	curs_set(0);
	noecho();
	mapc();
	endwin();
return 0;
}
	
