/*
����:DawsonLee
Email:dawsonlee1790@foxmail.com
*/


#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>

#define BLACK	      0 //�ڸ�:�������ͼ��
#define WHITEWALL	  1	//��ǽ:�����赲�����ƶ�
#define BLUEWALL	  2	//����:���ڱ�ʾ���ƶ��ռ�
#define BALL	      3	//��	:����ָ�����ӷ���λ��
#define BOX	          4	//����:���ڱ�ʾ��ʼ����λ��
#define REDBOX	      5	//��ɫ������:���ڱ�ʾ�����λ���Ѿ���������
#define MAN	          6	//����:���ڱ�ʾ����λ��
#define MANBALL       7//����վ�ڵ���




int main()
{
	int map[13][16];//����һ��map���������洢������Ϣ
	int man_i, man_j;//�����洢�����λ����Ϣ
	int readmap(int map[13][16], int &man_x, int &man_y);
	void darm(int a, int ii, int jj);

	readmap(map, man_i, man_j);//����readmap()������


	initgraph(800, 650);//����һ����800����650�Ĵ��ڡ��������Ԫ�ض�Ӧ��ÿ��С������50*50�ģ��Ǹ����ھ�Ӧ������ô��
						
	//����һ��Ư���ı���ͼƬ
	PIMAGE imgui;
	imgui = newimage();
	getimage(imgui, "pic/����.jpg");
	putimage(0, 0, imgui);

	for (int i = 0; i<13; i++)
		for (int j = 0; j < 16; j++)
		{
			darm(map[i][j], i, j);//��������ÿ��С����
		}

	void move(char get, int map[13][16], int &man_i, int &man_j);
	char get;
	for (; is_run(); delay_fps(60))//is_run()��ʾ����һֱ��ʾ��delay_fps(60)��ʾ������60֡��Ƶ��ˢ��
	{
		get = getch();//�ȴ��û�������̰���
		move(get, map, man_i, man_j);
	}

	closegraph();//�رմ���
	return 0;
}

int readmap(int map[13][16], int &man_i, int &man_j)//map[13][16]���βΣ�����&man_i���ǵ���man_i�����ã����ô��ݵ��������ڣ���������������еĲ������ı�
{
	FILE *fp = fopen("MAP.txt", "rb");//��ֻ����ʽ���ļ�MAP.txt
	if (!fp) {
		printf("���ļ�ʧ�ܣ��ļ�λ������ܷŴ���\n");
		exit(1);//��ʧ�����������
	}
	int i, j;
	char str[10];//���ڴ洢���ı��ļ���ȡ���ַ�����Ϣ
	for (i = 0; i<13; i++)
		for (j = 0; j < 16; j++) 
		{
			fscanf(fp, "%s", str); //���ļ��ж�ȡһ���ַ����������ո����
			map[i][j] = atoi(str);//���ַ���ת��Ϊ���ͣ�����ֵ��map[i][j]
			if (map[i][j] == MAN) //����ҵ���MAN��λ�ã��򷵻������� man_i�� man_j ��
			{
				man_i = i;
				man_j = j;
			}
		}
	return 0;
}
/*
��������ͼ�ο����С������ͼ��Ĺ���ģ��
�ⲿ���漰C++�е�֪ʶ��C�������ֲ��ع�����᲻���Ķ�������Ҫ֪����������Դ�ļ�Ҫ��cpp��ʽ��
*/

void darm(int a, int ii, int jj)
{
	PIMAGE img;//����
	img = newimage();//ʵ����
	switch (a)
	{
	case BLACK:break;
	case WHITEWALL:
	{
		getimage(img, "pic/ǽ.jpg");//getimage()��putimage�뷭��egeͼ�ο�����ֲᡣ
		putimage(jj * 50, ii * 50, img);//��ii��jj�л���һ��50*50���صľ���ͼ��
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

/*
���뺯���Ĳ��� get��ʾ�û�����ļ��̰���������ʵʱ����map����Ϣ������ʵʱMAN��λ����Ϣman_i��man_j��
*/
void move(char get, int map[13][16], int &man_i, int &man_j)
{
	//���Ȱ�����ı仯����table[12][4]������
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
	void darm(int a, int ii, int jj);//Ҫ�õ����ƺ���������������
	switch (get)//switch�ж��û�����ļ�����Ϣ
	{
	case 37:   //���ƣ��������ASCII��
		//forѭ�������ж�MAN�����ƶ���Ӧ�����������
		for (i = 0; i < 12; i++)
			if (map[man_i][man_j] * map[man_i][man_j - 1] * map[man_i][man_j - 2] == table[i][0] ||
				map[man_i][man_j] * map[man_i][man_j - 1] == table[i][0])
			{
				//�ҵ���Ӧ�������ִ���������

				map[man_i][man_j] = table[i][1];
				map[man_i][man_j - 1] = table[i][2];
				if (table[i][3] != -1)map[man_i][man_j - 2] = table[i][3];//�������Ҫ�ı���������ӵ�ͼ�񣬾Ͳ���ֵ��Ҳ�������table[i][3]==-1ʱ��

				//�������ƶ�Ӧ������������Ϣ
				darm(map[man_i][man_j], man_i, man_j);
				darm(map[man_i][man_j - 1], man_i, man_j - 1);
				darm(map[man_i][man_j - 2], man_i, man_j - 2);

				man_j--;//���ƽ�����Ҫ�ı�MAN��ʵʱλ����Ϣ����break����ѭ��
				break;
			}
		break;//�ٴ�break����switch���
	case 38://���ƣ����ϼ���ASCII��
		//forѭ�������ж�MAN�����ƶ���Ӧ�����������
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
	case 39://���ƣ����Ҽ���ASCII��
		//forѭ�������ж�MAN�����ƶ���Ӧ�����������
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
	case 40://���ƣ����¼���ASCII��
		//forѭ�������ж�MAN�����ƶ���Ӧ�����������
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
