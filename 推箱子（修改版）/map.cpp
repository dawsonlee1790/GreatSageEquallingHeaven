#include"map.h"
#include<math.h>
void MAP::readmap(char str[])
{
	string str1;
	char path[100];
	strcpy(path, "map/");
	strcat_s(path, str);
	strcat_s(path, ".txt");
	ifstream openfile(path);
	if (!openfile)
	{
		cout << "open error!" << endl;
		exit(1);
	}
	for (i = 0; i < LIST; i++)
	{

		for (j = 0; j < ROW; j++)
		{
			openfile >> str1;
			map[i][j] = atoi(str1.c_str());
			if (map[i][j] == MAN)
			{
				x = i;
				y = j;
			}
		}
	}
	openfile.close();
	strcpy_s(name, str);
}
void MAP::darmmap()
{
	img = newimage();
	for (i = 0; i < LIST; i++)
	{
		for (j = 0; j < ROW; j++)
			switch (map[i][j])
			{
			case BLACK:break;
			case WHITEWALL:
			{
				getimage(img, "pic/ǽ.jpg");
				putimage(j * 50, i * 50, img);
				break;
			}
			case BLUEWALL:
			{
				getimage(img, "pic/·.jpg");
				putimage(j * 50, i * 50, img);
				break;
			}
			case BALL:
			{
				getimage(img, "pic/Ŀ�ĵ�.png");
				putimage(j * 50, i * 50, img);
				break;
			}
			case BOX:
			{
				getimage(img, "pic/����.png");
				putimage(j * 50, i * 50, img);
				break;
			}
			case MAN:
			{
				getimage(img, "pic/��.jpg");
				putimage(j * 50, i * 50, img);
				break;
			}
			case MANBALL:
			{
				getimage(img, "pic/��.jpg");
				putimage(j * 50, i * 50, img);
				break;
			}
			case REDBOX:
			{
				getimage(img, "pic/������.png");
				putimage(j * 50, i * 50, img);
				break;
			}
			}
	}
	delimage(img);
}
int MAP::move(char a)
{
	switch (a)
	{
	case 40:   //����
	{
		if (map[x][y] + map[x + 1][y] == MAN + BOX
			&& map[x + 2][y] == BLUEWALL)
		{
			map[x][y] = BLUEWALL; darm(BLUEWALL, x, y);
			map[x + 1][y] = MAN; darm(MAN, x + 1, y);
			map[x + 2][y] = BOX; darm(BOX, x + 2, y);
		}
		else if (map[x][y] + map[x + 1][y] == MAN + BOX
			&& map[x + 2][y] == BALL)
		{
			map[x][y] = BLUEWALL; darm(BLUEWALL, x, y);
			map[x + 1][y] = MAN; darm(MAN, x + 1, y);
			map[x + 2][y] = REDBOX; darm(REDBOX, x + 2, y);
		}
		else if (map[x][y] + map[x + 1][y] == MANBALL + BOX
			&& map[x + 2][y] == BALL)
		{
			map[x][y] = BALL; darm(BALL, x, y);
			map[x + 1][y] = MAN; darm(MAN, x + 1, y);
			map[x + 2][y] = REDBOX; darm(REDBOX, x + 2, y);
		}
		else if (map[x][y] + map[x + 1][y] == MANBALL + BOX
			&& map[x + 2][y] == BLUEWALL)
		{
			map[x][y] = BALL; darm(BALL, x, y);
			map[x + 1][y] = MAN; darm(MAN, x + 1, y);
			map[x + 2][y] = BOX; darm(BOX, x + 2, y);
		}
		else if (map[x][y] + map[x + 1][y] == MANBALL + REDBOX
			&& map[x + 2][y] == BLUEWALL)
		{
			map[x][y] = BALL; darm(BALL, x, y);
			map[x + 1][y] = MANBALL; darm(MANBALL, x + 1, y);
			map[x + 2][y] = BOX; darm(BOX, x + 2, y);
		}
		else if (map[x][y] + map[x + 1][y] == MAN + BLUEWALL)
		{
			map[x][y] = BLUEWALL; darm(BLUEWALL, x, y);
			map[x + 1][y] = MAN; darm(MAN, x + 1, y);
		}
		else if (map[x][y] + map[x + 1][y] == MAN + BALL)
		{
			map[x][y] = BLUEWALL; darm(BLUEWALL, x, y);
			map[x + 1][y] = MANBALL; darm(MANBALL, x + 1, y);
		}
		else if (map[x][y] + map[x + 1][y] == MANBALL + BLUEWALL)
		{
			map[x][y] = BALL; darm(BALL, x, y);
			map[x + 1][y] = MAN; darm(MAN, x + 1, y);
		}
		else if (map[x][y] + map[x + 1][y] == MANBALL + BALL)
		{
			map[x][y] = BALL; darm(BALL, x, y);
			map[x + 1][y] = MANBALL; darm(MANBALL, x + 1, y);
		}
		else if (map[x][y] + map[x + 1][y] == MANBALL + BOX
			&&map[x + 2][y] == BALL)
		{
			map[x][y] = BALL; darm(BALL, x, y);
			map[x + 1][y] = MANBALL; darm(MANBALL, x + 1, y);
			map[x + 2][y] = REDBOX; darm(REDBOX, x + 2, y);
		}
		else if (map[x][y] + map[x + 1][y] == MAN + REDBOX
			&& map[x + 2][y] == BALL)
		{
			map[x][y] = BLUEWALL; darm(BLUEWALL, x, y);
			map[x + 1][y] = MANBALL; darm(MANBALL, x + 1, y);
			map[x + 2][y] = REDBOX; darm(REDBOX, x + 2, y);

		}
		else if (map[x][y] + map[x + 1][y] == MAN + REDBOX
			&& map[x + 2][y] == BLUEWALL)
		{
			map[x][y] = BLUEWALL; darm(BLUEWALL, x, y);
			map[x + 1][y] = MANBALL; darm(MANBALL, x + 1, y);
			map[x + 2][y] = BOX; darm(BOX, x + 2, y);

		}
		else
		{
			cout << "�����ƶ�" << endl;
			return(1);
			break;
		}
		x = x + 1;
		break;
	}
	case 38:   //����
	{
		if (map[x][y] + map[x - 1][y] == MAN + BOX
			&& map[x - 2][y] == BLUEWALL)
		{
			map[x][y] = BLUEWALL; darm(BLUEWALL, x, y);
			map[x - 1][y] = MAN; darm(MAN, x - 1, y);
			map[x - 2][y] = BOX; darm(BOX, x - 2, y);
		}
		else if (map[x][y] + map[x - 1][y] == MAN + BOX
			&& map[x - 2][y] == BALL)
		{
			map[x][y] = BLUEWALL; darm(BLUEWALL, x, y);
			map[x - 1][y] = MAN; darm(MAN, x - 1, y);
			map[x - 2][y] = REDBOX; darm(REDBOX, x - 2, y);
		}
		else if (map[x][y] + map[x - 1][y] == MANBALL + BOX
			&& map[x - 2][y] == BALL)
		{
			map[x][y] = BALL; darm(BALL, x, y);
			map[x - 1][y] = MAN; darm(MAN, x - 1, y);
			map[x - 2][y] = REDBOX; darm(REDBOX, x - 2, y);
		}
		else if (map[x][y] + map[x - 1][y] == MANBALL + BOX
			&& map[x - 2][y] == BLUEWALL)
		{
			map[x][y] = BALL; darm(BALL, x, y);
			map[x - 1][y] = MAN; darm(MAN, x - 1, y);
			map[x - 2][y] = BOX; darm(BOX, x - 2, y);
		}
		else if (map[x][y] + map[x - 1][y] == MANBALL + REDBOX
			&& map[x - 2][y] == BLUEWALL)
		{
			map[x][y] = BALL; darm(BALL, x, y);
			map[x - 1][y] = MANBALL; darm(MANBALL, x - 1, y);
			map[x - 2][y] = BOX; darm(BOX, x - 2, y);
		}
		else if (map[x][y] + map[x - 1][y] == MAN + BLUEWALL)
		{
			map[x][y] = BLUEWALL; darm(BLUEWALL, x, y);
			map[x - 1][y] = MAN; darm(MAN, x - 1, y);
		}
		else if (map[x][y] + map[x - 1][y] == MAN + BALL)
		{
			map[x][y] = BLUEWALL; darm(BLUEWALL, x, y);
			map[x - 1][y] = MANBALL; darm(MANBALL, x - 1, y);
		}
		else if (map[x][y] + map[x - 1][y] == MANBALL + BLUEWALL)
		{
			map[x][y] = BALL; darm(BALL, x, y);
			map[x - 1][y] = MAN; darm(MAN, x - 1, y);
		}
		else if (map[x][y] + map[x - 1][y] == MANBALL + BALL)
		{
			map[x][y] = BALL; darm(BALL, x, y);
			map[x - 1][y] = MANBALL; darm(MANBALL, x - 1, y);
		}
		else if (map[x][y] + map[x - 1][y] == MANBALL + REDBOX
			&& map[x - 2][y] == BALL)
		{
			map[x][y] = BALL; darm(BALL, x, y);
			map[x - 1][y] = MANBALL; darm(MANBALL, x - 1, y);
			map[x - 2][y] = REDBOX; darm(REDBOX, x - 2, y);
		}
		else if (map[x][y] + map[x - 1][y] == MAN + REDBOX
			&& map[x - 2][y] == BALL)
		{
			map[x][y] = BLUEWALL; darm(BLUEWALL, x, y);
			map[x - 1][y] = MANBALL; darm(MANBALL, x - 1, y);
			map[x - 2][y] = REDBOX; darm(REDBOX, x - 2, y);
		}
		else if (map[x][y] + map[x - 1][y] == MAN + REDBOX
			&& map[x - 2][y] == BLUEWALL)
		{
			map[x][y] = BLUEWALL; darm(BLUEWALL, x, y);
			map[x - 1][y] = MANBALL; darm(MANBALL, x - 1, y);
			map[x - 2][y] = BOX; darm(BOX, x - 2, y);
		}
		else
		{
			cout << "�����ƶ�" << endl;
			return(1);
			break;
		}
		x = x - 1;
		break;
	}
	case 37:   //����
	{
		if (map[x][y] + map[x][y - 1] == MAN + BOX
			&& map[x][y - 2] == BLUEWALL)
		{
			map[x][y] = BLUEWALL; darm(BLUEWALL, x, y);
			map[x][y - 1] = MAN; darm(MAN, x, y - 1);
			map[x][y - 2] = BOX; darm(BOX, x, y - 2);
		}
		else if (map[x][y] + map[x][y - 1] == MAN + BOX
			&& map[x][y - 2] == BALL)
		{
			map[x][y] = BLUEWALL; darm(BLUEWALL, x, y);
			map[x][y - 1] = MAN; darm(MAN, x, y - 1);
			map[x][y - 2] = REDBOX; darm(REDBOX, x, y - 2);
		}
		else if (map[x][y] + map[x][y - 1] == MANBALL + BOX
			&& map[x][y - 2] == BALL)
		{
			map[x][y] = BALL; darm(BALL, x, y);
			map[x][y - 1] = MAN; darm(MAN, x, y - 1);
			map[x][y - 2] = REDBOX; darm(REDBOX, x, y - 2);
		}
		else if (map[x][y] + map[x][y - 1] == MANBALL + BOX
			&& map[x][y - 2] == BLUEWALL)
		{
			map[x][y] = BALL; darm(BALL, x, y);
			map[x][y - 1] = MAN; darm(MAN, x, y - 1);
			map[x][y - 2] = BOX; darm(BOX, x, y - 2);
		}
		else if (map[x][y] + map[x][y - 1] == MANBALL + REDBOX
			&& map[x][y - 2] == BLUEWALL)
		{
			map[x][y] = BALL; darm(BALL, x, y);
			map[x][y - 1] = MANBALL; darm(MANBALL, x, y - 1);
			map[x][y - 2] = BOX; darm(BOX, x, y - 2);
		}
		else if (map[x][y] + map[x][y - 1] == MAN + BLUEWALL)
		{
			map[x][y] = BLUEWALL; darm(BLUEWALL, x, y);
			map[x][y - 1] = MAN; darm(MAN, x, y - 1);
		}
		else if (map[x][y] + map[x][y - 1] == MAN + BALL)
		{
			map[x][y] = BLUEWALL; darm(BLUEWALL, x, y);
			map[x][y - 1] = MANBALL; darm(MANBALL, x, y - 1);
		}
		else if (map[x][y] + map[x][y - 1] == MANBALL + BLUEWALL)
		{
			map[x][y] = BALL; darm(BALL, x, y);
			map[x][y - 1] = MAN; darm(MAN, x, y - 1);
		}
		else if (map[x][y] + map[x][y - 1] == MANBALL + BALL)
		{
			map[x][y] = BALL; darm(BALL, x, y);
			map[x][y - 1] = MANBALL; darm(MANBALL, x, y - 1);
		}
		else if (map[x][y] + map[x][y - 1] == MAN + REDBOX
			&& map[x][y - 2] == BALL)
		{
			map[x][y] = BLUEWALL; darm(BLUEWALL, x, y);
			map[x][y - 1] = MANBALL; darm(MANBALL, x, y - 1);
			map[x][y - 2] = REDBOX; darm(REDBOX, x, y - 2);
		}
		else if (map[x][y] + map[x][y - 1] == MANBALL + REDBOX
			&& map[x][y - 2] == BALL)
		{
			map[x][y] = BALL; darm(BALL, x, y);
			map[x][y - 1] = MANBALL; darm(MANBALL, x, y - 1);
			map[x][y - 2] = REDBOX; darm(REDBOX, x, y - 2);
		}
		else if (map[x][y] + map[x][y - 1] == MAN + REDBOX
			&& map[x][y - 2] == BLUEWALL)
		{
			map[x][y] = BLUEWALL; darm(BLUEWALL, x, y);
			map[x][y - 1] = MANBALL; darm(MANBALL, x, y - 1);
			map[x][y - 2] = BOX; darm(BOX, x, y - 2);
		}
		else
		{
			cout << "�����ƶ�" << endl;
			return(1);
			break;
		}
		y = y - 1;
		break;
	}
	case 39:    //����
	{
		if (map[x][y] + map[x][y + 1] == MAN + BOX
			&& map[x][y + 2] == BLUEWALL)
		{
			map[x][y] = BLUEWALL; darm(BLUEWALL, x, y);
			map[x][y + 1] = MAN; darm(MAN, x, y + 1);
			map[x][y + 2] = BOX; darm(BOX, x, y + 2);
		}
		else if (map[x][y] + map[x][y + 1] == MAN + BOX
			&& map[x][y + 2] == BALL)
		{
			map[x][y] = BLUEWALL; darm(BLUEWALL, x, y);
			map[x][y + 1] = MAN; darm(MAN, x, y + 1);
			map[x][y + 2] = REDBOX; darm(REDBOX, x, y + 2);
		}
		else if (map[x][y] + map[x][y + 1] == MANBALL + BOX
			&& map[x][y + 2] == BALL)
		{
			map[x][y] = BALL; darm(BALL, x, y);
			map[x][y + 1] = MAN; darm(MAN, x, y + 1);
			map[x][y + 2] = REDBOX; darm(REDBOX, x, y + 2);
		}
		else if (map[x][y] + map[x][y + 1] == MANBALL + BOX
			&& map[x][y + 2] == BLUEWALL)
		{
			map[x][y] = BALL; darm(BALL, x, y);
			map[x][y + 1] = MAN; darm(MAN, x, y + 1);
			map[x][y + 2] = BOX; darm(BOX, x, y + 2);
		}
		else if (map[x][y] + map[x][y + 1] == MAN + BLUEWALL)
		{
			map[x][y] = BLUEWALL; darm(BLUEWALL, x, y);
			map[x][y + 1] = MAN; darm(MAN, x, y + 1);
		}
		else if (map[x][y] + map[x][y + 1] == MANBALL + REDBOX
			&& map[x][y + 2] == BLUEWALL)
		{
			map[x][y] = BALL; darm(BALL, x, y);
			map[x][y + 1] = MANBALL; darm(MANBALL, x, y + 1);
			map[x][y + 2] = BOX; darm(BOX, x, y + 2);
		}
		else if (map[x][y] + map[x][y + 1] == MAN + BALL)
		{
			map[x][y] = BLUEWALL; darm(BLUEWALL, x, y);
			map[x][y + 1] = MANBALL; darm(MANBALL, x, y + 1);
		}
		else if (map[x][y] + map[x][y + 1] == MANBALL + BLUEWALL)
		{
			map[x][y] = BALL; darm(BALL, x, y);
			map[x][y + 1] = MAN; darm(MAN, x, y + 1);
		}
		else if (map[x][y] + map[x][y + 1] == MANBALL + BALL)
		{
			map[x][y] = BALL; darm(BALL, x, y);
			map[x][y + 1] = MANBALL; darm(MANBALL, x, y + 1);
		}
		else if (map[x][y] + map[x][y + 1] == MANBALL + REDBOX
			&& map[x][y + 2] == BALL)
		{
			map[x][y] = BALL; darm(BALL, x, y);
			map[x][y + 1] = MANBALL; darm(MANBALL, x, y + 1);
			map[x][y + 2] = REDBOX; darm(REDBOX, x, y + 2);
		}
		else if (map[x][y] + map[x][y + 1] == MAN + REDBOX
			&& map[x][y + 2] == BALL)
		{
			map[x][y] = BLUEWALL; darm(BLUEWALL, x, y);
			map[x][y + 1] = MANBALL; darm(MANBALL, x, y + 1);
			map[x][y + 2] = REDBOX; darm(REDBOX, x, y + 2);
		}
		else if (map[x][y] + map[x][y + 1] == MAN + REDBOX
			&& map[x][y + 2] == BLUEWALL)
		{
			map[x][y] = BLUEWALL; darm(BLUEWALL, x, y);
			map[x][y + 1] = MANBALL; darm(MANBALL, x, y + 1);
			map[x][y + 2] = BOX; darm(BOX, x, y + 2);
		}
		else
		{
			cout << "�����ƶ�" << endl;
			return(1);
			break;
		}
		y = y + 1;
		break;
	}
	case 'r':
	case 'R':
	{
		readmap(name);
		darmmap();
		break;
	}
	default:
		return(1);
		break;
	}
	return 0;
}

