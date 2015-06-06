// mapSize[0]      map ������
// mapSize[1]      map ������
// mapMaxBlocks[0] map ��������� block ��
// mapMaxBlocks[1] map ��������� block ��

void draw() {
	unsigned int i, j;
	system("cls");
	printf(">> Nonograms \n");
	/*
	for (i = 0; i < mapSize[0]; i++) {
		for (j = 0; j < mapMaxBlocks[0]; j++) printf("%5d\n", map[0][i][j]);
		printf("\n");
	}
	for (i = 0; i < mapSize[1]; i++) {
		for (j = 0; j < mapMaxBlocks[1]; j++) printf("%5d\n", map[1][i][j]);
		printf("\n");
	}
	*/
	for (i = 0; i < mapMaxBlocks[1]; i++) {
		// i Ϊ�У�j Ϊ�� 
		//printf("    \n");
		//for (j = 0; j < mapMaxBlocks[0]; j++)
		for (j = 0; j <= mapMaxBlocks[0]; j++) printf("    ");
		if (i == 0) {
			printf("����");
			for (j = 1; j < mapSize[1]; j++) printf("�Щ�");
			printf("��\n");
		}
		else {
			printf("����");
			for (j = 1; j < mapSize[1]; j++) printf("�੤");
			printf("��\n");
		}
		for (j = 0; j <= mapMaxBlocks[0]; j++) printf("    ");
		for (j = 0; j < mapSize[1]; j++) {
			//printf("%d %d %d\n", i, j, getMapLineBlocks(1, j));
			if (mapMaxBlocks[1] - i <= getMapLineBlocks(1, j)) printf("��%2d", map[1][j][(getMapLineBlocks(1, j) - mapMaxBlocks[1] + i)]);
			else printf("��  ");
		}
		printf("��\n");
	}
	for (i = 0; i < mapSize[0]; i++) {
		// i Ϊ�У�j Ϊ��
		printf("    ");
		if (i == 0) {
			printf("����");
			for (j = 1; j < mapMaxBlocks[0]; j++) printf("�Щ�");
		}
		else {
			printf("����");
			for (j = 1; j < mapMaxBlocks[0]; j++) printf("�੤");
		}
		for (j = 0; j < mapSize[1]; j++) printf("�੤");
		printf("��\n");
		printf("    ");
		for (j = 0; j < mapMaxBlocks[0]; j++) {
			if (mapMaxBlocks[0] - j <= getMapLineBlocks(0, i)) printf("��%2d", map[0][i][getMapLineBlocks(0, i) - mapMaxBlocks[0] + j]);
			else printf("��  ");
		}
		for (j = 0; j < mapSize[1]; j++) {
			printf("��");
			if (userMap[i][j] == 1) {
				if (pointer[0] == i && pointer[1] == j) printcf("��", FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
				else printcf("  ", BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
			}
			else {
				if (pointer[0] == i && pointer[1] == j) printcf("��", FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				else printf("  ");
			}
		}
		printf("��\n");
	}
	printf("    ��");
	for (j = 1; j < mapMaxBlocks[0] + mapSize[1]; j++) printf("����");
	printf("����");
}