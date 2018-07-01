#include"player.h"
#define LOGIN_OK 0
#define LOGIN_NO 1
void PLAYER::gegister()//用户注册函数
{

	inputbox_getline("注册", "昵称（回车确认）", name, 100);
	ofstream savefile("user.txt", ios::app);
	savefile << name << endl;
}
int PLAYER::login()//用户登录函数
{
	inputbox_getline("登陆", "昵称（回车确认）,可以输入dawson或者user", name, 100);
	ifstream openfile("user.txt");
	int a;
	char user[100];
	while (!openfile.eof())
	{
		openfile.getline(user, 100);
		if (strcmp(user, name) == 0)
		{
			a = LOGIN_OK;
			break;
		}
		else a = LOGIN_NO;
	}
	openfile.close();
	while (a == LOGIN_NO)
	{
		inputbox_getline("登陆", "登陆失败，请重新输入昵称（回车确认）,可以输入dawson或者user", name, 100);
		ifstream openfile("user.txt");
		while (!openfile.eof())
		{
			openfile.getline(user, 100,'\n');
			if (strcmp(user, name) == 0)
			{
				a = LOGIN_OK;
				break;
			}
			else a = LOGIN_NO;
		}
	}
	return 0;
}
