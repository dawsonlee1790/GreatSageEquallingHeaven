#include"player.h"
#define LOGIN_OK 0
#define LOGIN_NO 1
void PLAYER::gegister()//�û�ע�ắ��
{

	inputbox_getline("ע��", "�ǳƣ��س�ȷ�ϣ�", name, 100);
	ofstream savefile("user.txt", ios::app);
	savefile << name << endl;
}
int PLAYER::login()//�û���¼����
{
	inputbox_getline("��½", "�ǳƣ��س�ȷ�ϣ�,��������dawson����user", name, 100);
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
		inputbox_getline("��½", "��½ʧ�ܣ������������ǳƣ��س�ȷ�ϣ�,��������dawson����user", name, 100);
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
