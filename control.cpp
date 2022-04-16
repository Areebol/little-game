//file: control.cpp

#include"control.h"
using namespace std;
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

//��Ϸ�����������
void control::game()
{
	play_start();//չʾ��������

	choose_start();//ѡ�������Ϸ

}

//չʾ��������
void control::play_start()
{
	game_interface.clear_map();//��յ�ͼ��Ļ
	tool_set_cursor_position(23, 15);
	SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY | BACKGROUND_GREEN | FOREGROUND_BLUE
		| FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "WELECOME TO OUR GAME!";
	tool_set_regular_text_color();
}

//��ʼ�˵�ѡ�����
void control::choose_start()
{
	switch (menu_start())//���ò˵� start �ж�����
	{
	case 1://ѡ��1 ������Ϸ������ѡ��
		choose_game();//������Ϸѡ����
		break;
	case 2://ѡ��2 �˳���Ϸ
		game_end();//������Ϸ��������
		break;
	}
}

//��Ϸ�����ò���
void control::choose_game()
{
	switch (menu_set())//������Ϸ���ò˵��ж�����
	{
	case 1://ѡ��1 ������Ϸ�ؿ�ѡ��
		choose_level();//���ùؿ�ѡ����
		break;
	case 2://ѡ��2 ������Ϸ�Ѷ�����
		choose_difficulty();//�����Ѷ����ú���
		break;
	case 3://ѡ��3 ���ؿ�ʼ�˵�
		choose_start();//���ÿ�ʼѡ�����
		break;
	}
}


//��Ϸ�Ĺؿ�ѡ��
void control::choose_level()
{
	switch (menu_level())//������Ϸ�ؿ�ѡ��˵��ж�����
	{
	case 1:
		game_interface.set_map1();
		break;//����ؿ�1
	case 2:
		game_interface.set_map2();
     	break;//����ؿ�2
	case 3:
		game_interface.set_map3();
		break;//����ؿ�3
	case 4:
		choose_game();//���ؿ�ʼ�˵�
		break;
	}
	enter_game();
}

//������Ϸ
void control::game_end()
{
	play_end();//չʾ��Ϸ��������
	pause();//��ͣһ��
	exit(1);
}


//��Ϸ���Ѷ����ú���
void control::choose_difficulty()
{
	switch (menu_difficulty())//�����Ѷ����ú�����������
	{
	case 1:
		break;//�Ѷ�1 
	case 2:
		break;//�Ѷ�2
	case 3:
		break;//�Ѷ�3 
	case 4:
		break;//����
	}
	//������֮�󷵻���Ϸѡ��˵�
	choose_game();
}


//������Ϸ��������
void control::play_end()
{
	game_interface.clear_map();
	tool_set_cursor_position(23, 15);
	SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY | BACKGROUND_GREEN | FOREGROUND_BLUE
		| FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "WELECOME NEXT PLAY!";
	tool_set_regular_text_color();
}


//��ʼ��Ϸ�ĺ���
void control::enter_game()
{
	play();
	pause();
	game_interface.clear_map();
	switch (menu_finish())
	{
	case 1:
		choose_game();
	case 2:
		game_end();
	}
}


//��ͣ����
void control::pause()
{
	tool_set_cursor_position(68, 28);
	system("pause");
}


//��ʼ�˵�
int control::menu_start()
{
	game_interface.clear_tip();
	string sentence = "START MENU";
	SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY |
		FOREGROUND_GREEN);
	game_interface.print_in_tip(8,sentence);

	tool_set_regular_text_color();
	sentence = "1  ENTER GAME";
	game_interface.print_in_tip(13, sentence);
	sentence = "2  QUIT  GAME";
	game_interface.print_in_tip(16, sentence);

	SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY | FOREGROUND_BLUE |
		FOREGROUND_GREEN);
	sentence = "ENTER YOUR CHOICE";
	game_interface.print_in_tip(24, sentence);

	tool_set_regular_text_color();

	char choice = _getch();
	while (choice != '1' && choice != '2')
	{
		choice = _getch();
	}
	return choice - '0';
}


