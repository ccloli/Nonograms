// PrintColorText By Zhihu@����ǿ http://www.zhihu.com/question/20572982

int printcf(const char *Text, WORD Attributes)
{
        int     nRet = 0;
 
        //
        //ע�⣺GetStdHandle()���صĲ���һ��duplicate handle����������������������ľ����
        //���Բ�Ҫ��ͼ�ر������������Ҳ�����򻺳�������κζ����ˡ�
        //
        HANDLE  hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut != INVALID_HANDLE_VALUE)
        {
                if (SetConsoleTextAttribute(hOut, Attributes))
                {
                        nRet = printf(Text);
                }
                //
                //�ָ���ɫ���֣���ɫ����
                //
                SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
        }
 
        return nRet;
}
