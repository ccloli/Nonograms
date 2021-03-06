Nonograms
================

Nonograms（お絵かきロジック）是一款拼图游戏。


介绍
----------------

Nonogram 是一种逻辑游戏，以猜谜的方式绘画位图。

在一个网格中，每一行和列都有一组数，玩家需根据它们来填满或留空格子，最后就可以由此得出一幅图画。

例如，“4 8 3”的意思就是指该行或列上有三条独立的线，分别占了 4、8 和 3 格，而每条线最少要由一个空格分开。

传统上，玩家是以黑色填满格子，和以“×”号标记一定不需要填充的格子。

Nonogram 是在 1987 年由日本人西尾彻也发明的。

在日本，Nonogram 的名称是“お絵かきロジック”，意思是“以数绘画”，初见于日本的谜题杂志。


程序逻辑
----------------

1. 开启程序后进入游戏菜单（线为直接进入游戏，待定）；

2. 选择关卡（现为随机选择关卡，待定）；

3. 游戏初始化并绘制游戏界面；

4. 用户使用上、下、左、右移动光标，空格落子与起子，X 键画×；

5. 每次起子与落子后计算地图并与原始地图进行匹配；

6. 若完全匹配，告知用户游戏成功；

7. 退出程序（待定）。


编译
----------------

* 请在 `index.c` 下进行编译


分支说明
----------------

* 请自行在 `master` 分支下新开分支进行编码，请勿污染 `master` 分支下的代码

* 可按照自己的开发计划自开多个分支，完成后用 `git push --all` 推送本地所有分支

* 分支名统一用 `nickName-functionName` 的形式命名，如 `ccloli-draw`


代码规范
----------------

* 所有需要调用系统库的 `include` 均在 `require.c` 内引入

* 请将自己的代码写在一个与函数名相同或类似的 c 文件内并在 `module.c` 内引入

* 全局变量请在 `config.c` 内申明而不要污染 `index.c`

* 主函数 `main.c` 目前还未完全确定用途，暂可用于代码调试

* 变量名统一采用小驼峰法命名

* 注意代码缩进，除大括号本身所在行外，大括号内各行代码均需要缩进

* 代码缩进使用 1 个 TAB 键或 4 个空格

* 大括号位置与标点前后的空格不作要求，按照个人代码风格习惯