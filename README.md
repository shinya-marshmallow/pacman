# pacman

-----

## mapdataモジュール
マップのデータを保持する構造体をメモリに生成し、管理します。  
一般的には利用するソースファイルに「MAPDATA *map;」と宣言して使用します。

- **MAPDATA createMap(int sy, int sx);**  
マップのデータを格納するMAPDATA構造体を生成(malloc)し、そのポインタを返却します。引数にはマップデータの大きさ(sy×sx)を指定します。

- **void destroyMap(MAPDATA *map);**  
引数に指定されたMAPDATA構造体のメモリ領域を解放(free)します。引数には開放したいMAPDATA構造体へのポインタを指定します。

- **int loadMap(MAPDATA *map, char *fname);**  
ファイルからデータを読み込み、MAPDATA構造体にデータを格納します。第1引数には格納先のMAPDATA構造体へのポインタ、第2引数には読み込むファイル名を指定します。

- **int map_get(MAPDATA *map, int y, int x);**  
引数mapで指定されたMAPDATA構造体の(y, x)の位置の値を取得して返却します。

- **void map_set(MAPDATA *map, int y, int x, int val)**  
引数mapで指定されたMPADATA構造体の(y, x)の位置の値をvalに置き換えます。

- void initMap(MAPDATA *map);  
MAPDATA構造体に格納されたデータを初期化(0にセット)します。

- void printMapData(MAPDATA *map);  
MAPDATA構造体の内容を整数で標準出力に出力します。


## mapsモジュール
マップのデータを管理するモジュールです。mapdataモジュールを簡単に操作するためのモジュールです。

- **void loadMaps(int size_y, int size_x, int *file_name);**  
大きさが(size_y×size_x)のマップデータ構造体を生成し、file_nameで指定されたファイルの内容をロードします。生成されたマップデータ構造体はmaps.c内でグローバル宣言された変数に格納され、この関数が呼び出された以降の操作はすべてこのマップデータ構造体に対して行われます。
- **void drawMaps(int y, int x);**
マップデータ構造体の内容を(y, x)の位置に描画します。マップデータ構造体に格納された整数データを、maps.c内で定義されているSYMBOL配列によって変換して描画します。描画する元のマップデータはloadMaps関数によって生成されたマップデータであり、この関数を利用する前にloadMaps関数が実行されている必要があります。
- **int maps_get(int y, int x);**  
マップデータ構造体の(y, x)の位置の値を取得して返却します。
- **void maps_set(int y, int x, int val);**  
マップデータ構造体の(y, x)の位置の値をvalに置き換えます。
