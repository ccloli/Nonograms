//unsigned int firstRun; // �Ƿ��ǵ�һ�����г�������ǵ�һ�����г�������Ҫִ�� init() ����� 0 ����

unsigned int userMap[50][50]; // �û����Ƶĵ�ͼ�������Ϊһ������
unsigned int map[3][50][25]; // ��ǰ�ĵ�ͼ��������������е�����
unsigned int mapSize[2]; // ��ǰ��ͼ�Ĵ�С
unsigned int mapMaxBlocks[2]; // ��ǰ��ͼ���и��������������
unsigned int pointer[2]; // �û���ָ��λ��
unsigned int mapAction[2];
unsigned int progress[9][50];

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
