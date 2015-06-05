int getMapLineLength(int type) {
	int line = 0;
	int size = (sizeof(map[type]) / sizeof(map[type][0]));
	while (map[type][line][0] != 0 && line < size) line++;
	return line;
}
void clearUserMap() {
	int i, j;
	for(i = 0; i < 100; i++) {
		for(j = 0; j < 100; j++) {
			userMap[i][j] = 0;
		}
	}
}

void init() {
	//int length = sizeof(maps) / sizeof(maps[0]);
	srand((unsigned int)time(NULL) + (unsigned int)getpid());
	//int mapId = rand() % length;
	unsigned int mapId = rand() % (sizeof(maps) / sizeof(maps[0]));
	mapId = 1;
	//printf("%d\n", id);
	//map = maps[mapId];
	memcpy(map, maps[mapId], sizeof(maps[mapId]));
	mapSize[0] = getMapLineLength(0); // map 的行数
	mapSize[1] = getMapLineLength(1); // map 的列数
	//printf("%d %d\n", mapSize[0], mapSize[1]);
	if (!firstRun) {
		pointer[0] = pointer[1] = 0;
		//printf("%d %d\n", pointer[0], pointer[1]);
		clearUserMap();
		firstRun = 1;
	}
}