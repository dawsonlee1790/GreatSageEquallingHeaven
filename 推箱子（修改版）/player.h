#pragma once
#include<string>
#include<fstream>
#include<graphics.h>
using namespace std;
class PLAYER
{
public:
	char name[100];//���ID
	int checkpoint = 1;//�ؿ�
	void gegister();//�û�ע�ắ��
	int login();//�û���¼����
};

