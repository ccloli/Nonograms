#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "config.c"
#include "maps.c"
#include "init.c"
//#include "start.c"

int main (int argc, char const *argv[]) {
	int a;
	//start();
	//printf("%d %d\n", mapId, map[0][0][0]);
	
	while (1){
		a = getch();
		printf("%d\n", a);
		if (a == 72) system("cls");

	}
	
	getchar();
	return 0;
}