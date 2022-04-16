//file: tools.cpp

//�Կ���̨�����ĺ�������

//��Ҫ���õ�ͷ�ļ�
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
	//����ṹ�� ���ڸı����λ��
	COORD coord = { position_x,position_y };
	SetConsoleCursorPosition(buff, coord);
}


void tool_close_cursor()
{
	//���ò��� �رչ��
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(buff, &cursor_info);
}


void tool_open_cursor()
{
	//���ò����򿪹��
	CONSOLE_CURSOR_INFO cursor_info = { 20, 1 };
	SetConsoleCursorInfo(buff, &cursor_info);
}


void tool_set_text_color(int front_color, int back_color)
{
	SetConsoleTextAttribute(buff, BACKGROUND_INTENSITY | back_color * 16 | FOREGROUND_INTENSITY | front_color);
}


COORD tool_get_cursor_now_position()
{
	//�õ�����������Ϣ ���ұ��滺������Ϣ
	CONSOLE_SCREEN_BUFFER_INFO   infoBuffer;
	GetConsoleScreenBufferInfo(buff, &infoBuffer);

	//��������Ϣ��������б���
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
	//����end
	end = clock();
	return (end - start) / CLOCKS_PER_SEC;
}

