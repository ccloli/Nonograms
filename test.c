void randomPointer() {
	pointer[0] = rand() % mapSize[0];
	pointer[1] = rand() % mapSize[1];
}

void randomMap() {
	int i, j;
	for (i = 0; i < mapSize[0]; i++) {
		for (j = 0; j < mapSize[1]; j++) {
			userMap[i][j] = rand() % 2;
		}
	}
}

void changeKey() {
	userMap[pointer[0]][pointer[1]] = !userMap[pointer[0]][pointer[1]];
}
/*
void correctMap() {
	clearUserMap();
	userMap[0][1] = userMap[0][2] = userMap[0][3] = userMap[1][0] = userMap[1][1] = userMap[1][3] = userMap[1][4] = userMap[2][0] = userMap[2][4] = userMap[3][0] = userMap[3][1] = userMap[3][3] = userMap[3][4] = userMap[4][1] = userMap[4][2] = userMap[4][3] = 1;
}
*/