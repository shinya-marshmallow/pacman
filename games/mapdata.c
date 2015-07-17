#include <stdio.h>
#include <stdlib.h>
#include "mapdata.h"


MAPDATA *createMap(int sy, int sx){
	MAPDATA *nmap;
	
	if( (nmap = malloc(sizeof(MAPDATA))) == NULL ){
		fprintf(stderr, "createMap: memory allocate error(1)\n");
		exit(1);
	}
	
	if( (nmap->matrix = malloc(sizeof(int) * sy * sx)) == NULL ){
		fprintf(stderr, "createMap: memory allocate error(2)\n");
		exit(1);
	}
	
	nmap->size_y = sy;
	nmap->size_x = sx;
	
	initMap(nmap);
	
	return nmap;
}


void initMap(MAPDATA *map){
	int *p;
	int i;
	
	p = map->matrix;
	for( i=0; i<(map->size_y * map->size_x); i++){
		*p = 0;
		p++;
	}
}


int map_get(MAPDATA *map, int y, int x){
	int *p;
	p = map->matrix + ((y * map->size_x) + x);
	
	return *p;
}


void map_set(MAPDATA *map, int y, int x, int val){
	int *p;
	p = map->matrix + ((y * map->size_x) + x);
	
	*p = val;
}


void destroyMap(MAPDATA *map){
	initMap(map);
	free(map->matrix);
	free(map);
}


int loadMap(MAPDATA *map, char *fname){
	FILE *fp;
	int *mp;
	int tmp, length, cnt, flag;
	
	flag = 0;
	
	if( (fp = fopen(fname, "r")) == NULL ){
		fprintf(stderr, "loadMap: file open error\n");
		exit(1);
	}
	
	cnt = 0;
	length = map->size_y * map->size_x;
	mp = map->matrix;
	while( fscanf(fp, "%d", &tmp) != EOF ){
		if( cnt >= length ){
			flag = -1;
			break;
		}
		
		*mp = tmp;
		mp++;

		cnt++;
	}
	
	fclose(fp);
	return flag;
}


void printMapData(MAPDATA *map){
	int i, j;

	printf("SIZEY = %d, SIZEX = %d\n", map->size_y, map->size_x);
	printf("/// MAP MATRIX ///\n");

	for( i=0; i<map->size_y; i++){
		for( j=0; j<map->size_x; j++){
			printf("%d ", map_get(map, j, i));
		}
		printf("\n");
	}
}

