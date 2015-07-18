/*extern MAPDATA *MAP;*/

void loadMaps(int size_y, int size_x, char *file_name);
void drawMaps(int y, int x);
int maps_get(int y, int x);
void maps_set(int y, int x, int val);
void destroyMap(void);
