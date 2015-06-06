void changePointer(int j, int i) {
	if (pointer[0] + i >= 0 && pointer[0] + i < mapSize[1] && pointer[1] + j >= 0 && pointer[1] + j < mapSize[0])	{
		pointer[0] += i;
		pointer[1] += j;
	}
}

void changeChess() {
	userMap[pointer[0]][pointer[1]] = !userMap[pointer[0]][pointer[1]];
}