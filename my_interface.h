//file: my_interface.h
//包含界面类的设计

#ifndef MY_INTERFACE_H
#define MY_INTERFACE_H

#include"tools.h"
#include"cloud.h"
#include<string>
#include<vector>
using std::string;

class my_interface
{
public:
	//对于界面进行初始化设置
	//参数1调整地图的宽度 默认60
	//参数2调整提示栏的宽度 默认30
	//参数3调整界面的高度 默认30
	//对于界面进行大小调整，并且打印边界
	my_interface(int map_w = 60, int tooltip_w = 30, int l = 30);

	//打印边界
	void print_edge()const;

	//在提示栏显示内容 
	//参数1表示在第几行显示
	//参数2接收一个字符串打印
	//如果参数1超出范围，抛出 out_of_range
	//如果参数2超出范围，抛出 out_of_range
	void print_in_tip(int start,string& content)const;

	//打印地图内容
	void print_map()const;

	//设置地图
	void set_map1();

	void set_map2();

	void set_map3();

	//清除旁栏的内容
	void clear_tip()const;

	//清空地图界面的内容
	void clear_map()const;

	//操纵迷雾类 让点 x, y 可视 注意坐标 30*60
	void set_see(int i,int j);
private:
	//打印上下边框
	//参数1表示从第几行开始打印
	void print_width_edge(int start)const;

private:
	//地图界面的宽度
	int map_width;
	//提示栏界面的宽度
	int tooltip_width;
	//界面设计中地图以及提示栏的高度
	int height;
	//界面设计的总高度
	int interface_height;
	//界面设计的总宽度
	int interface_width;
	//存放地图
	bool map[30][30];

	cloud foggy;
};


#endif 


