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
		i = getch();
		if (i == 72 && (*j) > 0) --(*j);
		else if (i == 80 && (*j) < 8) ++(*j);
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
				sprintf(selectedStr, "  > %2d. %-18s", i+1, mapsName[*j][i]);
				printcf(selectedStr, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
			}
			else printf("    %2d. %-18s", i+1, mapsName[*j][i]);
			i++;
			if (i % 3 == 0) printf("\n ");
		}
		l = i;
		i = getch();
		if (i == 72 && (*k) - 3 >= 0) (*k) -= 3;
		else if (i == 80 && (*k) + 3 < l) (*k) += 3;
		else if (i == 75 && (*k) > 0) (*k)--;
		else if (i == 77 && (*k) < l - 1) (*k)++;
		else if (i == 8) {
			//(*j) = 0;
			(*k) = 0;
			return 0;
		}
	}
	while (i != 13);
	return 1;
}

int main (int argc, char const *argv[]) {
	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	system("mode con cols=80 lines=25");
	int a;
	int i = 0, j = 0, k = 0, l;
	printTitle(1);
	printf("                              Press Enter to Start");
	do i = getch();
	while (i != 13);
	do chooseLevel(&j);
	while (chooseGame(&j, &k) == 0);
	
	init(j, k);
	draw();
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
		a = getch();
		//printf("%d\n", a);
		if (a == 13) system("cls");
		// Up: 72, Down: 80, Left: 75, Right: 77
		else if (a == 72) {
			changePointer(0, -1);
			draw();
		}
		else if (a == 80) {
			changePointer(0, 1);
			draw();
		}
		else if (a == 75) {
			changePointer(-1, 0);
			draw();
		}
		else if (a == 77) {
			changePointer(1, 0);
			draw();
		}
		else if (a == 32) {
			changeChess();
			draw();
			if(check()) {
				printf("\nCongratulation! You Win!\n");
				break;
			}
		}
		else if (a == 48) {
			srand((unsigned int)time(NULL) + (unsigned int)getpid());
			l = rand() % (sizeof(maps) / sizeof(maps[0]));
			init(l, rand() % (sizeof(maps[l]) / sizeof(maps[l][0])));
			draw();
		}
		else if (a == 49) {
			randomPointer();
			draw();
		}
		else if (a == 50) {
			changeKey();
			draw();
			//printf("%d\n", check());
			if(check()) {
				printf("\nCongratulation! You Win!\n");
				break;
			}
		}
		else if (a == 51) {
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