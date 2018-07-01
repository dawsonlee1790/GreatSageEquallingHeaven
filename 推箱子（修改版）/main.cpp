#include"map.h"
#include"player.h"
#include"ui.h"

#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
int main()
{
	initgraph(800, 650);
	mciSendString(TEXT("open music/�Ϻ���.mp3 alias mysong"), NULL, 0, NULL);
	mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);
	MAP map;
	UI ui;
	PLAYER player;
	char str[100];
	for (; is_run(); delay_fps(60))
	{
		ui.ui1();    //����һ�������ͼ��������Ϣ
		int turn1 = 0;
		int turn = 0;
		while (turn1 == 0)
		{
			switch (getch())
			{
			case '1': player.login(); turn1 = 1; break;
			case '2': player.gegister(); turn1 = 0; break;
			case '3':
			{
				ui.ui4();
				switch (getch())
				{
				  case '1': 
				  {
					  mciSendString(TEXT("close mysong"), NULL, 0, NULL);
					  mciSendString(TEXT("open music/�춹.mp3 alias mysong"), NULL, 0, NULL);
					  mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);
					  break;
				  }
				  case '2': 
				  {
					  mciSendString(TEXT("close mysong"), NULL, 0, NULL);
					  mciSendString(TEXT("open music/����.mp3 alias mysong"), NULL, 0, NULL);
					  mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);
					  break;
				  }
				  case '3':
				  {
					  mciSendString(TEXT("close mysong"), NULL, 0, NULL);
					  mciSendString(TEXT("open music/�ʺ�.mp3 alias mysong"), NULL, 0, NULL);
					  mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);
					  break;
				  }
				  case '4':
				  {
					  mciSendString(TEXT("close mysong"), NULL, 0, NULL);
					  mciSendString(TEXT("open music/�������.mp3 alias mysong"), NULL, 0, NULL);
					  mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);
					  break;
				  }
				  case '5':
				  {
					  mciSendString(TEXT("close mysong"), NULL, 0, NULL);
					  mciSendString(TEXT("open music/�Ϻ���.mp3 alias mysong"), NULL, 0, NULL);
					  mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);
					  break;
				  }
				  case '6':
				  {
					  mciSendString(TEXT("pause mysong"), NULL, 0, NULL);
					  break;
				  }
				  default:
					break;
				}
				turn = 1;
				turn1 = 1;
				break;
			}
			default:
				break;
			};
		}

		while (turn == 0)
		{
			ui.ui2();  //������������ͼ��������Ϣ
			switch (getch())
			{
			case '1':
			{

				PIMAGE imgui;
				imgui = newimage();
				getimage(imgui, "pic/����.jpg");
				putimage(0, 0, imgui);

				char a;
				int b, c;
				c = 1;
				map.choose(c);
				map.darmmap();
				sprintf_s(str, "��%d��", c);
				outtextxy(100, 0, "�������ҿ��ƣ�R���¼��ر��أ�C����ѡ��");
				outtextxy(0, 0, str);
				for (; c <= 4; )
				{
					a = getch();
					if (a == 'C'||a=='c')break;
					map.move(a);
					b = map.judge();
					if (b == 0)
					{
						c = c + 1;
						getch();
						putimage(0, 0, imgui);
						map.choose(c);
						map.darmmap();
						sprintf_s(str, "��%d��", c);
						outtextxy(0, 0, str);
						outtextxy(100, 0, "�������ҿ��ƣ�R���¼��ر��أ�C����ѡ��");
					}
				}
				break;
			}
			case '2':
			{

				PIMAGE imgui;
				imgui = newimage();
				getimage(imgui, "pic/����.jpg");
				putimage(0, 0, imgui);
				setcolor(EGERGB(0, 100, 0));     //������ɫ��ɫ
				setfont(25, 0, "����");
				outtextxy(200, 200, "��������ѡ��Ĺؿ���1��2��3��4��");
				char a;
				int b, c, d = 1;
				while (d != 0)
				{
					a = getch();
					c = a - 48;
					d = map.choose(c);
				}
				putimage(0, 0, imgui);
				map.darmmap();
				sprintf_s(str, "��%d��", c);
				outtextxy(0, 0, str);
				outtextxy(100, 0, "�������ҿ��ƣ�R���¼��ر��أ�C����ѡ��");
				for (; c < 5; )
				{
					a = getch();
					if (a == 'C'||a=='c')break;
					map.move(a);
					b = map.judge();
					if (b == 0)
					{
						c = c + 1;
						getch();
						putimage(0, 0, imgui);
						map.choose(c);
						map.darmmap();
						sprintf_s(str, "��%d��", c);
						outtextxy(0, 0, str);
						outtextxy(100, 0, "�������ҿ��ƣ�R���¼��ر��أ�C����ѡ��");
					}
				}
				break;
			}
			case '3':
			{
				cleardevice();
				ui.ui3();
				getch();
				break;
			}
			case'6':
			{
				turn = 1;
				break;
			}
			case'4':
			{
				map.newmap();
				break;
			}
			case '5':
			{
				char str2[20];
				inputbox_getline("������Ƶ��µ�ͼ", "�������ͼ�ļ���������Ҫ��չ����", str2, 100);
				map.readmap(str2);
				char a;
				int b, c;
				PIMAGE imgui;
				imgui = newimage();
				getimage(imgui, "pic/����.jpg");
				putimage(0, 0, imgui);
				map.darmmap();
				outtextxy(0, 0, str2);
				outtextxy(150, 0, "�������ҿ��ƣ�R���¼��ر��أ�C����ѡ��");
				c = 0;
				for (; c == 0; )
				{				
					a = getch();
					if (a == 'C' || a == 'c')break;
					map.move(a);
					b = map.judge();
					if (b == 0)
					{
						c = c + 1;
						getch();
					}	
				}
				break;
			}
			default:
				break;
			};
		}
	}
	closegraph();
	return 0;
}