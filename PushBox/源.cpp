/*
作者:DawsonLee
Email:dawsonlee1790@foxmail.com
*/


#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>

#define BLACK	      0 //黑格:用于填充图像
#define WHITEWALL	  1	//白墙:用于阻挡主角移动
#define BLUEWALL	  2	//蓝格:用于表示可移动空间
#define BALL	      3	//点	:用于指定箱子放置位置
#define BOX	          4	//箱子:用于表示初始箱子位置
#define REDBOX	      5	//变色的箱子:用于表示这个点位置已经放置箱子
#define MAN	          6	//主角:用于表示主角位置
#define MANBALL       7//主角站在点上




int main()
{
	int map[13][16];//创建一个map数组用来存储矩阵信息
	int man_i, man_j;//用来存储人物的位置信息
	int readmap(int map[13][16], int &man_x, int &man_y);
	void darm(int a, int ii, int jj);

	readmap(map, man_i, man_j);//调用readmap()函数。


	initgraph(800, 650);//生成一个宽800，高650的窗口。假设矩阵元素对应的每个小矩形是50*50的，那个窗口就应该是这么大。
						
	//载入一张漂亮的背景图片
	PIMAGE imgui;
	imgui = newimage();
	getimage(imgui, "pic/背景.jpg");
	putimage(0, 0, imgui);

	for (int i = 0; i<13; i++)
		for (int j = 0; j < 16; j++)
		{
			darm(map[i][j], i, j);//遍历绘制每个小矩形
		}

	void move(char get, int map[13][16], int &man_i, int &man_j);
	char get;
	for (; is_run(); delay_fps(60))//is_run()表示窗口一直显示，delay_fps(60)表示窗口以60帧的频率刷新
	{
		get = getch();//等待用户输入键盘按键
		move(get, map, man_i, man_j);
	}

	closegraph();//关闭窗口
	return 0;
}

int readmap(int map[13][16], int &man_i, int &man_j)//map[13][16]是形参，其中&man_i表是的是man_i的引用，引用传递的意义在于：传入参数会因函数中的操作而改变
{
	FILE *fp = fopen("MAP.txt", "rb");//以只读形式打开文件MAP.txt
	if (!fp) {
		printf("打开文件失败，文件位置你可能放错了\n");
		exit(1);//打开失败则结束程序
	}
	int i, j;
	char str[10];//用于存储从文本文件读取的字符串信息
	for (i = 0; i<13; i++)
		for (j = 0; j < 16; j++) 
		{
			fscanf(fp, "%s", str); //从文件中读取一个字符串，遇到空格结束
			map[i][j] = atoi(str);//将字符串转变为整型，并赋值给map[i][j]
			if (map[i][j] == MAN) //如果找到了MAN的位置，则返回坐标在 man_i和 man_j 中
			{
				man_i = i;
				man_j = j;
			}
		}
	return 0;
}
/*
下面是在图形库绘制小矩形中图像的功能模块
这部分涉及C++中的知识，C语言新手不必过多纠结不懂的东西。但要知道，创建的源文件要是cpp格式的
*/

void darm(int a, int ii, int jj)
{
	PIMAGE img;//声明
	img = newimage();//实例化
	switch (a)
	{
	case BLACK:break;
	case WHITEWALL:
	{
		getimage(img, "pic/墙.jpg");//getimage()和putimage请翻阅ege图形库帮助手册。
		putimage(jj * 50, ii * 50, img);//在ii行jj列绘制一个50*50像素的矩形图像
		break;
	}
	case BLUEWALL:
	{
		getimage(img, "pic/路.jpg");
		putimage(jj * 50, ii * 50, img);
		break;
	}
	case BALL:
	{
		getimage(img, "pic/目的地.png");
		putimage(jj * 50, ii * 50, img);
		break;
	}
	case BOX:
	{
		getimage(img, "pic/箱子.png");
		putimage(jj * 50, ii * 50, img);
		break;
	}
	case MAN:
	{
		getimage(img, "pic/人.jpg");
		putimage(jj * 50, ii * 50, img);
		break;
	}
	case MANBALL:
	{
		getimage(img, "pic/人.jpg");
		putimage(jj * 50, ii * 50, img);
		break;
	}
	case REDBOX:
	{
		getimage(img, "pic/红箱子.png");
		putimage(jj * 50, ii * 50, img);
		break;
	}
	}
	ege::delimage(img);
}

