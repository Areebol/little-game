//file: tools.cpp

//对控制台操作的函数定义

//需要引用的头文件
#include"tools.h"

HANDLE buff = GetStdHandle(STD_OUTPUT_HANDLE);
void tool_set_window_size(short length, short width)
{
	char cmd[64];
	sprintf_s(cmd, "mode con cols=%d lines=%d", width, length);
	system(cmd);
}


void tool_set_regular_text_color()
{
	SetConsoleTextAttribute(buff, FOREGROUND_INTENSITY | 7);
}


void tool_set_cursor_position(short position_x, short position_y)
{
	//坐标结构体 用于改变光标的位置
	COORD coord = { position_x,position_y };
	SetConsoleCursorPosition(buff, coord);
}


void tool_close_cursor()
{
	//设置参数 关闭光标
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(buff, &cursor_info);
}


void tool_open_cursor()
{
	//设置参数打开光标
	CONSOLE_CURSOR_INFO cursor_info = { 20, 1 };
	SetConsoleCursorInfo(buff, &cursor_info);
}


void tool_set_text_color(int front_color, int back_color)
{
	SetConsoleTextAttribute(buff, BACKGROUND_INTENSITY | back_color * 16 | FOREGROUND_INTENSITY | front_color);
}


COORD tool_get_cursor_now_position()
{
	//得到缓冲区的信息 并且保存缓冲区信息
	CONSOLE_SCREEN_BUFFER_INFO   infoBuffer;
	GetConsoleScreenBufferInfo(buff, &infoBuffer);

	//缓冲区信息的坐标进行保存
	COORD now_position = { infoBuffer.dwCursorPosition.X, infoBuffer.dwCursorPosition.Y };

	return now_position;
}


tool_time::tool_time()
{
	start = clock();
	end = clock();
}


int tool_time::get_clock()
{
	//更新end
	end = clock();
	return (end - start) / CLOCKS_PER_SEC;
}

