//file: tools.h

#ifndef TOOLS_H
#define TOOLS_H

//对控制台操作的函数声明

//需要引用的头文件
#include<Windows.h>
#include<iostream>
#include<conio.h>
#include<ctime>


//工具函数 设置控制台窗口的大小
//参数1 表示控制台的高 需要大于0
//参数2 表示控制台的宽 需要大于0
void tool_set_window_size(short length, short width);


//工具函数 恢复控制台输出的字体颜色
//黑底白字的标准型
//参数1 表示对应调整的缓冲区
void tool_set_regular_text_color();


//工具函数 改变控制台光标的位置
//参数1 光标的x位置
//参数2 光标的y位置
//参数3 表示对应调整的缓冲区
//使用的时候 谨慎使用换行符号
void tool_set_cursor_position(short position_x, short position_y);


//工具函数 关闭光标的显示
//参数1 表示对应调整的缓冲区
void tool_close_cursor();

//工具函数 打开光标的显示
//参数1 表示对应调整的缓冲区
void tool_open_cursor();

//工具函数 设置控制台输出的字体颜色
//参数1 表示前景色  
//参数2 表示后景
//参数3 表示对应调整的缓冲区
//0 = 浅灰 8 = 灰色
//1 = 蓝色 9 = 淡蓝色
//2 = 绿色 10 = 淡绿色
//3 = 浅绿 11 = 淡浅绿色
//4 = 红色 12 = 淡红色
//5 = 紫色 13 = 淡紫色
//6 = 黄色 14 = 淡黄色
//7 = 白色 15 = 亮白色
//使用后字体颜色保持不变
//如果要恢复默认值 
//需要调用工具函数 tool_set_regular_text_color()
void tool_set_text_color(int front_color, int back_color);


//工具函数 返回当前光标的坐标
//返回值是一个COORD结构体
//包含的了 x以及y 可以调整光标位置
//参数1 表示对应调整的缓冲区
COORD tool_get_cursor_now_position();

//工具类 获得从类开始构建的时间变化
//构建一个类开始计算时间
//成员函数get_clock()返回的是构造这个类开始经过的时间
class tool_time
{
public:
	//构造函数 初始化 start以及end
	tool_time();
	
	//返回经过的时间
	int get_clock();

private:
	int start;//存储创建的时间
	int end;//存储调用的时间
};

#endif TOOLS_H