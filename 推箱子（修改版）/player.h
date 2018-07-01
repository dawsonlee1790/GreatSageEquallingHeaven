#pragma once
#include<string>
#include<fstream>
#include<graphics.h>
using namespace std;
class PLAYER
{
public:
	char name[100];//玩家ID
	int checkpoint = 1;//关卡
	void gegister();//用户注册函数
	int login();//用户登录函数
};

