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