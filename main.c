void printTitle(int i) {
	if (i == 1 || i == 2) printf("\n\n\n\n\n\n\n\n");
	printcf(
		"           _______                                                    \n"
		"          |    |  |.-----.-----.-----.-----.----.---.-.--------.-----.\n"
		"          |       ||  _  |     |  _  |  _  |   _|  _  |        |__ --|\n"
		"          |__|____||_____|__|__|_____|___  |__| |___._|__|__|__|_____|\n"
		"                                     |_____|                          \n", FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
	);
	if (i == 1 | i == 3) printf("\n\n\n\n\n");
}

void chooseLevel(int *j) {
	int i;
	char selectedStr[80];
	do {
		system("cls");
		printTitle(2);
		i = 0;
		while (i < 9) {
			printf("\n                                 ");
			if (i == (*j)) {
				sprintf(selectedStr, "  > %s <  ", mapsLevel[i++]);
				if (*j >= 5) printcf(selectedStr, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_INTENSITY);
				else printcf(selectedStr, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
			}
			else printf("    %s", mapsLevel[i++]);
		}
		if (*j >= 5) printcf("\n                                 Coming soon...", FOREGROUND_RED | FOREGROUND_INTENSITY);
		i = getInputAction();
		if (i == 1) {
			if (inputASCII == 38 && (*j) > 0) --(*j);
			else if (inputASCII == 40 && (*j) < 8) ++(*j);
			else if (inputASCII == 27) exit(EXIT_SUCCESS);
			else i = inputASCII;
		}
		else if (i == 2) {
			//printf("%d %d\n", clickPosition[0], clickPosition[1]); // 14~22
			if (clickPosition[1] > 13 && clickPosition[1] < 23) {
				*j = clickPosition[1] - 14;
				i = 13;
			}
		}
	}
	while (i != 13 || *j >= 5);
}

int chooseGame(int *j, int *k) {
	int i, l;
	char selectedStr[30];
	do {
		system("cls");
		printf("\n\n");
		printTitle(0);
		printf("\n\n    Press Backspace to go back. \n\n ");
		i = 0;
		while (mapsName[*j][i][0] != '\0') {
			if (i == (*k)) {
				//printf("  > %2d. %-18s", i+1, mapsName[*j][i]);
				sprintf(selectedStr, "  > %2d. %-16s%s", i+1, mapsName[*j][i], progress[*j][i] ? "¡Ì" : "  ");
				printcf(selectedStr, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
			}
			else printf("    %2d. %-16s%s", i+1, mapsName[*j][i], progress[*j][i] ? "¡Ì" : "  ");
			i++;
			if (i % 3 == 0) printf("\n ");
		}
		l = i;
		i = getInputAction();
		if (i == 1) {
			// 38 40 37 39
			if (inputASCII == 38 && (*k) - 3 >= 0) (*k) -= 3;
			else if (inputASCII == 40 && (*k) + 3 < l) (*k) += 3;
			else if (inputASCII == 37 && (*k) > 0) (*k)--;
			else if (inputASCII == 39 && (*k) < l - 1) (*k)++;
			else if (inputASCII == 8) {
				//(*j) = 0;
				(*k) = 0;
				return 0;
			}
			else if (inputASCII == 27) exit(EXIT_SUCCESS);
			else i = inputASCII;
		}
		else if (i == 2) {
			//printf("%d %d\n", clickPosition[0], clickPosition[1]); // 11~
			if (clickPosition[1] > 10 && clickPosition[0] > 0 && clickPosition[0] < 79) {
				i = (clickPosition[1] - 11) * 3 + (clickPosition[0] - 1) / 26;
				//printf("%d\n", i);
				if (i < l) {
					(*k) = i;
					i = 13;
				}
			}
			else if (clickPosition[1] == 9) {
				(*k) = 0;
				return 0;
			}
			//getInputAction();

		}
	}
	while (i != 13);
	return 1;
}
/*
void startGame(int *j, int *k) {
	system("mode con cols=80 lines=25");
	do chooseLevel(&j);
	while (chooseGame(&j, &k) == 0);
	mapAction[0] = j;
	mapAction[1] = k;
	init(j, k);
	draw();
	printActionTips(1);
}
*/
void printActionTips(int i) {
	if (i == 0) {
		printf("\n\n > Press ");
		printcf("Space", FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		printf(" to fill or clear.");
	}
	else if (i == 1) {
		printcf("\n Congratulation! You Win!", FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		printf("\n > Press ");
		printcf("Enter", FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		printf(" to play next game.");
	}
	printf("\n > Press ");
	printcf("Backspace", FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	printf(" to go back.\n > Press ");
	printcf("Esc", FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf(" to quit.");
}

int main(int argc, char const *argv[]) {
	getProgress();
	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	system("title Nonograms");
	system("mode con cols=80 lines=25");
	int a;
	int i = 0, j = 0, k = 0, l = 0;
	printTitle(1);
	printf("                          Press Enter or Click to Start");
	do {
		i = getInputAction();
		if (i == 1) i = inputASCII;
		else i = 13;
	}
	while (i != 13);
	//startGame(&j, &k);
	do chooseLevel(&j);
	while (chooseGame(&j, &k) == 0);
	mapAction[0] = j;
	mapAction[1] = k;
	init(j, k);
	draw();
	printActionTips(0);
	//printf("%d %d\n", mapId, map[0][0][0]);
	/*printf(
		"            ©°©¤©Ð©¤©Ð©¤©Ð©¤©Ð©¤©´\n"
		"            ©¦  ©¦ 2©¦  ©¦ 2©¦  ©¦\n"
		"            ©À©¤©à©¤©à©¤©à©¤©à©¤©È\n"
		"            ©¦ 2©¦ 2©¦ 2©¦ 2©¦ 2©¦\n"
		"    ©°©¤©Ð©¤©à©¤©à©¤©à©¤©à©¤©à©¤©È\n"
		"    ©¦ 1©¦ 1©¦  ©¦  ©¦  ©¦  ©¦  ©¦\n"
		"    ©À©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©È\n"
		"    ©¦ 2©¦ 2©¦  ©¦  ©¦  ©¦  ©¦  ©¦\n"
		"    ©À©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©È\n"
		"    ©¦ 3©¦ 3©¦  ©¦  ©¦  ©¦  ©¦  ©¦\n"
		"    ©À©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©È\n"
		"    ©¦ 4©¦ 4©¦  ©¦  ©¦  ©¦  ©¦  ©¦\n"
		"    ©À©¤©à©¤©à©¤©à©¤©à©¤©à©¤©à©¤©È\n"
		"    ©¦ 5©¦ 5©¦  ©¦  ©¦  ©¦  ©¦  ©¦\n"
		"    ©¸©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©Ø©¤©¼\n"
		);*/
	while (1){
		i = getInputAction();
		//printf("%d\n", a);
		if ((i == 1 && inputASCII == 8) || (i == 2 && clickPosition[1] == 2 * (mapSize[0] + mapMaxBlocks[1] + 3) - 1)) {
			system("mode con cols=80 lines=25");
			//startGame(&j, &k);
			do chooseLevel(&j);
			while (chooseGame(&j, &k) == 0);
			mapAction[0] = j;
			mapAction[1] = k;
			init(j, k);
			draw();
			printActionTips(0);
		}
		else if ((i == 1 && inputASCII == 27) || (i == 2 && clickPosition[1] == 2 * (mapSize[0] + mapMaxBlocks[1] + 3))) exit(EXIT_SUCCESS);
		//if (a == 13) system("cls");
		// Up: 72, Down: 80, Left: 75, Right: 77
		else if ((i == 1 && inputASCII == 38)) {
			if (changePointer(0, -1)) {
				draw();
				printActionTips(0);
			}
		}
		else if ((i == 1 && inputASCII == 40)) {
			if (changePointer(0, 1)) {
				draw();
				printActionTips(0);
			}
		}
		else if ((i == 1 && inputASCII == 37)) {
			if (changePointer(-1, 0)) {
				draw();
				printActionTips(0);
			}
		}
		else if ((i == 1 && inputASCII == 39)) {
			if (changePointer(1, 0)) {
				draw();
				printActionTips(0);
			}
		}
		/*else if (i == 2 && clickPosition[0] > (mapMaxBlocks[0] + 1) * 2 && clickPosition[0] < 2 * (2 * (mapSize[1] + mapMaxBlocks[0]) + 5) - 5 && clickPosition[1] > (mapMaxBlocks[1] + 1) * 2 && clickPosition[1] < (mapMaxBlocks[1] + 1 + mapSize[1]) * 2 && clickPosition[1] % 2 == 1) {
			setPointer((clickPosition[0] - (mapMaxBlocks[0] + 1) * 4 - 1) / 4, (clickPosition[1] - (mapMaxBlocks[1] + 1) * 2) / 2);
			printf("%d %d\n", pointer[0], pointer[1]);
			changeChess();
			getInputAction();
			draw();
		}*/
		else if ((i == 1 && inputASCII == 32) || (i == 2 && clickPosition[0] > (mapMaxBlocks[0] + 1) * 2 && clickPosition[0] < 2 * (2 * (mapSize[1] + mapMaxBlocks[0]) + 5) - 5 && clickPosition[1] > (mapMaxBlocks[1] + 1) * 2 && clickPosition[1] < (mapMaxBlocks[1] + 1 + mapSize[1]) * 2 && clickPosition[1] % 2 == 1)) {
			if (i == 2) setPointer((clickPosition[0] - (mapMaxBlocks[0] + 1) * 4 - 1) / 4, (clickPosition[1] - (mapMaxBlocks[1] + 1) * 2) / 2);
			changeChess();
			draw();
			if(check()) {
				saveProgress(j, k);
				printActionTips(1);
				l = 0;
				do {
					i = getInputAction();
					if ((i == 1 && inputASCII == 8) || (i == 2 && clickPosition[1] == 2 * (mapSize[0] + mapMaxBlocks[1] + 3) - 1)) {
						//startGame(&j, &k);
						system("mode con cols=80 lines=25");
						do chooseLevel(&j);
						while (chooseGame(&j, &k) == 0);
						mapAction[0] = j;
						mapAction[1] = k;
						init(j, k);
						draw();
						printActionTips(0);
					}
					else if ((i == 1 && inputASCII == 13) || (i == 2 && clickPosition[1] == 2 * (mapSize[0] + mapMaxBlocks[1] + 2))) {
						if (maps[j][k + 1][2][0][0] != 0) {
							init(j, ++k);
							mapAction[0] = j;
							mapAction[1] = k;
							draw();
							printActionTips(0);
						}
						else if (maps[j + 1][0][2][0][0] != 0) {
							init(++j, k = 0);
							mapAction[0] = j;
							mapAction[1] = k;
							draw();
							printActionTips(0);
						}
						else l = 1;
					}
					else if((i == 1 && inputASCII == 27) || (i == 2 && clickPosition[1] == 2 * (mapSize[0] + mapMaxBlocks[1] + 3))) exit(EXIT_SUCCESS);
					else continue;
					break;
				}
				while (1);
				if (l == 1) {
					printf("No more games to continue. Press Enter to quit.\n");
					break;
				}
				//break;
			}
			else printActionTips(0);
		}
		else if (i == 1 && (inputASCII == 48 || inputASCII == 96)) {
			srand((unsigned int)getpid());
			l = rand() % (sizeof(maps) / sizeof(maps[0]));
			init(l, rand() % (sizeof(maps[l]) / sizeof(maps[l][0])));
			draw();
		}
		else if (i == 1 && (inputASCII == 49 || inputASCII == 97)) {
			randomPointer();
			draw();
		}
		else if (i == 1 && (inputASCII == 50 || inputASCII == 98)) {
			changeKey();
			draw();
			//printf("%d\n", check());
			if(check()) {
				printf("\nCongratulation! You Win!");
				break;
			}
		}
		else if (i == 1 && (inputASCII == 51 || inputASCII == 99)) {
			randomMap();
			draw();
		}
		/*else if (a == 54) {
			correctMap();
			draw();
		}*/
	}
	fflush(stdin);
	getchar();
	return 0;
}


/*
printcf("  ", BACKGROUND_RED);
printcf("  ", BACKGROUND_RED | BACKGROUND_INTENSITY);
printcf("  ", BACKGROUND_GREEN);
printcf("  ", BACKGROUND_GREEN | BACKGROUND_INTENSITY);
printcf("  ", BACKGROUND_BLUE);
printcf("  ", BACKGROUND_BLUE | BACKGROUND_INTENSITY);
printcf("  ", BACKGROUND_RED | BACKGROUND_GREEN);
printcf("  ", BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
printcf("  ", BACKGROUND_RED | BACKGROUND_BLUE);
printcf("  ", BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
printcf("  ", BACKGROUND_BLUE | BACKGROUND_GREEN);
printcf("  ", BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
printcf("  ", BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
printcf("  ", BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
printcf("  ", FOREGROUND_INTENSITY);
printcf("  ", BACKGROUND_INTENSITY);
*/