unsigned int firstRun;

unsigned int userMap[100][100];
unsigned int map[2][100][50];
unsigned int mapSize[2];
unsigned int pointer[2];

// 初始化游戏
void init();

// 绘制界面，每次操作后均调用一次以更新画面
void draw();

// 控制指针移动
void move(int i);

// 在当前位置落子或起子
void put();

// 检查游戏是否完成
int check();

// 开始游戏
void start();
