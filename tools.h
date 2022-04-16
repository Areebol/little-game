//file: tools.h

#ifndef TOOLS_H
#define TOOLS_H

//�Կ���̨�����ĺ�������

//��Ҫ���õ�ͷ�ļ�
#include<Windows.h>
#include<iostream>
#include<conio.h>
#include<ctime>


//���ߺ��� ���ÿ���̨���ڵĴ�С
//����1 ��ʾ����̨�ĸ� ��Ҫ����0
//����2 ��ʾ����̨�Ŀ� ��Ҫ����0
void tool_set_window_size(short length, short width);


//���ߺ��� �ָ�����̨�����������ɫ
//�ڵװ��ֵı�׼��
//����1 ��ʾ��Ӧ�����Ļ�����
void tool_set_regular_text_color();


//���ߺ��� �ı����̨����λ��
//����1 ����xλ��
//����2 ����yλ��
//����3 ��ʾ��Ӧ�����Ļ�����
//ʹ�õ�ʱ�� ����ʹ�û��з���
void tool_set_cursor_position(short position_x, short position_y);


//���ߺ��� �رչ�����ʾ
//����1 ��ʾ��Ӧ�����Ļ�����
void tool_close_cursor();

//���ߺ��� �򿪹�����ʾ
//����1 ��ʾ��Ӧ�����Ļ�����
void tool_open_cursor();

//���ߺ��� ���ÿ���̨�����������ɫ
//����1 ��ʾǰ��ɫ  
//����2 ��ʾ��
//����3 ��ʾ��Ӧ�����Ļ�����
//0 = ǳ�� 8 = ��ɫ
//1 = ��ɫ 9 = ����ɫ
//2 = ��ɫ 10 = ����ɫ
//3 = ǳ�� 11 = ��ǳ��ɫ
//4 = ��ɫ 12 = ����ɫ
//5 = ��ɫ 13 = ����ɫ
//6 = ��ɫ 14 = ����ɫ
//7 = ��ɫ 15 = ����ɫ
//ʹ�ú�������ɫ���ֲ���
//���Ҫ�ָ�Ĭ��ֵ 
//��Ҫ���ù��ߺ��� tool_set_regular_text_color()
void tool_set_text_color(int front_color, int back_color);


//���ߺ��� ���ص�ǰ��������
//����ֵ��һ��COORD�ṹ��
//�������� x�Լ�y ���Ե������λ��
//����1 ��ʾ��Ӧ�����Ļ�����
COORD tool_get_cursor_now_position();

//������ ��ô��࿪ʼ������ʱ��仯
//����һ���࿪ʼ����ʱ��
//��Ա����get_clock()���ص��ǹ�������࿪ʼ������ʱ��
class tool_time
{
public:
	//���캯�� ��ʼ�� start�Լ�end
	tool_time();
	
	//���ؾ�����ʱ��
	int get_clock();

private:
	int start;//�洢������ʱ��
	int end;//�洢���õ�ʱ��
};

#endif TOOLS_H