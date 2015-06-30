void getProgress()
{
    FILE *fp = NULL;
    int i, j;

    fp = fopen("GameData.txt", "r");                  //以只读方式打开文件
    if (fp != NULL) {                                 //判断文件不为空
        for (i = 0; i < 9; i++) {                    //级别递增 
            for (j = 0; j < 50; j++) {                  //关卡递增     
                progress[i][j] = fgetc(fp) == '0' ? 0 : 1;   /* 读取关卡数据，等于0则取0，否则取1*/
            }
        }
        fclose(fp);                             //关闭文件   
    } else {                                     //判断文件是否为空
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 50; j++) {
                progress[i][j] = 0;              //令所有关卡重置为0
            }
        }
    }
}

void saveProgress(int jibie, int guan)
{
    FILE *fp = NULL;
    int i, j;

    if (jibie <= 9 && guan <= 50) {    //判断未到达最大关卡（9级50关）时
        progress[jibie][guan] = 1;         //将上一关储存为完成 
    }

    fp = fopen("GameData.txt", "w+");           //以读写方式打开文件
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 50; j++) {
            if (progress[i][j] == 0) {           //判断关卡为未完成
                fputc('0', fp);                //写入0到指针所指位置
            } else {                            //关卡为完成
                fputc('1', fp);                 //写入1到指针所指位置
            }
        }
    }
    fclose(fp);                           //关闭文件   
}
