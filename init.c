/*
int getMapLineLength(int type) {
	int line = 0;
	int size = (sizeof(map[type]) / sizeof(map[type][0]));
	while (map[type][line][0] != 0 && line < size) line++;
	return line;
}
*/
int getMapLineBlocks(int type, int i) {
	int j = 0;
	while(map[type][i][j] != 0) j++;
	return j;
}

int getMapLineMaxBlocks(int type) {
	int max = 0, i, j, k;
	for (i = 0; i < mapSize[type]; ++i)	{
		j = getMapLineBlocks(type, i);
		if (j > max) max = j;
	}
	return max;
}

void clearUserMap() {
	int i, j;
	for (i = 0; i < 50; i++) {
		for (j = 0; j < 50; j++) {
			userMap[i][j] = 0;
		}
	}
}

void init(int i, int j) {
	system("cls");
	char windowSize[50];
	//int length = sizeof(maps) / sizeof(maps[0]);
	//srand((unsigned int)time(NULL) + (unsigned int)getpid());
	//int mapId = rand() % length;
	//unsigned int mapId = rand() % (sizeof(maps) / sizeof(maps[0]));
	// mapId = 1; 开发时以第二张地图进行测试
	//printf("%d\n", id);
	//map = maps[mapId];
	//memcpy(map, maps[mapId], sizeof(maps[mapId]));
	memcpy(map, maps[i][j], sizeof(maps[i][j]));
	//mapSize[0] = getMapLineLength(0); // map 的行数
	//mapSize[1] = getMapLineLength(1); // map 的列数
	mapSize[0] = map[2][0][0];
	mapSize[1] = map[2][0][1];
	//printf("%d %d %d %d\n", mapSize[0], mapSize[1], map[2][0][0], map[2][0][1]);
	//memcpy(mapSize, map[2][0], sizeof(map[2][0]));
	mapMaxBlocks[0] = getMapLineMaxBlocks(0); // map 的行数
	mapMaxBlocks[1] = getMapLineMaxBlocks(1); // map 的列数
	//printf("%d %d\n", mapSize[0], mapSize[1]);
	//printf("%d %d\n", mapMaxBlocks[0], mapMaxBlocks[1]);
	sprintf(windowSize,  "mode con cols=%d lines=%d", 2 * (2 * (mapSize[1] + mapMaxBlocks[0]) + 5), 2 * (mapSize[0] + mapMaxBlocks[1] + 4));
	system(windowSize);
	//if (!firstRun) {
	pointer[0] = pointer[1] = 0;
	//printf("%d %d\n", pointer[0], pointer[1]);
	clearUserMap();
	//firstRun = 1;
	//}
}