//��Ϸ���ò˵�
int control::menu_set()
{
	game_interface.clear_tip();
	string sentence = "GAME MENU";
	SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY |
		FOREGROUND_GREEN);
	game_interface.print_in_tip(8, sentence);

	tool_set_regular_text_color();
	sentence = "1  CHOOSE LEVEL  ";
	game_interface.print_in_tip(13, sentence);
	sentence = "2  SET DIFFICULTY";
	game_interface.print_in_tip(16, sentence);
	sentence = "3  RETURN        ";
	game_interface.print_in_tip(19, sentence);
	SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY | FOREGROUND_BLUE |
		FOREGROUND_GREEN);
	sentence = "ENTER YOUR CHOICE";
	game_interface.print_in_tip(24, sentence);

	tool_set_regular_text_color();

	char choice = _getch();
	while (choice != '1' && choice != '2'
		&&choice!='3')
	{
		choice = _getch();
	}
	return choice - '0';
}

//��Ϸ�ؿ�ѡ��˵�
int control::menu_level()
{
	game_interface.clear_tip();
	string sentence = "CHOOSE LEVEL";
	SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY |
		FOREGROUND_GREEN);
	game_interface.print_in_tip(8, sentence);

	tool_set_regular_text_color();
	sentence = "1  LEVEL 1    ";
	game_interface.print_in_tip(13, sentence);
	sentence = "2  LEVEL 2    ";
	game_interface.print_in_tip(16, sentence);
	sentence = "3  LEVEL 3    ";
	game_interface.print_in_tip(19, sentence);
	sentence = "4  RETURN     ";
	game_interface.print_in_tip(22, sentence);
	SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY | FOREGROUND_BLUE |
		FOREGROUND_GREEN);
	sentence = "ENTER YOUR CHOICE";
	game_interface.print_in_tip(24, sentence);

	tool_set_regular_text_color();

	char choice = _getch();
	while (choice != '1' && choice != '2'
		&& choice != '3'&&choice!='4')
	{
		choice = _getch();
	}
	return choice - '0';
}

//��Ϸ�Ѷ����ò˵�
int control::menu_difficulty()
{
	game_interface.clear_tip();
	string sentence = "SET DIFFICULTY";
	SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY |
		FOREGROUND_GREEN);
	game_interface.print_in_tip(8, sentence);

	tool_set_regular_text_color();
	sentence = "1  SET EASY      ";
	game_interface.print_in_tip(13, sentence);
	sentence = "2  SET MIDDLE    ";
	game_interface.print_in_tip(16, sentence);
	sentence = "3  SET DIFFICULTY";
	game_interface.print_in_tip(19, sentence);
	sentence = "4  RETURN        ";
	game_interface.print_in_tip(22, sentence);
	SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY | FOREGROUND_BLUE |
		FOREGROUND_GREEN);
	sentence = "ENTER YOUR CHOICE";
	game_interface.print_in_tip(24, sentence);

	tool_set_regular_text_color();

	char choice = _getch();
	while (choice != '1' && choice != '2'
		&& choice != '3'&&choice!='4')
	{
		choice = _getch();
	}
	return choice - '0';
}


//��Ϸ�����˵�
int control::menu_finish()
{
	game_interface.clear_tip();
	string sentence = "YOU WIN";
	SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY |
		FOREGROUND_GREEN);
	game_interface.print_in_tip(8, sentence);

	tool_set_regular_text_color();
	sentence = "1  CONTINUE PLAY";
	game_interface.print_in_tip(13, sentence);
	sentence = "2  QUIT GAME    ";
	game_interface.print_in_tip(16, sentence);

	SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY | FOREGROUND_BLUE |
		FOREGROUND_GREEN);
	sentence = "ENTER YOUR CHOICE";
	game_interface.print_in_tip(24, sentence);

	tool_set_regular_text_color();

	char choice = _getch();
	while (choice != '1' && choice != '2')
	{
		choice = _getch();
	}
	return choice - '0';
}


void control::play()
{
	//��ѭ�� �ж���Ϸ�Ƿ����

	print_map();

	//�ж����ﶯ�� �Լ��ı�����λ��
}

void control::print_map()
{
	game_interface.print_map();
}
