#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "mapc.h"


int c;

int **mat (int y, int x){
	int **mat;
	int i;
	mat = malloc(sizeof(int *) * y);
  for (i=0;i<y;i++) {
		c++;
    mat[i] = malloc(sizeof(int) * x);
  }
	return mat;
}

int mapc(int y, int x){

  FILE *fp;
  int i,j;
  int  num;

  if ((fp = fopen("map.txt", "r")) == NULL) {
    fprintf(stderr, "ファイル%sがありません。\n", "map.txt");
    exit(1);
  }

  matrix = mat(y, x);
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

  return 0;
}
	

void mapcfree(void){
	int i;
  for (i=0;i<c;i++) {
    free(matrix[i]);
  }
  free(matrix);
}

