//file: control.h

#ifndef CONTROL_H
#define CONTROL_H
#include"my_interface.h"

class control
{
public:
	//��ʼ������
	control()
	{}

	//������Ϸ�Ĳ�������
	//1 
	void game();

private:
	//��ӡ��Ϸ�Ŀ�ʼ��ʾ����
	//2
	void play_start();

	//��ʼ�˵�����ѡ��
	//3
	void choose_start();

	//ѡ��������Ϸ�Ѷ�
	//4
	void choose_game();

	//�˳���Ϸ
	//5
	void game_end();

	//ѡ��ؿ�
	//6
	void choose_level();

	//ѡ���Ѷ�
	//7
	void choose_difficulty();

	//���Ž�������
	//8
	void play_end();

	//������Ϸ���� �˳�
	//9  
	void enter_game();


	//��Ϸ��������
	//10
	void play();


	//------------------------��Ϸ��������--------------------------
	//1 �ж���Ϸ�Ƿ����


	//2 �������������ͼ
	void print_map();

	//-------------------------�˵�����-----------------------------
	//1 չʾ��ʼ�˵�
	//����ѡ��
	int menu_start();

	//2 չʾ��Ϸ���ò˵�
	//����ѡ��
	int menu_set();

	//3 չʾ�Ѷ�ѡ��˵�
	//����ѡ��
	int menu_difficulty();

	//4 չʾ��Ϸ��ɲ˵�
	//����ѡ��
	int menu_finish();

	//5 չʾ��Ϸ�ؿ��˵�
	//����ѡ��
	int menu_level();

	void pause();
private:
	//������Ϸ����
	my_interface game_interface;
};

#endif