//file: control.h

#ifndef CONTROL_H
#define CONTROL_H
#include"my_interface.h"

class control
{
public:
	//初始化界面
	control()
	{}

	//整个游戏的操作函数
	//1 
	void game();

private:
	//打印游戏的开始提示动画
	//2
	void play_start();

	//开始菜单进行选择
	//3
	void choose_start();

	//选择设置游戏难度
	//4
	void choose_game();

	//退出游戏
	//5
	void game_end();

	//选择关卡
	//6
	void choose_level();

	//选择难度
	//7
	void choose_difficulty();

	//播放结束动画
	//8
	void play_end();

	//控制游戏进入 退出
	//9  
	void enter_game();


	//游戏操作部分
	//10
	void play();


	//------------------------游戏操作部分--------------------------
	//1 判断游戏是否结束


	//2 根据迷雾输出地图
	void print_map();

	//-------------------------菜单部分-----------------------------
	//1 展示开始菜单
	//返回选择
	int menu_start();

	//2 展示游戏设置菜单
	//返回选择
	int menu_set();

	//3 展示难度选择菜单
	//返回选择
	int menu_difficulty();

	//4 展示游戏完成菜单
	//返回选择
	int menu_finish();

	//5 展示游戏关卡菜单
	//返回选择
	int menu_level();

	void pause();
private:
	//控制游戏界面
	my_interface game_interface;
};

#endif