//*************************************�������ж�ʤ��ģ��******************************
int MAP::judge()
{
	int i, j;
	int charge = 0;
	for (i = 0; i<LIST; i++)
		for (j = 0; j<ROW; j++)
			if (map[i][j] == BOX)
			{
				charge++;
			}
	if (charge == 0)
	{
		cout << "��ϲ�㣬ͨ�سɹ�" << endl;
		return 0;
	}
	else return 1;
}
//*************************************ѡ��ģ��**********************************
int MAP::choose(int checkpoint)
{
	switch (checkpoint)
	{
	case 1:readmap("MAP1");  break;
	case 2:readmap("MAP2");  break;
	case 3:readmap("MAP3");  break;
	case 4:readmap("MAP4");  break;
	default:
		return 1;
		break;
	}
	return 0;
}

//********************************�ڣ�ii,jj��������λ�û���ͼƬ****************************
void MAP::darm(int a, int ii, int jj)
{
	img = newimage();
	switch (a)
	{
	case BLACK:break;
	case WHITEWALL:
	{
		getimage(img, "pic/ǽ.jpg");
		putimage(jj * 50, ii * 50, img);
		break;
	}
	case BLUEWALL:
	{
		getimage(img, "pic/·.jpg");
		putimage(jj * 50, ii * 50, img);
		break;
	}
	case BALL:
	{
		getimage(img, "pic/Ŀ�ĵ�.png");
		putimage(jj * 50, ii * 50, img);
		break;
	}
	case BOX:
	{
		getimage(img, "pic/����.png");
		putimage(jj * 50, ii * 50, img);
		break;
	}
	case MAN:
	{
		getimage(img, "pic/��.jpg");
		putimage(jj * 50, ii * 50, img);
		break;
	}
	case MANBALL:
	{
		getimage(img, "pic/��.jpg");
		putimage(jj * 50, ii * 50, img);
		break;
	}
	case REDBOX:
	{
		getimage(img, "pic/������.png");
		putimage(jj * 50, ii * 50, img);
		break;
	}
	}
	ege::delimage(img);
}

