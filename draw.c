// mapSize[0]      map 的行数
// mapSize[1]      map 的列数
// mapMaxBlocks[0] map 各行中最大 block 数
// mapMaxBlocks[1] map 各列中最大 block 数

void draw() {
	unsigned int i, j;
	char drawStr[9999];
	int offset = 0;
	system("cls");
	offset += sprintf(drawStr + offset, "\n >> Nonograms %s\n", mapsName[mapAction[0]][mapAction[1]]);
	//offset += sprintf(drawStr + offset, "%d %d %d %d\n", mapSize[0], mapSize[1], map[2][0][0], map[2][0][1]);
	/*
	for (i = 0; i < mapSize[0]; i++) {
		for (j = 0; j < mapMaxBlocks[0]; j++) offset += sprintf(drawStr + offset, "%5d\n", map[0][i][j]);
		offset += sprintf(drawStr + offset, "\n");
	}
	for (i = 0; i < mapSize[1]; i++) {
		for (j = 0; j < mapMaxBlocks[1]; j++) offset += sprintf(drawStr + offset, "%5d\n", map[1][i][j]);
		offset += sprintf(drawStr + offset, "\n");
	}
	*/
	for (i = 0; i < mapMaxBlocks[1]; i++) {
		// i 为行，j 为列 
		//offset += sprintf(drawStr + offset, "    \n");
		//for (j = 0; j < mapMaxBlocks[0]; j++)
		for (j = 0; j <= mapMaxBlocks[0]; j++) offset += sprintf(drawStr + offset, "    ");
		if (i == 0) {
			offset += sprintf(drawStr + offset, "┌─");
			for (j = 1; j < mapSize[1]; j++) offset += sprintf(drawStr + offset, "┬─");
			offset += sprintf(drawStr + offset, "┐\n");
		}
		else {
			offset += sprintf(drawStr + offset, "├─");
			for (j = 1; j < mapSize[1]; j++) offset += sprintf(drawStr + offset, "┼─");
			offset += sprintf(drawStr + offset, "┤\n");
		}
		for (j = 0; j <= mapMaxBlocks[0]; j++) offset += sprintf(drawStr + offset, "    ");
		for (j = 0; j < mapSize[1]; j++) {
			//offset += sprintf(drawStr + offset, "%d %d %d\n", i, j, getMapLineBlocks(1, j));
			if (mapMaxBlocks[1] - i <= getMapLineBlocks(1, j)) offset += sprintf(drawStr + offset, "│%2d", map[1][j][(getMapLineBlocks(1, j) - mapMaxBlocks[1] + i)]);
			else offset += sprintf(drawStr + offset, "│  ");
		}
		offset += sprintf(drawStr + offset, "│\n");
	}
	printf(drawStr);
	for (i = 0; i < mapSize[0]; i++) {
		drawStr[0] = '\0';
		offset = 0;
		// i 为行，j 为列
		offset += sprintf(drawStr + offset, "    ");
		if (i == 0) {
			offset += sprintf(drawStr + offset, "┌─");
			for (j = 1; j < mapMaxBlocks[0]; j++) offset += sprintf(drawStr + offset, "┬─");
		}
		else {
			offset += sprintf(drawStr + offset, "├─");
			for (j = 1; j < mapMaxBlocks[0]; j++) offset += sprintf(drawStr + offset, "┼─");
		}
		for (j = 0; j < mapSize[1]; j++) offset += sprintf(drawStr + offset, "┼─");
		offset += sprintf(drawStr + offset, "┤\n");
		offset += sprintf(drawStr + offset, "    ");
		for (j = 0; j < mapMaxBlocks[0]; j++) {
			if (mapMaxBlocks[0] - j <= getMapLineBlocks(0, i)) offset += sprintf(drawStr + offset, "│%2d", map[0][i][getMapLineBlocks(0, i) - mapMaxBlocks[0] + j]);
			else offset += sprintf(drawStr + offset, "│  ");
		}
		printf(drawStr);
		for (j = 0; j < mapSize[1]; j++) {
			printf("│");
			if (userMap[i][j] == 1) {
				if (pointer[0] == i && pointer[1] == j) printcf("＋", FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
				else printcf("  ", BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
			}
			else {
				if (pointer[0] == i && pointer[1] == j) printcf("＋", FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				else printf("  ");
			}
		}
		printf("│\n");
	}
	drawStr[0] = '\0';
	offset = 0;
	offset += sprintf(drawStr + offset, "    └");
	for (j = 1; j < mapMaxBlocks[0] + mapSize[1]; j++) offset += sprintf(drawStr + offset, "─┴");
	offset += sprintf(drawStr + offset, "─┘");
	printf(drawStr);
}