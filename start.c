void start() {
	init();
	draw();
	do {
		int key = getch();
		// Up: 72, Down: 80, Left: 75, Right: 77, Space: 32, Enter: 13
		if (key == 32) put();
		else //...
	}
	while (check());
}