void MAP::newmap()
{
	char str[100];
	char path[100];
	int turn = 0;
	while (turn == 0)
	{
		strcpy(path, "map/");
		inputbox_getline("���Ƶ�ͼ", "�������ͼ����", str, 100);
		strcat(str, ".txt");
		strcat_s(path, str);
		ofstream savefile(path);
		if (!savefile)turn = 0;
		else turn = 1;
	}
	int xx, yy;
	initgraph(850, 650);
	darm(MAN, 0, 16);
	darm(WHITEWALL, 1, 16);
	darm(BLUEWALL, 2, 16);
	darm(BOX, 3, 16);
	darm(REDBOX, 4, 16);
	darm(BALL, 5, 16);
	darm(BLACK, 6, 16);
	line(799, 300, 799, 351);
	line(799, 351, 850, 351);
	setfont(40, 0, "����");
	outtextxy(800, 350, "��");
	outtextxy(800, 400, "��");
	outtextxy(800, 450, "��");
	outtextxy(800, 500, "��");
	outtextxy(800, 550, "��");
	outtextxy(800, 600, "��");
	PIMAGE img2;
	img2 = newimage();
	mouse_msg msg = {0};
	setbkmode(OPAQUE);
	for (i = 0; i < LIST; i++)
		for (j = 0; j < ROW; j++)
			map[i][j] = 0;
	int ii, jj;
	int pen;
	char q[100], p[100];
	darmmap();
	int a=0;
	for (; a==0; delay_fps(60))
	{
		mousepos(&xx, &yy);
		sprintf(q, "%4d", xx/50);
		sprintf(p, "%4d", yy/50);
		sscanf(q, "%d", &ii);
		sscanf(p, "%d", &jj);
		setfont(30, 0, "����");
		outtextxy(0, 0, q);
		outtextxy(60, 0, p);
		setfont(40, 0, "����");
		while (mousemsg())
		{
			msg = getmouse();
		}

		if (ii == 16 && msg.is_left())
				switch (jj)
				{
				case 0:getimage(img2, 800, 0, 50, 50); pen = MAN; break;
				case 1:getimage(img2, 800, 50, 50, 50); pen = WHITEWALL; break;
				case 2:getimage(img2, 800, 100, 50, 50); pen = BLUEWALL; break;
				case 3:getimage(img2, 800, 150, 50, 50); pen = BOX; break;
				case 4:getimage(img2, 800, 200, 50, 50); pen = REDBOX; break;
				case 5:getimage(img2, 800, 250, 50, 50); pen = BALL; break;
				case 6:getimage(img2, 800, 300, 50, 50); pen = BLACK; break;
				default:
					break;
				}
		if (ii < 16 && msg.is_left())
		{
			putimage(ii * 50, jj * 50,img2);
			map[jj][ii] = pen;
		}
		if (msg.is_right()) a = 1;
	}
	
	ofstream savefile(path);
	for (jj = 0; jj < LIST; jj++)

	{
		savefile << "\n";
		for (ii = 0; ii < ROW; ii++)
			savefile << map[jj][ii] << "\t";
	}
	savefile.close();
	memset(path, 0, strlen(path));
	delimage(img2);
	initgraph(800, 650);
	setbkmode(TRANSPARENT);
}