/*
传入函数的参数 get表示用户输入的键盘按键，传入实时数组map的信息，传入实时MAN的位置信息man_i，man_j。
*/
void move(char get, int map[13][16], int &man_i, int &man_j)
{
	//首先把情况的变化存在table[12][4]数组中
	int table[12][4];

	table[0][0] = MAN * BLUEWALL;
	table[1][0] = MAN * BALL;
	table[2][0] = MAN * BOX * BLUEWALL;
	table[3][0] = MAN * BOX * BALL;
	table[4][0] = MAN * REDBOX * BLUEWALL;
	table[5][0] = MAN * REDBOX * BALL;
	table[6][0] = MANBALL * BLUEWALL;
	table[7][0] = MANBALL * BALL;
	table[8][0] = MANBALL * BOX * BLUEWALL;
	table[9][0] = MANBALL * BOX * BALL;
	table[10][0] = MANBALL * REDBOX * BLUEWALL;
	table[11][0] = MANBALL * REDBOX * BALL;

	table[0][1] = BLUEWALL;
	table[1][1] = BLUEWALL;
	table[2][1] = BLUEWALL;
	table[3][1] = BLUEWALL;
	table[4][1] = BLUEWALL;
	table[5][1] = BLUEWALL;
	table[6][1] = BALL;
	table[7][1] = BALL;
	table[8][1] = BALL;
	table[9][1] = BALL;
	table[10][1] = BALL;
	table[11][1] = BALL;

	table[0][2] = MAN;
	table[1][2] = MANBALL;
	table[2][2] = MAN;
	table[3][2] = MAN;
	table[4][2] = MANBALL;
	table[5][2] = MANBALL;
	table[6][2] = MAN;
	table[7][2] = MANBALL;
	table[8][2] = MAN;
	table[9][2] = MAN;
	table[10][2] = MANBALL;
	table[11][2] = MANBALL;

	table[0][3] = -1;
	table[1][3] = -1;
	table[2][3] = BOX;
	table[3][3] = REDBOX;
	table[4][3] = BOX;
	table[5][3] = REDBOX;
	table[6][3] = -1;
	table[7][3] = -1;
	table[8][3] = BOX;
	table[9][3] = REDBOX;
	table[10][3] = BOX;
	table[11][3] = REDBOX;



	int i;
	void darm(int a, int ii, int jj);//要用到绘制函数，所以先声明
	switch (get)//switch判断用户输入的键盘信息
	{
	case 37:   //左移，向左键的ASCII码
		//for循环遍历判断MAN向左移动对应的是哪种情况
		for (i = 0; i < 12; i++)
			if (map[man_i][man_j] * map[man_i][man_j - 1] * map[man_i][man_j - 2] == table[i][0] ||
				map[man_i][man_j] * map[man_i][man_j - 1] == table[i][0])
			{
				//找到对应的情况后执行以下语句

				map[man_i][man_j] = table[i][1];
				map[man_i][man_j - 1] = table[i][2];
				if (table[i][3] != -1)map[man_i][man_j - 2] = table[i][3];//如果不需要改变第三个格子的图像，就不赋值。也就是如果table[i][3]==-1时。

				//遍历绘制对应的三个格子信息
				darm(map[man_i][man_j], man_i, man_j);
				darm(map[man_i][man_j - 1], man_i, man_j - 1);
				darm(map[man_i][man_j - 2], man_i, man_j - 2);

				man_j--;//绘制结束后，要改变MAN的实时位置信息，并break跳出循环
				break;
			}
		break;//再次break跳出switch语句
	case 38://上移，向上键的ASCII码
		//for循环遍历判断MAN向上移动对应的是哪种情况
		for (i = 0; i < 12; i++)
			if (map[man_i][man_j] * map[man_i - 1][man_j] * map[man_i - 2][man_j] == table[i][0] ||
				map[man_i][man_j] * map[man_i - 1][man_j] == table[i][0])
			{
				map[man_i][man_j] = table[i][1];
				map[man_i - 1][man_j] = table[i][2];
				if (table[i][3] != -1)map[man_i - 2][man_j] = table[i][3];
				darm(map[man_i][man_j], man_i, man_j);
				darm(map[man_i - 1][man_j], man_i - 1, man_j);
				darm(map[man_i - 2][man_j], man_i - 2, man_j);
				man_i--;
				break;
			}
		break;
	case 39://右移，向右键的ASCII码
		//for循环遍历判断MAN向右移动对应的是哪种情况
		for (i = 0; i < 12; i++)
			if (map[man_i][man_j] * map[man_i][man_j + 1] * map[man_i][man_j + 2] == table[i][0] ||
				map[man_i][man_j] * map[man_i][man_j + 1] == table[i][0])
			{
				map[man_i][man_j] = table[i][1];
				map[man_i][man_j + 1] = table[i][2];
				if (table[i][3] != -1)map[man_i][man_j + 2] = table[i][3];
				darm(map[man_i][man_j], man_i, man_j);
				darm(map[man_i][man_j + 1], man_i, man_j + 1);
				darm(map[man_i][man_j + 2], man_i, man_j + 2);
				man_j++;
				break;
			}
		break;
	case 40://下移，向下键的ASCII码
		//for循环遍历判断MAN向下移动对应的是哪种情况
		for (i = 0; i < 12; i++)
			if (map[man_i][man_j] * map[man_i + 1][man_j] * map[man_i + 2][man_j] == table[i][0] ||
				map[man_i][man_j] * map[man_i + 1][man_j] == table[i][0])
			{
				map[man_i][man_j] = table[i][1];
				map[man_i + 1][man_j] = table[i][2];
				if (table[i][3] != -1)map[man_i + 2][man_j] = table[i][3];
				darm(map[man_i][man_j], man_i, man_j);
				darm(map[man_i + 1][man_j], man_i + 1, man_j);
				darm(map[man_i + 2][man_j], man_i + 2, man_j);
				man_i++;
				break;
			}
		break;
	default:
		break;
	}
}
