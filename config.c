unsigned int firstRun; // �Ƿ��ǵ�һ�����г�������ǵ�һ�����г�������Ҫִ�� init() ����� 0 ����

unsigned int userMap[100][100]; // �û����Ƶĵ�ͼ�������Ϊһ������
unsigned int map[2][100][50]; // ��ǰ�ĵ�ͼ��������������е�����
unsigned int mapSize[2]; // ��ǰ��ͼ�Ĵ�С
unsigned int mapMaxBlocks[2]; // ��ǰ��ͼ���и��������������
unsigned int pointer[2]; // �û���ָ��λ��

// ��ʼ����Ϸ
void init();

// ���ƽ��棬ÿ�β����������һ���Ը��»���
void draw();

// ����ָ���ƶ�
void move(int i);

// �ڵ�ǰλ�����ӻ�����
void put();

// �����Ϸ�Ƿ����
int check();

// ��ʼ��Ϸ
void start();
