// PrintColorText By Zhihu@王文强 http://www.zhihu.com/question/20572982

int printcf(const char *Text, WORD Attributes)
{
        int     nRet = 0;
 
        //
        //注意：GetStdHandle()返回的不是一个duplicate handle，而是真正的输出缓冲区的句柄！
        //所以不要试图关闭它，否则就再也不能向缓冲区输出任何东西了。
        //
        HANDLE  hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut != INVALID_HANDLE_VALUE)
        {
                if (SetConsoleTextAttribute(hOut, Attributes))
                {
                        nRet = printf(Text);
                }
                //
                //恢复白色文字，黑色背景
                //
                SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
        }
 
        return nRet;
}
