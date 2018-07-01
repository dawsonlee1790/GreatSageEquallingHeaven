#include"ui.h"
void UI::ui2()//二级菜单
{
	imgui = newimage();
	getimage(imgui, "pic/UI.jpg");
	putimage(0, 0, imgui);
	setcolor(EGERGB(0, 100, 0));     //文字颜色绿色
	setfont(200, 0, "宋体");
	outtextxy(100, 40, "推箱子");
	setfont(40, 0, "宋体");
	outtextxy(250, 250, "1.从新开始");
	outtextxy(250, 300, "2.选择关卡");
	outtextxy(250, 350, "3.游戏介绍");
	outtextxy(250, 400, "4.绘制地图");
	outtextxy(250, 450, "5.读取绘制的地图");
	outtextxy(250, 500, "6.返回上一级");
	setfont(25, 0, "宋体");
	outtextxy(230, 600, "(键盘输入1,2,3,4,5,6操作)");
	delimage(imgui);
}
void UI::ui1()//一级菜单
{
	imgui = newimage();
	getimage(imgui, "pic/UI.jpg");
	putimage(0, 0, imgui);
	setcolor(EGERGB(0, 100, 0));     //文字颜色绿色
	setbkmode(TRANSPARENT);     //设置文字背景填充方式为透明，默认为OPAQUE不透明
	setfont(200, 0, "宋体");
	outtextxy(100, 50, "推箱子");
	setfont(50, 0, "宋体");
	outtextxy(300, 300, "1.登陆");
	outtextxy(300, 400, "2.注册");
	outtextxy(300, 500, "3.音乐");
	setfont(25, 0, "宋体");
	outtextxy(150, 600, "(键盘输入1,2,3操作，不要用任何输入法)");
	delimage(imgui);
}
void UI::ui3()//游戏介绍
{
	imgui = newimage();
	getimage(imgui, "pic/背景.jpg");
	putimage(0, 0, imgui);
	setcolor(EGERGB(0, 100, 0));     //文字颜色绿色
	setbkmode(TRANSPARENT);     //设置文字背景填充方式为透明，默认为OPAQUE不透明
	setfont(25, 0, "宋体");
	outtextxy(100, 150, "(1)箱子只能推动而不能拉动。一次只能推动一个箱子。");
	outtextxy(100, 200, "(2)在一个狭小的仓库中,要求把木箱放到指定的位置,");
	outtextxy(100, 250, "稍不小心就会出现箱子无法移动或者通道被堵住的情况。");
	outtextxy(100, 300, "(3)本游戏的目的就是把所有的箱子都推到目标位置上。");
	outtextxy(100, 350, "(4)此游戏目的是在训练你的逻辑思考能力。");
	delimage(imgui);
}
void UI::ui4()//音乐控制
{
	imgui = newimage();
	getimage(imgui, "pic/背景.jpg");
	putimage(0, 0, imgui);
	
	setfont(200, 0, "宋体");
	outtextxy(150, 50, "音 乐");
	setfont(40, 0, "宋体");
	outtextxy(300, 300, "1.红豆");
	outtextxy(300, 350, "2.王妃");
	outtextxy(300, 400, "3.彩虹");
	outtextxy(300, 450, "4.告白气球");
	outtextxy(300, 500, "5.上和下");
	outtextxy(300, 550, "6.关闭音乐");
	delimage(imgui);
}