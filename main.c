int main (int argc, char const *argv[]) {
	int a;
	init();
	//printf("%d %d\n", mapId, map[0][0][0]);
	printf(
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
		);
	while (1){
		a = getch();
		printf("%d\n", a);
		if (a == 13) system("cls");
	}
	
	getchar();
	return 0;
}