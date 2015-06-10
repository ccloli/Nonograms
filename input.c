// Source: tieba@冰是沉默的水3 http://tieba.baidu.com/p/2609166559 & SorinAlex http://www.cplusplus.com/forum/beginner/121585/ 
/*
#include<stdio.h>
#include<windows.h>
*/
HANDLE hInput;  /*  获取标准输入设备句柄 */
INPUT_RECORD inRec;/*  返回数据记录 */
DWORD numRead; /*  返回已读取的记录数 */
int clickPosition[2];
int inputASCII;
int type;
//int Y,X;/* X和Y的坐标 */
int getInputAction()
{
	hInput = GetStdHandle(STD_INPUT_HANDLE); // 输入设备句柄
	COORD pos = {0,0};
	while (1) {
		ReadConsoleInput(hInput, &inRec, 1, &numRead); // 读取1个输入事件
		if (inRec.EventType == KEY_EVENT && inRec.Event.KeyEvent.bKeyDown) {
			type = 1;
			break;
		}
		// https://msdn.microsoft.com/en-us/library/windows/desktop/ms684239(v=vs.85).aspx
		else if (inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
			pos = inRec.Event.MouseEvent.dwMousePosition;
			type = 2;
			break;
		}
	}
	if (type == 1) {
		inputASCII = (int)inRec.Event.KeyEvent.wVirtualKeyCode;//uChar.AsciiChar;
	}
	else if (type == 2) {
		clickPosition[0] = (int)pos.X;
		clickPosition[1] = (int)pos.Y;
	}
	//printf("215615\n");
	return type;
}

/*
int main(){
	int response;
	while (1) {
		response = getInputAction();
		if (response == 1) printf("%d\n", inputASCII);
		else if (response == 2) printf("%d %d\n", clickPosition[0], clickPosition[1]);
	}
	getchar();
	return 0;
}
*/