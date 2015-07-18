#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "mapdata.h"
#include "maps.h"

#define SYMBOL_NUM 3

MAPDATA *MAP = NULL;

char *SYMBOL[SYMBOL_NUM] = {
	"　", "■", "・"
};


void loadMaps(int size_y, int size_x, char *file_name){
	if( MAP != NULL ){
		destroyMap(MAP);
	}
	MAP = createMap(size_y, size_x);
	loadMap(MAP, file_name);
}


void drawMaps(int y, int x){
	int i, j, tmp;
	
	for( i=0; i<MAP->size_y; i++){
		for( j=0; j<MAP->size_x; j++){
			tmp = map_get(MAP, i, j);
			if( tmp >= 0 || tmp < SYMBOL_NUM ){
				mvprintw(y + i, x + (j*2), SYMBOL[tmp]);
			}else{
				mvprintw(y + i, x + j, SYMBOL[0]);
			}
		}
	}
}


int maps_get(int y, int x){
	return map_get(MAP, y, x);
}


void maps_set(int y, int x, int val){
	map_set(MAP, y, x, val);
}
