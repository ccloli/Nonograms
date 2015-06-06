int main (int argc, char const *argv[]) {
	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	int a;
	init();
	draw();
	//printf("%d %d\n", mapId, map[0][0][0]);
	/*printf(
		"            �����Щ��Щ��Щ��Щ���\n"
		"            ��  �� 2��  �� 2��  ��\n"
		"            �����੤�੤�੤�੤��\n"
		"            �� 2�� 2�� 2�� 2�� 2��\n"
		"    �����Щ��੤�੤�੤�੤�੤��\n"
		"    �� 1�� 1��  ��  ��  ��  ��  ��\n"
		"    �����੤�੤�੤�੤�੤�੤��\n"
		"    �� 2�� 2��  ��  ��  ��  ��  ��\n"
		"    �����੤�੤�੤�੤�੤�੤��\n"
		"    �� 3�� 3��  ��  ��  ��  ��  ��\n"
		"    �����੤�੤�੤�੤�੤�੤��\n"
		"    �� 4�� 4��  ��  ��  ��  ��  ��\n"
		"    �����੤�੤�੤�੤�੤�੤��\n"
		"    �� 5�� 5��  ��  ��  ��  ��  ��\n"
		"    �����ة��ة��ة��ة��ة��ة���\n"
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
			init();
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