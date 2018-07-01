#pragma once
#include <graphics.h>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define LIST 13
#define ROW 16
#define BLACK	      0 //�ڸ�:�������ͼ��
#define WHITEWALL	  1	//��ǽ:�����赲�����ƶ�
#define BLUEWALL	  2	//����:���ڱ�ʾ���ƶ��ռ�
#define BALL	      3	//��	:����ָ�����ӷ���λ��
#define BOX	      4	//����:���ڱ�ʾ��ʼ����λ��
#define REDBOX	  5	//��ɫ������:���ڱ�ʾ�����λ���Ѿ���������
#define MAN	      6	//����:���ڱ�ʾ����λ��
#define MANBALL    20//����վ�ڵ���
class MAP
{
private:
	int checkpoint;
	int i, j;
public:
	PIMAGE img;
	char name[20];                  //�����洢��ȡ�ĵ�ͼ�����ƣ�����ʵ���������뵱����Ϸ
	int map[LIST][ROW];             //�����洢������ͼÿ�������ʾ����Ϣ
	int x, y;                   //�˵����꣨readmap()���������Ժ��õ���
	void readmap(char str[]);   //��ȡ��ͼģ�飨ʵ�����Ƕ�ȡһ����������map���������У�
	void darmmap();              //���Ƶ�ͼģ�� ��ʵ�����ǻ�������Ķ�Ӧͼ��
	int move(char a);                 //ʵ��������ƶ�(ʵ������map����ĸı�)(WSAD�ٿ��������ң�C����ѡ�أ�R�������뱾��)
	int judge();             //�ж�ģ��
	int choose(int checkpoint);       //ѡ��ģ��
	void darm(int a, int jj, int ii);//���ڻ���ĳ�����꣨yy��xx��λ�õĵ�ͼ��
	void newmap();
};
