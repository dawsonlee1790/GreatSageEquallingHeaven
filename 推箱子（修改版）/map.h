#pragma once
#include <graphics.h>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define LIST 13
#define ROW 16
#define BLACK	      0 //黑格:用于填充图像
#define WHITEWALL	  1	//白墙:用于阻挡主角移动
#define BLUEWALL	  2	//蓝格:用于表示可移动空间
#define BALL	      3	//点	:用于指定箱子放置位置
#define BOX	      4	//箱子:用于表示初始箱子位置
#define REDBOX	  5	//变色的箱子:用于表示这个点位置已经放置箱子
#define MAN	      6	//主角:用于表示主角位置
#define MANBALL    20//主角站在点上
class MAP
{
private:
	int checkpoint;
	int i, j;
public:
	PIMAGE img;
	char name[20];                  //用来存储读取的地图的名称，用于实现重新载入当关游戏
	int map[LIST][ROW];             //用来存储整幅地图每个坐标表示的信息
	int x, y;                   //人的坐标（readmap()函数进行以后便得到）
	void readmap(char str[]);   //读取地图模块（实际上是读取一个数组存放在map【】【】中）
	void darmmap();              //绘制地图模块 （实际上是绘制数组的对应图像）
	int move(char a);                 //实现人物的移动(实际上是map数组的改变)(WSAD操控上下左右，C重新选关，R重新载入本关)
	int judge();             //判断模块
	int choose(int checkpoint);       //选关模块
	void darm(int a, int jj, int ii);//用于绘制某个坐标（yy，xx）位置的的图像
	void newmap();
};
