#include"ui.h"
void UI::ui2()//�����˵�
{
	imgui = newimage();
	getimage(imgui, "pic/UI.jpg");
	putimage(0, 0, imgui);
	setcolor(EGERGB(0, 100, 0));     //������ɫ��ɫ
	setfont(200, 0, "����");
	outtextxy(100, 40, "������");
	setfont(40, 0, "����");
	outtextxy(250, 250, "1.���¿�ʼ");
	outtextxy(250, 300, "2.ѡ��ؿ�");
	outtextxy(250, 350, "3.��Ϸ����");
	outtextxy(250, 400, "4.���Ƶ�ͼ");
	outtextxy(250, 450, "5.��ȡ���Ƶĵ�ͼ");
	outtextxy(250, 500, "6.������һ��");
	setfont(25, 0, "����");
	outtextxy(230, 600, "(��������1,2,3,4,5,6����)");
	delimage(imgui);
}
void UI::ui1()//һ���˵�
{
	imgui = newimage();
	getimage(imgui, "pic/UI.jpg");
	putimage(0, 0, imgui);
	setcolor(EGERGB(0, 100, 0));     //������ɫ��ɫ
	setbkmode(TRANSPARENT);     //�������ֱ�����䷽ʽΪ͸����Ĭ��ΪOPAQUE��͸��
	setfont(200, 0, "����");
	outtextxy(100, 50, "������");
	setfont(50, 0, "����");
	outtextxy(300, 300, "1.��½");
	outtextxy(300, 400, "2.ע��");
	outtextxy(300, 500, "3.����");
	setfont(25, 0, "����");
	outtextxy(150, 600, "(��������1,2,3��������Ҫ���κ����뷨)");
	delimage(imgui);
}
void UI::ui3()//��Ϸ����
{
	imgui = newimage();
	getimage(imgui, "pic/����.jpg");
	putimage(0, 0, imgui);
	setcolor(EGERGB(0, 100, 0));     //������ɫ��ɫ
	setbkmode(TRANSPARENT);     //�������ֱ�����䷽ʽΪ͸����Ĭ��ΪOPAQUE��͸��
	setfont(25, 0, "����");
	outtextxy(100, 150, "(1)����ֻ���ƶ�������������һ��ֻ���ƶ�һ�����ӡ�");
	outtextxy(100, 200, "(2)��һ����С�Ĳֿ���,Ҫ���ľ��ŵ�ָ����λ��,");
	outtextxy(100, 250, "�Բ�С�ľͻ���������޷��ƶ�����ͨ������ס�������");
	outtextxy(100, 300, "(3)����Ϸ��Ŀ�ľ��ǰ����е����Ӷ��Ƶ�Ŀ��λ���ϡ�");
	outtextxy(100, 350, "(4)����ϷĿ������ѵ������߼�˼��������");
	delimage(imgui);
}
void UI::ui4()//���ֿ���
{
	imgui = newimage();
	getimage(imgui, "pic/����.jpg");
	putimage(0, 0, imgui);
	
	setfont(200, 0, "����");
	outtextxy(150, 50, "�� ��");
	setfont(40, 0, "����");
	outtextxy(300, 300, "1.�춹");
	outtextxy(300, 350, "2.����");
	outtextxy(300, 400, "3.�ʺ�");
	outtextxy(300, 450, "4.�������");
	outtextxy(300, 500, "5.�Ϻ���");
	outtextxy(300, 550, "6.�ر�����");
	delimage(imgui);
}