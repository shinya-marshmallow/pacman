#include <stdio.h>
#include <stdlib.h>
#include "mapdata.h"


int main(void){
	MAPDATA *map;

	map = createMap(15, 14);
	printf("created\n");
	loadMap(map, "map.txt");
	printf("loaded\n");

	printMapData(map);

	return 0;
}
