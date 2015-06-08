void getProgress()
{
    FILE *fp = NULL;
    int i, j;

    fp = fopen("GameData.txt", "r");
    if (fp != NULL) {
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 50; j++) {
                progress[i][j] = fgetc(fp) == '0' ? 0 : 1;
            }
        }
        fclose(fp);
    } else {
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 50; j++) {
                progress[i][j] = 0;
            }
        }
    }
}

void saveProgress(int jibie, int guan)
{
    FILE *fp = NULL;
    int i, j;

    if (jibie <= 9 && guan <= 50) {
        progress[jibie][guan] = 1;
    }

    fp = fopen("GameData.txt", "w+");
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 50; j++) {
            if (progress[i][j] == 0) {
                fputc('0', fp);
            } else {
                fputc('1', fp);
            }
        }
    }
    fclose(fp);
}
