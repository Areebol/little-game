//file: control.cpp

#include"control.h"
using namespace std;
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

//游戏主体操作部分
void control::game()
{
	play_start();//展示开场动画

	choose_start();//选择进入游戏

}

//展示开场动画
void control::play_start()
{
	game_interface.clear_map();//清空地图屏幕
	tool_set_cursor_position(23, 15);
	SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY | BACKGROUND_GREEN | FOREGROUND_BLUE
		| FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "WELECOME TO OUR GAME!";
	tool_set_regular_text_color();
}

//开始菜单选择操作
void control::choose_start()
{
	switch (menu_start())//调用菜单 start 判断输入
	{
	case 1://选择1 进入游戏的设置选择
		choose_game();//调用游戏选择函数
		break;
	case 2://选择2 退出游戏
		game_end();//调用游戏结束函数
		break;
	}
}

//游戏的设置操作
void control::choose_game()
{
	switch (menu_set())//调用游戏设置菜单判断输入
	{
	case 1://选择1 进入游戏关卡选择
		choose_level();//调用关卡选择函数
		break;
	case 2://选择2 进入游戏难度设置
		choose_difficulty();//调用难度设置函数
		break;
	case 3://选择3 返回开始菜单
		choose_start();//调用开始选择操作
		break;
	}
}


//游戏的关卡选择
void control::choose_level()
{
	switch (menu_level())//调用游戏关卡选择菜单判断输入
	{
	case 1:
		game_interface.set_map1();
		break;//进入关卡1
	case 2:
		game_interface.set_map2();
     	break;//进入关卡2
	case 3:
		game_interface.set_map3();
		break;//进入关卡3
	case 4:
		choose_game();//返回开始菜单
		break;
	}
	enter_game();
}

//结束游戏
void control::game_end()
{
	play_end();//展示游戏结束画面
	pause();//暂停一下
	exit(1);
}


//游戏的难度设置函数
void control::choose_difficulty()
{
	switch (menu_difficulty())//调用难度设置函数进行设置
	{
	case 1:
		break;//难度1 
	case 2:
		break;//难度2
	case 3:
		break;//难度3 
	case 4:
		break;//返回
	}
	//设置完之后返回游戏选择菜单
	choose_game();
}


//播放游戏结束动画
void control::play_end()
{
	game_interface.clear_map();
	tool_set_cursor_position(23, 15);
	SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY | BACKGROUND_GREEN | FOREGROUND_BLUE
		| FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "WELECOME NEXT PLAY!";
	tool_set_regular_text_color();
}


//开始游戏的函数
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


//暂停函数
void control::pause()
{
	tool_set_cursor_position(68, 28);
	system("pause");
}


//开始菜单
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


//游戏设置菜单
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

//游戏关卡选择菜单
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

//游戏难度设置菜单
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


//游戏结束菜单
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
	//死循环 判断游戏是否结束

	print_map();

	//判断人物动作 以及改变人物位移
}

void control::print_map()
{
	game_interface.print_map();
}
