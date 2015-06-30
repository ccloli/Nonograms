void getProgress()
{
    FILE *fp = NULL;
    int i, j;

    fp = fopen("GameData.txt", "r");                  //��ֻ����ʽ���ļ�
    if (fp != NULL) {                                 //�ж��ļ���Ϊ��
        for (i = 0; i < 9; i++) {                    //������� 
            for (j = 0; j < 50; j++) {                  //�ؿ�����     
                progress[i][j] = fgetc(fp) == '0' ? 0 : 1;   /* ��ȡ�ؿ����ݣ�����0��ȡ0������ȡ1*/
            }
        }
        fclose(fp);                             //�ر��ļ�   
    } else {                                     //�ж��ļ��Ƿ�Ϊ��
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 50; j++) {
                progress[i][j] = 0;              //�����йؿ�����Ϊ0
            }
        }
    }
}

void saveProgress(int jibie, int guan)
{
    FILE *fp = NULL;
    int i, j;

    if (jibie <= 9 && guan <= 50) {    //�ж�δ�������ؿ���9��50�أ�ʱ
        progress[jibie][guan] = 1;         //����һ�ش���Ϊ��� 
    }

    fp = fopen("GameData.txt", "w+");           //�Զ�д��ʽ���ļ�
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 50; j++) {
            if (progress[i][j] == 0) {           //�жϹؿ�Ϊδ���
                fputc('0', fp);                //д��0��ָ����ָλ��
            } else {                            //�ؿ�Ϊ���
                fputc('1', fp);                 //д��1��ָ����ָλ��
            }
        }
    }
    fclose(fp);                           //�ر��ļ�   
}
