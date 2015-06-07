//unsigned int firstRun; // 是否是第一次运行程序，如果是第一次运行程序则不需要执行 init() 里的填 0 操作

unsigned int userMap[50][50]; // 用户绘制的地图，可理解为一个矩阵
unsigned int map[3][50][25]; // 当前的地图，包含各行与各列的数据
unsigned int mapSize[2]; // 当前地图的大小
unsigned int mapMaxBlocks[2]; // 当前地图各行各列中最大区块数
unsigned int pointer[2]; // 用户的指针位置
unsigned int mapAction[2];

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
