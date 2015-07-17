struct map {
	int *matrix;
	int size_x;
	int size_y;
};
typedef struct map MAPDATA;


MAPDATA *createMap(int sy, int sx);
void destroyMap(MAPDATA *map);

int loadMap(MAPDATA *map, char *fname);

void initMap(MAPDATA *map);

int map_get(MAPDATA *map, int y, int x);
void map_set(MAPDATA *map, int y, int x, int val);

void printMapData(MAPDATA *map);
